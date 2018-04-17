# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

# A PID Controller project

## Installation and Prerequisites

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 


## Project introduction and purpose
In this project implemented a PID controller in C++ to maneuver the vehicle around the track!

The simulator will provided the cross track error (CTE) and the velocity (mph) in order to compute the appropriate steering angle.

Main expectations from project is compete track without going to side track.

## Rubik point discussion and methods

#### Code and Compilation
Code is stored in src [src](https://github.com/namoshri/CarND-PID-Control-Project/tree/master/src) . PID.cpp implements PID controller while main.cpp communicates with simulator also does initalization of PID.

Code is ready to build, compile without errors with cmake and make.

#### Implementation and reflection
PID controller implemented as learnt in lessons.
To triage and understand importance of each 

"P: Proportional"
"I: Intergral"
"D:Differential"

- started with configuring each with differently initially. It failed as expected and car went off the track when individual programmed. Even programming two of them were not giving expected results.

- Further, used hyperparameters mentioned in lesson to get better results. With those parameteres 
KP = 0.2, KD = 3.0, KI = 0.004 I was able to get car pass track completely. However travel wasn't smooth.

- Twiddle algorithm implemented in main.cpp. However I didn't get better output. 

- So final parameter choosen based on more and more manul tunning to get angle change smooth. I did judgemental calucation based error to cost function.

- Tried threshold and on streering between range of [-1, 1] to avoid sudden change in value and restrict consdering acceleration.

- thrrotling also updated and was able to get better speed. However, final video is without static throttle of 0.3

#### Simulation output
Here is final [video](https://www.youtube.com/watch?v=bex8PovDWsE) for successful track completion