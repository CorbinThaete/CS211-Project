#include <iostream>
using namespace std;

#include "student.h"
#include "array.h"

int student::curStuId = START_STU_ID;

/*****************************************
Constructor
 ****************************************/
student::student(string f, string l, char g, int i)//:stuId(curStuId)
{
  fN = f;
  lN = l;
  gender = g;
  numClasses = 0;
  //curStuId++;
  stuId = i;
}

student::student()//:stuId(curStuId)
{
  fN = "unknown";
  lN = "unknown";
  gender = 'x';
  //curStuId++;
  numClasses = 0;
  stuId = -1;
}

/*************************************
This function return the first name of the student
*************************************/
string student::getFirstName() const
{
  return fN;
}

/******************************
This function returns the last name of the student
*************************/
string student::getLastName() const
{
  return lN;
}
/****************************
This function returns the students gender
*************************/
char student::getGender() const
{
  return gender;
}

/******************************
returns the classes
****************************/
int student::getClassOf(int i) const
{
  return classes[i];
}

/*************************************
retusn the number of classes
************************************/
int student::getNumClasses() const
{
  return numClasses;
}

/***********************************
retusn the student id
*********************************/
int student::getStuId() const
{
  return stuId;
}

/*******************************
returns the current student id
********************************/
int student:: getCurStuId()
{
  return curStuId;
}

/*******************************
this function adds a course for the student
******************************/
int student::addCourse(int crn)
{
  int ac;  //boolean variable to be returned
  //cout << find(classes, numClasses, crn)<< endl;
  if(find(classes, numClasses, crn) >= 0)  //if there are values in the array
    {
      ac = 0;
    }
  else if(numClasses < MAX)  //if the array is less than the maximum amount
    {
      //  cout << "yes" << endl;
      classes[numClasses++] = crn;  //add one to numclasses, set it equal to crn
      ac = 1;
    }
  else
    {
      ac = -1;
    }
  //cout << ac << endl;
  return ac; //return the int variable
  }
/**********************************
function drops a given course for a student
********************************/
bool student:: dropCourse(int crn)
{
  bool dc;
  dc = remove(classes, numClasses, crn);
  if(dc == true)
    {
      numClasses -= 1;
      dc = true;
    }
  else
    {
      dc = false;
    }
  return dc;
}

/*********************************
prints the courses the student is in
***********************************/
void student::viewAllCourses()
{
  print(classes, numClasses);
}

/***********************************
retuns the balance the student owes
************************************/
Price student::getBalance()const
{
  return balance;
}

/****************************************
adds a fee to the students balance
*****************************************/
void student::addFee(int d, int c)
{
  Price p(d, c);
  balance = balance + p;
}

/*****************************************
takes a fee off a students balance
******************************************/
void student::reduceFee(int d, int c)
{
  Price p(d, c);
  balance = balance - p;
}
