#include<iostream>
#include<string>
#include "Patient.h"
using namespace std;

Patient::Patient(const string& name, int age, const string& gender, const string& bloodType,const string& patientID, const string& illness, const string& hospitalName)
: Person(name, age, gender, bloodType), patientID(patientID), illness(illness), hospitalName(hospitalName) {}

Patient::~Patient() {}

string Patient::getPatientID() const 
{
    return patientID;
}

string Patient::getIllness() const
{
    return illness;
}

string Patient::getHospitalName() const
{
    return hospitalName;
}

void Patient::setPatientID(const string& patientID)
{
    this->patientID = patientID;
}

void Patient::setIllness(const string& illness) 
{
    this->illness = illness;
}

void Patient::setHospitalName(const string& hospitalName) 
{
    this->hospitalName = hospitalName;
}

void Patient::display() const 
{
    Person::display();
    cout << "Patient ID: " << patientID << "\nIllness: " << illness << "\nHospital Name: " << hospitalName << endl;
}