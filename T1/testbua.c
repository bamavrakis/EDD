#include <stdio.h> /* Standard Input Output */
#include <string.h> /* operaciones de strings */
#include <stdlib.h>
#include "pizzalist.h"
#include "closedhashing.h"
#include "queuepizza.h" /* Malloc duderino */
int main(int argc, char const *argv[]) {
  Array *hash = array_init(sizeof(Pizzalist),pizzalist_destroy);
  int cantidad;
  int i;
  Pizzalist *list = pizzalist_init(sizeof(Queuepizza),queuepizza_destroy); //acá se pierde memoria
  Queuepizza *queue = pizzalist_init(sizeof(int),NULL);//lo mismo
  char cliente[2048];
  char pizza[2048];
  scanf("%s", cliente);
  scanf("%d", &cantidad);
  scanf("%s", pizza);
  for(i=0;i<cantidad;i++)
  {

    array_item_at(hash, closed_addressing_hashing(hash, (unsigned char *)&(pizza[0])),list);
    // en vez de 1  closed_addressing_hashing(hash, (unsigned char *)&(pizza[0]))
    //pizzalist_find(list,queue,&(pizza[0]));
    if(!(pizzalist_find(list,queue,&(pizza[0]))))
    {
      queue=queuepizza_init(sizeof(int),NULL);
      pizzalist_addlast(list,queue,(char *)&(pizza[0]));
    }
    //queuepizza_enqueue(queue,0,&(cliente[0]));
  }
  return 0;
}
