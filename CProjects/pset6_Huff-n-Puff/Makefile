#
# Makefile
#
# Computer Science 50
# Problem Set 6
#


# compiler to use
CC = clang

# flags to pass compiler
CFLAGS = -ggdb -O0 -Qunused-arguments -std=c99 -Wall -Werror

# dump
DUMP = dump
DUMP_SRCS = dump.c forest.c huffile.c tree.c
DUMP_OBJS = $(DUMP_SRCS:.c=.o)

# space-separated list of header files
HDRS = forest.h huffile.h tree.h

# space-separated list of libraries, if any,
# each of which should be prefixed with -l
LIBS = -lm

# target
$(DUMP): $(DUMP_OBJS) $(HDRS)
	$(CC) $(CFLAGS) -o $@ $(DUMP_OBJS) $(LIBS)

# housekeeping
clean:
	rm -f core $(DUMP) *.o

puff:
	$(CC) $(CFLAGS) puff.c -o puff forest.c huffile.c tree.c
huff:
	$(CC) $(CFLAGS) huff.c -o huff forest.c huffile.c tree.c
