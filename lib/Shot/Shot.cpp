// shot.cpp
#include <Shot.h>
#include <Spaceship.h>
#include <Asteroid.h>
#include <Graphics.h>

int potValue;

const int shot_limit = 20;
Spaceship_shot shots[shot_limit];
unsigned long lastShotTime = 0;
const unsigned long shotInterval = 400; // 700

void initializeShots() {
  for (int i = 0; i < shot_limit; i++) {
    shots[i].active = false;
  }
}

void spawnShot(TFT_eSPI &tft) { // Add tft as a parameter
  for (int i = 0; i < shot_limit; i++) {
    if (!shots[i].active) {
      shots[i].x = spaceshipX + 10;
      shots[i].y = tft.height() - 30;  // Start near the spaceship
      shots[i].active = true; // Activate the shot
      break;
    }
  }
}

void updateShots(TFT_eSPI &tft) {
  for (int i = 0; i < shot_limit; i++) {
    if (shots[i].active) {
      tft.fillRect(shots[i].x, shots[i].y, 8, 3, TFT_BLACK); // Clear previous shot position
      shots[i].y -= 2;  // Move the shot upward by 2 pixels

      if (shots[i].y < 0) {
        shots[i].active = false; // Deactivate the shot when off screen
      } else {
        drawShot(tft, shots[i].x, shots[i].y); // Draw the shot
      }
    }
  }
}

void checkCollision(TFT_eSPI &tft) {
    if (potValue > 10) {
        for (int i = 0; i < maxAsteroids; i++) {
            if (asteroids[i].active) {
                if (spaceshipX < asteroids[i].x + 16 && spaceshipX + spaceshipWidth > asteroids[i].x &&
                    tft.height() - 40 < asteroids[i].y + 16 && tft.height() - 40 + spaceshipHeight > asteroids[i].y) {

                    // Collision detected
                    if (Spaceship_life > 0) {
                        drawHeart(tft, Spaceship_life - 1); // Update the heart display
                        Spaceship_life--;
                        tft.fillRect(asteroids[i].x, asteroids[i].y-12, 16, 28, TFT_BLACK);//16
                        asteroids[i].active = false; // Deactivate the asteroid after collision
                    } 

                    if (Spaceship_life == 0) {
                        tft.setCursor((tft.width() / 2) - 56, (tft.height() / 2) - 8);
                        tft.setTextColor(TFT_WHITE, TFT_BLACK);
                        tft.setTextSize(2);
                        tft.println("Game Over!");

                        while (1);  // Halt the program after game over
                    }
                }
            }

            for (int j = 0; j < shot_limit; j++) {
                if (shots[j].active && asteroids[i].active) {
                    if (shots[j].x < asteroids[i].x + 16 && shots[j].x + 8 > asteroids[i].x &&
                        shots[j].y < asteroids[i].y + 16 && shots[j].y + 3 > asteroids[i].y) {
                        shots[j].active = false; // Deactivate the shot
                        asteroids[i].hitpoints--; // Decrement hitpoints

                        if (asteroids[i].hitpoints <= 0) {
                            tft.fillRect(asteroids[i].x, asteroids[i].y - 14, 18, 32, TFT_BLACK); // Clear asteroid from screen
                            //^to do: make fillrect after asteroid shot-out bigger/ positioned bigger
                            asteroids[i].active = false; // Deactivate the asteroid
                        }
                    }
                }
            }
        }
    }
}