CC	= gcc
CFLAGS	= -Wall -O0 -g
TEST	= exec_stack_test
LIBRARY	= libstack.a

all: $(TEST) $(LIBRARY)

stack.o:
	$(CC) $(CFLAGS) stack.c -c

$(TEST): stack.o
	$(CC) $(CFLAGS) test_stack.c $^ -o $@

$(LIBRARY): stack.o
	ar rs $@ $<

.phony: test clean

test: $(TEST)
	@./$(TEST) > /dev/null && echo "Success when the value is zero >>> $$?"

clean:
	@rm -rf *.o $(TEST) $(TEST).dSYM $(LIBRARY)
