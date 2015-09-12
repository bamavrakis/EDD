/******************************************************************************\
|
|   Author:     Chaumier Pierre-Victor <pvchaumier@uc.cl>
|
\******************************************************************************/

// Include Guards to avoid double declarations
#ifndef LINKEDLISTSIMPLE_H
#define LINKEDLISTSIMPLE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



// We will implement a doubly linked list. Each element points towards its
// previous and next element in the list.
// Notice that you can easily modify iy to get a Queue or a Stack !

// In this implementation, we assume that the list will only contain natural
// integer (otherwise, we would encounter issues in the get function. Send a
// mail if you want more details)

// Defining an element type
typedef void (*freeFunction)(void *);
typedef struct ElementSimple
{
    // what the element contains. This is where you need to modify if you want
    // to change the type of the list (list of string for instance).
    void *value;
    // Pointer toward the next element in the list
    // You need to use struct Element and not only Element here because
    // it is inside the definition of the struct
    struct ElementSimple *next;
    // Pointer towards the previous element
}ElementSimple;

// Defining the general data structure
typedef struct LinkedListSimple
{
    freeFunction freef;
    // Pointer towards the first element of the list
    ElementSimple *first;
    // Pointer towards the last element of the list
    ElementSimple *last;
    // Size of the list, this is used to not have to go through the list
    // each time we want to know the size of the list.
    // This is used in the list_get function.
    int size;
    int elementsize;
}LinkedListSimple;

// Memory management part of the implementation
LinkedListSimple *list_init(int elementsize, freeFunction function);
void list_alloc_test(LinkedListSimple *list);
void list_destroy(LinkedListSimple *linkedlist);

// Implementation of the basic operations
void list_addbeg(LinkedListSimple *linkedlist, void *ValueToAdd);
void list_addlast(LinkedListSimple *linkedlist, void *ValueToAdd);
int list_delbeg(LinkedListSimple *linkedlist, void *puntero, bool delete);
// You will get a -1 if you want to reach a position not in the list. Thus
// this implies you can only use natural integer with this implementation.
int list_get(LinkedListSimple *linkedlist, void *puntero, int posicion);
void list_print(LinkedListSimple *linkedlist);

#endif
