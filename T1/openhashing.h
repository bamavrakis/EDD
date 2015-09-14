#ifndef ARRAYSIMPLE_H
#define ARRAYSIMPLE_H

typedef void (*freeFunction)(void *);
typedef struct Arraysimple {
	void *elements;
	int elementsize;
	int size;
	int maxsize;
	freeFunction freef;
	//void (*freeFn)(void *);
} Arraysimple;

void array_alloc_test(Arraysimple *array);
Arraysimple *array_init(int elementsize, freeFunction freeFn);
void array_destroy(Arraysimple *array);
int array_size(Arraysimple *array);

void array_add(Arraysimple *array, void *element);
void array_item_at(Arraysimple *array, int index, Pizzalist **target);
void array_insert_at(Arraysimple *array, int index, void *target);
void array_remove_at(Arraysimple *array, int index);
void array_add_at(Arraysimple *array, void *element,int index);
int opensimple_addressing_hashing(Arraysimple *array, char *target);

unsigned long closed_addressing(Arraysimple *array, unsigned char *target);


#endif
