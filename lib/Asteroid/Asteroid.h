// asteroid.h
#ifndef ASTEROID_H
#define ASTEROID_H

#include <TFT_eSPI.h>

extern const int maxAsteroids;
extern unsigned long lastSpawnTime;
extern const unsigned long spawnInterval;

struct Asteroid {
  int x;
  int y;
  bool active;
  int hitpoints;
};

extern Asteroid asteroids[];

void initializeAsteroids();
void spawnAsteroid(TFT_eSPI &tft);
void updateAsteroids(TFT_eSPI &tft);

#endif
