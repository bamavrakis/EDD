/******************************************************************************\
|
|   Author:     Chaumier Pierre-Victor <pvchaumier@uc.cl>
|
\******************************************************************************/

// Include Guards to avoid double declarations
#ifndef QUEUEPIZZA_H
#define QUEUEPIZZA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pizzalist.h"

// We will implement a doubly linked list. Each element points towards its
// previous and next element in the list.
// Notice that you can easily modify iy to get a Queue or a Stack !

// In this implementation, we assume that the list will only contain natural
// integer (otherwise, we would encounter issues in the get function. Send a
// mail if you want more details)

// Defining an element type
// Defining the general data structure
typedef struct Queuepizza
{
    // Pointer towards the first element of the list

    // Pointer towards the last element of the list
    Pizzalist *list;
    // Size of the list, this is used to not have to go through the list
    // each time we want to know the size of the list.
    // This is used in the list_get function.

}Queuepizza;

// Memory management part of the implementation
Queuepizza *queuepizza_init(int elementsize,freeFunction function);
void queuepizza_alloc_test(Queuepizza *queue);
void queuepizza_destroy(void *queue);

// Implementation of the basic operations
void queuepizza_enqueue(Queuepizza *queue, void *ValueToAdd, char* cliente);
void queuepizza_dequeue(Queuepizza *queue, void *puntero, bool delete);
bool queuepizza_is_empty(Queuepizza *queue);

// You will get a -1 if you want to reach a position not in the list. Thus
// this implies you can only use natural integer with this implementation.

void queuepizza_print(Queuepizza *queue);

#endif
