![Spaceship_Asteroid_game](https://github.com/RobertNeat/Rocket-Asteroid_game/assets/47086490/8cc19141-a412-444b-b38f-bc0bd03f08de)

![ESP_32](https://img.shields.io/badge/microcontroller-ESP_32-orange)
![ST7789](https://img.shields.io/badge/display-ST7789-lightblue)
![potenciometer](https://img.shields.io/badge/potenciometer-10K-green)
![button](https://img.shields.io/badge/button-push_button-white)


# Spaceship - Rocket game

This project is the game program that runs on ESP 32 using C++ language. The main objective is to fly as long as possible in the rocket while avoiding the asteroids. The spaceship can shot asteroids if the two successfull shots are made. The timer in the top corner shows time that rocket is alive, when going into display mod the timer pauses. The display mode is when the potenciometer is set to zero and during that timer is disabled and all collisions (between spaceship, shots and asteroids) in that mode the game is presented as no-play demo.

## Components used:

The project uses components:

- ESP 32 - Espressif system on a chip microcontroller with integrated Wi-Fi and dual-mode Bluetooth (although wifi nor bluetooth is not used in this project),
- ST7789 - used to display spaceship, spaceship shoots and asteroids during the game as well as "game over" title on the center of the screen,
- 10K potenciometer - used by player to set the spaceship vertical position across the screen (this generated the need for step-calculation .. in the future rotary encode woth integrated switch should be used),
- push button - used to fire a shot from spaceship to asteroids that are rendered on screen in 2D (after two successfull shots the asteroid vanishes).

## Game play:

![game_play-short](https://github.com/RobertNeat/Rocket-Asteroid_game/assets/47086490/081b298e-8ea0-405f-a6bd-10a75d7b2e69)


## Connection diagram:

<!--![spaceship-asteroid_game_schematics](https://github.com/RobertNeat/Rocket-Asteroid_game/assets/47086490/e857b775-0576-4189-97ab-4fe4e82d8d64)-->
<img src="https://github.com/RobertNeat/Rocket-Asteroid_game/assets/47086490/e857b775-0576-4189-97ab-4fe4e82d8d64" width="450"/>
