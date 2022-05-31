#pragma once
#include "degree.h"
#include <iostream>
#include <array>
#include <string>

class Student {
	
	public:
		/*Student Object Constructor/Destructor*/

		Student(std::string studentID, std::string firstName, std::string lastName, 
		        std::string emailAddr, int age, int daysToComp[], DegreeProgram degree); 

		~Student();

		/*Getters*/

		int	getAge();
		int* getDaysToComp();
		std::string	getStudentID();
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getEmailAddr();
		DegreeProgram getDegree();

		/*Setters*/

		void setAge(int age);
		void setDaysToComp(int*);
		void setStudentID(std::string studentID);
		void setFirstName(std::string firstName);
		void setLastName(std::string LastName);
		void setEmailAddr(std::string emailAddr);
		void setDegree(DegreeProgram degree);
		
		/*Print*/

		void print();


	private:

		/*Variables*/

		int age;
		int daysToComp[3];
		std::string studentID;
		std::string firstName;
		std::string lastName;
		std::string	emailAddr;
		DegreeProgram degree;

};
