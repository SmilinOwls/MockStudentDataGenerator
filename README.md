*[**On progress**] Still Update..*

<h1 align="center">MOCK STUDENT DATA GENERATOR 👋</h1>
<p>
  <img alt="Version" src="https://img.shields.io/badge/version-v1.0.0-blue.svg?cacheSeconds=2592000" />
  <a href="https://github.com/SmilinOwls/MockStudentDataGenerator#readme" target="_blank">
    <img alt="Documentation" src="https://img.shields.io/badge/documentation-yes-brightgreen.svg" />
  </a>
  <a href="https://github.com/kefranabg/readme-md-generator/graphs/commit-activity" target="_blank">
    <img alt="Maintenance" src="https://img.shields.io/badge/Maintained%3F-yes-green.svg" />
  </a>
  <a href="https://github.com/SmilinOwls/MockStudentDataGenerator/blob/master/LICENSE" target="_blank">
    <img alt="License: MIT" src="https://img.shields.io/badge/license-MIT-green" />
  </a>
  <a href="https://visualstudio.microsoft.com/downloads/">
    <img alth="IDE: Visual Studio Code 2019" src = "https://img.shields.io/badge/IDE-VS%20Code%202019-ff69b4"/>  
  </a>
  <img alt="Git Followers" src ="https://img.shields.io/github/followers/SmilinOwls?style=social"/>
</p>

> Project OOP's 01 - Detailed Instruction: [Mock Data Generator](https://tdquang7.notion.site/Project-Mock-data-generator-1-7c70a1a81b724049bd82ede839e2ff24) 

### 🏠 [Homepage](https://github.com/SmilinOwls/MockStudentDataGenerator#readme)

## ✨ Objectives
   ### Main Target 
   - Create Simple Classes (File.h, Rand_Student.h, Student.h,..)
   ### Sub Goal
   - Practice On Handling Data Stream By `tuple<classs T1,class T2,..>` (when reading & writing file **.txt**)
   - Using `rand()` Function To Generate Data Randomly (for every each student's infor)
   - Read A File In `JSON` Format (for address random generator)
   - Validate Check: Indicate the **Error Line** position in text if wrongly formatted (bonus function)
   - Sort A Vector And Save As A Ranked List In **.csv** Format (bonus function)

## Prerequisites
- Visual Studio Code 2019 or latest versions
- Build, Compile & Run on `g++ -std=c++11 [..]` or above

## Install

- Open Terminal (MacOS) or CMD Shell (Windows), then go on command line described below:
```sh
#Change your direction path to Desktop/ 
cd Desktop/
#Fork the project, clone this fork in a repo called MockStudentDataGenerator
git clone https://github.com/SmilinOwls/MockStudentDataGenerator/ MockStudentDataGenerator
#Navigate to the newly cloned repo
cd MockStudentDataGenerator/
```

## Usage
- Open file `.exe` in *Release* folder to run all functions to check wether all requirements are completely done
```sh
cd MockStudentDataGenerator/Release
open MockStudentDataGenerator.exe
```

## Run tests
- Open file *students.txt* to make a mini test on validating data with format
```sh
npm run test
```

## Author

👤 **NGO NGUYEN QUANG TU**

* Github: [@SmilinOwls](https://github.com/SmilinOwls "SmilinOwls")
* Student ID: 20120234
* Full Name: Ngô Nguyễn Quang Tú

## 📅 Working Progress
After project, we both appreciate our experience on our team-working time which we are so grateful for and proud of ourselves. We are on 200% of our ability way to have accomplished one as soon as possible. Hence, all requirements described in [Project Instruction](https://tdquang7.notion.site/Project-Mock-data-generator-1-7c70a1a81b724049bd82ede839e2ff24) are completely met.

|Basic Requirements|Done Status|
|------------------|-----------|
|Read all students saved in the file "students.txt" back into a vector of Student|Yes|
|Generate randomly a number n in the range of [5, 10]|Yes|
|Generate randomly n Students and add to the previous vector|Yes|
|Overwrite and save and the students in the current vector back to the file "students.txt"|Yes|
|Print out the average GPA of all students|Yes|
|Print out all the students that have a GPA greater than the average GPA|Yes|

## Bonus Functions
 Not only building the essential-coded function, we also add an [external lib]( https://github.com/SmilinOwls/MockStudentDataGenerator/blob/master/MockStudentDataGenerator/json.hpp "nlogmann/json.hpp") to help make a better random for [addresses](https://github.com/SmilinOwls/MockStudentDataGenerator/blob/master/MockStudentDataGenerator/address.json "address") that are written in `JSON` format. In addition, there are some bonus functions to check the wrongly-formatted line in file **students.txt** (validate GPA, telephone, email, dob) then indicate where that line is through showing a message on console with line index. If prgramm runs without no failure, based on their own GPA a <i> .csv </i> ranked list will be released demonstrating the TOP students sorted ASC with ranked order. 

## Expected Grades
|Student ID| Workload |  Fulfilled-Work Percent | Subjective Grade |
|----------|----------|-------------------------|------------------|
|20120234  |          |                         |                  |
|20120229  |          |                         |                  |

## Demo Video 

## 🤝 Contributing
Contributions, issues and feature requests are welcome! You can also take a look at the [contributing guide](https://github.com/SmilinOwls/MockStudentDataGenerator/blob/master/CONTRIBUTING.md)

## Show your support

Give a ⭐️ if this project helped you!

## 📝 License

Copyright © 2022 [TU NGO NGUYEN QUANG](https://github.com/SmilinOwls).<br />
This project is [MIT](https://github.com/SmilinOwls/MockStudentDataGenerator/blob/master/LICENSE) licensed.

***
_A ton thanks to [**kefranabg**](https://github.com/kefranabg) for helping me foster a great interest in creating a powerful [readme.md](https://github.com/SmilinOwls/MockStudentDataGenerator/blob/master/README.md) ❤️_
