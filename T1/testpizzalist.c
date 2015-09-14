#include <stdio.h> /* Standard Input Output */
#include <string.h> /* operaciones de strings */
#include <stdlib.h>
#include "pizzalist.h"
#include "closedhashing.h"
#include "queuepizza.h" /* Malloc duderino */

void readCommand() {
  Array *hash;
  Pizzalist *list = pizzalist_init(sizeof(Queuepizza),queuepizza_destroy); //acá se pierde memoria
  Queuepizza *queue = queuepizza_init(sizeof(int),NULL);//lo mismo
  char *clienteichon=calloc(1,sizeof(char *));
  char *cliente;
  char *pizza;
  char command[4];
  int cantidad;
  int i;
  hash = array_init(sizeof(Pizzalist),pizzalist_destroy);
  while (1)
  {
      scanf("%s", command);

      if (!strcmp(command,"ASK"))/* Es lo mismo que strcmp(command,"NEW") == 0 */
      /* strcmp resta strings, si son iguales, la resta da 0 (TRUE) */
      {
        cliente=malloc(sizeof(char)*2048);
        pizza=malloc(sizeof(char)*2048);
        int add = 0;
        scanf("%s", cliente);
        scanf("%d", &cantidad);
        scanf("%s", pizza);
        for(i=0;i<cantidad;i++)
        {
          //printf("%d",(int)closed_addressing_hashing(hash, (unsigned char *)&(pizza[0])));
          array_item_at(hash, (int)closed_addressing_hashing(hash, (unsigned char *)&(pizza[0])),list);
          if(!(pizzalist_find(list,queue,(char *)&(pizza[0]))))
          {
            queue=queuepizza_init(sizeof(int),NULL);
            pizzalist_addlast(list,queue,(char *)&(pizza[0]));
            printf("LOLOGRE ");

          }
          queuepizza_enqueue(queue,&add,&(cliente[0]));
        }
        free(cliente);
        free(pizza);



    }
      else if(!strcmp(command,"RDY"))
      {
          pizza=malloc(sizeof(char)*2048);
          scanf("%s", pizza);
          array_item_at(hash, closed_addressing_hashing(hash, (unsigned char *)&(pizza[0])),list);
          if(pizzalist_find(list,queue,&(pizza[0])))
          {
            queuepizza_dequeue(queue,clienteichon,1);
            //printf("%s",*clienteichon);
          }

          free(pizza);

      }
      else if(!strcmp(command,"END"))
      {
        //scanf("%s", name);
        //scanf("%d", &gravity);
      }

      else
      {
        break;
        exit(1);
      }
      free(clienteichon);
  }

}
int main(int argc, char const *argv[]) {
  readCommand();
  return 0;
}