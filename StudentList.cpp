#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/*Name: Austin Holst
 *Date: 10/18/17
 *Code: Student List - You can add students, remove them, list all of the students
 *      and quit the program
 */

//Strut for student
struct Student {
  char fname[80];
  char lname[80];
  int id;
  float gpa;
};

//Initializing methods
void add(vector<Student*> &vect);
void remove(vector<Student*> &vect);
void print(vector<Student*> &vect);

//Main method
int main() {
  
  vector<Student*> vect;
  char input[10];
  bool running = true;

  //While loop runs while the user hasn't quit yet
  while (running == true) {
    cout << "Do you want to add, delete, print, or quit" << endl;
    cin.getline(input, 10);
    //if they select add
    if(strcmp(input, "add") == 0) {
      add(vect);
    }
    //if they select delete
    else if(strcmp(input, "delete") == 0) {
      remove(vect);
    }
    //if they select print
    else if(strcmp(input, "print") == 0) {
      print(vect);
    }
    //if they select quit
    else if(strcmp(input, "quit") == 0) {
      cout << "Quitting Program" << endl;
      running = false;
    }
    //if they put an input that isn't listed above
    else {
      cout << "You can only perform these commands: add delete print quit" << endl;
    }
  }
  return 0;
}

//Add function
void add(vector<Student*> &vect) {
  //creates new student that points to the struct of students
  Student* student  = new Student;

  cout << "Enter the first name of the student" << endl;
  cin >> student->fname;
  cin.ignore(10, '\n');
  cout << "Enter the last name of the student" << endl;
  cin >> student->lname;
  cin.ignore(10, '\n');
  cout << "Enter the ID of the student" << endl;
  cin >> student->id;
  cin.ignore(10, '\n');
  cout << "Enter the GPA of the studnet" << endl;
  cin >> student->gpa;
  cin.ignore(10, '\n');
 
  vect.push_back(student);
}

//Remove function
void remove(vector<Student*> &vect) {
  cout << "Enter a student to erase from the list" << endl;
  
  //initialize input variableds
  int number  = 0;
  cin >> number;
  cin.ignore(10, '\n');
  
  for(vector<Student*>::iterator it = vect.begin(); it != vect.end(); it++) {
    //If the index's id equals what the user put in for input
    if((*it)-> id == number) {
      //delete that spot
      delete vect[it - vect.begin()];
      //erase all the data within that student
      vect.erase(it);
      //break the loop
      break;
    }
  }
}

//Print method
void print(vector<Student*> &vect) {
  cout << "Listing all students:" << endl;
  for(vector<Student*>::iterator it = vect.begin(); it != vect.end(); it++) {
    //Print out the info at the vector's current index
    cout << (*it)-> fname << " ";
    cout << (*it)-> lname << ": ";
    cout << (*it)-> id << ", ";
    cout << (*it)-> gpa << endl;
  }
}
