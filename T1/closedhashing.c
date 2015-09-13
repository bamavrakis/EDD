#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "closedhashing.h"
#include "hash.h"

void array_alloc_test(Array *array){
    // Test if the array is allocated in memory, if not returns with error
    if (array == NULL)
    {
        exit(EXIT_FAILURE);
    }
}
static void array_grow(Array *array) //me falta hacer el hash de nuevo.
{
  array_alloc_test(array);
  int i;
  array->maxsize *= 2;
  void *oldelements = array->elements;

  array->elements = calloc(array->maxsize,array->elementsize);
  assert(array->elements);

  for(i = 0; i < array->maxsize; i++) {
    addtemp=(char *)oldelements + array->elementsize * i;
    if (addtemp != NULL)
    {
      source = (char *)oldelements + array->elementsize * i
      target = array_address(array, i); //hash
      memcpy(target, source, array->elementsize);
    }
    if (array->freef)
    {
      array->freef((char *)oldelements + array->elementsize * i);
    }

  }
	}

	// free main elements
	free(oldelements);






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

Array *array_init(int elementsize, freeFunction function)
{
	assert(elementsize > 0);
  Array *array = malloc(sizeof(*array));
  array_alloc_test(array);
	array->elementsize = elementsize;
	array->size = 0;
	array->maxsize = 2;
	array->freef = function;
  array->elements = calloc(array->maxsize,array->elementsize);

  assert(array->elements);
	//array_grow(array);
  return array;
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
		array_grow(array);
	}

	void *target = array_address(array, array->size++);
	memcpy(target, element, array->elementsize);
}

void array_item_at(Array *array, int index, void *target)
{
  array_alloc_test(array);
	assert(index >= 0 && index < array->size);
	void *source = array_address(array, index);
	memcpy(target, source, array->elementsize);
}

void array_insert_at(Array *array, int index, void *target)
{
  array_alloc_test(array);
	assert(index >= 0 && index <= array->size);
	array_add(array, target);

	if(index < array->size) {
		int i;
		void *source;
		void *destination;

		for(i = array->size - 2; i > index; i--) {
			source = array_address(array, i);
			destination = array_address(array, i + 1);
			memcpy(destination, source, array->elementsize);
		}

		destination = array_address(array, i);
		memcpy(destination, target, array->elementsize);
	}
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
    array_grow(array);
  }
  assert(index >= 0 && index < array->maxsize);
  void *posicion = array_address(array,index);
  memcpy(posicion, element, array->elementsize);
  array->size++;
}
