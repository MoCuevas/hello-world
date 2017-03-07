#include <iostream>
#include <string.h>
#include "cqueue.h"
using namespace std;

enum choice { BOOKED, WAITING };
const int LINES = 2;
int showMenu(void);
void addPassenger(CQueue*);
void deletePassenger(CQueue*);
void showPassengers(CQueue*);

int main (void)
{
CQueue qPassengers[LINES]; //array of cqueue
int x;
do{
x = showMenu();
switch (x)
{
case 1: addPassenger(qPassengers);
break;
case 2: deletePassenger(qPassengers);
break;
case 3: showPassengers(qPassengers);
break;
default:x=4;	//avoids infinite loop
}
} while (x != 4);
return 0;
}

int showMenu(void)
{
int select;

cout << "Menu\n";
cout << "========\n";
cout << "1. Add Passenger\n";
cout << "2. Delete Passenger\n";
cout << "3. Show Passengers\n";
cout << "4. Exit\n";
cout << "Enter choice: ";
cin >> select;
return select;
}
 
// To do: implement addPassenger, deletePassenger and showPassengers
void addPassenger(CQueue* qlist)
{
	Passenger newpassenger;

	cout << "Enter name: ";
	cin>>newpassenger.name;
	if (qlist[BOOKED].IsFull())
	{
		if (qlist[WAITING].IsFull())
			cout<<"Sorry. Plane and waiting list fully booked. Try later.\n\n";
		else
		{
			cout<<"Sorry. Plane fully booked. Adding "<<newpassenger.name<<" to waiting list\n\n";
			qlist[WAITING].Enqueue(newpassenger);
		}
	}
	else
	{
		cout << "Booking " << newpassenger.name<<" on flight.\n"<<endl;
		qlist[BOOKED].Enqueue(newpassenger);
	}
}

void deletePassenger(CQueue* qlist)
{
	if(qlist[BOOKED].IsEmpty())
		cout << "No passengers to delete.\n\n";
	else
	{
		cout <<"Removing " << qlist[BOOKED].Front().name<<" from booked passengers.\n";
		qlist[BOOKED].Dequeue();

		if(!qlist[WAITING].IsEmpty())
		{
			cout <<"Adding "<<qlist[WAITING].Front().name<<" from waiting list.\n"<<endl;
			qlist[BOOKED].Enqueue(qlist[WAITING].Front());
			qlist[WAITING].Dequeue();
		}
		else
			cout<<endl;
	}
}

void showPassengers(CQueue* qlist)
{
	if(qlist[BOOKED].IsEmpty())
		cout << "No passengers.\n\n";
	else
	{
		cout << "Booked passengers\n";
		cout << "===================\n";

		CQueue temp;   //temporary storage
		while(!qlist[BOOKED].IsEmpty())
		{
			cout << qlist[BOOKED].Front().name<<endl;
			temp.Enqueue(qlist[BOOKED].Front());
			qlist[BOOKED].Dequeue();
		}
		while(!temp.IsEmpty())
		{
			qlist[BOOKED].Enqueue(temp.Front());
			temp.Dequeue();
		}
		cout<<endl;

		if(!qlist[WAITING].IsEmpty())  //Check Waiting List
		{
			cout << "Waiting List\n";
			cout << "===================\n";
			while(!qlist[WAITING].IsEmpty())
			{
				cout << qlist[WAITING].Front().name<<endl;
				temp.Enqueue(qlist[WAITING].Front());
				qlist[WAITING].Dequeue();
			}
			while(!temp.IsEmpty())
			{
				qlist[WAITING].Enqueue(temp.Front());
				temp.Dequeue();
			}
		}
		else
			cout << "No passengers on waiting list.\n";
		cout<<endl;
	}
}