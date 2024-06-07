// main.cpp
#include <TFT_eSPI.h>
#include <Graphics.h>
#include <Spaceship.h>
#include <Asteroid.h>
#include <Shot.h>

#define BUTTON_PIN 23

TFT_eSPI tft = TFT_eSPI();
const int potPin = 36;  // Potentiometer pin (other to ground)

unsigned long currentTime = 0;
unsigned int game_time = 0;
int last_loop_time = 0;
int current_loop_time = 0;

// Button shooting (press when High>>Low)
int lastState = LOW;
int currentState;

int Spaceship_life;

void setup() {
  //Serial.begin(115200); //debugging serial
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);

    pinMode(BUTTON_PIN, INPUT_PULLUP);

    initializeSpaceship(tft);
    initializeAsteroids();
    initializeShots();
    Spaceship_life = 3; // Initialize spaceship life
    drawHeart(tft, Spaceship_life); // Initial draw of hearts
}

void loop() {
  
  currentTime = millis();
  currentState = digitalRead(BUTTON_PIN);

  if (currentTime % 30 == 0) { // Base refresh speed

    

    last_loop_time = current_loop_time;
    current_loop_time = millis();
    int difference = current_loop_time - last_loop_time;

    potValue = analogRead(potPin) - 20;

    updateSpaceship(tft, potValue, difference, game_time);
    drawTimer(tft,game_time);
    drawHeart(tft, Spaceship_life);

    if (currentTime - lastSpawnTime >= spawnInterval) {
      spawnAsteroid(tft);
      lastSpawnTime = currentTime; // Update last spawn time
    }

    if (lastState == HIGH && currentState == LOW) {
      if (currentTime - lastShotTime >= shotInterval) {
        spawnShot(tft);
        lastShotTime = currentTime; // Update last shot time
      }
    }
    lastState = currentState;

    updateAsteroids(tft);
    updateShots(tft);
    checkCollision(tft);
  }
  
}