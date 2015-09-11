#include "array.h"


/* ---------------- Memory manipulation for data structure ---------------- */

void array_alloc_test(Array *array){
    // Test if the array is allocated in memory, if not returns with error
    if (array == NULL)
    {
        exit(EXIT_FAILURE);
    }
}

Array *array_init(int elementsize)
{
    // Define a pointer to an Array structure and reserves the necessary size
    Array *array = malloc(sizeof(*array));

    // Test if the pointer has been allocated
    array_alloc_test(array);

    // We define the basic elements
    array->elementsize=elementsize;
    array->size = 0;
    array->capacity = INITIAL_SIZE;
    array->content = malloc(array->elementsize * array->capacity);

    // Every time you use a pointer, it needs to be allocated. We test this now
    // for the content of the array
    if (array->content == NULL)
    {
        printf("ERROR. The content of the array could not be initialize.\n");
        exit(EXIT_FAILURE);
    }

    return array;
}

void array_double_size_if_full(Array *array){
    /**
    This function uses the realloc function to take the content array and double
    its size.
    Check for dynamic memory allocation to found out more about this.
    Functions to check are :
      - malloc
      - calloc
      - realloc
    **/

    // Test if the array exists in the first place (pointer is allocated)
    array_alloc_test(array);

    void *contentTmp;

    if (array->size >= array->capacity)
    {
        // Modification of the capacity
        array->capacity *= 2;
        // Reallocation of the content in a new array two times bigger
        contentTmp = realloc(array->content, elementsize * array->capacity);
        // Test if reallocation went well
        if (contentTmp == NULL)
        {
            array_destroy(array);
            printf("ERROR. The content could not be reallocated\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            array->content = contentTmp;
        }
    }
}

void array_destroy(Array *array)
{
    /**
    This function will now deallocate all the pointers we have used. This is
    necessary to free the memory.
    /!\ Be careful, if the content element is an array of string (array of
    array of char), you will need to deallocate all the different string also
    if you used a pointer to define them !
    **/
    array_alloc_test(array);
    free(array->content);
    //VER COMO BORRAR LAS COSAS.
    free(array);
}


/* ---------------- Manipulation of the data structure ---------------- */

void array_add(Array *array, void *ValueToAdd){
    array_alloc_test(array);
    // Check if it is possible to add a new value, if the content array is full,
    // we need to double its size
    array_double_size_if_full(array);

    array->content[array->size++] = ValueToAdd;
    // Be careful here again, with strings, you would need to use the string.h
    // library and the strcpy function as one cannot generally assign an
    // array with an equal sign.
}

void array_del(Array *array, int iValueToDel)
{
    array_alloc_test(array);

    int i = 0, iKeepGoing = 1;
    while(iKeepGoing == 1 && i < array->size)
    {
        if (array->content[i] == iValueToDel)
        {
            // We need to shift the array to delete the element.
            while (i < array->size - 1)
            {
                array->content[i] = array->content[i + 1];
                i++;
            }
            array->size--;
            iKeepGoing = 0;
        }
        else
        {
            i++;
        }
    }
    if (iKeepGoing == 1)
    {
        printf("ERROR. Element not found in the array.\n");
    }
}

int array_get(Array *array, int iPosition)
{
    array_alloc_test(array);

    if (iPosition > array->size - 1)
    {
        printf("ERROR. The array only contains %d elements\n", array->size);
        return -1;
    }

    return array->content[iPosition];
}

void array_print(Array *array){
    array_alloc_test(array);

    printf("[");
    int i;
    for (i = 0; i < array->size; i++)
    {
        printf("%d", array->content[i]);
        if (i != array->size - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}
