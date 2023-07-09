/*****************************************************
Template prepared by Kazumi Slott
CS211
lab on template functions
This header file provides useful operations on an array
of any data type.

Your name:
*****************************************************/

#include <iostream>
using namespace std;

/********************************************
This function fills the array with data entered from the keyboard.

ar is an array of any data type
n is the number of items entered into ar
********************************************/
template<class T>
T fill(const T ar[], int n)
{
  T i = 0;
  cout << "Enter an item: "; // uses user output and input to fill the arrays
  cin >> i;
  return i; //return the information to be stored in the arrays in the main
}

/********************************************
This function prints the array.

ar is an array of any data type
n is the number of items in ar
********************************************/
template<class T>
void print( const T ar[],const int n)
{
  int count = 0;
  for(int i = 0; i < n; i++)
    {
      cout << ar[i] << " "; // while the index is less than the size of the array, output t\
he index of the array
      count ++;

      if(count == 7)
        {
  count = 0;
          cout << endl;
        }
    }
  cout << endl;
}

/*******************************************
This function returns the index of the highest value.

ar is an array of any data type.
n is the number of items in ar
*******************************************/
template<class T>
T getHighest(const T ar[], int n)
{
  T temp = 0;
  for(int i = 0; i < n; i++)
    {
      if(ar[i] > temp) //using a temp variable to store the value of the highest while comp\
aring it to each value of the array
        {
          temp = ar[i];
        }
    }
  return temp;
}

/*******************************************
This function returns the index of the lowest value.

ar is an array of any data type.
n is the number of items in array
*******************************************/
template<class T>
T getLowest(const T ar[], int n)
{
  T temp = 20;
  for(int i = 0; i < n; i++)
    {
      if(ar[i] < temp) //using a temp variable to store the value of the lowest while makin\
g comparrisons
        {
          temp = ar[i];
 }
    }
  return temp;
}

/********************************************
This function returns the average.

ar is an array of any data type.
n is the number of items in ar
********************************************/
template<class T>
T getAvg(const T ar[], int n)
{
  T total = 0;
  T avg = 0;
  for(int i = 0; i < n; i++)
    {
      total += ar[i];  // adding each value of the array into total
    }
  avg = total/n; //dividing total by the number of elements to return the average
  return avg;
}

/*******************************************
This function stores unique items into an array
and returns the number of the unique items.
  e.g.  If ar contains  9 3 5 3 9 1 9
        uniqAr gets 9 3 5 1
        The function returns 4

ar is the original array of any data type
uniqAr is the array that will have only unique items
n is the number of items in ar and uniqAr
*******************************************/
template<class T>
int  unique(const T ar[], T uni[] ,int n)
{
  //creating a boolean variable to track weather or not a value has already entered the uni\
que array
  bool has_ever = false;
  uni[0] = ar[0]; //entering the first value of the int array to unique array
  int num = 1;
  for(int i = 1; i < n; i++)   // first for loop will control the index of the int array
    {
 for(int j = 0; j < num; j++)  //second loop will control the index in the unique arra\
y
        {
          if(ar[i] == uni[j]) //testing wether the index of i = index of j, they cannot be \
the same value
            {
              has_ever = true; //if the value has already been entered, break from the seco\
nd for loop
            }
        }
      if(has_ever != true)
        {
          uni[num] = ar[i]; // if the value has not been entered and is unique, store into \
the index of i in the unique array, reset  num, and break
          num += 1;
        }
    }
  return num; //return the value of num
}

/***********************************************
This function sorts the items in ascending order: smallest to largest

array is an array of any data type
N is the number of items in the array
**********************************************/                                            \


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//The following function sorts an integer array in ascending order
//using the selection sort algorithm.
//You need to change this code so it works with an array of any data type.
template<class T>
void sort(T array[], int N)
{
  int lrgIndx; //the index of the largest value                                            \

  T temp; //temporary variable that holds the largest value                                \


  //last is the last index in unsorted portion                                             \

  for(int last = N-1; last >= 1; last--)
    {
 lrgIndx = 0; //assume the first item is the largest                                  \

      //find the largest in unsorted portion ([0..last])                                   \

      for(int i = 1; i <= last; i++)
        {
          if(array[i] > array[lrgIndx]) //The current item is larger                       \

            lrgIndx = i;
        }

      //swap the largest with the last item in the unsorted portion                        \

      temp = array[lrgIndx];
      array[lrgIndx] = array[last];
      array[last] = temp;
    }
}
/*****************************************
This function locates the index in the array that a provided course should be, if it is not\
 found, return -1
******************************************/

template<class T1, class T2>
int find(const T1 array[], int n, const T2& k)
{
   //will return the index
  for(int i = 0; i < n; i++)  //look at each value in the array
    {
      if(array[i] == k)  //if the current value equals the course number
        {
          return i;  //store index into ans
        }
    }
  return -1;
}

/**************************************
This function locates the index of a class and determines wether or not it can be removed f\
rom the array
***********************************/

template <class T, class T2>
bool remove(T array[], int n, T2 e)
{
  int index;  //value that will hold the index of the course to be removed
  int course;  //variable that will hold the position in the switch
  T t;  //a temp variable to help preform the switch

  index = find(array, n, e);  //first set index equal to the index where the classes to be \
removed was found

  if(index >= 0)  //if the index is greater than or qual to zero
    {
      course = index;  //set course equal to the index

      while(index < n)  //while the index from the srray is less than the number of classes\
 the student is enrolled in
        {
          index ++;  //increment index to the index following the desired course to be remo\
ved. if the course is the last in the array it will go to the n+1 index which is null
          t = array[index];  //the value of the following index is stored in temp
          array[course] = t;  //the origional index of the class removed is replaced by the\
 following index
          course++;  //increment course. the index of the origional class to be removed has\
 been replaced
        }
      return true;  //if this process was carried out, return true
    }
  return false;  //if the class was never loacted by the find function in the first place, \
return false
}


template <class T>
void bubbleSort(T array[], int N)
{
  bool done = false;
  T temp;
  do
    {
      for(int j = 0; j < N; j++)
        {
          for(int i = 0; i < N; i++)
            {
              if(array[i] < array[i+1])
                {
                  temp = array[i];
  array[i] = array[i+1];
                  array[i+1] = temp;
                }
            }
        }
      done = true;
    }while(done == false);
}