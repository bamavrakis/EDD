#include "linkedlist.h"
#include "queue.h"

/* ---------------- Memory manipulation for data structure ---------------- */

void queuepizza_alloc_test(Queuepizza *queue){
    // Test if the list is allocated in memory, if not returns with error
    if (queue == NULL)
    {
        exit(EXIT_FAILURE);
    }
}

Queuepizza *queuepizza_init(int elementsize,freeFunction function)
{
  Queuepizza *queue = malloc(sizeof(*queue));
  queuepizza_alloc_test(queue);
  queue->list = pizzalist_init(elementsize,function);
  return queue;
}

void queuepizza_destroy(Queuepizza *queue)
{
  queuepizza_alloc_test(queue);
  pizzalist_destroy(queue->list);
  free(queue);
}

void queuepizza_enqueue(Queuepizza *queue, void *ValueToAdd, char *cliente, int clientesize)
{
  queuepizza_alloc_test(queue);
  pizzalist_addlast(queue->list,ValueToAdd);
}

void queuepizza_dequeue(Queuepizza *queue, void *puntero, bool delete)
{
  queuepizza_alloc_test(queue);
  pizzalist_delbeg(queue->list,puntero,delete);
}
bool queuepizza_is_empty(Queuepizza *queue)
{
  if(queue->list.size == 0)
  {
    return true;
  }
  return false;
}

void queuepizza_print(Queuepizza *queue)
{
  queuepizza_alloc_test(queue);
  pizzalist_print(queue->list);
}