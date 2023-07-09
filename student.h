#include <string>
using namespace std;
#include "price.h"

const int START_STU_ID = 100000;
const int MAX = 6;

class student
{
 private:
  static int curStuId;
  int stuId;
  string fN; //first name
  string lN;  //last name
  char gender;
  int numClasses;  //number of class student is enrolled in
  int classes[MAX];  //array of classes with max of 6 slots
  Price balance;

 public:
  student(string f, string l, char g, int i); //constructor
  student();
  string getFirstName() const; //returns first name of student
  string getLastName() const; //returns last name of student
  char getGender() const;  //returns gender of student
  int getClassOf(int i)const;
  int getNumClasses()const;
  int getStuId() const;
  int addCourse(int crn);  //adds a course provided
  bool dropCourse(int crn);  //drops the provided course
  void viewAllCourses();  //prints a list of courses the students are enrolled in
  static int getCurStuId();
  Price getBalance()const;
  void addFee(int d, int c);
  void reduceFee(int d, int c);
};
