#include <iostream>
using namespace std;


// ----------- Non-OOP C++ Feature -----------
// Inline function (C++ concept, not OOP)
inline string availabilityStatus(bool available) {
    return available ? "Available" : "Rented";
}

// ----------- Base Class (Abstraction) -----------
class Vehicle {
protected:
    int vehicleId;
    string brand;

public:
    void inputVehicle() {
        cout << "Enter Vehicle ID: ";
        cin >> vehicleId;
        cout << "Enter Brand Name: ";
        cin >> brand;
    }

    int getVehicleId() {
        return vehicleId;
    }

    virtual void display() = 0;
};

// ----------- First Inheritance -----------
class Car : public Vehicle {
protected:
    string model;
    float rentPerDay;

public:
    void inputCar() {
        inputVehicle();
        cout << "Enter Model Name: ";
        cin >> model;
        cout << "Enter Rent Per Day: ";
        cin >> rentPerDay;
    }

    virtual void display() {
        cout << "\nVehicle ID: " << vehicleId;
        cout << "\nBrand: " << brand;
        cout << "\nModel: " << model;
        cout << "\nRent Per Day: Rs." << rentPerDay;
    }
};




// ----------- Second Inheritance (Multilevel) -----------
class RentalCar : public Car {
private:
    bool isAvailable;

public:
    RentalCar() {
        isAvailable = true;
    }

    void inputRentalCar() {
        inputCar();
        isAvailable = true;
    }

    void rentCar() {
        if (isAvailable) {
            isAvailable = false;
            cout << "\nCar rented successfully!";
        } else {
            cout << "\nCar is already rented!";
        }
    }

    void returnCar() {
        if (!isAvailable) {
            isAvailable = true;
            cout << "\nCar returned successfully!";
        } else {
            cout << "\nCar was not rented!";
        }
    }

    void display() {
        Car::display();
        cout << "\nStatus: " << availabilityStatus(isAvailable);
        cout << "\n-----------------------------";
    }
};

int main() {
    RentalCar cars[50];
    int choice, count = 0, id;
    bool found;

    do {
        cout << "\n===== Car Rental System =====";
        cout << "\n1. Add Car Details";
        cout << "\n2. Rent a Car";
        cout << "\n3. Return a Car";
        cout << "\n4. Display All Cars";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {




 case 1:
            cars[count].inputRentalCar();
            count++;
            break;

        case 2:
            cout << "Enter Vehicle ID to Rent: ";
            cin >> id;
            found = false;
            for (int i = 0; i < count; i++) {
                if (cars[i].getVehicleId() == id) {
                    cars[i].rentCar();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "\nCar not found!";
            break;

        case 3:
            cout << "Enter Vehicle ID to Return: ";
            cin >> id;
            found = false;
            for (int i = 0; i < count; i++) {
                if (cars[i].getVehicleId() == id) {
                    cars[i].returnCar();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "\nCar not found!";
            break;

        case 4:
            if (count == 0) {
                cout << "\nNo car records available!";
            } else {
                for (int i = 0; i < count; i++) {
                    cars[i].display();
                }
            }
            break;

        case 5:
            cout << "Exiting program...";
            break;

        default:
            cout << "\nInvalid Choice!";
        }

    } while (choice != 5);

    return 0;
}
