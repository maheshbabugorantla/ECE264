
GCC = gcc  
CFLAGS =-g -Wall -Wshadow

echo-lite: echo.o
	$(GCC) $(CFLAGS) echo.o -o echo-lite

echo.o: echo.c
	$(GCC) $(CFLAGS) -c echo.c


make: echo
		
