#include <stdio.h> /* Standard Input Output */
#include <string.h> /* operaciones de strings */
#include <stdlib.h>
#include "pizzalist.h"
#include "closedhashing.h"
#include "queuepizza.h" /* Malloc duderino */
int main(int argc, char const *argv[]) {
  void readCommand() {
    char command[4];
    int gravity;
    char name[2048];
    scanf("%s", command);
    if (!strcmp(command,"NEW"))/* Es lo mismo que strcmp(command,"NEW") == 0 */
    /* strcmp resta strings, si son iguales, la resta da 0 (TRUE) */
    {
      scanf("%s", name);
      scanf("%d", &gravity);
      //Persona* person = malloc(sizeof(Persona));
      //person->name = malloc(sizeof(char)*(strlen(name)));
      //erson->gravity = gravity;
      //add(person);
    }
    else if(!strcmp(command,"NXT"))
    {

    }
    else if(!strcmp(command,"UPD"))
    {
      scanf("%s", name);
      scanf("%d", &gravity);
    }
    else if(!strcmp(command,"DIE"))
    {

    }
    else if(!strcmp(command,"END"))
    {

    }
    else
    {
      exit(1);
    }
  }
  readCommand();
  return 0;
}
