#ifndef ALPHA
#define ALPHA

#include<iostream>
#include<cstring>

using namespace std;

class Student {
public:
  Student(char* initfirstName, char* initlastName, int newId, float newGPA);//contructor for student
  char* getFirstName();//return first name
  char* getLastName();//return last name
  int getId();//return id
  float getGPA();//return GPA
  void printStudent();//print out the student

private:
  char* firstName;
  char* lastName;
  int id;
  float GPA;
};

#endif
