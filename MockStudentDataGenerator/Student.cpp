#pragma once
#include "Student.h"

Student::Student() : _id(""), _full_name(""), _gpa(0.0), _phone(""), _email(""), _dob(""), _address("") {}

Student::Student(const string& _id, const string& _full_name, const double& _gpa, const string& _phone, const string& _email, const string& _dob, const string& _address)
    : _id(_id), _full_name(_full_name), _gpa(_gpa), _phone(_phone), _email(_email), _dob(_dob), _address(_address)
{}

Student::Student(const Student& S)
{
    this->_id = S._id;
    this->_full_name = S._full_name;
    this->_gpa = S._gpa;
    this->_phone = S._phone;
    this->_email = S._email;
    this->_dob = S._dob;
    this->_address = S._address;
}

Student& Student::operator=(const Student& S)
{
    this->_id = S._id;
    this->_full_name = S._full_name;
    this->_gpa = S._gpa;
    this->_phone = S._phone;
    this->_email = S._email;
    this->_dob = S._dob;
    this->_address = S._address;
    return *this;
}

string Student::getId() const
{
    return _id;
}

void Student::setId(const string& _id)
{
    this->_id = _id;
}

string Student::getFullname() const
{
    return _full_name;
}

void Student::setFullname(const string& _full_name)
{
    this->_full_name = _full_name;
}

double Student::getGpa() const
{
    return _gpa;
}

void Student::setGpa(const double& _gpa)
{
    this->_gpa = _gpa;
}

string Student::getPhone() const
{
    return _phone;
}

void Student::setPhone(const string& _phone)
{
    this->_phone = _phone;
}

string Student::getEmail() const
{
    return _email;
}

void Student::setEmail(const string& _email)
{
    this->_email = _email;
}

string Student::getDob() const
{
    return _dob;
}

void Student::setDob(const string& _dob)
{
    this->_dob = _dob;
}
string Student::getAddress() const
{
    return _address;
}

void Student::setAddress(const string& _address)
{
    this->_address = _address;
}

ostream& operator<<(ostream& os, const Student& S)
{
    os << "Student: " << S.getId() << " - " << S.getFullname() << endl;
    os << "    GPA=" << S.getGpa() << ", Telephone=" << S.getPhone() << endl;
    os << "    Email=" << S.getEmail() << endl;
    os << "    DOB=" << S.getDob() << endl;
    os << "    Address=" << S.getAddress() << endl;
    return os;
}