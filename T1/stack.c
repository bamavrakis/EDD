#include "linkedlist.h"
#include "stack.h"

/* ---------------- Memory manipulation for data structure ---------------- */

void stack_alloc_test(StackSimple *stack){
    // Test if the list is allocated in memory, if not returns with error
    if (stack == NULL)
    {
        exit(EXIT_FAILURE);
    }
}

StackSimple *stack_init(int elementsize,freeFunction function)
{
  StackSimple *stack = malloc(sizeof(*stack));
  stack_alloc_test(stack);
  stack->list = list_init(elementsize,function);
  return stack;
}

void stack_destroy(StackSimple *stack)
{
  stack_alloc_test(stack);
  list_destroy(stack->list);
  free(stack);
}

void stack_push(StackSimple *stack, void *ValueToAdd)
{
  stack_alloc_test(stack);
  list_addbeg(stack->list,ValueToAdd);
}

void stack_pop(StackSimple *stack, void *puntero, bool delete)
{
  stack_alloc_test(stack);
  list_delbeg(stack->list,puntero,delete);
}
bool stack_is_empty(StackSimple *stack)
{
  if(stack->list.size == 0)
  {
    return true;
  }
  return false;
}

void stack_print(StackSimple *stack)
{
  stack_alloc_test(stack);
  list_print(stack->list);
}
