# Intersection Simulation

A demonstrative project simulating a simple multi-lane, left-hand traffic intersection using modern C++, multi-threading, and SDL2 for rendering (defaulting to OpenGL under the hood). It showcases concurrency control, resource management for a shared intersection, and a straightforward 2D visualization of moving cars.

![Intersection Simulation Demo](relative/path/to/demo.gif)

## Features

- **Multi-threaded Simulation:** Each car runs on its own thread, coordinating access to the intersection via mutex locks.
- **Left-Hand Traffic Model:** Cars are placed and moved in lanes as per Japanese (left-hand) driving rules.
- **SDL2 Rendering:** Renders the simulation in real time, using hardware-accelerated graphics by default.
- **Expandable Design:** Classes and logic distributed across multiple files for ease of maintenance and extension.

## Requirements

- A C++ compiler supporting C++17 (e.g. GCC 9+, Clang 10+, or MSVC 2019+).
- [CMake](https://cmake.org/) 3.10 or higher.
- [SDL2](https://www.libsdl.org/) library installed on your system.

## Build Instructions

1. Clone this repository or download and extract the project files.
2. Open a terminal in the project's root directory.
3. Create and enter a build directory:
   ```bash
   mkdir build
   cd build
   ```
4. Run CMake to configure the project:
   ```bash
   cmake ..
   ```
   If SDL2 is not found automatically, specify the path:  
   ```bash
   cmake -DCMAKE_PREFIX_PATH=/path/to/SDL2 ..
   ```
5. Build the project:
   ```bash
   cmake --build .
   ```
6. Run the executable:
   ```bash
   ./IntersectionSimulation
   ```

## Usage

- The simulation automatically starts four cars approaching from each side of the intersection.
- Press the **Escape** key or close the window to exit.

## Project Structure

- **main.cpp**: Entry point, sets up SDL2, creates the window, initializes the intersection manager, and starts the simulation loop.
- **Car.h / Car.cpp**: Encapsulates car properties and movement logic.
- **IntersectionManager.h / IntersectionManager.cpp**: Handles concurrency, threads, and intersection locking mechanisms.

## Contributing

Pull requests and issues are welcomed. Feel free to suggest improvements, new features, or bug fixes.

## License

This project is provided under the MIT License. See [LICENSE](https://opensource.org/license/mit) for details.

---

**Author:** Dmitrii Smirnov
**Contact:** https://www.linkedin.com/in/dmitrii-smirnov-57a812187/

*Made with love for concurrency and a fascination with how intersections (and traffic jams!) can be modeled programmatically.*
