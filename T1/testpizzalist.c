#include <stdio.h> /* Standard Input Output */
#include <string.h> /* operaciones de strings */
#include <stdlib.h>
#include "pizzalist.h"
#include "closedhashing.h"
#include "queuepizza.h" /* Malloc duderino */

void readCommand() {
  Array *hash;
  Pizzalist list;
  list = *pizzalist_init(sizeof(Queuepizza),queuepizza_destroy);
  Pizzalist *punter=&list;//acá se pierde memoria
  Queuepizza queue = *queuepizza_init(sizeof(int),NULL);//lo mismo
  char *clienteichon=malloc(sizeof(char )*2048);
  char *cliente;
  char *pizza;
  char *redi;
  int *modo;
  int *cantidad;

  cliente=malloc(sizeof(char)*2048);
  pizza=malloc(sizeof(char)*2048);
  redi=malloc(sizeof(char)*2048);
  modo=malloc(sizeof(int));

  char command[4];
  cantidad=malloc(sizeof(int));

  int i;

  hash = array_init(sizeof(Pizzalist),pizzalist_destroy);
  scanf("%d",modo);
  if(*modo==0)
  {
    while (1)
    {
        scanf("%s", command);
        if (!strcmp(command,"ASK"))
        {
          int add = 0;
          scanf("%s", cliente);
          scanf("%d", cantidad);
          scanf("%s", pizza);
          array_item_at(hash,closed_addressing_hashing(hash, pizza),&punter);
          for(i=0;i<*cantidad;i++)
          {
            if(!(pizzalist_find(&list,&queue,pizza)))
            {
              queue=*queuepizza_init(sizeof(int),NULL);
              pizzalist_addlast(&list,&queue,pizza);
            }
            queuepizza_enqueue(&queue,&add,cliente);

          }
      }
        else if(!strcmp(command,"RDY"))
        {
            scanf("%s", redi);
            array_item_at(hash, closed_addressing_hashing(hash, redi),&punter);

            if(pizzalist_find(&list,&queue,redi))
            {
              if(queue.list->size!=0)
              {
                queuepizza_dequeue(&queue,clienteichon,1);
                printf("%s\n",clienteichon);
              }
            }

        }
        else if(!strcmp(command,"END"))
        {
        }
        else
        {
          break;
          exit(1);
        }

    }

  }
  free(cliente);
  free(pizza);
  free(redi);
  free(clienteichon);
  free(modo);
  free(cantidad);
  pizzalist_destroy(&list);
  queuepizza_destroy(&queue);
  array_destroy(hash);
}
int main(int argc, char const *argv[]) {
  readCommand();
  return 0;
}