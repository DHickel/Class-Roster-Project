#pragma once
#include "student.h"
#include <array>
#include <iostream>
#include <sstream>
#include <regex>


class Roster {

	public:
		
		
		/*Parse individual row data from studentData*/

		void parse(std::string rowData);


		/*Adds parsed data to student object*/

		void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, 
                                     int age, int daysToComp0, int daysToComp1, int daysToComp2, DegreeProgram degree);
		
		/*Removes a student object*/

		void remove(std::string studentID);


		/*Various print functions*/

		void printAll();
		void printAverageDaysInCourse(std::string studentID);
		void printByDegreeProgram(DegreeProgram degree);
		void printInvalidEmails();
		
	
		/*Destructor*/
		
		~Roster();
	
	


	private:
		
		/*Pointer array to student objects*/

		Student* classRosterArray[5];

		/*Variables*/

		int currRosterSize  = -1;
		int intDataIn[4];
		std::string stdDataIn[9];
		std::stringstream rowStream;
		DegreeProgram degree;

};

