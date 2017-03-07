#include <iostream>
#include "cqueue.h"
#include <string.h>

using namespace std;

CQueue::CQueue() //constructor
{
	front=MAX-1;
	rear=MAX-1;
}

bool CQueue::IsEmpty()
{
	bool emp;
	if(front == rear)
		emp= 1;
	else emp=0;
	return emp;
}

bool CQueue::IsFull()
{
	bool ful;
	if((rear+1)%MAX == front)
		ful=1;
	else ful=0;
	return ful;
}

void CQueue::Enqueue(Passenger added)
{
	if(IsFull())
	{
		cout<<"Queue is full\n"; //error check
	}
	else
	{
		rear=(rear+1)% MAX;
		strcpy(passengers[rear].name, added.name);
	}
}

Passenger CQueue::Front()
{
	return passengers[(front+1)%MAX];
}

void CQueue::Dequeue()
{
	if(IsEmpty())
	{
		cout<<"Queue is empty\n"; //error check
	}
	else
	{
		front=(front+1)%MAX;
	}
}
