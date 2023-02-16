#include <stdio.h>
#include <stdlib.h>
//Bunu değiştir
#include <limits.h>

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);

// A class for Min Heap
typedef struct {
int *arr; // pointer to array of elements in heap
int capacity; // maximum possible size of min heap
int heap_size; // Current number of elements in min heap
} MinHeap;

// Constructor: Builds a heap from a given array a[] of given size
MinHeap* create_heap(int capacity)
{
MinHeap* heap = malloc(sizeof(MinHeap));
heap->heap_size = 0;
heap->capacity = capacity;
heap->arr = malloc(capacity * sizeof(int));
return heap;
}

// Inserts a new key 'k'
void insert_key(MinHeap* heap, int k)
{
if (heap->heap_size == heap->capacity)
{
printf("\nOverflow: Could not insert key\n");
return;
}


// First insert the new key at the end
heap->heap_size++;
int i = heap->heap_size - 1;
heap->arr[i] = k;

// Fix the min heap property if it is violated
while (i != 0 && heap->arr[(i - 1) / 2] > heap->arr[i])
{
    swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
    i = (i - 1) / 2;
}
}

// Decreases value of key at index 'i' to new_val. It is assumed that
// new_val is smaller than arr[i].
void decrease_key(MinHeap* heap, int i, int new_val)
{
heap->arr[i] = new_val;
while (i != 0 && heap->arr[(i - 1) / 2] > heap->arr[i])
{
swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
i = (i - 1) / 2;
}
}

// Method to remove minimum element (or root) from min heap
int extract_min(MinHeap* heap)
{
if (heap->heap_size <= 0)
return INT_MAX;
if (heap->heap_size == 1)
{
heap->heap_size--;
return heap->arr[0];
}


// Store the minimum value, and remove it from heap
int root = heap->arr[0];
heap->arr[0] = heap->arr[heap->heap_size - 1];
heap->heap_size--;
min_heapify(heap, 0);

return root;
}

// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void delete_key(MinHeap* heap, int i)
{
decrease_key(heap, i, INT_MIN);
extract_min(heap);
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void min_heapify(MinHeap* heap, int i)
{
int l = 2 * i + 1;
int r = 2 * i + 2;
int smallest = i;
if (l < heap->heap_size && heap->arr[l] < heap->arr[i])
smallest = l;
if (r < heap->heap_size && heap->arr[r] < heap->arr[smallest])
smallest = r;
if (smallest != i)
{
swap(&heap->arr[i], &heap->arr[smallest]);
min_heapify(heap, smallest);
}
}

// A utility function to swap two elements
void swap(int* x, int* y)
{
int temp = *x;
*x = *y;
*y = temp;
}


