#pragma once
#ifndef STUDENT_h
#define STUDENT_h
#include <iostream>
using namespace std;

class Student {
private:
    string fName;
    string lName;
    int MNumber;
public:
    Student();
    Student(string fn, string ln, int mn);
    string getfName() { return fName; }
    string getlName() { return lName; }
    int getMNumber() { return MNumber; }
    void setfName(string fn) { fName = fn; }
    void setlName(string ln) { lName = ln; }
    void setMNumber(int mn) { MNumber = mn; }
};

Student::Student(string fn, string ln, int mn) {
    fName = fn;
    lName = ln;
    MNumber = mn;
}

Student::Student() {
    fName = "First Name";
    lName = "Last Name";
    MNumber = 0;
}

#endif
