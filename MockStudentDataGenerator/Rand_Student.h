#pragma once
#ifndef _H_R_STUDENT_H
//define vector of string class
//to call in functions
#define _H_R_STUDENT_H
#include "Student.h"
typedef vector<string> info_arr;
typedef vector<Student> student_arr;

//function to store first name string
static info_arr first_name()
{
    return info_arr({ "Nguyen","Ngo","Tran","Huynh","Pham","Ho","Do","Luong","Le","Phan","Vu","Vo","Bui","Duong","Ly" });
}

//function to store middle name string
static info_arr middle_name()
{
    return info_arr({ "Quang","Van","Thi","Cam","Huu","Dieu","Thoi","" });
}

//function to store last name string
static info_arr last_name()
{
    return info_arr({ "Minh","Linh","Chanh","Truong","Sang","Tai","Thinh","Phuoc" });
}

//class for generating randomly students
class Rand_Student
{
public: //constructor, destructor
    Rand_Student();
    Rand_Student(const student_arr&);
    Rand_Student(const Rand_Student&);
    ~Rand_Student() {}
public: //setter / getter
    Rand_Student& operator=(const Rand_Student&); //operator = function 
    Rand_Student& operator+=(const Rand_Student&);//operator += function
    student_arr getArr() const;
    void setArr(const student_arr&);
public: //random of segments in a student's infor
    int rand_num(int, int); //random a number from min to max
    void rand_student_info(); //random student infor
    void rand_id_phone(size_t, Student&); //based on number inputed, it would  be
                                         //either random an id or random a phone series
    void rand_name_set_email(Student&); //random student's name, then convert these 
                                       //characters into email format
    void rand_gpa(Student&); //random a student's GPA which in range [0.0,10.0]
    void rand_dob(Student&); //random birthdate
    void rand_address(Student&); //random address
public:
    friend ostream& operator<<(ostream&, const Rand_Student&); //print out all students in current vector
public:
    static double avgGpa(const student_arr&); //calculate the average GPA of all students
    void avgPrint(double); //then, print out students having greater GPA than average one
    void sortStudent(); //sort students on their own GPA DESCENDING -> a GPA ranking list of students
private:
    student_arr _s; //a vector of students called _s
};
#endif // !_H_R_STUDENT_H


