# Compiler and flags
CC = gcc
CFLAGS = -Wall

# Targets
all: cook waiter customer

# Rule to compile cook.c
cook: cook.c sharedMemory.c sharedMemory.h
	$(CC) $(CFLAGS) -o cook cook.c sharedMemory.c

# Rule to compile waiter.c
waiter: waiter.c sharedMemory.c sharedMemory.h
	$(CC) $(CFLAGS) -o waiter waiter.c sharedMemory.c

# Rule to compile customer.c
customer: customer.c sharedMemory.c sharedMemory.h
	$(CC) $(CFLAGS) -o customer customer.c sharedMemory.c

# Rule to clean up compiled binaries
clean:
	-rm -f cook waiter customer gencustomers

# Phony targets (not actual files)
.PHONY: all db clean