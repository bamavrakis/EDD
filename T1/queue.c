#include "linkedlist.h"
#include "queue.h"

/* ---------------- Memory manipulation for data structure ---------------- */

void queue_alloc_test(QueueSimple *queue){
    // Test if the list is allocated in memory, if not returns with error
    if (queue == NULL)
    {
        exit(EXIT_FAILURE);
    }
}

QueueSimple *queue_init(int elementsize)
{
  QueueSimple *queue = malloc(sizeof(*queue));
  queue_alloc_test(queue);
  queue->list = list_init(elementsize);
  return queue;
}

void queue_destroy(QueueSimple *queue)
{
  queue_alloc_test(queue);
  list_destroy(queue->list);
  free(queue);
}

void queue_enqueue(QueueSimple *queue, void *ValueToAdd)
{
  queue_alloc_test(queue);
  list_addlast(queue->list,ValueToAdd);
}

void queue_dequeue(QueueSimple *queue, void *puntero, bool delete)
{
  queue_alloc_test(queue);
  list_delbeg(queue->list,puntero,delete);
}
bool queue_is_empty(QueueSimple *queue)
{
  if(queue->list.size == 0)
  {
    return true;
  }
  return false;
}

void queue_print(QueueSimple *queue)
{
  queue_alloc_test(queue);
  list_print(queue->list);
}
