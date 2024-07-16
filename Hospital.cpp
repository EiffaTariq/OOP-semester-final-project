#include<iostream>
#include "Hospital.h"
#include<string>
using namespace std;
Hospital::Hospital() : patientCount(0), donorCount(0), patientCapacity(10), donorCapacity(10) 
{
    patients = new Patient * [patientCapacity];
    donors = new BloodDonor * [donorCapacity];
}
Hospital::~Hospital()
{
    for (int i = 0; i < patientCount; i++) 
    {
        delete patients[i];
    }
    delete[] patients;

    for (int i = 0; i < donorCount; i++) 
    {
        delete donors[i];
    }
    delete[] donors;
}

void Hospital::resizePatients()
{
    patientCapacity *= 2;
    Patient** newPatients = new Patient * [patientCapacity];
    for (int i = 0; i < patientCount; i++) 
    {
        newPatients[i] = patients[i];
    }
    delete[] patients;
    patients = newPatients;
}


void Hospital::resizeDonors() 
{
    donorCapacity *= 2;
    BloodDonor** newDonors = new BloodDonor * [donorCapacity];
    for (int i = 0; i < donorCount; i++)
    {
        newDonors[i] = donors[i];
    }
    delete[] donors;
    donors = newDonors;
}


void Hospital::addPatient(const Patient& patient)
{
    if (patientCount == patientCapacity)
    {
        patients[patientCount++] = new Patient(patient);
    }
}


void Hospital::addDonor(const BloodDonor& donor) 
{
    if (donorCount == donorCapacity) 
    {
        resizeDonors();
    }
    donors[donorCount++] = new BloodDonor(donor);
}


double Hospital::generateBill(const Patient& patient, double treatmentCost, double bloodCost, double travelCost) const 
{
    double totalCost = treatmentCost + bloodCost + travelCost;
    cout << "Bill for patient " << patient.getName() << ":\n";
    cout << "Treatment Cost: $" << treatmentCost << "\n";
    cout << "Blood Cost: $" << bloodCost << "\n";
    cout << "Travel Cost: $" << travelCost << "\n";
    cout << "Total Cost: $" << totalCost << "\n";
    return totalCost;
}


void Hospital::payDonor(const BloodDonor& donor, double amount) 
{
    cout << "Paying donor " << donor.getName() << " $" << amount << " for donating blood.\n";
}


BloodDonor* Hospital::requestDonor(const string& bloodType)
{
    for (int i = 0; i < donorCount; i++) 
    {
        if (donors[i]->isCompatible(Patient("", 0, "", bloodType,"","",""))) 
        {
            return donors[i];
        }
    }
    cout << "No compatible donor found for blood type: " << bloodType << endl;
    return nullptr;
}


void Hospital::displayPatients() const 
{
    cout << "Patients:\n";
    for (int i = 0; i < patientCount; i++) 
    {
        patients[i]->display();
        cout << endl;
    }
}


void Hospital::displayDonors() const
{
    cout << "Donors:\n";
    for (int i = 0; i < donorCount; i++)
    {
        donors[i]->display();
        cout << endl;
    }
}


int Hospital::getPatientCount() const
{
    return patientCount;
}

int Hospital::getDonorCount() const
{
    return donorCount;
}

Patient** Hospital::getPatients() const 
{
    return patients;
}

BloodDonor** Hospital::getDonors() const 
{
    return donors;
}