#include<iostream>
#include<iomanip>
#include<cstring>
#include"Student.h"

using namespace std;

Student :: Student(char* initfirstName, char* initlastName, int newId, float newGPA) {//Contructor for student
  firstName = new char[80];
  strcpy(firstName, initfirstName);
  lastName = new char[80];
  strcpy(lastName, initlastName);
  id = newId;
  GPA = newGPA;

}

char* Student :: getFirstName() {//returns first name
  return firstName;
}

char* Student :: getLastName() {//returns last name
  return lastName;
}

int Student :: getId() {//returns id
  return id;
}

float Student :: getGPA() {//return GPA
  return GPA;
}

void Student :: printStudent() {// will print out the student
  cout << "First name is " << firstName << endl;
  cout << "Last name is " << lastName << endl;
  cout << "ID is " << id << endl;
  cout << "GPA is " << fixed << setprecision(2) << GPA << endl;


}
