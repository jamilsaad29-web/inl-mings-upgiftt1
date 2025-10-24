#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <vector>
#include <string>

class Measurement {
private:
    double value;              
    std::string timestamp;     // Tidpunkt d� v�rdet registrerades

    std::string nowTimestamp(); // Returnerar aktuell tid som string

public:
    Measurement();              
    Measurement(double v);      // Skapar en m�tning med angivet v�rde

    double getValue() const;   
    void setValue(double v);    // S�tter v�rdet och uppdaterar timestamp

    const std::string& getTimestamp() const; // Returnerar timestamp
    void setTimestamp(const std::string& ts); 
};

// Samling av m�tv�rden
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
