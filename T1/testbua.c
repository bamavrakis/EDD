#include <stdio.h> /* Standard Input Output */
#include <string.h> /* operaciones de strings */
#include <stdlib.h>
#include "pizzalist.h"
#include "closedhashing.h"
#include "queuepizza.h" /* Malloc duderino */
int main(int argc, char const *argv[]) {
  Array *hash = array_init(sizeof(Pizzalist),pizzalist_destroy);
  scanf("%d", &cantidad);
  printf("%d",cantidad);

  return 0;
}
