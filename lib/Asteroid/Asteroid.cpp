// asteroid.cpp
#include <Asteroid.h>
#include <Graphics.h>

const int maxAsteroids = 10;
unsigned long lastSpawnTime = 0;
const unsigned long spawnInterval = 600;

Asteroid asteroids[maxAsteroids];

void initializeAsteroids() {
  for (int i = 0; i < maxAsteroids; i++) {
    asteroids[i].active = false;
  }
}

void spawnAsteroid(TFT_eSPI &tft) {
  for (int i = 0; i < maxAsteroids; i++) {
    if (!asteroids[i].active) {
      int asteroidX = random(0, tft.width() - 16); // Assuming asteroid width is 16
      asteroids[i].x = asteroidX;
      asteroids[i].y = 0;  // Start at the top of the screen
      asteroids[i].active = true; // Activate the asteroid
      asteroids[i].hitpoints = 2; // Reset hitpoints
      break;
    }
  }
}

void updateAsteroids(TFT_eSPI &tft) {
  for (int i = 0; i < maxAsteroids; i++) {
    if (asteroids[i].active) {
      tft.fillRect(asteroids[i].x, asteroids[i].y - 13, 16, 29, TFT_BLACK); // Clear previous asteroid position
      asteroids[i].y += 2;  // Move the asteroid downward by 2 pixels

      if (asteroids[i].y > tft.height() + 20) {
        tft.fillRect(asteroids[i].x, asteroids[i].y - 13, 16, 29, TFT_BLACK); // Clear off-screen asteroid
        asteroids[i].active = false; // Deactivate the asteroid when off screen
      } else {
        drawAsteroid(tft, asteroids[i].x, asteroids[i].y); // Draw the asteroid
      }
    }
  }
}