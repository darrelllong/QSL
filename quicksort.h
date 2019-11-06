# ifndef _QUICKSORT_H
# define _QUICKSORT_H

# ifndef SWAP
# define SWAP(x, y)     { uint32_t t = x; x = y; y = t; }
# endif

void qSortI(uint32_t a[], int length);

# endif
