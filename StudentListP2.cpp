//Arjun Vinsel
//12/19/2023
//This code takes a Node class provided by Sai Sahu and uses it to create a list of students sorted by GPA. The user can delete add print average or delete students.
#include<iostream>
#include<cstring>
#include"Node.h"
#include"Student.h"
#include<iterator>
#include<iomanip>

using namespace std;


void add(Node* &head);//Funtion prototype for add
void print(Node* next, Node* head); // Funtion prototype for print
void deleteStudent(Node* &head, Node* previous, Node* current, int id);// Funtion prototype for deleteStudent
void nodeCreator(Student* stu, Node* &head, Node* previous, Node* current);//creates the nodes
void average(Node* next, Node* head, float total, float count);//will take the average GPA of the students in the list

int main () {
  Node* head = NULL;
  bool stillActive = true;
  while(stillActive == true) {
    cout << "Please enter add print average delete or quit: " << endl;
    char input[20];
    cin >> input;
    if (strcmp(input, "add") == 0) {//When a user enters add this condition will call the add method  
    add(head);
  }
    if (strcmp(input, "print") == 0) {// When a user enters print the condition will call the print funtion
      print(head, head);
  }
    if (strcmp(input, "average") == 0) {// When a user enters average the condition will call the print funtion
      average(head, head, 0, 0);
  }

    if (strcmp(input, "delete") == 0) {// When a user enters delete the condition will call the delete funtion
      int id = 0;
      cout << "please enter in a student Id: " << endl;
      cin >> id;
      deleteStudent(head,head,head,id);
  }
    if (strcmp(input, "quit") == 0) {// When a user enters quit the loop will set still active to false and quit the program
    stillActive = false;
  }
  }

  return 0;
}

void add(Node* &head) {// This method will have a user enter in the fist name, last name, ID, and Gpa of a student, then it will add the student to the vector 
  char* firstName;
  firstName = new char[80];
  char* lastName;
  lastName = new char[80];
  int id;
  float GPA;
  cout << "Enter a first name: " << endl;
  cin >> firstName;
    cout << "Enter a last name: " << endl;
  cin >> lastName;
  cout << "Enter a ID number: " << endl;
  cin >> id;
  cout << "Enter a GPA: " << endl;
  cin >> GPA;
  Student *stu = new Student(firstName, lastName, id, GPA);
  nodeCreator(stu, head, head, head);
}


void nodeCreator(Student* stu, Node* &head, Node* previous, Node* current) {//takes the node from "add" and puts it into the list
  //Node* next = current -> getNext();
  if(current == NULL) {
     head = new Node(stu);
  }
  if(current != NULL) {
  if(current -> getStudent() -> getId() > stu -> getId() &&
     previous -> getStudent() -> getId() < stu -> getId()) {//inside
    Node* temp = new Node(stu);
    previous -> setNext(temp);
    temp -> setNext(current);
  }
  else if(current -> getNext() == NULL && current -> getStudent() -> getId() < stu -> getId() ) {//last
    Node* temp = new Node(stu);
    current -> setNext(temp);
   }
  else if(current -> getStudent() -> getId() > stu -> getId()) {//first
    Node* temp = new Node(stu);
    temp -> setNext(current);
    head = temp;
  }
  
  else {
  previous = current;
  current = current-> getNext();
  nodeCreator(stu, head, previous, current);
 }
  }
}



void print(Node* next, Node* head) {// This method will print all the students in the vector
  if(next == head) {
    cout << "Students" << endl;
  }
  if (next != NULL) {
    next->getStudent() -> printStudent();
    print(next->getNext() , head);
  }
  }


void deleteStudent (Node* &head, Node* previous, Node* current, int id) {// This method will have a user enter a name and delete student
  if(current != NULL) {
    if(current-> getStudent() -> getId() == id && current == head) {// delete the first position
      if(current-> getNext() != NULL) {//when there is a next position
	head = current -> getNext();
	  delete current;
      }
      else {//if the list only has one value
	head = NULL;
      }
    }
    else if(current-> getStudent() -> getId() == id && previous != NULL && current->getNext() != NULL) { //deleting whithin the list
      previous -> setNext(current -> getNext());
      delete current; 
    }
    else if(current-> getStudent() -> getId() == id && current->getNext() == NULL) {//deleting the last position
      previous -> setNext(NULL);
      delete current;
    }

    else {
      previous = current;
      current = current -> getNext();
      deleteStudent(head, previous, current, id);
    }
  }
}

void average(Node* next, Node* head, float total, float count) {// This method will fin the averge GPA of the students in the vector 
  if (next != NULL) {
    total += next->getStudent() -> getGPA();
    count++;
    average(next->getNext() , head, total, count);
  }
  if(next == NULL) {
    cout << "Average is: " << fixed << setprecision(2) << (total/count) << endl;
  }
  
  }



