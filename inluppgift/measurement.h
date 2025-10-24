#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <vector>
#include <string>

class Measurement {
private:
    double value;
    std::string timestamp;

    std::string nowTimestamp();

public:
    Measurement();
    Measurement(double v);

    double getValue() const;
    void setValue(double v);

    const std::string& getTimestamp() const;
    void setTimestamp(const std::string& ts);
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
