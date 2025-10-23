#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
#include "Measurement.h"

class Statistics {
private:
    std::vector<Measurement> measurements;

public:
    Statistics();
    void addMeasurement(double value);
    void addMeasurements();
    void showAllMeasurements();
    void showStatistics();
    void sortMeasurements();
    void showBarChart();
    void generateRandomData();
    void runProgram();

private:
    void showMenu();
    int getChoice();
    double getNumber();
    int getCount();
};

#endif