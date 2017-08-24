// Zain Budhwani 912268778
// Jeffery Warner 
#include "CPUTimer.h"
#include "LinkedList.h"
#include "CursorList.h"
#include "StackAr.h"
#include "dsexceptions.h"
#include "vector.h"
#include "QueueAr.h"
#include "StackLi.h"
#include "SkipList.h"
#include <iostream>
#include <fstream>
using namespace std;

vector < CursorNode <int> > cursorSpace(500001); // make cursor list compile, taken from handout

int getChoice();
void RunList(char* filename);
void RunCursorList(char* filename);
void RunStackAr(char* filename);
void RunStackLi(char* filename);
void RunQueueAr(char* filename);
void RunSkipList(char* filename);


int main()
{
  int choice; // for getting the choice
  char filename[80]; //accessing the functions for the file
  CPUTimer ct;    // cpu tumer
  
  cout<<"Filename >>";
  cin>>filename;
  
  do //copied from handout
  {
    choice = getChoice();
    ct.reset();
    switch (choice)
    {
      case 1: RunList(filename); break;
      case 2: RunCursorList(filename); break;
      case 3: RunStackAr(filename); break;
      case 4: RunStackLi(filename); break;
      case 5: RunQueueAr(filename); break;
      case 6: RunSkipList(filename);break;
    } //switch

    cout << "CPU time: " << ct.cur_CPUTime() << endl;
  } // do while 
  while(choice > 0);

  return 0;
} // main

int getChoice()
{
  int choice;
  do
  {
    cout << "\n      ADT Menu\n0. Quit\n1. LinkedList\n2. CursorList\n3. StackAr\n4. StackLi\n5. QueueAr\n6. SkipList\n Your choice >> ";
    cin >> choice;
    if (choice < 0 || choice > 6)
      cout << "Make sure you type a number between 0 and 6" << endl;	
  } // do while loop
  while (choice < 0 ||  choice > 6);	
  return choice;
}

void RunList(char* filename)
{
  List <int> l;
  char com;
  char size_of_string[256]; 
  ListItr <int> lItr = l.zeroth();
  ifstream file(filename);
  int num;

  file.getline(size_of_string, 256);
  
  while(file >> com >> num)
  {
    if (com == 'i')
      l.insert(num, lItr);
    else
      l.remove(num);
  }//while
}//RunList()

void RunCursorList(char* filename)
{
  CursorList <int> cl(cursorSpace);
  char com;
  char size_of_string[256]; 
  CursorListItr <int> clItr = cl.zeroth();
  ifstream file(filename);
  int num;

  file.getline(size_of_string, 256);
  
  while(file >> com >> num)
  {
    if (com == 'i')
      cl.insert(num, clItr);
    else
      cl.remove(num);
  }//while loop      
}//CursorList()

void RunStackAr(char* filename)
{
  StackAr <int> sA(5000001);
  char com;
  char size_of_string[256]; 
  ifstream file(filename);
  int num;

  file.getline(size_of_string, 256);
  
  while(file >> com >> num)
  {
    if (com == 'i')
      sA.push(num);
    else
      sA.pop();
  }//while loop
}//StackAr()

void RunStackLi(char* filename)
{
  StackLi <int> sL;
  char com;
  char size_of_string[256]; 
  ifstream file(filename);
  int num;

  file.getline(size_of_string, 256);
  
  while(file >> com >> num)
  {
    if (com == 'i')
      sL.push(num);
    else
      sL.pop();
  }//while loop      
}//StackLi()

void RunQueueAr(char* filename)
{
  Queue <int> q(500000);
  char com;
  char size_of_string[256]; 
  ifstream file(filename);
  int num;

  file.getline(size_of_string, 256);
  
  while(file >> com >> num)
  {
    if (com == 'i')
       q.enqueue(num);
    else
       q.dequeue();
  }//while loop
}//QueueAr()

void RunSkipList(char* filename)
{
  SkipList <int> s(0, 500000);
  char com;
  char size_of_string[256]; 
  ifstream file(filename);
  int num;

  file.getline(size_of_string, 256);
  
  while(file >> com >> num)
  {
    if (com == 'i')
       s.insert(num);
    else
       s.deleteNode(num);
  }//while loop
}//SkipList()