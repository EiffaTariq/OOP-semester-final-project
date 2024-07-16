#ifndef BLOODDONOR_H
#define BLOODDONOR_H
#include "Person.h"
#include <string>
#include <iostream>
class BloodDonor : public Person 
{
    bool hasDisease;
    bool isPatient;

public:
    BloodDonor(const string& name, int age, const string& gender, const string& bloodType, bool hasDisease, bool isPatient);
    ~BloodDonor();
    bool getHasDisease() const;
    bool getIsPatient() const;
    void setHasDisease(bool hasDisease);
    void setIsPatient(bool isPatient);
    bool isCompatible(const Person& patient) const;
    void display() const override;
};

#endif
