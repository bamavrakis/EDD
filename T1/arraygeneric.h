#ifndef ARRAYGENERIC_H
#define ARRAYGENERIC_H

typedef void (*freeFunction)(void *);
typedef struct ArrayGeneric {
	void *elements;
	int elementsize;
	int size;
	int maxsize;
	freeFunction freef;
	//void (*freeFn)(void *);
} ArrayGeneric;

void array_alloc_test(Array *array);
Array *array_init(int elementsize, freeFunction freeFn);
void array_destroy(ArrayGeneric *array);
int array_size(ArrayGeneric *array);

void array_add(ArrayGeneric *array, void *element);
void array_item_at(ArrayGeneric *array, int index, void *target);
void array_insert_at(ArrayGeneric *array, int index, void *target);
void array_remove_at(ArrayGeneric *array, int index);

#endif
