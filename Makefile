CC = gcc
CFLAGS = -O3
LDFLAGS = -lm

csort: main.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	-rm -f csort
