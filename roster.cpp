#include "roster.h"
#include <regex>


/*Parser for comma delimited input strings*/

void Roster::parse(std::string rowInput) {

    std::stringstream rowStream(rowInput); 
    std::string tmpDataCtnr;

    //loop, parses each studentData string to temp array, 
    //Then creates student objects from parsed elements

    for (int i = 0; i < 9; ++i) {
    
        std::getline(rowStream, tmpDataCtnr, ',');
        
        stdDataIn[i] = tmpDataCtnr;
    }

    //Parses Degree type to enum

    if (stdDataIn[8] == "NETWORK") {
        degree = DegreeProgram::NETWORK;
    }

    else if (stdDataIn[8] == "SECURITY") {
        degree = DegreeProgram::SECURITY;
    }

    else if (stdDataIn[8] == "SOFTWARE") {
        degree = DegreeProgram::SOFTWARE;
    }

    //Calls add function with parsed data

    add(stdDataIn[0], stdDataIn[1], stdDataIn[2], stdDataIn[3], std::stoi(stdDataIn[4]), 
        std::stoi(stdDataIn[5]), std::stoi(stdDataIn[6]), std::stoi(stdDataIn[7]), degree);
      
}


/*Function for creating a student object and adding to classRosterArray*/

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddr,
                 int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,DegreeProgram degree) {
    
    int daysToComp[3] = {
        daysInCourse1, 
        daysInCourse2, 
        daysInCourse3
    };

    //Adds pointer to new student object to array

    classRosterArray[++currRosterSize] = new Student(studentID, firstName, lastName, emailAddr, age, daysToComp, degree);

}


/*Function to remove a student object from classRosterArray*/

void Roster::remove(std::string studentID) {

    //searches for studentID for removal 
    //if found move to end of array, 
    //resize useable array index

    for (int i = 0; i <= currRosterSize; ++i) {

        if (classRosterArray[i]->getStudentID() == studentID) {
            
            for (int j = i; j < currRosterSize; ++j) {

            	std::swap(classRosterArray[j], classRosterArray[j + 1]);
            }

            //resize useable array, to "soft" delete values at end of array

            --currRosterSize; 

            std::cout << "Student ID: " << studentID << " Successfully Removed" << std::endl;
            break;
        }

        //not found exception

        else if (i == currRosterSize){
            
            std::cout << "Student Id: " << studentID << " Not Found." << std::endl;

        }
    }
}


/*Print Functions*/

//loops through prints all usable array object

void Roster::printAll() {

    for (int i = 0; i <= currRosterSize; ++i) {
        
        classRosterArray[i]->print();
    }
}

//prints objects in specified degree program

void Roster::printByDegreeProgram(DegreeProgram degree) {
    
    for (int i = 0; i <= currRosterSize; ++i) {

        if (classRosterArray[i]->getDegree() == degree) {
            
            classRosterArray[i]->print();

        }
    }
}

//prints average of days to complete 3 courses

void Roster::printAverageDaysInCourse(std::string studentID) {
    
    for (int i = 0; i <= currRosterSize; ++i) {
        
        if (classRosterArray[i]->getStudentID() == studentID) {
            
            int dayTotal = 0;

            for (int j = 0; j < 3; ++j) {
                dayTotal = dayTotal + classRosterArray[i]->getDaysToComp()[j];
                
            }

            std::cout << "Student ID: " << studentID << " | " << (dayTotal / 3) << " Days" << std::endl;

        }
    }
}

//loops through classRosterArray, checks for valid emails

void Roster::printInvalidEmails() {

    std::regex validPtrn("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    std::regex wSpaceChk("\s");


    for (int i = 0; i <= currRosterSize; ++i) {

        if (std::regex_match(classRosterArray[i]->getEmailAddr(), validPtrn) != true) {

            std::cout << classRosterArray[i]->getEmailAddr() << std::endl;
        }

        if (std::regex_match(classRosterArray[i]->getEmailAddr(), wSpaceChk) == true) {

            std::cout << classRosterArray[i]->getEmailAddr() << std::endl;

        }
    }
}


/*Destructor, deletes object pointers in classRosterArray when called*/

Roster::~Roster() {

    for (int i = 0; i <= currRosterSize; ++i) {

        delete classRosterArray[i];

    }
}