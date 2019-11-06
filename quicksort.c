#include "quicksort.h"
#include "stack.h"
#include <stdint.h>

int partition(uint32_t a[], int32_t low, int32_t high) {
  uint32_t pivotValue = a[(low + high) / 2];

  int32_t i = low - 1;
  int32_t j = high + 1;
  do {
    do {
      i += 1;
      compares += 1;
    } while (a[i] < pivotValue);
    do {
      j -= 1;
      compares += 1;
    } while (a[j] > pivotValue);
    if (i < j) {
      SWAP(a[i], a[j]);
    }
  } while (i < j);
  return j;
}

void quickSortI(uint32_t a[], int left, int right) {
  stack *s = newStack();

  push(s, left);
  push(s, right);
  while (!empty(s)) {
    int high = pop(s);
    int low = pop(s);
    int p = partition(a, low, high);
    if (p + 1 < high) {
      push(s, p + 1);
      push(s, high);
    }
    if (low < p) {
      push(s, low);
      push(s, p);
    }
  }
  delStack(s);
  return;
}

void qSortI(uint32_t a[], int length) { quickSortI(a, 0, length - 1); }
