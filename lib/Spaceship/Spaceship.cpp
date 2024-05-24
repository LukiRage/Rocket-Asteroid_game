// spaceship.cpp
#include <Spaceship.h>
#include <Graphics.h>

int spaceshipX;
bool movingDown = true;
int Speed = 2;

void initializeSpaceship(TFT_eSPI &tft) {
  spaceshipX = (tft.width() - 19) / 2; // 19 is the spaceshipWidth
}

void updateSpaceship(TFT_eSPI &tft, int potValue, int difference, unsigned int &game_time) {
  tft.fillRect(spaceshipX, tft.height() - 40, 19, 14, TFT_BLACK); // clear spaceship

  if (potValue <= 10) {
    if (movingDown) {
      spaceshipX += Speed;
    } else {
      spaceshipX -= Speed;
    }

    if (spaceshipX <= 0) {
      movingDown = true;  // Change direction to downward
    } else if (spaceshipX >= tft.width() - 19) {
      movingDown = false;  // Change direction to upward
    }
  } else {
    game_time += difference;
    spaceshipX = (((potValue * 250) / 4075) + 5);  // Set spaceshipX between 5 and 255
  }

  drawSpaceship(tft, spaceshipX);  // Draw spaceship at the new position
}