#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void
test_basic_operations(void){
    stack *s;

    s = stack_init(64);

    printf("All tests are done gracefully.\n");
}

int
main(int argc, char **argv){

    test_basic_operations();

    return 0;
}
