#include "Hospital.h"
#include "Patient.h"
#include "BloodDonor.h"
#include"Person.h"
#include <iostream>
#include <string>
using namespace std;

void displayMenu() 
{
    cout << "Hospital Blood Donation System\n";
    cout << "1. Add Patient\n";
    cout << "2. Add Blood Donor\n";
    cout << "3. Request Blood Donor\n";
    cout << "4. Generate Bill\n";
    cout << "5. Display Patients\n";
    cout << "6. Display Donors\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

int main() 
{
    Hospital hospital;
    int choice;
    Person p;
    while (true) 
    {
        displayMenu();
        cin >> choice;

        switch (choice) 
        {
        case 1:
        {
            string name, gender, bloodType, patientID, illness, hospitalName;
            int age;
            cout << "Enter patient name: ";
            cin >> name;
            cout << "Enter patient age: ";
            cin >> age;
            p.setAge(age);
            cout << "Enter patient gender: ";
            cin >> gender;
            p.setGender(gender);
            cout << "Enter patient blood type: ";
            cin >> bloodType;
            p.setBloodType(bloodType);
            cout << "Enter patient ID: ";
            cin >> patientID;
            cout << "Enter patient illness: ";
            cin >> illness;
            cout << "Enter hospital name: ";
            cin >> hospitalName;
            Patient patient(name, age, gender, bloodType, patientID, illness, hospitalName);
            hospital.addPatient(patient);
            break;
        }
        case 2:
        {
            string name, gender, bloodType;
            int age;
            bool hasDisease, isPatient;
            cout << "Enter donor name: ";
            cin >> name;
            cout << "Enter donor age: ";
            cin >> age;
            p.setAge(age);
            cout << "Enter donor gender: ";
            cin >> gender;
            p.setGender(gender);
            cout << "Enter donor blood type: ";
            cin >> bloodType;
            p.setBloodType(bloodType);
            cout << "Does the donor have any disease? (1 for yes, 0 for no): ";
            cin >> hasDisease;
            cout << "Is the donor also a patient? (1 for yes, 0 for no): ";
            cin >> isPatient;
            BloodDonor donor(name, age, gender, bloodType, hasDisease, isPatient);
            hospital.addDonor(donor);
            break;
        }
        case 3: 
        {
            string bloodType;
            cout << "Enter required blood type: ";
            cin >> bloodType;
            BloodDonor* donor = hospital.requestDonor(bloodType);
            if (donor != nullptr) {
                cout << "Found compatible donor: \n";
                donor->display();
            }
            break;
        }
        case 4: 
        {
            string patientID;
            double treatmentCost, bloodCost, travelCost;
            cout << "Enter patient ID: ";
            cin >> patientID;
            cout << "Enter treatment cost: ";
            cin >> treatmentCost;
            cout << "Enter blood cost: ";
            cin >> bloodCost;
            cout << "Enter travel cost: ";
            cin >> travelCost;

            for (int i = 0; i < hospital.getPatientCount(); ++i) 
            {
                if (hospital.getPatients()[i]->getPatientID() == patientID) 
                {
                    double totalBill = hospital.generateBill(*hospital.getPatients()[i], treatmentCost, bloodCost, travelCost);
                    cout << "Total bill: $" << totalBill << "\n";
                    break;
                }
            }
            break;
        }
        case 5: 
        {
            hospital.displayPatients();
            break;
        }
        case 6: 
        {
            hospital.displayDonors();
            break;
        }
        case 7: 
        {
            cout << "Exiting...\n";
            return 0;
        }
        default: 
        {
            cout << "Invalid choice. Please try again.\n";
            break;
        }
        }
    }
    return 0;
}
