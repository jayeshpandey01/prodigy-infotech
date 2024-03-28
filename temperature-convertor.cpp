#include <iostream>
using namespace std;

float feranite(float temp) {
    return (temp * 9.0 / 5.0) + 32.0; 
}

float kelvin(float num){
    return num + 273.15;
} 

int main() {
    float num;
    int choice;
    
    cout << "Enter temperature in Celsius: ";
    cin >> num;
    
    cout << "Choose conversion:" << endl;
    cout << "1. Fahrenheit" << endl;
    cout << "2. Kelvin" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Temperature in Fahrenheit: " << feranite(num) << endl;
            break;
        case 2:
            cout << "Temperature in Kelvin: " << kelvin(num) << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }
    
    return 0;
}
