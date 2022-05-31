#pragma once
#include "roster.h"
#include <iomanip>


/*Print Personal Header*/

void PrintHeader() {
    std::cout << std::setfill('*') << std::setw(51);
    std::cout << "*" << std::endl;
    std::cout << "* Scripting and Programming - Applications - C867 *" << std::endl;
    std::cout << std::setfill('*') << std::setw(51) << "*" << std::endl;
    std::cout << std::left << std::setfill(' ') << std::setw(50);
    std::cout << "*             Language:   C++" << "*" << std::endl;
    std::cout << std::left << std::setfill(' ') << std::setw(50);
    std::cout << "*             Student ID: #001378298" << "*" << std::endl;
    std::cout << std::left << std::setfill(' ') << std::setw(50);
    std::cout << "*             Student:    Dwight Hickel" << "*" << std::endl;
    std::cout << std::setfill('*') << std::setw(51) << "*" << std::endl;
}


/*Provided studentData Table*/

const std::string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Dwight,Hickel,dhickel@wgu.edu,29,42,40,11,SOFTWARE"
};


/*Main*/

int main() {

    PrintHeader();
    std::cout << std::endl << std::endl;


    /*Add students to classRoster*/

    Roster classRoster;

    for (int i = 0; i < 5; ++i) {

        classRoster.parse(studentData[i]);
    }
    

    /*Print roster*/

    std::cout << "--------------\n"
              << "Student Roster\n"
              << "--------------\n"
              << std::endl;

    classRoster.printAll();


    /*Print invalid emails*/

    std::cout << "\n\n--------------------\n"
              << "Invalid Emails Found\n" 
              << "--------------------\n" 
              << std::endl;

    classRoster.printInvalidEmails();


    /*Print course completion time average for students*/
    
    std::cout << "\n\n------------------------------\n"
              <<"Average Course Completion Time\n" 
              << "------------------------------\n"
              << std::endl;

    for (int i = 0; i < 5; ++i) {

        std::string tmpArr[] = {"A1","A2","A3","A4","A5"};

        classRoster.printAverageDaysInCourse(tmpArr[i]);
    }


    /*Print students in SOFTWARE degree program*/

    std::cout << "\n\n-----------------------------------\n"
              << "Students In Software Degree Program\n"
              << "-----------------------------------\n"
              << std::endl;

    classRoster.printByDegreeProgram(SOFTWARE);


    /*Remove student "A3"*/

    std::cout << "\n\n------------------\n"
              << "Remove Student: A3\n"
              << "------------------\n"
              << std::endl;

    classRoster.remove("A3");


    /*Print Updated Roster*/

    std::cout << "\n\n--------------\n"
              << "Student Roster\n"
              << "--------------\n"
              << std::endl;

    classRoster.printAll();


    /*Remove student "A3" | 2nd attempt*/

    std::cout << "\n\n------------------\n"
              << "Remove Student: A3\n"
              << "------------------\n"
              << std::endl;

    classRoster.remove("A3");
    

    /*Wait for input to close*/

    std::cout << std::endl << std::endl;

    system("PAUSE");

    return 0;
}
