/******************************************************************************\
|
|   Author:     Chaumier Pierre-Victor <pvchaumier@uc.cl>
|
\******************************************************************************/

// Include Guards to avoid double declarations
#ifndef array_H
#define array_H

#include <stdio.h>
#include <stdlib.h>

// When the array will be initialized, it will be of size INITIAL_SIZE
// Notice that it is empty for now
// You can modify this value
#define INITIAL_SIZE 10

// typedef allows you to use Array instead of struct Array when defyning new
// variables
typedef struct Array
{
    // Number of element in the array
    int size;
    // How many elements the current array can contain
    int capacity;
    // What is in the array, in this case we have an array of int
    // this is where you should modify the code if you want to
    // change the type of the content
    void *content;

    int elementsize;
}Array;

Array *array_init();
void array_alloc_test(Array *array);
void array_double_size_if_full(Array *array);
void array_destroy(Array *array);

void array_add(Array *array, int iValueToAdd);
void array_del(Array *array, int iValueToDel);
int array_get(Array *array, int iPosition);
void array_print(Array *array);

#endif
