# Measurement Program

A simple C++ program that helps you manage measurement data. You can add measurements, view them, calculate statistics, sort them, and generate random test data.

## What the Program Does

- Add measurements manually by typing in numbers
- View all your measurements in a list
- Calculate basic statistics (average, min, max, etc.)
- Sort measurements from smallest to largest or largest to smallest
- Show measurements as a simple bar chart made of asterisks
- Generate random test data between 20.0 and 30.0

## How to Run

### Compile the program:
```bash
make
```

### Run the program:
```bash
./measurement_program
```

### Clean up compiled files:
```bash
make clean
```

## How the Code Works

The program is split into 3 files:

### `main.cpp`
This is where the program starts. It creates a Statistics object and runs the program.

### `Measurement.h` and `Measurement.cpp`
Contains two classes:

**Measurement class:**
- Holds one measurement value
- Has simple functions to get and set the value

**MeasurementCollection class:**
- Manages a list of measurements
- Can add measurements, show them, sort them, and create bar charts

### `Statistics.h` and `Statistics.cpp`
Contains the Statistics class that:
- Stores measurements in a vector
- Calculates statistics like average, min, max, variance
- Shows a menu and handles user input
- Runs the main program loop

## Key C++ Concepts Used

- **Classes**: Each class has a specific job
- **Vectors**: To store lists of measurements
- **Loops**: For calculations and displaying data
- **Functions**: Each function does one thing
- **Switch statements**: To handle menu choices
- **Basic math**: For statistics calculations

## Example Usage

1. Run the program
2. Choose option 1 to add measurements
3. Enter how many measurements you want
4. Type in your measurement values
5. Choose option 3 to see statistics
6. Choose option 5 to see a bar chart
7. Choose option 7 to exit

The program is designed to be simple and easy to understand for someone learning C++.