#include <iostream>
#include <string>
using namespace std;

// base class for all vehicles (just has name and year)
class Vehicle {
protected:
    string model_name;
    int year;

public:
    // sets the model name and year when the object is made
    Vehicle(const string& model_name, int year)
        : model_name(model_name), year(year) {}

    // this will get overridden later but just shows basic info
    virtual void display_info() const {
        cout << "Model: " << model_name << ", Year: " << year << endl;
    }

    // virtual destructor
    virtual ~Vehicle() {}
};

// car class inherits from vehicle, adds number of doors
class Car : public Vehicle {
private:
    int number_of_doors;

public:
    // also sets number of doors along with model and year
    Car(const string& model_name, int year, int number_of_doors)
        : Vehicle(model_name, year), number_of_doors(number_of_doors) {}

    // overrides the display to include doors
    void display_info() const override {
        cout << "Car Model: " << model_name
             << ", Year: " << year
             << ", Doors: " << number_of_doors << endl;
    }
};

// motorcycle class, inherits from vehicle too, adds engine type
class Motorcycle : public Vehicle {
private:
    string engine_type;

public:
    // sets model, year, and engine type
    Motorcycle(const string& model_name, int year, const string& engine_type)
        : Vehicle(model_name, year), engine_type(engine_type) {}

    // overrides display to include engine info
    void display_info() const override {
        cout << "Motorcycle - Model: " << model_name
             << ", Year: " << year
             << ", Engine Type: " << engine_type << endl;
    }
};

// just testing everything here
int main() {
    // made a car
    Car myCar("Toyota Camry", 2022, 4);

    // made a motorcycle
    Motorcycle myBike("Yamaha MT-07", 2021, "Parallel-Twin");

    // show info for both
    myCar.display_info();
    myBike.display_info();

    return 0;
}
