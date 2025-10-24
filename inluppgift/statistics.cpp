#include "Statistics.h"    // Header med klassdefinition
#include <iostream>        // Standard input/output
#include <algorithm>       // Sortering av mätvärden
#include <cmath>           // Matematiska funktioner, t.ex. sqrt
#include <cstdlib>         // Slumpfunktioner rand() och srand()
#include <ctime>           // Tid för timestamp och slumpgenerering

Statistics::Statistics() {}

// Lägger till en mätning
void Statistics::addMeasurement(double value) {
    Measurement m(value);
    measurements.push_back(m);
}

// Lägger till flera mätningar via användarinput
void Statistics::addMeasurements() {
    int count = getCount();
    for (int i = 0; i < count; i++) {
        std::cout << "Enter value " << (i + 1) << ": ";
        double value = getNumber();
        addMeasurement(value);
    }
}

// Visar alla mätningar med timestamps
void Statistics::showAllMeasurements() {
    if (measurements.empty()) {
        std::cout << "No measurements.\n";
        return;
    }

    std::cout << "\nAll measurements:\n";
    for (int i = 0; i < measurements.size(); i++) {
        std::cout << "Value " << (i + 1) << ": " << measurements[i].getValue()
            << " (Time: " << measurements[i].getTimestamp() << ")\n";
    }
}

// Beräknar och visar statistik
void Statistics::showStatistics() {
    if (measurements.empty()) {
        std::cout << "No measurements.\n";
        return;
    }

    double sum = 0;
    double min = measurements[0].getValue();
    double max = measurements[0].getValue();

    for (int i = 0; i < measurements.size(); i++) {
        double val = measurements[i].getValue();
        sum += val;
        if (val < min) min = val;
        if (val > max) max = val;
    }

    double mean = sum / measurements.size();
    double variance = 0;
    for (int i = 0; i < measurements.size(); i++) {
        double diff = measurements[i].getValue() - mean;
        variance += diff * diff;
    }
    variance /= measurements.size();
    double stdDev = sqrt(variance);

    std::cout << "\nStatistics:\n";
    std::cout << "Count: " << measurements.size() << "\n";
    std::cout << "Sum: " << sum << "\n";
    std::cout << "Min: " << min << "\n";
    std::cout << "Max: " << max << "\n";
    std::cout << "Mean: " << mean << "\n";
    std::cout << "Variance: " << variance << "\n";
    std::cout << "Std Dev: " << stdDev << "\n";
}

// Sorterar mätningar och visar dem direkt
void Statistics::sortMeasurements() {
    if (measurements.empty()) {
        std::cout << "No measurements to sort.\n";
        return;
    }

    std::cout << "Sort order? 1=Asc, 2=Desc: ";
    int order = getChoice();

    if (order == 1) {
        std::sort(measurements.begin(), measurements.end(),
            [](const Measurement& a, const Measurement& b) { return a.getValue() < b.getValue(); });
        std::cout << "Sorted ascending.\n";
    }
    else if (order == 2) {
        std::sort(measurements.begin(), measurements.end(),
            [](const Measurement& a, const Measurement& b) { return a.getValue() > b.getValue(); });
        std::cout << "Sorted descending.\n";
    }
    else {
        std::cout << "Invalid choice.\n";
        return;
    }

    showAllMeasurements(); // Visa sorterad lista direkt
}

// Visar stapeldiagram
void Statistics::showBarChart() {
    if (measurements.empty()) {
        std::cout << "No measurements.\n";
        return;
    }

    double minVal = measurements[0].getValue();
    double maxVal = measurements[0].getValue();

    for (int i = 0; i < measurements.size(); i++) {
        if (measurements[i].getValue() < minVal) minVal = measurements[i].getValue();
        if (measurements[i].getValue() > maxVal) maxVal = measurements[i].getValue();
    }

    double range = maxVal - minVal;
    if (range == 0) range = 1;

    std::cout << "\nBar Chart:\n";
    for (int i = 0; i < measurements.size(); i++) {
        int bars = (int)((measurements[i].getValue() - minVal) / range * 30);
        std::cout << measurements[i].getValue() << " |";
        for (int j = 0; j < bars; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

// Genererar slumpmässiga mätvärden
void Statistics::generateRandomData() {
    int count = getCount();
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        double value = 20.0 + ((double)rand() / RAND_MAX) * 10.0;
        addMeasurement(value);
    }
    std::cout << "Generated " << count << " random values.\n";
}

// Huvudprogramloop med meny
void Statistics::runProgram() {
    int choice = 0;
    std::cout << "Measurement Program\n";
    do {
        showMenu();
        choice = getChoice();
        switch (choice) {
        case 1: addMeasurements(); break;
        case 2: showAllMeasurements(); break;
        case 3: showStatistics(); break;
        case 4: sortMeasurements(); break;
        case 5: showBarChart(); break;
        case 6: generateRandomData(); break;
        case 7: std::cout << "Goodbye!\n"; break;
        }
    } while (choice != 7);
}

// Visar huvudmeny
void Statistics::showMenu() {
    std::cout << "\n1. Add measurements\n";
    std::cout << "2. Show all measurements\n";
    std::cout << "3. Show statistics\n";
    std::cout << "4. Sort measurements\n";
    std::cout << "5. Show bar chart\n";
    std::cout << "6. Generate random data\n";
    std::cout << "7. Exit\n";
    std::cout << "Choice: ";
}

// Hämtar användarens val
int Statistics::getChoice() {
    int choice;
    std::cin >> choice;
    return choice;
}

// Hämtar ett mätvärde från användaren
double Statistics::getNumber() {
    double num;
    std::cin >> num;
    return num;
}

// Hämtar antal mätvärden från användaren
int Statistics::getCount() {
    int count;
    std::cout << "How many? ";
    std::cin >> count;
    return count;
}
