#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// creating the Student struct to have the four relevant data
struct Student {
  string firstname;
  string lastname;
  int studentID;
  double GPA;
};

//introduce functions at the top because stupid C++ can't look ahead
void print(vector<Student *> & slist);
void add(vector<Student *> & slist);
void del(vector<Student *> & slist);

//main loop
int main(){
  vector<Student*> slist;
  bool exit = false;
  // loops asking what the user wants to do, if "EXIT" then it exits, else it refers to the relevant function
  while (exit == false){
  cout << "Want to ADD, DELETE, or PRINT student list? If not, say EXIT. ";
    string request;
    cin >> request;
    if (request == "PRINT") {
      print(slist);
    }
    if (request == "ADD") {
      add(slist);
    }
    if (request == "DELETE") {
      del(slist);
    }
    if (request == "EXIT") {
      exit = true;
    }
  }
  return 0;
}
//print just takes everything in slist and reads out its four stored data
void print(vector<Student*> & slist){
  for(int i = 0; i < slist.size(); i++){
    Student stud = *(slist.at(i));
    cout << stud.firstname << " " << stud.lastname << ", " << stud.studentID << ", " << fixed << setprecision(2) << stud.GPA << endl;
  }
  return;
}
//add gets the four data from cin, makes a struct for the new student, and concatenates it to the end of slist; this is why the vector is useful
void add(vector<Student*> & slist){
  string fn;
  string ln;
  int id;
  double gpa;
  cout << "New student first name: "; cin >> fn;
  cout << "New student last name: "; cin >> ln;
  cout << "New student ID number: "; cin >> id;
  cout << "New student GPA: "; cin >> gpa;
  Student newstudent = {fn,ln,id,gpa};
  Student* newstudentptr = &newstudent;
  slist.push_back(newstudentptr);
  return;
}
//del asks for an ID number, goes through every student and deletes only the first student it finds with this ID
//(otherwise the size of the list is changing while the loop loops and it is weird)
void del(vector<Student*> & slist){
  cout << "What student would you like to delete? Enter their student ID: ";
  int IDinput;
  cin >> IDinput;
  int i = 0;
  bool foundID = false;
  while((foundID == false) && (i <= slist.size()))
    {
      i++;
      Student* stud = slist.at(i);
      Student stud1 = *stud; 
      if (stud1.studentID == IDinput){
        slist.erase(slist.begin()+i);
        foundID = true;
      }
    }
  return;
}
