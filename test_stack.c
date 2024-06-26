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

/* The test data won't allocate any data. */
static void
test_free_cb(void *p){}

static void
test_basic_operations(void){
    stack *s;

    s = stack_init(5);

    stack_set_callbacks(s, test_free_cb);

    assert(stack_is_empty(s));
    assert(stack_top(s) == NULL); /* top() */
    stack_push(s, (void *) 1);
    stack_push(s, (void *) 2);
    stack_push(s, (void *) 3);
    stack_push(s, (void *) 4);
    stack_push(s, (void *) 5);
    stack_push(s, (void *) 6);
    stack_push(s, (void *) 7);
    assert(stack_top(s) == (void *) 5); /* top() */
    assert(stack_is_full(s));

    test_dump_stack(s);

    assert(stack_pop(s) == (void *) 5);
    assert(stack_top(s) == (void *) 4); /* top() */
    assert(stack_pop(s) == (void *) 4);
    assert(stack_pop(s) == (void *) 3);
    assert(stack_pop(s) == (void *) 2);
    assert(stack_top(s) == (void *) 1); /* top() */
    assert(stack_pop(s) == (void *) 1);
    assert(stack_pop(s) == NULL);
    assert(stack_is_empty(s));

    test_dump_stack(s);

    stack_destroy(s);
}

int
main(int argc, char **argv){

    test_basic_operations();

    printf("All tests are done gracefully.\n");

    return 0;
}
