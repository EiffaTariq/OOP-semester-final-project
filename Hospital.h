#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Patient.h"
#include "BloodDonor.h"
#include <string>
#include <iostream>

class Hospital 
{
private:
    Patient** patients;
    BloodDonor** donors;
    int patientCount;
    int donorCount;
    int patientCapacity;
    int donorCapacity;

    void resizePatients();
    void resizeDonors();

public:
    Hospital();
    ~Hospital();

    
    void addPatient(const Patient& patient);
    void addDonor(const BloodDonor& donor);

    
    double generateBill(const Patient& patient, double treatmentCost, double bloodCost, double travelCost) const;

    
    void payDonor(const BloodDonor& donor, double amount);

    
    BloodDonor* requestDonor(const string& bloodType);

    void displayPatients() const;
    void displayDonors() const;
    int getPatientCount() const;
    int getDonorCount() const;
    Patient** getPatients() const;
    BloodDonor** getDonors() const;
};

#endif // HOSPITAL_H
