/******************************************************************************\
|
|   Author:     Chaumier Pierre-Victor <pvchaumier@uc.cl>
|
\******************************************************************************/

// Include Guards to avoid double declarations
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h> 
#include <stdlib.h>

// We will implement a doubly linked list. Each element points towards its 
// previous and next element in the list.
// Notice that you can easily modify iy to get a Queue or a Stack !

// In this implementation, we assume that the list will only contain natural
// integer (otherwise, we would encounter issues in the get function. Send a
// mail if you want more details)

// Defining an element type
typedef struct Element
{
    // what the element contains. This is where you need to modify if you want
    // to change the type of the list (list of string for instance).
    int value;
    // Pointer toward the next element in the list
    // You need to use struct Element and not only Element here because
    // it is inside the definition of the struct 
    struct Element *next;
    // Pointer towards the previous element
    struct Element *previous;
}Element;

// Defining the general data structure
typedef struct LinkedList
{
    // Pointer towards the first element of the list
    Element *first;
    // Pointer towards the last element of the list
    Element *last;
    // Size of the list, this is used to not have to go through the list 
    // each time we want to know the size of the list. 
    // This is used in the list_get function.
    int size;
}LinkedList;

// Memory management part of the implementation
LinkedList *list_init();
void list_alloc_test(LinkedList *list);
void list_destroy(LinkedList *linkedlist);

// Implementation of the basic operations
void list_add(LinkedList *linkedlist, int iValueToAdd);
void list_del(LinkedList *linkedlist, int iValueToDel);
// You will get a -1 if you want to reach a position not in the list. Thus
// this implies you can only use natural integer with this implementation.
int list_get(LinkedList *linkedlist, int iPosition);
void list_print(LinkedList *linkedlist);

#endif
