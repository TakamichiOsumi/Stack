#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack *
stack_init(int stack_size){
    stack *s;

    if (stack_size <= 0){
	printf("detect invalid stack size = %d\n",
	       stack_size);
	exit(-1);
    }

    s = (stack *) malloc(sizeof(stack));
    if (s == NULL){
	perror("malloc");
	exit(-1);
    }

    s->stack_pointer = 0;
    s->max_size = stack_size;

    s->main_data = (void **) malloc(sizeof(void *) * stack_size);
    if (s->main_data == NULL){
	perror("malloc");
	exit(-1);
    }

    s->free = NULL;

    return s;
}

void
stack_set_callbacks(stack *s, free_cb free){
    s->free = free;
}

bool
stack_is_empty(stack *s){
    return s->stack_pointer == 0;
}

bool
stack_is_full(stack *s){
    return s->stack_pointer >= s->max_size;
}

void
stack_push(stack *s, void *p){
    if (stack_is_full(s)){
	printf("stack is full. failed to push\n");
	return;
    }

    s->main_data[s->stack_pointer++] = p;
}

void *
stack_pop(stack *s){
    void *p;

    if (stack_is_empty(s)){
	printf("stack is empty. failed to pop\n");
	return NULL;
    }

    p = s->main_data[s->stack_pointer - 1];
    s->stack_pointer--;

    return p;
}

void *
stack_top(stack *s){
    if (stack_is_empty(s)){
	printf("stack is empty. failed to return the reference\n");
	return NULL;
    }

    return s->main_data[s->stack_pointer - 1];
}

void
stack_destroy(stack *s){
    int i;

    if (s == NULL)
	return;

    if (!s->free){
	printf("internal free callback is missing\n");
	return;
    }

    for (i = 0; i < s->stack_pointer; i++){
	s->free(s->main_data[i]);
    }

    s->stack_pointer = 0;
    s->max_size = 0;
    free(s->main_data);
    s->main_data = NULL;
    free(s);
}
