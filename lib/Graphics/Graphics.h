// graphics.h
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <TFT_eSPI.h>


extern const int spaceshipWidth;
extern const int spaceshipHeight;

void drawSpaceship(TFT_eSPI &tft, int spaceshipX);
void drawAsteroid(TFT_eSPI &tft, int x, int y);
void drawShot(TFT_eSPI &tft, int x, int y);
void drawTimer(TFT_eSPI &tft, int game_time);
void drawHeart(TFT_eSPI &tft, int heart_count);

#endif
