#ifndef __STACK__
#define __STACK__

#include <stdbool.h>

typedef struct stack stack;

typedef void (*free_cb)(void *p);

typedef struct stack {
    int stack_pointer;
    int max_size;
    void **main_data;
    free_cb free;
} stack;

stack *stack_init(int stack_size);
void stack_set_callbacks(stack *s,
			 free_cb free);
bool stack_is_empty(stack *s);
bool stack_is_full(stack *s);
void stack_push(stack *s, void *p);
void *stack_pop(stack *s);
void *stack_top(stack *s);
void stack_destroy(stack *s);

#endif
