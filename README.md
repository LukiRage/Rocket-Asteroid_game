\[banner\]
\[shields\]

# Spaceship - Rocket game

This project is the game program that runs on ESP 32 using C++ language. The main objective is to fly as long as possible in the rocket while avoiding the asteroids. The spaceship can shot asteroids if the two successfull shots are made. The timer in the top corner shows time that rocket is alive, when going into display mod the timer pauses. The display mode is when the potenciometer is set to zero and during that timer is disabled and all collisions (between spaceship, shots and asteroids) in that mode the game is presented as no-play demo.

## Components used:

The project uses components:

- ESP 32 - Espressif system on a chip microcontroller with integrated Wi-Fi and dual-mode Bluetooth (although wifi nor bluetooth is not used in this project),
- ST7789 - used to display spaceship, spaceship shoots and asteroids during the game as well as "game over" title on the center of the screen,
- 10K potenciometer - used by player to set the spaceship vertical position across the screen (this generated the need for step-calculation .. in the future rotary encode woth integrated switch should be used),
- push button - used to fire a shot from spaceship to asteroids that are rendered on screen in 2D (after two successfull shots the asteroid vanishes).

## Connection diagram:

/here will be connection diagram/
