#include "linkedlistsimple.h"
#include <stdbool.h>
#include <string.h>
/* ---------------- Memory manipulation for data structure ---------------- */

void list_alloc_test(LinkedListSimple *list){
    // Test if the list is allocated in memory, if not returns with error
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }
}

LinkedListSimple *list_init(int elementsize,freeFunction function)
{
    // Allocation of the different pointers.

    LinkedListSimple *list = malloc(sizeof(*list));
    list->freef = function;

    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // HALP.

    list->elementsize = elementsize;
    list->first = NULL;
    list->last = NULL;
    list->size = 0;

    return list;
}

void list_destroy(LinkedListSimple *list)
{
    list_alloc_test(list);

    ElementSimple *elementCurrent, *elementNext;

    elementCurrent = list->first;
    while (elementCurrent != NULL)
    {
        elementNext = elementCurrent->next;
        if (list->freef)
        {
          list->freef(elementCurrent->value);
        }
        free(elementCurrent->value);
        free(elementCurrent);
        elementCurrent = elementNext;
    }
    free(elementCurrent);
    free(elementNext);
    free(list);
}

/* ---------------- Manipulation of the data structure ---------------- */

void list_addlast(LinkedListSimple *list, void *ValueToAdd)
{
    list_alloc_test(list);

    // We allocate memory for the new element that will be added.
    ElementSimple *element = malloc(sizeof(*element));
    element->value=malloc(list->elementsize);
    if (element == NULL || element->value == NULL)
    {
        exit(EXIT_FAILURE);
    }
    memcpy(element->value, ValueToAdd, list->elementsize);

    // the next element is null because we add at the end of the list.
    element->next = NULL;

    // If the list was empty
    if (list->size == 0)
    {
        // Be careful we need to free the first element because it was
        // initiated.

        list->first = element;

    }
    // If the list already contains at least one other element.
    else
    {
        list->last->next = element;
    }

    list->last = element;
    list->size++;
}

void list_addbeg(LinkedListSimple *list, void *ValueToAdd)
{
    list_alloc_test(list);

    // We allocate memory for the new element that will be added.
    ElementSimple *element = malloc(sizeof(*element));
    element->value=malloc(list->elementsize);
    if (element == NULL || element->value == NULL)
    {
        exit(EXIT_FAILURE);
    }
    memcpy(element->value, ValueToAdd, list->elementsize);



    // the next element is null because we add at the end of the list.
    // element->next = NULL;

    // If the list was empty
    element->next = list->first;
    list->first = element;
    if (list->size == 0)
    {
        // Be careful we need to free the first element because it was
        // initiated.

        list->last = element;

    }
    // If the list already contains at least one other element.



    list->size++;
}

int list_delbeg(LinkedListSimple *list,void *puntero, bool delete)
{
    list_alloc_test(list);
    if (list->size == 0)
    {
      return -1;

    }
    ElementSimple *element=list->first;
    memcpy(puntero, element->value, list->elementsize);
    if(delete)
    {
      if (list->size ==1)
      {
        list->last = NULL;
      }
      if(list->freef)
      {
        list->freef(element->value);
        free(element->value);
      }
      list->first = element->next;
      free(element);
      list->size--;
    }



    return 0;




}

// NO CREO QUE SEA NECESARIO PERO IGUAL.
int list_get(LinkedListSimple *list, void *puntero, int Position)
{
    list_alloc_test(list);

    ElementSimple *element;

    // Check if position asked is present in the list.
    if (Position > list->size - 1)
    {
        printf("ERROR. The list only contains %d elements.\n", list->size);
        return -1;
    }
    else
    {
        // We need to go through the list to acced to the iPosition element.
        int i;
        element = list->first;
        for (i = 0; i < Position; i++)
        {
            element = element->next;
        }
        // Now we reached the iPosition element of the list.
        puntero=element->value;
        return 0;
    }
}


void list_print(LinkedListSimple *list)
{
    // We will go through the list and print each of the element.s
    list_alloc_test(list);

    ElementSimple *element;

    printf("{");

    if (list->size > 0)
    {
        element = list->first;
        while (element != NULL)
        {
            int *caca=(int *)element->value;
            printf("%d", *caca);
            element = element->next;
            if (element != NULL)
            {
                printf(", ");
            }
        }
    }
    printf("}\n");
}
