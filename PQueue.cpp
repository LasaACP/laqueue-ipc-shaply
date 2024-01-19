/*
 * LaQueue
 * 
 * 
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *  
 * (c) copyright 2018, James Shockey - all rights reserved
 * 
 * */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "PQueue.h"



/*
 * Class Priority Queue
 */

		
/*
* Insert into Priority Queue
*/
void PQueue::push(void *item, int priority)
{
	/* Your code here */
  // std::cout << "1*** ***" << std::endl;
  // display();
  node * newNode = new node;
  newNode->data = item;
  newNode->priority = priority;
  newNode->link = NULL;
  if (front == NULL) {
    front = newNode;
    return;
  }
  node * temp = front;
  if (priority < temp->priority) {
    newNode->link = temp;
    front = newNode;
    return;
  }
  while (temp->link != NULL && priority >= temp->link->priority)
    temp = temp->link;
  newNode->link = temp->link;
  temp->link = newNode;
  // std::cout << "2*** ***" << std::endl;
  // display();
  return;
}

/*
 * Delete from Priority Queue
 */
void* PQueue::top()
{
	/* Your code here */
  if (front)
    return front->data;
  else
    return NULL;
}
/*
 * Delete from Priority Queue
 */
void PQueue::pop()
{
	/* Your code here */
  if (front == NULL)
    return;
  node * temp = front;
  front = front->link;
  temp->link = NULL;
  // delete temp;
}

/*
 * Print Priority Queue
 */
void PQueue::display()
{

	/* Your code here */
  node * temp = front;
	while (temp != NULL) {
	/* Use the following out command for the data */
	 std::cout<<temp->priority<<" "<<(char*)temp->data<<std::endl;
    temp = temp->link;
  }
}

/*
* Return Priority Queue Size
*/
int PQueue::size() {
  node * temp = front;
  int s = 0;
  while (temp != NULL) {
    s++;
    temp = temp->link;
  }
  return s;
}