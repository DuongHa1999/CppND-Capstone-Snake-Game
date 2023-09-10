# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## The Capstone project (Snake-Game) meets following project requirements:

### A. Introduction New Features:
* Menu
  * The Game interfeces with the player by simplified MAIN MENU. On the main menu the user is allowed to perform 4 different choices:
    1. Play: Start the new game which can be abandoned by pressing the END key.
       * Before starting the game, the player will be asked for the player name. When the game is finished the name, the score and time are saved on the disk (game_history.txt).

    2. Game Level: Choose the level of game. There are two levels: easy and difficult, also can turn on or off wall mode here.
       By default, the game is at Easy level and when score > 20, the game level will automatically increase to difficult level.
       * Easy level: There is a 30% chance for a toxic food (slow food)
       * Dificult level: There is a 20% chance for a toxic food (slow food and poison food) also have the wall around the game table.
       * Game statuses such as turning walls on/off or eating slow/poison food will be displayed on the game table.

    3. Check history of the game (sorted list of the 10 best playeres is displayed).

    4. Intruction of game.

    5. Quit the game (terminates the game without possibility for return).

  On the main menu the player can press keys 1,2,3,4 and 5. Other configuration is not allowed and suppressed.

* Pause
  * Game can be **paused/resumed** by pressing `Fn+Insert` button.

* There is a **end** option available.
  * Exit game while playing.

* There is a **wall** option available.
  * If don't like turning on and off in game levels, I have prepared a button to turn it on and off while playing.
  * Pressing the `w` key will enable/disable the wall around the game table.
  * Snake can't appear on the other side of the screen if the wall is active and this will result the death of the snake.

* Modal box added
  * When you die, a small dialog box appears and shows score and size informations. Console output is still available

* Toxic Foods
  * There is a 20% chance for a toxic food.
  * Toxic foods are unidentified until eaten , there are two type of toxic food
    * If snake eats a *poison* toxic food it will be poisoned for 3 seconds.
      Poisoned snake will go in opposite direction. For ex. pressing *UP* key will result to go *DOWN*. This effect will last for 5 seconds.
    * If snake eats a *slow* toxic food it will be slow down the speed within 10 seconds, then the speed will recover.

### B. Criterias which support the Capstone Project:

#### 1. Loops, Functions:
  * The project code is OOP with the security mechanism in order to avoid fail states
  * The project code is clearly organized into functions and classes. All reusable codes implemented as function in order to prevent copy-paste codes.

#### 2. I/O:
  * Application read and write the file: data.h class
  * Project accept user inputs during the game, these inputs are used by controlling the snake and other game features such as:
    * User Main Manu is the interactive interface with the game: menu.h class
    * Pausing/end and triggering the wall.

#### 3. Object Oriented Programming techniques:
  * The Capstone project supports OOP technique and uses its dedicated principles.
  * The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.
  * All class data members are explicitly specified as public, protected, or private.
  * The project make use of friend classes.
  * The classes uses dedicted class members to access class memebers. Class objects communicates with memebes by setters and getters.

#### 4. Memory Management
  * The project have used smart pointer.
  * The project makes use of references in function declarations. Both references and pointers used all around the project.

#### 5. Concurrency
  * The project creates a thread each time snake is poisoned/slow. This thread waits for some seconds and return back the snake's poisonous state to normal by modifying the game's private pointer variable.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
