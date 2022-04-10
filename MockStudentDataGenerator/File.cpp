#pragma once
#include "File.h"

tuple<bool, string, student_arr> File::readFile(const string& file_path)
{
    bool isRead = false;
    string message = "";
    student_arr sarr;
    fstream f;

    bool gpaValid = true;
    bool phoneValid = true;
    bool emailValid = true;
    bool dobValid = true;

    try
    {
        f.open(file_path, ios::in);
        isRead = true;
        message = "Successfully open file " + file_path + " for reading a range of students!";
    }
    catch (exception ex)
    {
        message = ex.what();
    }

    if (isRead)
    {
        int iLine = 1;
        Student X;
        string line = "";
        while (!f.eof())
        {
            getline(f, line);
            if (line == "") break;
            size_t index = line.find('-');
            X.setId(line.substr(9, index - 10));
            X.setFullname(line.substr(index + 2));

            iLine++;

            getline(f, line);
            ltrim(line);

            if (regex_match(line.substr(4, line.find(',') - 4), regex("^[\\d]+\\.[\\d]{1,2}$")))
                X.setGpa(stof(line.substr(4, line.find(',') - 4)));
            else
            {
                message = "Error format on GPA on line " + to_string(iLine); isRead = false;
                break;
            }

            if (regex_match(line.substr(line.find("Telephone=") + 10), regex("^0[\\d]{3}(-[\\d]{3}){2}")))
                X.setPhone(line.substr(line.find("Telephone=") + 10));
            else
            {
                message = "Error format on Phone on line " + to_string(iLine); isRead = false;
                break;
            }

            iLine++;

            getline(f, line);
            ltrim(line);
            if (regex_match(line.substr(6), regex("^[\\w-\\.]+@([\\w-]+\\.)+[\\w-]{2,4}$")))
                X.setEmail(line.substr(6));
            else
            {
                message = "Error format on Email on line " + to_string(iLine); isRead = false;
                break;
            }

            iLine++;

            getline(f, line);
            ltrim(line);
            if (regex_match(line.substr(4), regex("^([\\d]{2}\\/){2}[\\d]{4}")))
                X.setDob(line.substr(4));
            else
            {
                message = "Error format on DOB on line " + to_string(iLine); isRead = false;
                break;
            }

            getline(f, line);
            ltrim(line);
            X.setAddress(line.substr(8));

            iLine++;

            sarr.push_back(X);
        }
    }

    f.close();

    return make_tuple(isRead, message, sarr);
}

tuple<bool, string> File::writeFile(const string& file_path, const Rand_Student& Students)
{
    bool isRead = false;
    string message = "";
    fstream f;
    try
    {
        f.open(file_path, ios::out);
        isRead = true;
        message = "Successfully open file " + file_path + " for writing a range of students!";
    }
    catch (exception ex)
    {
        message = ex.what();
    }

    if (isRead)
    {
        for (auto& x : Students.getArr())
        {
            f << "Student: " << x.getId() << " - " << x.getFullname() << endl;
            f << "    GPA=" << x.getGpa() << ", Telephone=" << x.getPhone() << endl;
            f << "    Email=" << x.getEmail() << endl;
            f << "    DOB=" << x.getDob() << endl;
            f << "    Address=" << x.getAddress() << endl;
        }

    }

    f.close();

    return make_tuple(isRead, message);
}

void File::wRakingFile(const string& file_path, const Rand_Student& Students)
{
    ofstream f(file_path);
    if (f.fail()) return;
    f << "ID,FULL NAME,GPA,RANKED" << endl;
    double GPA = 0.0;
    int ranked = 0;

    for (auto& x : Students.getArr())
    {
        stringstream s;
        s << fixed << setprecision(2) << x.getGpa();
        s >> GPA;
        f << (x.getId() + "," + x.getFullname() + "," + to_string(GPA) + ",#" + to_string(++ranked)) << endl;
    }

    f.close();
}