#include <stdio.h> /* Standard Input Output */
#include <string.h> /* operaciones de strings */
#include <stdlib.h>
#include "pizzalist.h"
#include "closedhashing.h"
#include "queuepizza.h" /* Malloc duderino */

void readCommand() {
  Array *hash;
  Pizzalist *list = pizzalist_init(sizeof(Queuepizza),queuepizza_destroy); //acá se pierde memoria
  Queuepizza *queue = pizzalist_init(sizeof(int),NULL);//lo mismo
  char cliente[2048];
  char pizza[2048];
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

        scanf("%s", cliente);
        scanf("%d", &cantidad);
        scanf("%s", pizza);
        for(i=0;i<cantidad;i++)
        {
          printf("NOOOO");
          array_item_at(hash, closed_addressing_hashing(hash, (unsigned char *)&(pizza[0])),list);
          if(!(pizzalist_find(list,queue,&(pizza[0]))))
          {
            queue=queuepizza_init(sizeof(int),NULL);
            //pizzalist_addlast(list,queue,&(pizza[0]));
          }
          //queuepizza_enqueue(queue,0,&(cliente[0]));
        }


      //Persona* person = malloc(sizeof(Persona));
      //person->name = malloc(sizeof(char)*(strlen(name)));
      //erson->gravity = gravity;
      //add(person);
    }
      else if(!strcmp(command,"RDY"))
      {

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

}
int main(int argc, char const *argv[]) {
  printf("ya pue");
  readCommand();
  return 0;
}
