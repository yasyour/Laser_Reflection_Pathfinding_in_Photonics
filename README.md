# Laser_Reflection_Pathfinding_in_Photonics

A C++ program that simulates and visualizes a laser beam's path as it reflects inside a rectangular grid.

## Overview
It can be challenging to kee track of a laser's trajectory in real life, following its path after multiple reflections gets confusing, and a thin beam can be nearly invisible outside a controlled setup too. This program models that behavior, it traces a laser's path inside a four sided grid, reflecting off each edge according to the law of reflection (angle of incidence = angle of reflection), and can check whether the beam reaches a target point the user sets.

## How it works
- Inputs: grid width, grid length, maximum number of bounces, launch angle, starting edge, and target coordinates
- Outputs: success/failure in reaching the target, launch position, number of bounces, and a saved output file of the laser's path

The simulation calculates the distance to the nearest boundary based on the beam's direction, moves the beam there, marks the path, and reflects the direction, repeating until the target is hit or the maximum bounce count is reached.

## How to run
Compile and run the program, then enter the grid dimensions, launch edge, launch angle, maximum bounces, and target coordinates when prompted.

## Example
Grid: 20 × 79, starting edge: left, max bounces: 10, launch angle: 40°. 
The program traces the beam's path and displays it on screen.

## Documentation
Full write-up with test cases and algorithm design:
[Laser_Reflection_Pathfinding_in_Photonics_Report.docx.pdf](https://github.com/user-attachments/files/32326329/Laser_Reflection_Pathfinding_in_Photonics_Report.docx.pdf)
