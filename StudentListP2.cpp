//Arjun Vinsel
//12/19/2023
//
#include<string>
#include<iostream>
#include<cstring>
#include"Node.h"
#include"Student.h"
#include<iterator>
#include<iomanip>
#include<vector>
#include<fstream>

using namespace std;


void add(Node* ary[], int size);
void print(Node* ary[], int size);
void deleteStudent(Node* ary[], int size);
void hasher(Student* stu, Node* ary[], int size);
void arrayNuller(Node* ary[], int size);
void rehasher(Node* ary[], int size);
void randStu(int id, int size, Node* ary[], vector<char*> firstNameV,vector<char*> lastNameV);

int main () {

  int id = 400000;
  Node* ary[100];
  int size = sizeof(ary)/sizeof(ary[0]);
  arrayNuller(ary, size);
  bool stillActive = true;
  vector<char*> lastNameV;
  vector<char*> firstNameV;

  ifstream fin("Aaren.txt");
  char* temp;
  temp = new char[100];
  while(fin >> temp) {
    firstNameV.push_back(temp);
  }
  fin.close();

  ifstream fin1("Abraham.txt");
  char* temp1;
  temp1 = new char[100];
  while(fin1 >> temp1) {
    cout << temp1 << endl;
    lastNameV.push_back(temp1);
  }
  fin1.close();

  for (int i = 0; i < lastNameV.size(); i++) {
        cout << lastNameV[i];
    }

  
  while(stillActive == true) {
    cout << "Please enter add print average delete or quit: " << endl;
    char input[20];
    cin >> input;
    if (strcmp(input, "add") == 0) {//When a user enters add this condition will call the add method  
      add(ary, size);
  }
    if (strcmp(input, "print") == 0) {// When a user enters print the condition will call the print funtion
      print(ary, size);
  }


    if (strcmp(input, "delete") == 0) {// When a user enters delete the condition will call the delete funtion
      deleteStudent(ary, size);
  }
    if (strcmp(input, "quit") == 0) {// When a user enters quit the loop will set still active to false and quit the program
    stillActive = false;
  }
    if (strcmp(input, "generate") == 0) {
      randStu(id, size, ary,firstNameV,lastNameV);
    }
  }

  return 0;
}

void arrayNuller(Node* ary[], int size) {
  for(int i = 0; i < size; i++) {
    ary[i] = NULL;
  }
}

void add(Node* ary[],int size) {// This method will have a user enter in the fist name, last name, ID, and Gpa of a student, then it will add the student to the vector 
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
  hasher(stu, ary, size);
}

void hasher(Student* stu, Node* ary[],int size) {
  char* firstname;
  firstname = new char[80];
  int nameLen = 0;
  int place = 0;
  strcpy(firstname, stu-> getFirstName());
  for(int i =0; i < strlen(stu -> getFirstName()); i++) {
    nameLen += firstname[i];
    }
  place = nameLen % size;
  
  if(ary[place] == NULL) {
    ary[place] = new Node(stu);
  }

  else if(ary[place] != NULL) {
    Node* current = ary[place];
    int counter = 2;
    while(current -> getNext() != NULL) {
      current = current -> getNext();
      counter++;
    }
    if(counter != 4) {
    Node* temp = new Node(stu);
    current -> setNext(temp);
  }
    else if (counter == 4) {
      rehasher(ary, size);
      hasher(stu, ary,size);
    }
}
}





void print(Node* ary[],int size) {// This method will print all the students in the vector
  for(int i =0; i < size; i++) {
    if(ary[i] != NULL) {
      Node* current = ary[i];
      while(current != NULL) {
	current->getStudent() -> printStudent();
	current = current -> getNext();
      }
    }
  }
  }


void deleteStudent (Node* ary[], int size) {
  cout << "enter the id of the student you wish to delete" << endl;
  int id = 0;
  cin >> id;
   for(int i =0; i < size; i++) {
    if(ary[i] != NULL) {
      Node* current = ary[i];
      Node* previous = ary[i];
      Node* first = ary[i];
      while(current -> getNext() != NULL && current -> getStudent() -> getId()) {
	previous = current;
	current = current -> getNext();
      }
      if(current ->getNext() == NULL && current != first && current -> getStudent() -> getId() == id) {//last
	previous -> setNext(NULL);
	delete current;
	current = NULL;
      }
      else if(current == first && current -> getStudent() -> getId() == id) {//first
	cout << "d" << endl;
	ary[i] = NULL;
	if(current -> getNext() != NULL) {
	  ary[i] = current -> getNext();
	}
	delete current;
	current = NULL;
      }
      else if(current != previous && current-> getNext() != NULL && current -> getStudent() -> getId() == id) {
	previous -> setNext(current->getNext());
	delete current;
	current = NULL;
      }
    }
  }

}

void rehasher(Node* ary[], int size) {
  int newSize = 0;
  newSize = size*2;
  Node* temp[newSize];
  arrayNuller(temp, newSize);
  for(int i =0; i < size; i++) {
    if(ary[i] != NULL) {
      Node* current = ary[i];
      Node* first = current;
      while(current != NULL) {
	int nameLen = 0;
	int place = 0;
	char* firstname;
	firstname = new char[80];
        for(int i =0; i < strlen(current ->getStudent() -> getFirstName()); i++) {
	  nameLen += firstname[i];
	}
	place = nameLen % size;

	if(temp[place] == NULL) {
	  temp[place] = current;
	}
	else if(temp[place] != NULL) {
	  Node* currentTemp = temp[place];
	  cout << "fffffffffffffdddddddddddatgerfesfgrfgdergasdwgefrv" << endl;

	  while(currentTemp -> getNext() != NULL) {
	    cout << "1" << endl;
	    currentTemp = currentTemp -> getNext();
	  }
	  cout << "f555555555555555555555ffff" << endl;

	  currentTemp -> setNext(current);
	}
	cout << "fffff0000000000000000000000000000" << endl;

	current = current -> getNext();
	while(first -> getNext() != NULL) {
	  Node* temp = first;
	  first = first -> getNext();
	  temp ->setNext(NULL);
	}
      }
    }
  }
  ary = temp;

}

void randStu(int id, int size, Node* ary[], vector<char*> firstNameV,vector<char*> lastNameV) {
  int input;
  int counter = 0;
  srand((unsigned) time(NULL));
  cout << "How many students do you wish to make" << endl;
  cin >> input;
  while(counter < input) {
    id++;
    char* firstName;
  firstName = new char[80];
  char* lastName;
  lastName = new char[80];
    float GPA = rand() % 5;
    int first = rand() % 4946;
    int last = rand() % 150;
    firstName = firstNameV[first];
    lastName = lastNameV[last];
    Student *stu = new Student(firstName, lastName, id, GPA);
    hasher(stu, ary, size);
    GPA =0;
    first=0;
    last = 0;
    counter++;
  }
}



