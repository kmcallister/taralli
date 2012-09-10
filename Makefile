LDFLAGS= -L/usr/local/lib -lX11 -lXi
CFLAGS=	-I/usr/local/include -O2 -Wall -Wextra -std=c99 -pedantic

taralli_rectangular: taralli_rectangular.o main.o
	$(CC) $(LDFLAGS) -o taralli_rectangular taralli_rectangular.o main.o

taralli_rectangular.o: map_rectangular.c
	$(CC) $(CFLAGS) -c -o taralli_rectangular.o map_rectangular.c 

main.o: main.c
	$(CC) $(CFLAGS) -c -o main.o main.c

clean:
	rm -f *.o taralli_rectangular
