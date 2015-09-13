#include <stdio.h> /* Standard Input Output */
#include <string.h> /* operaciones de strings */
#include <stdlib.h>
#include "pizzalist.h"
#include "closedhashing.h"
#include "queuepizza.h" /* Malloc duderino */

typedef struct Persona
{
  char* name;
  int gravity;
}Persona;

typedef struct Heap
{
  Persona** elArreglo;
  int actual;
}Heap;

Heap elHeap;

void add(Persona* nuevaPersona) {
  elHeap.elArreglo[elHeap.actual] = nuevaPersona;
  elHeap.actual++;
}

void readCommand() {
  char command[4];
  int gravity;
  char name[32];
  scanf("%s", command);
  if (!strcmp(command,"NEW"))/* Es lo mismo que strcmp(command,"NEW") == 0 */
  /* strcmp resta strings, si son iguales, la resta da 0 (TRUE) */
  {
    scanf("%s", name);
    scanf("%d", &gravity);
    Persona* person = malloc(sizeof(Persona));
    person->name = malloc(sizeof(char)*(strlen(name)));
    person->gravity = gravity;
    add(person);
  };
  else if(!strcmp(command,"NXT"))
  {

  };
  else if(!strcmp(command,"UPD"))
  {
    scanf("%s", name);
    scanf("%s", &gravity);
  };
  else if(!strcmp(command,"DIE"))
  {

  };
  else if(!strcmp(command,"END"))
  {

  };
  else
  {
    exit(1);
  };
};

int main(int argc, char const *argv[]) {

  return 0;
}
