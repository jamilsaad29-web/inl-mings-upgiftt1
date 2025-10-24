#include "Measurement.h"   // Header för Measurement-klassen
#include <iostream>        // Standard input/output
#include <algorithm>       // Sortering och andra algoritmer
#include <cstdlib>         // Slumpfunktioner rand() och srand()
#include <ctime>           // Tidfunktioner time() och localtime
#include <sstream>         // Strängström för timestamp
#include <iomanip>         // Formatering av tid med put_time


Measurement::Measurement() : value(0.0), timestamp(nowTimestamp()) {}
Measurement::Measurement(double v) : value(v), timestamp(nowTimestamp()) {}

double Measurement::getValue() const {
    return value;
}

void Measurement::setValue(double v) {
    value = v;
    timestamp = nowTimestamp();  // updaterar tid
}

const std::string& Measurement::getTimestamp() const {
    return timestamp;
}

void Measurement::setTimestamp(const std::string& ts) {
    timestamp = ts;
}
// Returnerar aktuell tid som en string i format å-m-d-t-m-s
std::string Measurement::nowTimestamp() {
    std::time_t t = std::time(nullptr);
    std::tm localTm;
#if defined(_MSC_VER)
    localtime_s(&localTm, &t);
#else
    localtime_r(&t, &localTm);
#endif
    std::ostringstream ss;
    ss << std::put_time(&localTm, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

//  MeasurementCollection implementation 
// Lägger till ett nytt mätvärde
void MeasurementCollection::addMeasurement(double value) {
    Measurement m(value);
    measurements.push_back(m);
}
// Visar alla mätvärden med timestamp
void MeasurementCollection::showAllMeasurements() {
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
// vissar alla värden i ascending
void MeasurementCollection::sortAscending() {
    std::sort(measurements.begin(), measurements.end(),
        [](const Measurement& a, const Measurement& b) {
            return a.getValue() < b.getValue();
        });
}
// vissar alla värden i descending
void MeasurementCollection::sortDescending() {
    std::sort(measurements.begin(), measurements.end(),
        [](const Measurement& a, const Measurement& b) {
            return a.getValue() > b.getValue();
        });
}
// Visar stapeldiagram
void MeasurementCollection::showBarChart() {
    if (measurements.empty()) {                       // om det inte finns några värden
        std::cout << "No measurements.\n";
        return;
    }

    double minVal = measurements[0].getValue();
    double maxVal = measurements[0].getValue();

    for (int i = 0; i < measurements.size(); i++) {
        if (measurements[i].getValue() < minVal) minVal = measurements[i].getValue();
        if (measurements[i].getValue() > maxVal) maxVal = measurements[i].getValue();
    }
    // skillnader samt undvika null
    double range = maxVal - minVal;
    if (range == 0) range = 1;
    // // Rita staplar för varje mätvärde
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
// Genererar slumpmässiga värden
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
