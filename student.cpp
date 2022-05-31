#pragma once
#include "student.h"
#include "degree.h"


/*Constructor*/

Student::Student(std::string studentID, std::string firstName, std::string lastName,
                 std::string emailAddr, int age, int daysToComp[], DegreeProgram degree) {

	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddr = emailAddr;
	this->age = age;

	for (int i = 0; i < 3; ++i) {
		this->daysToComp[i] = daysToComp[i];
	}

	this->degree = degree;
}

/*Destructor*/

Student::~Student() {

}


/*Getters*/

std::string Student::getStudentID() {
	return studentID;
}

std::string Student::getFirstName() {
	return firstName;
}

std::string Student::getLastName() {
	return lastName;
}

std::string Student::getEmailAddr() {
	return emailAddr;
}

int Student::getAge() {
	return age;
}

int* Student::getDaysToComp() {
	return daysToComp;
}

DegreeProgram Student::getDegree() {
	return degree;
}


/*Setters*/

void Student::setStudentID(std::string studentID) {
	this->studentID = studentID;
}

void Student::setFirstName(std::string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(std::string lastName) {
	this->lastName = lastName;
}

void Student::setEmailAddr(std::string emailAddr) {
	this->emailAddr = emailAddr;
}

void Student::setDaysToComp(int* daysToComp) {
	for (int i = 0; i < 3; ++i) {
		this->daysToComp[i] = daysToComp[i];
	}
}

void Student::setDegree(DegreeProgram degree) {
	this->degree  = degree;
}

void Student::setAge(int age) {
	this->age = age;
}


/*Print*/

void Student::print() {

	//convert enum to string for printing

	std::string degreeStr;
	switch (getDegree()) {
		case NETWORK:
			degreeStr = "NETWORK";
			break;
		case SECURITY:
			degreeStr = "SECURITY";
			break;
		case SOFTWARE: 
			degreeStr = "SOFTWARE";
			break;
	}

	//Print student object

	std::cout << getStudentID() << "\t" << "First Name: " << getFirstName() << "\t"
		<< "Last Name: " << getLastName() << "\t" << "Age: " << getAge()  << "\t\t"
		<< "Days In Course: ";

	for (int i = 0; i < 3 ; ++i) {

		std::cout << daysToComp[i];

		if (i < 2) {
			std::cout << ", ";
		}
	}

	std::cout << "\t" << "Degree Program: " << degreeStr << std::endl;
}