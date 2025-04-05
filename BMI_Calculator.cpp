#include <iostream>
class BMI_Calculator {

public:
    typedef long double dd;
    typedef long long ll;

    dd calculateBMI(dd weight , dd heightInMeters) {
        using namespace std;
        if (weight <= 0) {
          cout << "Input Error: Please enter a valid weight!" << endl;
          return -1;
        }
        if (heightInMeters <= 0) {
           cout << "Input Error: Please enter a valid height!" << endl;
           return -2;
        }
        dd bmi = weight / ((heightInMeters * heightInMeters) / 10000);
        cout << "Caculation completed!" << endl;
        return bmi;
    }

 
};

int main() {
    using namespace std;
    BMI_Calculator calc;
    cout << "Please enter Your Weight:" << endl;
    BMI_Calculator::dd weight;
    cin >> weight;
    cout << "Please enter Your Height:" << endl;
    BMI_Calculator::dd height;
    cin >> height;
    cout << "Calculating:" << endl;
    BMI_Calculator::dd bmi = calc.calculateBMI(weight , height);
    cout << "Your final BMI is: " << bmi << endl;
    return 0;
}
