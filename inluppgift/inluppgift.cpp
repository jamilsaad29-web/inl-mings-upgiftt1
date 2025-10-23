//#include <iostream>       
//#include <vector>
//#include <algorithm>
//#include <limits>
//#include <cmath>
//#include <cstdlib> 
//#include <ctime>
//
//using namespace std;
//
//// Struct for measurement
//struct Measurement {
//    double value; // Holds a single measurement value
//    //string timestamp;
//};
//
//// Function declarations
//void add_measurements(vector<Measurement>& values);
//void show_all_measurements(const vector<Measurement>& values);
//void show_statistics(const vector<Measurement>& values);
//void sort_values(vector<Measurement>& values);
//void show_ascii_diagram(const vector<Measurement>& values);
//void simulate_sensor(vector<Measurement>& values);
//
//int main() {
//    vector<Measurement> values; // Vector to store all measurements
//    int choice = 0;
//
//    srand(static_cast<unsigned int>(time(NULL))); // Seed the random number generator
//
//    do {
//        // Display menu
//        cout << "\nMeasurement Program\n";
//        cout << "1. Add measurements manually\n";
//        cout << "2. Show all measurements\n";
//        cout << "3. Show statistics\n";
//        cout << "4. Sort values\n";
//        cout << "5. Show ASCII diagram\n";
//        cout << "6. Simulate sensor measurements\n";
//        cout << "7. Exit\n";
//        cout << "Your choice: ";
//
//        // Validate user input
//        while (!(cin >> choice) || choice < 1 || choice > 7) {
//            cout << "Invalid input. Enter 1–7: ";
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//        }
//
//        // Execute chosen option
//        switch (choice) {
//        case 1: add_measurements(values); break;
//        case 2: show_all_measurements(values); break;
//        case 3: show_statistics(values); break;
//        case 4: sort_values(values); break;
//        case 5: show_ascii_diagram(values); break;
//        case 6: simulate_sensor(values); break;
//        case 7: cout << "Exiting program.\n"; break;
//        }
//
//    } while (choice != 7);
//
//    return 0;
//}
//
//
//// Function to add measurements manually
//void add_measurements(vector<Measurement>& values) {
//    int amount;
//    cout << "How many values? ";
//    while (!(cin >> amount) || amount <= 0) {
//        cout << "Invalid. Enter positive number: ";
//        cin.clear();
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//    }
//
//    for (int i = 0; i < amount; i++) {
//        double v;
//        cout << "Enter value #" << (i + 1) << ": ";
//        while (!(cin >> v)) {
//            cout << "Invalid input. Enter number: ";
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//        }
//        Measurement m;
//        m.value = v;
//        values.push_back(m); // Add new measurement to vector
//    }
//}
//
//// Function to display all measurements
//void show_all_measurements(const vector<Measurement>& values) {
//    if (values.empty()) {
//        cout << "No measurements.\n";
//        return;
//    }
//    cout << "\nAll measurements:\n";
//    for (size_t i = 0; i < values.size(); i++) {
//        cout << "Value " << (i + 1) << ": " << values[i].value << "\n";
//    }
//}
//
//// Function to calculate and display statistics
//void show_statistics(const vector<Measurement>& values) {
//    if (values.empty()) {
//        cout << "No values.\n";
//        return;
//    }
//
//    double sum = 0;
//    double minVal = values[0].value;
//    double maxVal = values[0].value;
//
//    // Calculate sum, min and max
//    for (size_t i = 0; i < values.size(); i++) {
//        double val = values[i].value;
//        sum += val;
//        if (val < minVal) minVal = val;
//        if (val > maxVal) maxVal = val;
//    }
//
//    double mean = sum / values.size();
//
//    // Calculate variance
//    double variance = 0;
//    for (size_t i = 0; i < values.size(); i++)
//        variance += pow(values[i].value - mean, 2);
//    variance /= values.size();
//
//    double stdDev = sqrt(variance); // Standard deviation
//
//    cout << fixed;
//    cout.precision(2);
//    cout << "\nStatistics\n";
//    cout << "Count: " << values.size() << "\n";
//    cout << "Sum: " << sum << "\n";
//    cout << "Min: " << minVal << "\n";
//    cout << "Max: " << maxVal << "\n";
//    cout << "Mean: " << mean << "\nVariance: " << variance << "\nStd Dev: " << stdDev << "\n";
//}
//
//// Function to sort the measurements
//void sort_values(vector<Measurement>& values) {
//    if (values.empty()) {
//        cout << "No values to sort.\n";
//        return;
//    }
//
//    int order;
//    cout << "Sort order? 1=Asc, 2=Desc: ";
//    while (!(cin >> order) || (order != 1 && order != 2)) {
//        cout << "Invalid. Enter 1 or 2: ";
//        cin.clear();
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//    }
//
//    // Sort the measurements in ascending or descending order
//    if (order == 1)
//        sort(values.begin(), values.end(), [](const Measurement& a, const Measurement& b) { return a.value < b.value; });
//    else
//        sort(values.begin(), values.end(), [](const Measurement& a, const Measurement& b) { return a.value > b.value; });
//
//    cout << "Values sorted.\n";
//}
//
//// Function to display ASCII diagram of measurements
//void show_ascii_diagram(const vector<Measurement>& values) {
//    if (values.empty()) {
//        cout << "No values to visualize.\n";
//        return;
//    }
//
//    double minVal = values[0].value;
//    double maxVal = values[0].value;
//
//    // Find min and max
//    for (size_t i = 0; i < values.size(); i++) {
//        if (values[i].value < minVal) minVal = values[i].value;
//        if (values[i].value > maxVal) maxVal = values[i].value;
//    }
//
//    double range = maxVal - minVal;
//    if (range == 0) range = 1; // Avoid division by zero
//
//    cout << "\nASCII Diagram:\n";
//    for (size_t i = 0; i < values.size(); i++) {
//        int bars = (int)((values[i].value - minVal) / range * 30); // Scale to 30 characters
//        cout << values[i].value << " | ";
//        for (int j = 0; j < bars; j++) cout << '*';
//        cout << "\n";
//    }
//}
//
//// Function to simulate random sensor measurements
//void simulate_sensor(vector<Measurement>& values) {
//    int amount;
//    cout << "How many sensor values to simulate? ";
//    while (!(cin >> amount) || amount <= 0) {
//        cout << "Invalid. Enter positive number: ";
//        cin.clear();
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//    }
//
//    // Generate random values between 20–30
//    for (int i = 0; i < amount; i++) {
//        double v = 20.0 + ((double)rand() / RAND_MAX) * 10.0;
//        Measurement m;
//        m.value = v;
//        values.push_back(m);
//    }
//
//    cout << amount << " simulated sensor values added.\n";
//}
