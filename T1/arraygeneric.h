#ifndef ARRAY_H
#define ARRAY_H

typedef void (*freeFunction)(void *);
typedef struct Array {
	void *elements;
	int elementsize;
	int size;
	int maxsize;
	freeFunction freef;
	//void (*freeFn)(void *);
} Array;

void array_alloc_test(Array *array);
Array *array_init(int elementsize, freeFunction freeFn);
void array_destroy(Array *array);
int array_size(Array *array);

void array_add(Array *array, void *element);
void array_item_at(Array *array, int index, void *target);
void array_insert_at(Array *array, int index, void *target);
void array_remove_at(Array *array, int index);

#endif
