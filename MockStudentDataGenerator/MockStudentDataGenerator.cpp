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

using namespace std;

//pre-declare class definitions
class Student;
class Rand_Student;
class File;

//define vector of any classes
//to call in functions
typedef vector<Student> student_arr;
typedef vector<string> info_arr;

//function to store first name string
info_arr first_name()
{
    return info_arr({ "Nguyen","Ngo","Tran","Huynh","Pham","Ho","Do","Luong","Le","Phan","Vu","Vo","Bui","Duong","Ly" });
}

//function to store middle name string
info_arr middle_name()
{
    return info_arr({ "Quang","Van","Thi","Cam","Huu","Dieu","Thoi","" });
}

//function to store last name string
info_arr last_name()
{
    return info_arr({ "Minh","Linh","Chanh","Truong","Sang","Tai","Thinh","Phuoc" });
}

//to left trim a string if left characters of string 
//contains those chars like "\t\n\v\f\r" 
string& ltrim(string& str, const string& chars = "\t\n\v\f\r ")
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

class Student
{
public: //constructor,destructor
    Student();
    Student(const string&, const string&,const double&, const string&, const string&, const string&, const string&);
    Student(const Student& S);
    ~Student() {}
public: //setter / getter
    Student& operator=(const Student& S); //opeator = defined function for class

    string getId() const; 
    void setId(const string &_id); 

    string getFullname() const;
    void setFullname(const string &);

    double getGpa() const;
    void setGpa(const double&);

    string getPhone() const;
    void setPhone(const string &);

    string getEmail() const;
    void setEmail(const string &);

    string getDob() const;
    void setDob(const string &);

    string getAddress() const;
    void setAddress(const string &);
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


Student::Student() : _id(""),_full_name(""),_gpa(0.0),_phone(""),_email(""),_dob(""),_address(""){}

Student::Student(const string &_id, const string &_full_name, const double & _gpa, const string & _phone, const string & _email, const string & _dob, const string &_address)
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

void Student::setId(const string &_id)
{
    this->_id = _id;
}

string Student::getFullname() const
{
    return _full_name;
}

void Student::setFullname(const string &_full_name)
{
    this->_full_name = _full_name;
}

double Student::getGpa() const
{
    return _gpa;
}

void Student::setGpa(const double &_gpa)
{
    this->_gpa = _gpa;
}

string Student::getPhone() const
{
    return _phone;
}

void Student::setPhone(const string & _phone)
{
    this->_phone = _phone;
}

string Student::getEmail() const
{
    return _email;
}

void Student::setEmail(const string &_email)
{
    this->_email = _email;
}

string Student::getDob() const
{
    return _dob;
}

void Student::setDob(const string &_dob)
{
    this->_dob = _dob;
}
string Student::getAddress() const
{
    return _address;
}

void Student::setAddress(const string &_address)
{
    this->_address = _address;
}

ostream& operator<<(ostream& os, const Student&S)
{
    os << "Student: " << S.getId() << " - " << S.getFullname() << endl;
    os << "    GPA=" << S.getGpa() << ", Telephone=" << S.getPhone() << endl;
    os << "    Email=" << S.getEmail() << endl;
    os << "    DOB=" << S.getDob() << endl;
    os << "    Address=" << S.getAddress() << endl;
    return os;
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

    avgPoint /=  _s.size();
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

tuple<bool,string, student_arr> File::readFile(const string& file_path)
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
             
            if(regex_match(line.substr(line.find("Telephone=") + 10),regex("^0[\\d]{3}(-[\\d]{3}){2}")))
                X.setPhone(line.substr(line.find("Telephone=") + 10));
            else
            {
                message = "Error format on Phone on line " + to_string(iLine); isRead = false;
                break;
            }

            iLine++;

            getline(f, line);
            ltrim(line);
            if(regex_match(line.substr(6),regex("^[\\w-\\.]+@([\\w-]+\\.)+[\\w-]{2,4}$")))
                X.setEmail(line.substr(6));
            else
            {
                message = "Error format on Email on line " + to_string(iLine); isRead = false;
                break;
            }

            iLine++;

            getline(f, line);
            ltrim(line);
            if(regex_match(line.substr(4),regex("^([\\d]{2}\\/){2}[\\d]{4}")))
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

tuple<bool, string> File::writeFile(const string& file_path,const Rand_Student &Students)
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
        f << (x.getId() + "," + x.getFullname() + "," + to_string(GPA) + ",#" + to_string(++ranked))<< endl;
    }
        
    f.close();
}

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
