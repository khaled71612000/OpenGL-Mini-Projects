# OpenGL Mini Projects


![C++](https://img.shields.io/badge/C++-00599C?logo=c%2B%2B&logoColor=white)
![OpenGL](https://img.shields.io/badge/OpenGL-white?logo=opengl&logoColor=black)
![License](https://img.shields.io/badge/license-MIT-green)

**OpenGL Mini Projects** is a collection of small projects developed using OpenGL to demonstrate various graphical concepts and techniques. This repository includes examples of color wheels, line drawing, Mandelbrot sets, maze generation, and sine waves.

## Key Components

### Color Wheel
- **ColorWheel.cpp:** Implements a color wheel to demonstrate color interpolation and rendering techniques.
![image](https://github.com/khaled71612000/OpenGL-Mini-Projects/assets/59780800/24d6ab69-a8b6-4946-a71d-ce892845e920)
![image](https://github.com/khaled71612000/OpenGL-Mini-Projects/assets/59780800/6fa10bfd-d6ed-48f2-ba6b-eaa1beaf8445)
![image](https://github.com/khaled71612000/OpenGL-Mini-Projects/assets/59780800/f8d175d8-77e2-45b2-807d-a9af482147e7)

### Line Drawer
- **LineDrawer.cpp:** Demonstrates basic line drawing using OpenGL, showcasing algorithms like Bresenham's line algorithm.
![image](https://github.com/khaled71612000/OpenGL-Mini-Projects/assets/59780800/2a6212d5-6390-4ea7-99a9-8b9412603703)
![image](https://github.com/khaled71612000/OpenGL-Mini-Projects/assets/59780800/583a082f-da24-4c04-9b0c-05e872c00843)

### Mandelbrot
- **Mandelbrot.cpp:** Generates and visualizes the Mandelbrot set using iterative algorithms.
![image](https://github.com/khaled71612000/OpenGL-Mini-Projects/assets/59780800/23160f65-6750-40c5-b80f-87d5e6253ae6)
![image](https://github.com/khaled71612000/OpenGL-Mini-Projects/assets/59780800/adf23f48-46de-4095-ba88-64afd2291216)

### OpenGL Maze
- **Maze.cpp:** Implements a maze generation algorithm and visualizes it using OpenGL.
![image](https://github.com/khaled71612000/OpenGL-Mini-Projects/assets/59780800/3142be37-a219-4ccc-a025-97ce1492bb80)

### OpenGL Sine Wave
- **SineWave.cpp:** Visualizes sine waves, demonstrating the use of trigonometric functions in graphical applications.
![image](https://github.com/khaled71612000/OpenGL-Mini-Projects/assets/59780800/c66fee5e-e7cd-4356-91da-66d2ad86570b)
![image](https://github.com/khaled71612000/OpenGL-Mini-Projects/assets/59780800/9a360d7a-de05-47e5-b153-36c12b39335d)

## Features

- **Graphical Demonstrations:** Showcases various graphical techniques using OpenGL.
- **Educational Examples:** Provides practical examples for learning OpenGL and computer graphics.
- **Diverse Topics:** Covers a range of topics from color interpolation to fractal generation.

This project serves as a valuable resource for learning and experimenting with OpenGL and computer graphics concepts.


## Screenshots

![Screenshot 1](https://raw.githubusercontent.com/khaled71612000/OpenGL-Mini-Projects/HEAD/OpenGL Maze/OpenGLPuzzleGame/images/block.png)

![Screenshot 2](https://raw.githubusercontent.com/khaled71612000/OpenGL-Mini-Projects/HEAD/OpenGL Maze/OpenGLPuzzleGame/images/player.png)

![Screenshot 3](https://raw.githubusercontent.com/khaled71612000/OpenGL-Mini-Projects/HEAD/OpenGL Maze/OpenGLPuzzleGame/images/skybox/0001.jpg)

![Screenshot 4](https://raw.githubusercontent.com/khaled71612000/OpenGL-Mini-Projects/HEAD/OpenGL Maze/OpenGLPuzzleGame/images/skybox/0002.jpg)

![Screenshot 5](https://raw.githubusercontent.com/khaled71612000/OpenGL-Mini-Projects/HEAD/OpenGL Maze/OpenGLPuzzleGame/images/skybox/0003.jpg)


## Tech Stack

| Technology | Role |
|---|---|
| OpenGL 3.3+ | Graphics API |
| C++ | Application logic |
| GLFW | Window & input management |
| GLAD | OpenGL function loader |
| GLM | Math library (vectors, matrices) |


## Getting Started

### Prerequisites
- C++ compiler, CMake, GLFW, GLAD, GLM

```bash
git clone https://github.com/khaled71612000/OpenGL-Mini-Projects.git
cd OpenGL-Mini-Projects
mkdir build && cd build
cmake .. && cmake --build .
./output
```
