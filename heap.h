#ifndef Heap_H
#define HEAP_H
#include "task.h"
void insertTask(struct Task task);
struct Task extractMax();
struct Task peek();
void heapifyUp(int index);
void heapifyDown(int index);
void buildHeap();
extern int heapsize;
extern struct Task heap[maxtasks];
#endif // Heap_H
