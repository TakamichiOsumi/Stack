#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack *
stack_init(int stack_size){
    stack *s;

    if (stack_size <= 0){
	printf("Detect invalid stack size = %d\n",
	       stack_size);
	exit(-1);
    }

    s = (stack *) malloc(sizeof(stack));
    if (s == NULL){
	perror("malloc");
	exit(-1);
    }

    s->stack_pointer = 0;
    s->max_size = 0;

    s->main_data = (void **) malloc(sizeof(void *) * stack_size);
    if (s->main_data == NULL){
	perror("malloc");
	exit(-1);
    }

    return s;
}

bool
stack_is_full(void){
    return true;
}

void
stack_push(void *p){}

void *
stack_pop(void){
    return NULL;
}

void *
stack_top(void){
    return NULL;
}
