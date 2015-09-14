#include <stdio.h> /* Standard Input Output */
#include <string.h> /* operaciones de strings */
#include <stdlib.h>
#include "pizzalist.h"
#include "closedhashing.h"
#include "queuepizza.h" /* Malloc duderino */

void readCommand() {
  Array *hash;
  Pizzalist list;
  list = *pizzalist_init(sizeof(Queuepizza),queuepizza_destroy); //acá se pierde memoria
  //printf("%d",list);
  Queuepizza queue = *queuepizza_init(sizeof(int),NULL);//lo mismo
  char *clienteichon=malloc(sizeof(char )*2048);
  char *cliente;
  char *pizza;
  char *redi;
  cliente=malloc(sizeof(char)*2048);
  pizza=malloc(sizeof(char)*2048);
  redi=malloc(sizeof(char)*2048);

  char command[4];
  int *cantidad;
  int i;
  hash = array_init(sizeof(Pizzalist),pizzalist_destroy);
  while (1)
  {
      scanf("%s", command);
      //list = *pizzalist_init(sizeof(Queuepizza),queuepizza_destroy);
      //queue=queuepizza_init(sizeof(int),NULL);

       //acá se pierde memoria

      if (!strcmp(command,"ASK"))/* Es lo mismo que strcmp(command,"NEW") == 0 */
      /* strcmp resta strings, si son iguales, la resta da 0 (TRUE) */
      {
        cliente=malloc(sizeof(char)*2048);
        pizza=malloc(sizeof(char)*2048);
        cantidad=malloc(sizeof(int));

        int add = 0;
        scanf("%s", cliente);
        scanf("%d", cantidad);
        scanf("%s", pizza);




        //printf("%d \n",closed_addressing_hashing(hash,(pizza)));
        array_item_at(hash,closed_addressing_hashing(hash, pizza),&list);
        //printf("%d",list);

        //printf("%d",list->size);
        for(i=0;i<*cantidad;i++)
        {

          if(!(pizzalist_find(&list,&queue,pizza)))
          {
            //printf("%s",&(pizza[0]));
            //printf("NUNCA HE ENTRADO\n");
            //printf("%s \n",&pizza[0]);
            queue=*queuepizza_init(sizeof(int),NULL);
            pizzalist_addlast(&list,&queue,pizza);


          }
          //printf("%d\n",list);

          //(pizzalist_find(list,queue,(char *)&(pizza[0])))
          queuepizza_enqueue(&queue,&add,cliente);
          //Queuepizza *hue=list->first->value;
          //char *huehue=hue->list->first->key;


          //printf("%s",huehue);

        }



    }
      else if(!strcmp(command,"RDY"))
      {
          //pizza=calloc(1,sizeof(char)*2048);
          scanf("%s", redi);
          //list = pizzalist_init(sizeof(Queuepizza),queuepizza_destroy);
          //queue=queuepizza_init(sizeof(int),NULL);

          //printf("%d ",closed_addressing_hashing(hash,(unsigned char *)&(redi[0])));
          array_item_at(hash, closed_addressing_hashing(hash, redi),&list);
          //printf("%d",list->size);
          //printf("%d",closed_addressing_hashing(hash,(unsigned char *)&(pizza[0])));
          //Queuepizza *hue=list->first->value;
          //char *huehue=hue->list->first->key;
          //printf("%s",huehue);

          if(pizzalist_find(&list,&queue,redi))
          {
            //printf("encontrado");
            //printf("%s",queue.list->first->key);
            queuepizza_dequeue(&queue,clienteichon,1);
            printf("%s\n",clienteichon);
          }

          //free(pizza);

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

  }
  free(cliente);
  free(pizza);
  free(redi);

  free(clienteichon);


}
int main(int argc, char const *argv[]) {
  readCommand();
  return 0;
}