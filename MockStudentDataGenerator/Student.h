#pragma once
#ifndef _H_STUDENT_H
#define _H_STUDENT_H

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <tuple>
#include <regex>
#include <map>
using namespace std;
class Student
{
public: //constructor,destructor
    Student();
    Student(const string&, const string&, const double&, const string&, const string&, const string&, const string&);
    Student(const Student& S);
    ~Student() {}
public: //setter / getter
    Student& operator=(const Student& S); //opeator = defined function for class

    string getId() const;
    void setId(const string& _id);

    string getFullname() const;
    void setFullname(const string&);

    double getGpa() const;
    void setGpa(const double&);

    string getPhone() const;
    void setPhone(const string&);

    string getEmail() const;
    void setEmail(const string&);

    string getDob() const;
    void setDob(const string&);

    string getAddress() const;
    void setAddress(const string&);
public:
    friend ostream& operator<<(ostream&, const Student&); //print out the information 
                                                         //of every each student

private:
    string _id; //identity string
    string _full_name; //full name
    double _gpa; //gpa must be from [0.0,10.0]
    string _phone; //phone be a range of 10 numbers which has begining num range of "09"  
    string _email; //email of student based on full name, end up with "@student.hcmus.edu.vn"
    string _dob; //birthday 
    string _address; //address of students at TPHCM city
};

#endif // !_H_STUDENT_H
