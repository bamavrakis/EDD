/******************************************************************************\
|   --  TAREA1.C --
|   Author:     Chaumier Pierre-Victor <pvchaumier@uc.cl>
|   Date:       20/03/2015
|   Comments:   IIC2133 - estructuras de datos - tarea1
\******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "array.h"
#include "linkedlistsimple.h"
#include <stdbool.h>
#include <string.h>



int main( int argc, char *argv[] )
{
    int el;

    /*** Example for the array ***/

    printf("-----------------------------------\n");

    LinkedListSimple *list;
    list = list_init(4);

    printf("Empty list\n");
    list_print(list);
    int a=1;
    int b=2;
    int c=3;
    printf("LinkedList with 1, 2 and 3 added.\n");
    list_addlast(list, &a);
    printf("LinkedList with 1, 2 and 3 added.\n");

    list_addlast(list, &b);

    list_addlast(list, &c);
    list_print(list);

    printf("LinkedList with 3 deleted.\n");
    int *puntero;
    list_delbeg(list,puntero,true);
    list_print(list);

    printf("Looking for element at position number 1.\n");
    el = list_get(list,puntero, 1);


    printf("Looking for element at position number 2.\n");
    el = list_get(list, puntero, 1);


    list_destroy(list);

    return 0;
}
