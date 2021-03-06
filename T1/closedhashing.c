#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "closedhashing.h"
#include "hash.h"
#include "pizzalist.h"
#include "queuepizza.h"

void array_alloc_test(Array *array){
    // Test if the array is allocated in memory, if not returns with error
    if (array == NULL)
    {
        exit(EXIT_FAILURE);
    }
}

int closed_addressing_hashing(Array *array, char *target)
{
  return (int)(hash((unsigned char *)target) % array->maxsize);
}


static void *array_address(Array *array, int index)
{
	int addr = array->elementsize * index;
	return (char *)array->elements + addr;
}

static void array_copy_item(Array *array, int sourceIndex, int destIndex)
{
	void *source = array_address(array, sourceIndex);
	void *target = array_address(array, destIndex);
	memcpy(target, source, array->elementsize);
}

Array *array_init(int elementsais, freeFunction function)
{
	assert(elementsais > 0);
  Array *array = calloc(1,sizeof(*array));
  array_alloc_test(array);
	array->elementsize = elementsais;
	array->size = 0;
	array->maxsize = 100;
	array->elements = calloc(array->maxsize,array->elementsize);
	array->freef = function;
  llenar(array);
  return array;
}
void llenar(Array *array)
{
  array_alloc_test(array);
  int i;
  Pizzalist *lista;

  for(i=0;i<array->maxsize;i++)
  {
    lista=pizzalist_init(sizeof(Queuepizza),queuepizza_destroy);
    array_add_at(array,lista,i);
  }
}
void array_destroy(Array *array)
{
  array_alloc_test(array);
	if(array->freef) {
		int i;
		for(i = 0; i < array->maxsize; i++) {
			array->freef(array_address(array, i));
		}
	}

	// free main elements
	free(array->elements);
  free(array);
}

int array_size(Array *array)
{
  array_alloc_test(array);
	return array->size;
}

void array_add(Array *array, void *element)
{
  array_alloc_test(array);
	if (array->maxsize == array->size) {
    exit(1);
    return;

	}

	void *target = array_address(array, array->size++);
  memcpy(target, element, array->elementsize);
}

void array_item_at(Array *array, int index, Pizzalist **target)
{
  array_alloc_test(array);
	assert(index >= 0 && index < array->maxsize);
	void *source = array_address(array, index);
  *target=source;
}


void array_remove_at(Array *array, int index)
{
  array_alloc_test(array);
	assert(index >= 0 && index < array->maxsize);
	// remove the item
	void *item = array_address(array, index);
	if(array->freef) {
		array->freef(item);
	}
//duda
	while(++index < array->size) {
		array_copy_item(array, index, index - 1);
	}

	array->size--;
}

void array_add_at(Array *array, void *element,int index)
{
  array_alloc_test(array);
  if (array->maxsize == array->size) {

    exit(1);
    return;
    //array_grow(array);
  }
  assert(index >= 0 && index < array->maxsize);
  void *posicion = array_address(array,index);
  memcpy(posicion, element, array->elementsize);
  array->size++;
}
