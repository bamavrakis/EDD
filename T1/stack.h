/******************************************************************************\
|
|   Author:     Chaumier Pierre-Victor <pvchaumier@uc.cl>
|
\******************************************************************************/

// Include Guards to avoid double declarations
#ifndef STACKSIMPLE_H
#define STACKSIMPLE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedlistsimple.h"

// We will implement a doubly linked list. Each element points towards its
// previous and next element in the list.
// Notice that you can easily modify iy to get a Queue or a Stack !

// In this implementation, we assume that the list will only contain natural
// integer (otherwise, we would encounter issues in the get function. Send a
// mail if you want more details)

// Defining an element type
// Defining the general data structure
typedef struct StackSimple
{
    // Pointer towards the first element of the list

    // Pointer towards the last element of the list
    LinkedListSimple *list;
    // Size of the list, this is used to not have to go through the list
    // each time we want to know the size of the list.
    // This is used in the list_get function.

}StackSimple;

// Memory management part of the implementation
StackSimple *stack_init(int elementsize);
void stack_alloc_test(StackSimple *stack);
void stack_destroy(StackSimple *stack);

// Implementation of the basic operations
void stack_push(StackSimple *stack, void *ValueToAdd);
void stack_pop(StackSimple *stack, void *puntero, bool delete);
bool stack_is_empty(StackSimple *stack);

// You will get a -1 if you want to reach a position not in the list. Thus
// this implies you can only use natural integer with this implementation.

void queue_print(StackSimple *stack);

#endif
