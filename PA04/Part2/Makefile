
GCC = gcc  
CFLAGS =-g -Wall -Wshadow

cat-lite: cat.o
	$(GCC) $(CFLAGS) cat.o -o cat-lite

cat.o: cat-lite.c
	$(GCC) $(CFLAGS) -c cat-lite.c


make: cat
		
