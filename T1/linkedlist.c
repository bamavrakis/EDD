#include "linkedlist.h"

/* ---------------- Memory manipulation for data structure ---------------- */

void list_alloc_test(LinkedList *list){
    // Test if the list is allocated in memory, if not returns with error
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }
}

LinkedList *list_init()
{
    // Allocation of the different pointers.
    LinkedList *list = malloc(sizeof(*list));
    Element *element = malloc(sizeof(*element));

    if (list == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // We need to define the pointers.
    element->value = 0;
    element->next = NULL;
    element->previous = NULL;
    
    list->first = element;
    list->last = element;
    list->size = 0;

    return list;
}

void list_destroy(LinkedList *list)
{
    list_alloc_test(list);

    Element *elementCurrent, *elementNext;

    elementCurrent = list->first;
    while (elementCurrent != NULL)
    {
        elementNext = elementCurrent->next;
        free(elementCurrent);
        elementCurrent = elementNext;
    }
    free(elementCurrent);
    free(elementNext);
    free(list);
}

/* ---------------- Manipulation of the data structure ---------------- */

void list_add(LinkedList *list, int iValueToAdd)
{
    list_alloc_test(list);

    // We allocate memory for the new element that will be added.
    Element *element = malloc(sizeof(*element));

    if (element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // We initialize the element.
    element->value = iValueToAdd;
    // the next element is null because we add at the end of the list.
    element->next = NULL;

    // If the list was empty
    if (list->size == 0)
    {
        // Be careful we need to free the first element because it was 
        // initiated.
        free(list->first);
        element->previous = NULL;
        list->first = element;

    }
    // If the list already contains at least one other element.
    else
    {
        element->previous = list->last;
        list->last->next = element;
    }
    
    list->last = element;
    list->size += 1;
}

void list_del(LinkedList *list, int iValueToDel)
{
    list_alloc_test(list);

    Element *elementCurrent, *elementPrevious;
    
    // List empty
    if (list->size == 0)
    {
        printf("ERROR. List is empty, nothing to delete\n");
    }
    // List contains only one element
    else if (list->size == 1)
    {
        elementCurrent = list->first;
        if (elementCurrent->value == iValueToDel)
        {
            free(elementCurrent);
            list->first = NULL;
            list->last = NULL;
            list->size = 0;
        }
        else
        {
            printf("ERROR. Element not in list, nothing to delete\n");
        }
    }
    // List has at least two elements
    else
    {
        elementPrevious = list->first;
        elementCurrent = elementPrevious->next;

        // Element to delete is the first one
        if (elementPrevious->value == iValueToDel)
        {
            list->first = elementCurrent;
            elementCurrent->previous = NULL;
            list->size -= 1;
            free(elementPrevious);
        }
        // Element to delete is not the first
        else
        {
            // Loop to check if any of the value of the elements is iValueToDel
            int iKeepGoing = 1;
            while (elementCurrent != NULL && iKeepGoing == 1)
            {
                if (elementCurrent->value == iValueToDel)
                {
                    iKeepGoing = 0;
                    elementPrevious->next = elementCurrent->next;
                    list->size -= 1;
                    // if we are deleting the last element
                    if (elementCurrent->next == NULL)
                    {
                        list->last = elementPrevious;
                    }
                    else
                    {
                        elementCurrent->next->previous = elementPrevious;
                    }
                    free(elementCurrent);
                }
                else
                {
                    elementPrevious = elementCurrent;
                    elementCurrent = elementCurrent->next;
                }
            }
            // Feedback if element was not found
            if (iKeepGoing == 1)
            {
                printf("ERROR. Element not found.\n");
            }
        }
    }
}

int list_get(LinkedList *list, int iPosition)
{
    list_alloc_test(list);

    Element *elementCurrent;
   
    // Check if position asked is present in the list.
    if (iPosition > list->size - 1)
    {
        printf("ERROR. The list only contains %d elements.\n", list->size);
        return -1;
    }
    else
    {
        // We need to go through the list to acced to the iPosition element.
        int i;
        elementCurrent = list->first;
        for (i = 0; i < iPosition; i++)
        {
            elementCurrent = elementCurrent->next;
        }
        // Now we reached the iPosition element of the list.
        return elementCurrent->value;
    }
}


void list_print(LinkedList *list)
{
    // We will go through the list and print each of the element.s
    list_alloc_test(list);

    Element *elementCurrent;

    printf("{");

    if (list->size > 0)
    {
        elementCurrent = list->first;
        while (elementCurrent != NULL)
        {
            printf("%d", elementCurrent->value);
            elementCurrent = elementCurrent->next;
            if (elementCurrent != NULL)
            {
                printf(", ");
            }
        }
    }
    printf("}\n");
}
