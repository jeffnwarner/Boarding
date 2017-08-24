//Jeffery Warner
//Zsin Budhwani
#include<fstream>
#include<iostream>
#include"StackAr.h"
#include"QueueAr.h"

using namespace std;

enum STATE{EMPTY, WAITING_TO_MOVE, STORING_LUGGAGE1, STORING_LUGGAGE2, SEATING};
int count = 0;

class Passenger
{
  public:   
    int row; //"1"
    char c;  //"C"
};//Passenger

class Row
{
  public:
    StackAr<Passenger> lAisle;
    StackAr<Passenger> rAisle;
    StackAr<Passenger> inAisle;
    StackAr<Passenger> waiting;
    STATE state;
    int rowNum; 
};//Row


STATE Seating(Passenger& p, Row& r, int& i)
{
  int time = 0;
  //cout<<p.c<<endl;
  //cout<<p.row<<endl;
  if (p.c == 'A' || p.c == 'B' || p.c == 'C')
  {
    //cout<<"if 1"<<endl;
    if (r.lAisle.isEmpty())//if 2 puts in Row if row is empty
    {
        //cout<<"if 2"<<endl;
        r.lAisle.push(p);
        time += 5;
        if (r.inAisle.isEmpty())
        {
          r.inAisle.makeEmpty();
          return EMPTY;
        }
        else
          return SEATING;
    }  
    else
    {
      //cout<<"else 1"<<endl;
      if (p.c > r.lAisle.top().c)//if 3 puts in Row if closest seat is empty
        {
          //cout<<"if 3"<<endl;
          r.lAisle.push(p);
          time += 5;
          if (r.inAisle.isEmpty())
          {
            r.inAisle.makeEmpty();
            return EMPTY;
          }
          else
            return SEATING;
        }
      else if (p.c < r.lAisle.top().c)
      {
        //cout<<"else 20"<<endl;
        //cout<<r.lAisle.top().c<<endl;
        //cout<<r.lAisle.top().row<<endl;
        r.inAisle.push(r.lAisle.top());
        r.lAisle.pop(); 
        return SEATING;
      }
      else
      {
        r.lAisle.push(r.inAisle.top());
        r.inAisle.pop();
        if(r.inAisle.isEmpty())
        {
          r.inAisle.makeEmpty();
          return EMPTY;
        }
        else
          return SEATING;
      }
        //else
       // {
          //cout<<"else 3"<<endl;
          //cout<<r.lAisle.top().c<<endl;
          //cout<<r.lAisle.top().row<<endl;
          //cout<<p.c<<endl;
          //cout<<p.row<<endl;
          //if (p.c > r.lAisle.top().c)
         // {
            //cout<<"if 5"<<endl;
            //r.lAisle.push(p);
            //time += 5;
            //r.lAisle.push(r.inAisle.top());
            //time += 5;
            //return 0;
          //}//if 5 puts in Row if closest seat is empty
          //else
         // {
            //cout<<"else 4"<<endl;
            //r.inAisle.push(r.lAisle.top());
            //cout<<"inAisle push"<<endl;
            //time += 5;
            //r.lAisle.pop();
            //cout<<"lAisle pop"<<endl;
            //r.lAisle.push(p);
            //cout<<"lAisle push"<<endl;
            //time += 5;
            //r.lAisle.push(r.inAisle.top());
            //cout<<"laisle push"<<endl;
            //time += 5;
            //r.inAisle.pop();
            //r.lAisle.push(r.inAisle.top());
            //cout<<"laisle push"<<endl;
            //time += 5;
            //r.inAisle.pop();
           // return 0;
          //}//else 4 takes all passengers out and then puts passengers in ABC
        //}//else 3 checks if passengers are in way of passenger in aisle
      //}//else 2  checks if passengers are in way of passenger in aisle
    }//else 1 if row is not empty.
  }//if 1
  else
  {
    //cout<<"else 5"<<endl;
    if (r.rAisle.isEmpty())//if 2 puts in Row if row is empty
      {
        //cout<<"if 2"<<endl;
        r.rAisle.push(p);
        time += 5;
        if (r.inAisle.isEmpty())
        {
          r.inAisle.makeEmpty();
          return EMPTY;
        }
        else
          return SEATING;
      }  
    else
    {
      //cout<<"else 1"<<endl;
      if (p.c < r.rAisle.top().c)//if 3 puts in Row if closest seat is empty
      {
          //cout<<"if 3"<<endl;
          r.rAisle.push(p);
          time += 5;
          if (r.inAisle.isEmpty())
          {
            r.inAisle.makeEmpty();
            return EMPTY;
          }
          else
            return SEATING;
      }
      else if (p.c > r.rAisle.top().c)
      {
        //cout<<"else 90"<<endl;
        r.inAisle.push(r.rAisle.top());
        time += 5;
        r.rAisle.pop();
        //if (r.lAisle.isEmpty())//if 4 puts in Row if row is empty
          //{
            //cout<<"if 4"<<endl;
            //r.lAisle.push(p);
            //time += 5;
        return SEATING;
      }
      else
      {
        r.rAisle.push(r.inAisle.top());
        r.inAisle.pop();
        if(r.inAisle.isEmpty())
        {
          r.inAisle.makeEmpty();
          return EMPTY;
        }
        else
          return SEATING;
      }
       // else
        //{
          //cout<<"else 8"<<endl;
          //cout<<r.rAisle.top().c<<endl;
          //cout<<r.rAisle.top().row<<endl;
          //if (p.c < r.rAisle.top().c)
          //{
            //cout<<"if 9"<<endl;
            //r.rAisle.push(p);
            //time += 5;
            //r.rAisle.push(r.inAisle.top());
            //time += 5;
            //return 0;
          //}//if 5 puts in Row if closest seat is empty
          //else
         // {
            //cout<<"else 9"<<endl;
           // r.inAisle.push(r.rAisle.top());
            //time += 5;
            //cout<<"inAisle push"<<endl;
            //r.rAisle.pop();
            //r.rAisle.push(p);
            //cout<<"rAisle push"<<endl;
            //time += 5;
            //r.rAisle.push(r.inAisle.top());
            //cout<<"rAisle push"<<endl;
           // time += 5;
           // r.inAisle.pop();
           // r.rAisle.push(r.inAisle.top());
            //cout<<"rAisle push"<<endl;
           // time += 5;
            //r.inAisle.pop();
            //cout<<"inAisle pop"<<endl;
            //return 0;
          //}//else 4 takes all passengers out and then puts passengers in ABC
        //}//else 3 checks if passengers are in way of passenger in aisle
      //}//else 2  checks if passengers are in way of passenger in aisle
    }//else 1 if row is not empty.
  }//if 1
}//Seating()
//  while(Boarding_is_not_done)
    //if Empty Seat -> Store in Luggage 1 -> Store in Luggage 2 -> if needed C_out -> Then B_in or B_out then A_in
    //time+=5 for passing aise, 10 seconds for storing luggage, 5 seconds if needed c_out or b_out

