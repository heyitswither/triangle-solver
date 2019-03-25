CFLAGS=-Og -g -Wall -std=gnu11 -Werror -march=native -I./include -DDEBUG -pedantic
CC=gcc
OBJS=main.o id.o verify.o solve.o

notarget: solver

solver: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o solver

clean:
	$(RM) -r $(OBJS) solver solver.dSYM
