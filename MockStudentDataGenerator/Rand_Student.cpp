#pragma once
#ifndef _H_RAND_STUDENT_H
#define _H_RAND_STUDENT_H

#include "Rand_Student.h"
Rand_Student::Rand_Student() {}

Rand_Student::Rand_Student(const student_arr& _s) : _s(_s) {}

Rand_Student::Rand_Student(const Rand_Student& _r)
{
    this->_s = _r._s;
}

Rand_Student& Rand_Student::operator=(const Rand_Student& Rs)
{
    this->_s = Rs._s;
    return *this;
}

Rand_Student& Rand_Student::operator+=(const Rand_Student& Rs)
{
    for (auto& x : Rs._s) this->_s.push_back(x);
    return *this;
}

student_arr Rand_Student::getArr() const
{
    return _s;
}

void Rand_Student::setArr(const student_arr& _s)
{
    this->_s = _s;
}

int Rand_Student::rand_num(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void Rand_Student::rand_id_phone(size_t length, Student& x)
{
    auto randstr = []() -> char
    {
        const char charset[] = "0123456789";
        const size_t max_index = sizeof(charset) - 1;
        return charset[rand() % max_index];
    };

    string str(length, 0);

    generate_n(str.begin(), length, randstr);
    if (length == 3) x.setId("20120" + str);
    else
    {
        str.insert(2, "-");
        str.insert(6, "-");
        x.setPhone("09" + str);
    }
}

void Rand_Student::rand_name_set_email(Student& x)
{
    info_arr fir = first_name(), mid = middle_name(), las = last_name();

    string name = "";
    string email = "";
    size_t index = 0;

    name = fir[rand() % fir.size()];
    email = tolower(name[0]);
    index = name.size();

    int mid_index = rand() % mid.size();
    if (mid_index != mid.size() - 1) name += " " + mid[mid_index];
    else
    {
        string _temp = fir[rand() % fir.size()];
        if (strncmp(_temp.c_str(), name.c_str(), sizeof(_temp))) name += " " + _temp;
    }

    email += tolower(name[index + 1]);
    index = name.size();

    name += " " + las[rand() % las.size()];
    email += tolower(name[index + 1]);

    x.setFullname(name);
    x.setEmail(email + name.substr(index + 2) + "@student.hcmus.edu.vn");
}

void Rand_Student::rand_gpa(Student& x)
{
    stringstream s;
    double scale = (double)(rand() / (double)RAND_MAX) * 10.0;
    s << fixed << setprecision(2) << scale;
    s >> scale;
    x.setGpa(scale);
}

void Rand_Student::rand_dob(Student& x)
{
    string dob;
    int day;
    string _m = "01030507081012";
    int month = 1 + rand() % 12;
    string _month = to_string(month);
    if (_month.size() < 2) _month = "0" + _month;
    if (month == 2) day = 1 + rand() % 28;
    else if (_m.find(_month) == string::npos)
    {
        day = 1 + rand() % 30;
    }
    else day = 1 + rand() % 31;
    x.setDob((day < 10 ? "0" + to_string(day) : to_string(day)) + "/" + _month + "/" + "2002");
}

void Rand_Student::rand_address(Student& x)
{

}

void Rand_Student::rand_student_info()
{
    for (size_t i = 0; i < _s.size(); i++)
    {
        rand_id_phone(3, _s[i]); //random for id
        rand_name_set_email(_s[i]); //random for name
                                    //then, set email based on auto-generated name 
        rand_gpa(_s[i]); //random for gpa
        rand_id_phone(8, _s[i]); //random for phone
        rand_dob(_s[i]); //random for dob
      //  rand_address(_s[i]); //random for address
    }
}

ostream& operator<<(ostream& os, const Rand_Student& Rs)
{
    for (auto& student : Rs.getArr()) os << student;
    return os;
}

double Rand_Student::avgGpa(const student_arr& _s)
{
    static double avgPoint = 0.0;

    for (auto& student : _s)
    {
        avgPoint += student.getGpa();
    }

    avgPoint /= _s.size();
    stringstream convert;
    convert << setprecision(3) << avgPoint;
    convert >> avgPoint;

    return avgPoint;
}

void Rand_Student::avgPrint(double avgPoint)
{
    for (auto& student : _s)
    {
        if (student.getGpa() > avgPoint)
            cout << student.getId() << " - " << student.getFullname() << ", GPA:" << student.getGpa() << endl;
    }
}

void Rand_Student::sortStudent()
{
    sort(_s.begin(), _s.end(), [](const Student& s1, const Student& s2) -> bool { return s1.getGpa() > s2.getGpa(); });
}

#endif // !_H_RAND_STUDENT_H