//some algorithm not sure where to put
int fsm(Passenger& p, ifstream& inf, Queue<Row> &rQ, Queue<Row> &temp, int& i)
{
  int time = 0;
  int while_loop = 1;
  int time_it_should_be = 0;
  char seat_letter;
  int row_number;
  int seated_passengers = 0;
  int read_passengers = 0;
  Passenger tempPass;
  StackAr<Passenger> tempStack;
  bool airplane_is_full = false;
  bool rQ_row_is_empty = true;
  Row tempRow;
  while (!airplane_is_full)
  {
    int temp_num = 0;
    if (seated_passengers > 287)
      airplane_is_full = true;
    else
    {
      //cout<<"else 1"<<endl;
      for (int i = 48; i > 0; i--)
      {
        tempRow = rQ.getFront();
        rQ.dequeue();
        if(!rQ_row_is_empty)
        {
          //cout<<"if 1"<<endl;
          tempRow.waiting.pop();
          rQ_row_is_empty = true;
          tempRow.state = EMPTY;
        }
          //cout<<"if 2"<<endl;
        if (tempRow.state == EMPTY && tempRow.rowNum == 1)
        {
          //cout<<"if 3"<<endl;
          if (read_passengers < 288)            
          { 
            inf >> row_number >> seat_letter;
            p.row = row_number;
            //cout<<"p row "<<row_number<<endl;
            p.c = seat_letter;
            //cout<<"p c "<<seat_letter<<endl;
            tempRow.waiting.push(p);
            //cout<<seated_passengers<<endl;
            read_passengers++;
            //cout<<read_passengers<<endl;
            if (tempRow.waiting.top().row == 1)
            { 
              //cout<<"if 4"<<endl;
              tempRow.state = STORING_LUGGAGE1;
              //time += 5;
              temp.enqueue(tempRow);
            }//checks to see if new Passenger's seat is in first row.
            else
            {
              //cout<<"else 2"<<endl;          
              tempRow.state = WAITING_TO_MOVE;
              temp.enqueue(tempRow);
              temp_num++;
            }//else changes Row State to WAITING_TO_MOVE and puts it in temp Stack.
          }//if statemetn puts new passenger on plane
          else
          {
            //cout<<"else 3"<<endl;
            temp.enqueue(tempRow);
            temp_num++;
          }
        }// if statement checks to see if first row is empty
          //else
          //{
            // temp.enqueue(tempRow);
             //temp_num++;
          //}
        //}//if all of the rows are taken out of queue.  
        //else
        //{
          //cout<<"else 4"<<endl;
        else if (tempRow.state == EMPTY && rQ.getFront().state == WAITING_TO_MOVE)
        {
          //cout<<"if 5"<<endl;
          tempRow.waiting.push(rQ.getFront().waiting.top());
          tempStack = rQ.getFront().waiting;
          tempStack.pop();
          //erase the passenger from aisle in next loop.
          rQ_row_is_empty = false;
          if (tempRow.waiting.top().row == i)
          {
            //cout<<"if 6"<<endl;
            tempRow.state = STORING_LUGGAGE1;
            //time += 5;
            temp.enqueue(tempRow);
          }//if statementchecks to see if Passenger seat is in current row.
          else
          {
            //cout<<"else 5"<<endl;
            tempRow.state = WAITING_TO_MOVE;
            //cout<<"state"<<endl;
            temp.enqueue(tempRow);
            temp_num++;
            //cout<<"enqueue"<<endl;
          }//else changes Row State to WAITING_TO_MOVE and puts it in temp Stack.
        }//if statement puts passenger into the next row.
        else if (tempRow.state == STORING_LUGGAGE1 || tempRow.state == STORING_LUGGAGE2 || tempRow.state == SEATING)
        {
          if (tempRow.state == STORING_LUGGAGE2)
          {
            tempPass = tempRow.waiting.top();
            //cout<<"temp 2"<<endl;
            //cout<<tempPass.row<<endl;
            //cout<<tempRow.rowNum<<endl;
            //cout<<i<<endl;
            tempRow.state = Seating(tempPass, tempRow, i);
            //cout<<"Seating 2"<<endl;
            if(tempRow.state == EMPTY)
            {
              tempRow.waiting.pop();
              //cout<<"EMPTY"<<endl;
            }
            //else
              //cout<<"SEATING"<<endl;
            //cout<<"tempRow 2"<<endl;
            //tempRow.state = EMPTY;
            //cout<<"state 2"<<endl;
            temp.enqueue(tempRow);
            temp_num++;
            //cout<<"enqueue 2"<<endl;
            seated_passengers++;
            //cout<<"seated passen 2"<<endl;
          }
          else
          {
            tempRow.state = STORING_LUGGAGE2;
            //time += 5;
            temp.enqueue(tempRow);
            //cout<<"else 7"<<endl;
          }
        }//else if stroing luggage
        else//moves along the list. 
        {
          temp.enqueue(tempRow);
          temp_num++;
          //cout<<"else 6"<<endl;
        }
        //cout<<"row num "<<tempRow.rowNum<<endl;
        //cout<<"i "<<i<<endl;
        //time += 5;
      }//for loop
      time += 5;
      time_it_should_be = while_loop * 5;
      while_loop++;
      //cout<<"temp num "<<temp_num<<endl;
      //cout<<"seated passengers "<<seated_passengers<<endl;
      //cout<<"read passengers "<<read_passengers<<endl;
      temp_num = 0;
      //cout<<"temp num "<<temp_num<<endl;
      //for (int i = 48; i > 0; i--)
      //{
        //cout<<"for loop"<<i<<endl;
        //rQ.enqueue(temp.getFront());
        //cout<<"enqueue"<<endl;
        //temp.dequeue();
        //cout<<"dequeue"<<endl;
      //}
      //time += 5;
      for (int i = 48; i > 0; i--)
      {
        //cout<<"for loop"<<i<<endl;
        rQ.enqueue(temp.getFront());
        //cout<<"enqueue"<<endl;
        temp.dequeue();
        //cout<<"dequeue"<<endl;
      }//for loop
      //time += 5;
    }//else statement
  }//while loop  
  //cout<<"seated passengers "<<seated_passengers<<endl;
  //cout<<"read passengers "<<read_passengers<<endl;
  //cout<<"time_it_should_be "<<time_it_should_be<<endl;
  return time;           
}//fsm()  

int main(int argc, char* argv[])
{
  Queue <Row> rQ(48);
  Queue <Row> temp(48); //temporary queue for iteration
  Row r;
  Passenger p;
  int time = 0;
  
  ifstream inf(argv[1]);
  for (int j = 0; j < 3; j++)
  {
    //cout<<j<<endl;
    for (int i = 48; i > 0; i--)
    {
      r.rowNum = i;
      r.state = EMPTY;
      rQ.enqueue(r);
    }//for Loop
    time = fsm(p, inf, rQ, temp, time);
    rQ.makeEmpty();
    temp.makeEmpty();
    if (j == 0) {cout<<"Back to front: "<<time<<endl;}
    else if (j == 1) {cout<<"Random: "<<time<<endl;}
    else {cout<<"Outside in: "<<time<<endl;}
  }//for loop
  return 0;
}//main
