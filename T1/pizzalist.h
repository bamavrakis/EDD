/******************************************************************************\
|
|   Author:     Chaumier Pierre-Victor <pvchaumier@uc.cl>
|
\******************************************************************************/

// Include Guards to avoid double declarations
#ifndef Pizzalist_H
#define Pizzalist_H

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
typedef struct Pizzanodo
{
    // what the element contains. This is where you need to modify if you want
    // to change the type of the list (list of string for instance).
    void *value;

    char *key;
    //int keysize;
    // Pointer toward the next element in the list
    // You need to use struct Element and not only Element here because
    // it is inside the definition of the struct
    struct Pizzanodo *next;
    // Pointer towards the previous element
}Pizzanodo;

// Defining the general data structure
typedef struct Pizzalist
{
    freeFunction freef;
    // Pointer towards the first element of the list
    Pizzanodo *first;
    // Pointer towards the last element of the list
    Pizzanodo *last;
    // Size of the list, this is used to not have to go through the list
    // each time we want to know the size of the list.
    // This is used in the list_get function.
    int size;
    int elementsize;
}Pizzalist;

// Memory management part of the implementation
Pizzalist *pizzalist_init(int elementsize, freeFunction function);
void pizzalist_alloc_test(Pizzalist *list);
void pizzalist_destroy(Pizzalist *linkedlist);

// Implementation of the basic operations
//void pizzalist_addbeg(Pizzalist *linkedlist, void *ValueToAdd, char *key, int keysize);
//void pizzalist_addlast(Pizzalist *linkedlist, void *ValueToAdd,char *key, int keysize);
void pizzalist_addbeg(Pizzalist *linkedlist, void *ValueToAdd, char *key);
void pizzalist_addlast(Pizzalist *linkedlist, void *ValueToAdd,char *key);
int pizzalist_delbeg(Pizzalist *linkedlist, void *puntero, bool delete);
// You will get a -1 if you want to reach a position not in the list. Thus
// this implies you can only use natural integer with this implementation.
int pizzalist_get(Pizzalist *linkedlist, void *puntero, int posicion);
//int pizzalist_find(Pizzalist *linkedList,void *puntero,char *key, int keysize);
int pizzalist_find(Pizzalist *linkedList,void *puntero,char *key);
void pizzalist_print(Pizzalist *linkedlist);
void freekey(Pizzanodo *nodo);
//int keycomp(char *key1, char *key2, int keysize1, int keysize2);

#endif
