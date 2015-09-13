#include <stdio.h> /* Standard Input Output */
#include <string.h> /* operaciones de strings */
#include <stdlib.h>
#include "pizzalist.h"
#include "closedhashing.h"
#include "queuepizza.h" /* Malloc duderino */
#include "hash.h"


typedef struct Pizza
{
    // Pointer towards the first element of the list

    // Pointer towards the last element of the list
    char *tipo;
    char *cliente;
    // Size of the list, this is used to not have to go through the list
    // each time we want to know the size of the list.
    // This is used in the list_get function.

}Pizza;

int main(int argc, char const *argv[]) {
  void readCommand() {
    Array *hash;
    Pizzalist *list;
    Queuepizza *queue;
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
            array_item_at(hash, closed_addressing_hashing(hash, &(pizza[0])),list);
            if(!(pizzalist_find(list,queue,&(pizza[0]))))
            {
              queue=queuepizza_init(sizeof(int),NULL);
              pizzalist_addlast(list,queue,&(pizza[0]));
            }
            queuepizza_enqueue(queue,0,&(cliente[0]));
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
  readCommand();
  return 0;
}
