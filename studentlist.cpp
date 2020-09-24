#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Student {
  string firstname;
  string lastname;
  int studentID;
  double GPA;
};

void print(vector<Student> & slist);
void add(vector<Student> & slist);
void del(vector<Student> & slist);

int main(){
  vector<Student> slist;
  bool exit = false;
  while (exit == false){
  cout << "Want to ADD, DELETE, or PRINT student list? If not, say EXIT. Check";
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
      break;
    }
  }
  return 0;
}
void print(vector<Student> & slist){
  for(int i = 0; i < slist.size(); i++){
    cout << slist.at(i).firstname << " " << slist.at(i).lastname << ", " << slist.at(i).studentID << ", " << fixed << setprecision(2) << slist.at(i).GPA << endl;
  }
  return;
}
void add(vector<Student> & slist){
  int k = slist.size();
  string fn;
  string ln;
  int id;
  double gpa;
  cout << "New student first name: "; cin >> fn;
  cout << "New student last name: "; cin >> ln;
  cout << "New student ID number: "; cin >> id;
  cout << "New student GPA: "; cin >> gpa;
  struct Student newstudent = {fn,ln,id,gpa};
  slist.push_back(newstudent);
  return;
}
void del(vector<Student> & slist){
  cout << "What student would you like to delete? Enter their student ID: ";
  int IDinput;
  cin >> IDinput;
  bool IDfound = false;
  for(int i = 0; i <= slist.size(); i++)
    {
      if (slist.at(i).studentID == IDinput){
        slist.erase(slist.begin()+i);
        IDfound = true;
      }
    }
  if (IDfound == false) cout << "That ID couldn't be found.";
  return;
}
