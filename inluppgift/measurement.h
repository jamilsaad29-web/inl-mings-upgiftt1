#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <vector>

class Measurement {
private:
    double value;

public:
    Measurement();
    Measurement(double v);

    double getValue() const;
    void setValue(double v);
};

class MeasurementCollection {
private:
    std::vector<Measurement> measurements;

public:
    void addMeasurement(double value);
    void showAllMeasurements();
    void sortAscending();
    void sortDescending();
    void showBarChart();
    void generateRandomData(int count);
    int getCount();
    bool isEmpty();
};

#endif
