SYSTYPE=UNIX
OBJFORMAT=elf32

CC=gcc
CFLAGS+=-m32 -Wall -g -O2 -W

all: task6

function.o: function.asm
	nasm -g -f $(OBJFORMAT) $< -o $@ -D$(SYSTYPE)

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

root.o: root.c
	$(CC) $(CFLAGS) -c $< -o $@

integral.o: integral.c
	$(CC) $(CFLAGS) -c $< -o $@

testroot.o: testroot.c
	$(CC) $(CFLAGS) -c $< -o $@

testintegral.o: testintegral.c
	$(CC) $(CFLAGS) -c $< -o $@

task6: function.o main.o root.o integral.o testroot.o testintegral.o
	$(CC) $(CFLAGS) $^ -lm -o $@

.PHONY: clean

clean:
	-rm -rf *.o



