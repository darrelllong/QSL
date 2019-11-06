#include "stack.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

stack *newStack() {
  stack *s = (stack *) calloc(MIN_STACK, sizeof(stack));
  if (s) {
    s->size = MIN_STACK;
    s->top = 0;
    s->entries = (item *) calloc(MIN_STACK, sizeof(item));
    if (s->entries) {
      return s;
    }
  }
  return (stack *)0;
}

void delStack(stack *s) {
  if (s->entries) {
    free(s->entries);
  }
  if (s) {
    free(s);
  }
  return;
}

item pop(stack *s) {
  if (s && s->top > 0) {
    s->top -= 1;
    return s->entries[s->top];
  }
  return INVALID;
}

void push(stack *s, item i) {
  if (s) {
    if (s->top == s->size) {
      s->size *= 2;
      s->entries = (item *) realloc(s->entries, s->size * sizeof(item));
    }
    s->entries[s->top] = i;
    s->top += 1;
  }
  return;
}

bool empty(stack *s) { return s->top == 0; }
