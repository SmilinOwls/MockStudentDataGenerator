#pragma once
#include "File.h"

//pre-declare class definitions
class Student;
class Rand_Student;
class File;

int main(int argc, char *arcv[])
{
   //seed time
    srand((unsigned)time(0));
    
    //read all students saved from
    //"student.txt" file
    auto rFile = File::readFile("students.txt");

    //in case that file could either not be read 
    //or contain error
    if (!get<0>(rFile))
    {
        cout << get<1>(rFile);  //release the error messgae
        return -1;              //return error code -1
    }
    
    //if be possible to read, then put
    //these students' infor back
    //into a vector of Student
    auto Students = Rand_Student(get<2>(rFile));
   
    //create a new Student Vector
    //in order to store randomly-generated Students' infor
    Rand_Student Student_Vector(student_arr(0));

    //1. generate randomly a number of n in range of [5,10]
    int _num = Student_Vector.rand_num(5, 10);
    cout << "1. Generate randomly a number n in the range of [5, 10]: " <<  _num;

    //2. generate randomly n Students
    cout << "\n2. Generate randomly n Students and add to the previous vector. ";
    Student_Vector = student_arr(_num);
    Student_Vector.rand_student_info();
    
    //add the randomly vector 
    //to the previous vector which
    //stores a vector of Student 
    //read from text file by operator +=
    Students += Student_Vector;
    
    //3. overwite all students
    //saved in current vector back to
    //"student.txt" file
    auto wFile = File::writeFile("students.txt",Students);

    //in case that file could not be written
    if (!get<0>(wFile))
    {
        cout << get<1>(wFile);  //release the error messgae
        return 0;              //return error code 0
    }

    //as a result, output all data stored in the current Student vector
    cout << "\n3. Overwrite and save and the students in the current vector back to the file \"students.txt\" ";
    cout << endl << endl << Students;

    //4. print out the average GPA of all students
    double avgPoint = Rand_Student::avgGpa(Students.getArr());
    cout << "\n4. The average GPA of all students: " << avgPoint;

    //5. print out all the students having a GPA greater than the average GPA
    cout << "\n5. Print out all the students that have a GPA greater than the average GPA " << endl;
    Students.avgPrint(avgPoint);

    //6. sort Student vector DESC
    //then print out a TOP ranking student list
    //which is based on GPA of every each student
    cout << "\nBONUS: 6. A T.O.P GPA ranking list of Sudents: " << endl;
    Students.sortStudent();
    cout << Students;
    File::wRakingFile("rankings.csv", Students);

    return 1;
}
