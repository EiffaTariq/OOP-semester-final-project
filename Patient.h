#include<iostream>
#include "Person.h"
#ifndef PATIENT_H
#define PATIENT_H
using namespace std;
class Patient : public Person 
{
    string patientID;
    string illness;
    string hospitalName;
public:
    Patient(const string& name, int age, const string& gender, const string& bloodType,const string& patientID, const string& illness, const string& hospitalName);
    ~Patient();
    string getPatientID() const;
    string getIllness() const;
    string getHospitalName() const;
    void setPatientID(const string& patientID);
    void setIllness(const string& illness);
    void setHospitalName(const string& hospitalName);
    void display() const override;
};
#endif
