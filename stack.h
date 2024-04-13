#ifndef __STACK__
#define __STACK__

#include <stdbool.h>

typedef struct stack {
    int stack_pointer;
    int max_size;
    void **main_data;
} stack;

stack *stack_init(int stack_size);
bool stack_is_empty(void);
bool stack_is_full(void);
void stack_push(void *p);
void *stack_pop(void);
void *stack_top(void);

#endif
