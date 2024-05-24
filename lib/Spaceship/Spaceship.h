// Spaceship.h
#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <TFT_eSPI.h>

extern int spaceshipX;
extern bool movingDown;
extern int Speed;


void initializeSpaceship(TFT_eSPI &tft);
void updateSpaceship(TFT_eSPI &tft, int potValue, int difference, unsigned int &game_time);



#endif // SPACESHIP_H