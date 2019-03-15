CFLAGS=-Og -g -Wall -Wpedantic -Werror -march=native -I./include
CC=gcc
OBJS=main.o id.o verify.o solve.o

notarget: solver

solver: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o solver

clean:
	$(RM) -r $(OBJS) solver solver.dSYM
