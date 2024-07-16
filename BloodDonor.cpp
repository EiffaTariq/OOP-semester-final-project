#include "BloodDonor.h"

// Constructor
BloodDonor::BloodDonor(const std::string& name, int age, const std::string& gender, const std::string& bloodType, bool hasDisease, bool isPatient)
    : Person(name, age, gender, bloodType), hasDisease(hasDisease), isPatient(isPatient) {}

// Destructor
BloodDonor::~BloodDonor() {}

// Accessor methods
bool BloodDonor::getHasDisease() const {
    return hasDisease;
}

bool BloodDonor::getIsPatient() const {
    return isPatient;
}

// Mutator methods
void BloodDonor::setHasDisease(bool hasDisease) {
    this->hasDisease = hasDisease;
}

void BloodDonor::setIsPatient(bool isPatient) {
    this->isPatient = isPatient;
}

// Check compatibility
bool BloodDonor::isCompatible(const Person& patient) const {
    if (bloodType != patient.getBloodType()) {
        return false;
    }
    if (hasDisease || isPatient) {
        return false;
    }
    return true;
}

// Display method
void BloodDonor::display() const {
    Person::display();
    std::cout << "Has Disease: " << (hasDisease ? "Yes" : "No") << "\nIs Patient: " << (isPatient ? "Yes" : "No") << std::endl;
}
