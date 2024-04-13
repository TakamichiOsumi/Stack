#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

static void
test_dump_stack(stack *s){
    int i;

    printf("-----\n");
    for (i = 0; i < s->stack_pointer; i++){
	printf("%d : %p\n", i,
	       s->main_data[i]);
    }
    printf("-----\n");
}

static void
test_basic_operations(void){
    stack *s;

    s = stack_init(5);
    stack_push(s, (void *) 1);
    stack_push(s, (void *) 2);
    stack_push(s, (void *) 3);
    stack_push(s, (void *) 4);
    stack_push(s, (void *) 5);
    stack_push(s, (void *) 6);
    stack_push(s, (void *) 7);

    assert(stack_is_full(s));
    assert(stack_top(s) == (void *) 5);

    test_dump_stack(s);

    assert(stack_pop(s) == (void *) 5);
    assert(stack_top(s) == (void *) 4);
    assert(stack_pop(s) == (void *) 4);
    assert(stack_pop(s) == (void *) 3);
    assert(stack_pop(s) == (void *) 2);
    assert(stack_pop(s) == (void *) 1);
    assert(stack_pop(s) == NULL);

    test_dump_stack(s);

    printf("All tests are done gracefully.\n");
}

int
main(int argc, char **argv){

    test_basic_operations();

    return 0;
}
