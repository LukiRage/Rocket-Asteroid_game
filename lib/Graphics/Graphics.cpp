// graphics.cpp
#include <Graphics.h>

const int spaceshipWidth = 19;
const int spaceshipHeight = 14;

const unsigned char spaceshipBitmap[] = {
  0x00, 0xe0, 0x00, 0x00, 0xa0, 0x00, 0x03, 0xb8, 0x00, 0x02, 0x08, 0x00, 0x02, 0xe8, 0x00, 0x02, 0xa8, 0x00, 0x3a, 0xab, 0x80,
  0x2a, 0xea, 0x80, 0x2a, 0x0e, 0x80, 0xe0, 0x00, 0xe0, 0x80, 0x00, 0x20, 0xfe, 0x0f, 0xe0, 0x02, 0x08, 0x00, 0x03, 0xf8, 0x00
};

const unsigned char asteroid_bodyBitmap[] = {
  0x07, 0xe0, 0x1c, 0x38, 0x30, 0x0c, 0x6c, 0x06, 0x52, 0x02, 0xd2, 0x03, 0x8c, 0x01, 0x80, 0xf1, 0x81, 0x99, 0x99, 0x09,
  0xd9, 0x0b, 0x41, 0x9a, 0x60, 0xf6, 0x30, 0x0c, 0x1c, 0x38, 0x07, 0xe0
};

const unsigned char asteroid_tailBitmap[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x03, 0x80, 0x03, 0xc0, 0x03, 0xc2, 0x0b, 0xe2, 0x0f, 0xf6, 0x9f, 0xf7,
  0xdf, 0xff, 0xd8, 0x1f, 0xe0, 0x07, 0xc0, 0x03, 0x80, 0x01, 0x80, 0x01
};

const unsigned char heart_emptyBitmap[]={//14x14
  0x3c, 0x3c, 0x42, 0x42, 0x99, 0x81, 0xb0, 0x01, 0xa0, 0x01, 0x80, 0x01, 0x80, 0x01, 0x40, 0x02, 0x20, 0x04, 0x10, 0x08,
  0x08, 0x10, 0x04, 0x20, 0x02, 0x40, 0x01, 0x80 
};

const unsigned char heart_filledBitmap[]={//14x14
  0x3c, 0x3c, 0x7e, 0x7e, 0xe3, 0xff, 0xc7, 0xff, 0xcf, 0xff, 0xdf, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0x3f, 0xfc, 0x1f, 0xf8,
  0x0f, 0xf0, 0x07, 0xe0, 0x03, 0xc0, 0x01, 0x80  
};

const unsigned char shotBitmap[] = {
  0x18, 0x18, 0x18
};

void drawSpaceship(TFT_eSPI &tft, int spaceshipX) {
  tft.drawBitmap(spaceshipX, tft.height() - 40, spaceshipBitmap, spaceshipWidth, spaceshipHeight, TFT_WHITE, TFT_BLACK);
}

void drawAsteroid(TFT_eSPI &tft, int x, int y) {
  tft.drawBitmap(x, y - 13, asteroid_tailBitmap, 16, 16, TFT_DARKGREY, TFT_BLACK);
  tft.drawBitmap(x, y, asteroid_bodyBitmap, 16, 16, TFT_WHITE, TFT_BLACK);
}

void drawShot(TFT_eSPI &tft, int x, int y) {
  tft.drawBitmap(x, y, shotBitmap, 8, 3, TFT_WHITE, TFT_BLACK);
}

void drawTimer(TFT_eSPI &tft, int game_time){
  tft.setCursor(20, 20); // Set cursor to top-left corner
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(1);
  tft.print("Time: ");
  tft.print(game_time / 1000); // Convert milliseconds to seconds
}

void drawHeart(TFT_eSPI &tft, int heart_count){
  // tft.drawBitmap(tft.width()-35, 15, heart_emptyBitmap, 16, 14, TFT_WHITE, TFT_BLACK);//prawe
  // tft.drawBitmap(tft.width()-56, 15, heart_emptyBitmap, 16, 14, TFT_WHITE, TFT_BLACK);//srodkowe
  // tft.drawBitmap(tft.width()-77, 15, heart_emptyBitmap, 16, 14, TFT_WHITE, TFT_BLACK);//lewe
  
  
  // tft.drawBitmap(tft.width()-35, 15, heart_filledBitmap, 16, 14, TFT_WHITE, TFT_BLACK);//prawe
  // tft.drawBitmap(tft.width()-56, 15, heart_filledBitmap, 16, 14, TFT_WHITE, TFT_BLACK);//srodkowe
  // tft.drawBitmap(tft.width()-77, 15, heart_filledBitmap, 16, 14, TFT_WHITE, TFT_BLACK);//lewe

  switch(heart_count){
    case 1: //1/3
      tft.drawBitmap(tft.width()-35, 15, heart_emptyBitmap, 16, 14, TFT_WHITE, TFT_BLACK);//right
      tft.drawBitmap(tft.width()-56, 15, heart_emptyBitmap, 16, 14, TFT_WHITE, TFT_BLACK);//center
      tft.drawBitmap(tft.width()-77, 15, heart_filledBitmap, 16, 14, TFT_WHITE, TFT_BLACK);//left (filled)
      break;
    case 2: //2/3
      tft.drawBitmap(tft.width()-35, 15, heart_emptyBitmap, 16, 14, TFT_WHITE, TFT_BLACK);//right
      tft.drawBitmap(tft.width()-56, 15, heart_filledBitmap, 16, 14, TFT_WHITE, TFT_BLACK);//center (filled)
      tft.drawBitmap(tft.width()-77, 15, heart_filledBitmap, 16, 14, TFT_WHITE, TFT_BLACK);//left (filled)
      break;
    case 3: //3/3
      tft.drawBitmap(tft.width()-35, 15, heart_filledBitmap, 16, 14, TFT_WHITE, TFT_BLACK);//right (filled)
      tft.drawBitmap(tft.width()-56, 15, heart_filledBitmap, 16, 14, TFT_WHITE, TFT_BLACK);//center (filled)
      tft.drawBitmap(tft.width()-77, 15, heart_filledBitmap, 16, 14, TFT_WHITE, TFT_BLACK);//left (filled)
      break;
    default:
      tft.drawBitmap(tft.width()-35, 15, heart_emptyBitmap, 16, 14, TFT_WHITE, TFT_BLACK);//right
      tft.drawBitmap(tft.width()-56, 15, heart_emptyBitmap, 16, 14, TFT_WHITE, TFT_BLACK);//center
      tft.drawBitmap(tft.width()-77, 15, heart_emptyBitmap, 16, 14, TFT_WHITE, TFT_BLACK);//left
  }
}