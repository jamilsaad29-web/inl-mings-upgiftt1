#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
#include "Measurement.h"
// Klass som hanterar programmets logik och statistikfunktioner
class Statistics {
private:
    std::vector<Measurement> measurements;

public:   // Endast klassen kan använda detta
    Statistics();
    void addMeasurement(double value);
    void addMeasurements();
    void showAllMeasurements();
    void showStatistics();
    void sortMeasurements();
    void showBarChart();
    void generateRandomData();
    void runProgram();

private:      // Alla kan använda dessa funktioner
    void showMenu();
    int getChoice();
    double getNumber();
    int getCount();
};

#endif
