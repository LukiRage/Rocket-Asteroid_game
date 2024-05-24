// shot.h
#ifndef SHOT_H
#define SHOT_H

#include <TFT_eSPI.h>

extern int potValue; // Declare potValue as an extern variable

struct Spaceship_shot {
  int x;
  int y;
  bool active;
};

extern const int shot_limit;
extern Spaceship_shot shots[];
extern unsigned long lastShotTime;
extern const unsigned long shotInterval;

void initializeShots();
void spawnShot(TFT_eSPI &tft); // Add tft as a parameter
void updateShots(TFT_eSPI &tft);
void checkCollision(TFT_eSPI &tft);

#endif
