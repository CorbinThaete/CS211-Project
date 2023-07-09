#include <iostream>
using namespace std;
#include "student.h"

void addCourseToStudent(student& s, int cr);
void dropCourseFromStudent(student& s, int cr);
void print(const student& s);

int main()
{
  //create a student with Kathy, Ross, f
  student s1("Kathy", "Ross", 'f');

  //Create another student with Mike, Smith, m
  student s2("Mike", "Smith", 'm');

  //creating one more student using the default constructor
  student s3;

  //add 111 to Kathy
  addCourseToStudent(s1, 111);
  cout << endl;

  //add 111 to Mike
  addCourseToStudent(s2, 111);
  //add 222 to Mike
  addCourseToStudent(s2, 222);
  //try to add 222 to Mike
  addCourseToStudent(s2, 222);
  //add 333 to Mike
  addCourseToStudent(s2, 333);
  //add 444 to Mike
  addCourseToStudent(s2, 444);
  //add 555 to Mike
  addCourseToStudent(s2, 555);
  //add 666 to Mike
  addCourseToStudent(s2, 666);

  cout << endl;
  //Show all the courses each student is taking
  cout << "---- Kathy is taking ----" << endl;
  s1.viewAllCourses();
  cout << endl;
  cout << "---- Mike is taking ----" << endl;
  s2.viewAllCourses();

  cout << endl << endl;
  //try to add 777 to Mike
  addCourseToStudent(s2, 777);

  //Remove 222 from Kathy
  dropCourseFromStudent(s1, 222);
  //Remove 111 from Kathy
  dropCourseFromStudent(s1, 111);
  //Remove 111 from Kathy
  dropCourseFromStudent(s1, 111);

  //Remove 555 from Mike
  dropCourseFromStudent(s2, 555);
  //Remove 666 from Mike
  dropCourseFromStudent(s2, 666);
  //Remove 111 from Mile
  dropCourseFromStudent(s2, 111);

  cout << endl;
  //Show all the courses each student is taking
  cout << "---- Kathy is taking ----" << endl;
  s1.viewAllCourses();
  cout << endl;
  cout << "---- Mike is taking ----" << endl;
  s2.viewAllCourses();
  cout << endl;

  //Show each student's info
  cout << "\n----- s1 ----" << endl;
  print(s1);
  cout << "\n----- s2 ---" << endl;
  print(s2);
  cout << "\n----- s3 ---" << endl;
  print(s3);

  //Show how getCurStuID can be called
  cout << "\nstatic member curStuID: " << student::getCurStuId() << endl;

  return 0;
}

void addCourseToStudent(student& s, int cr)
{
  int code = s.addCourse(cr);
  if(code == 1)
    cout << cr << " has been added successfully to " << s.getFirstName() << endl;
  else if(code == 0)
    cout << cr << " was not added because " << s.getFirstName() << " has " << cr << " already." <<  endl;
  else //code == -1
    cout << cr << " was not added because " << s.getFirstName() << "'s schedule is full." <<  endl;
}

void dropCourseFromStudent(student& s, int cr)
{
  if(s.dropCourse(cr) == false)
    cout << cr << " wasn't dropped from " << s.getFirstName() << " because " << cr << " doesn't exist" << endl;
  else
    cout << cr << " has been dropped successfully from " << s.getFirstName() << endl;
}

void print(const student& s)
{
  cout << "first name: " << s.getFirstName() << endl;
  cout << "last name: " << s.getLastName() << endl;
  cout << "gender: " << s.getGender() << endl;
  cout << "stu id: " << s.getStuId() << endl;
  cout << "num classes: " << s.getNumClasses() << endl;

  cout << "Courses: ";
  for(int i = 0; i < s.getNumClasses(); i++)
  cout << s.getClassOf(i) << " ";

  cout << endl;
}
