#pragma once
#ifndef _H_FILE_H
#define _H_FILE_H
#include "Student.h"
#include "Rand_Student.h"

//to left trim a string if left characters of string 
//contains those chars like "\t\n\v\f\r" 
string& ltrim(string& str, const string& chars = "\t\n\v\f\r ")
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

//Error code
//-1: the file has error on being read or format definition
// 0: the file could not be written
// 1: No error, build & run successfully 
class File
{
public:
    static tuple<bool, string, student_arr> readFile(const string&);            //read file's data of students 
    static tuple<bool, string> writeFile(const string&, const Rand_Student&);  //write to a file with a list of students 
    static void wRakingFile(const string&, const Rand_Student&);
};


#endif // !_H_FILE_H
