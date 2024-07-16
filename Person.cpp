#include "Person.h"
#include <iostream>
using namespace std;
Person::Person()
{
    name = '\0';
    age = 0;
    gender = '\0';
    bloodType = '\0';
}
Person::Person(const string& name, int age, const string& gender, const string& bloodType)
    : name(name), age(age), bloodType(bloodType)
{
    //setGender(gender); 
    //setBloodType(bloodType); 
}

Person::~Person()
{

}
string Person::getName() const 
{
    return name;
}

int Person::getAge() const
{
    return age;
}

string Person::getGender() const 
{
    return gender;
}

string Person::getBloodType() const
{
    return bloodType;
}

void Person::setName(const string& name) 
{
    this->name = name;
}

void Person::setAge(int age) 
{
    this->age = age;
    while (age < 0 || age >70)
    {
        cin >> age;
    }
}

void Person::setGender(const string& gender) 
{
    string input;
    bool flag = true;
    do 
    {
        cout << "Enter gender (Male/Female/Custom): ";
        cin >> input;
        if (input == "Male" || input == "Female" || input == "Custom") 
        {
            this->gender = input;
            flag = false;
            break;
        }
        else 
        {
            cout << "Invalid input! Please enter Male, Female, or Custom." << endl;
        }
    } while (true);
}

void Person::setBloodType(const string& bloodType)
{
    string input;
    bool flag = true;
    do
    {
        cout << "Enter blood type (A+/A-/B+/B-/AB+/AB-/O+/O-): ";
        cin >> input;
        if (input == "A+" || input == "A-" || input == "B+" || input == "B-" || input == "AB+" || input == "AB-" || input == "O+" || input == "O-") 
        {
            this->bloodType = input;
            flag = false;
            break;
        }
        else 
        {
            cout << "Invalid input! Please enter a valid blood type (A+/A-/B+/B-/AB+/AB-/O+/O-)." << endl;
        }
    } while (true);
}

void Person::display() const 
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Blood Type: " << bloodType << endl;
}
