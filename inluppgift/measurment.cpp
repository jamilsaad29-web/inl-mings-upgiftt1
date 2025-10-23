#include "measurement.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

Measurement::Measurement() {
    value = 0.0;
}

Measurement::Measurement(double v) {
    value = v;
}

double Measurement::getValue() const {
    return value;
}

void Measurement::setValue(double v) {
    value = v;
}

void MeasurementCollection::addMeasurement(double value) {
    Measurement m(value);
    measurements.push_back(m);
}

void MeasurementCollection::showAllMeasurements() {
    if (measurements.empty()) {
        std::cout << "No measurements.\n";
        return;
    }

    std::cout << "\nAll measurements:\n";
    for (int i = 0; i < measurements.size(); i++) {
        std::cout << "Value " << (i + 1) << ": " << measurements[i].getValue() << "\n";
    }
}

void MeasurementCollection::sortAscending() {
    std::sort(measurements.begin(), measurements.end(),
        [](const Measurement& a, const Measurement& b) {
            return a.getValue() < b.getValue();
        });
}

void MeasurementCollection::sortDescending() {
    std::sort(measurements.begin(), measurements.end(),
        [](const Measurement& a, const Measurement& b) {
            return a.getValue() > b.getValue();
        });
}

void MeasurementCollection::showBarChart() {
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

void MeasurementCollection::generateRandomData(int count) {
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        double value = 20.0 + ((double)rand() / RAND_MAX) * 10.0;
        addMeasurement(value);
    }
    std::cout << "Generated " << count << " random values.\n";
}

int MeasurementCollection::getCount() {
    return measurements.size();
}

bool MeasurementCollection::isEmpty() {
    return measurements.empty();
}