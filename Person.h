#include <iostream>
#include<string>
#ifndef PERSON_H
#define PERSON_H
using namespace std;
class Person 
{
protected:
    string name;
    int age;
    string gender;
    string bloodType;
public:
    Person();
    Person(const string& name, int age, const string& gender, const string& bloodType);
    virtual ~Person();
    string getName() const;
    int getAge() const;
    string getGender() const;
    string getBloodType() const;
    void setName(const string& name);
    void setAge(int age);
    void setGender(const string& gender);
    void setBloodType(const string& bloodType);
    virtual void display() const;
};
#endif