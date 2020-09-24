all: p1 p2 p3

p1: p1.c
	gcc -Wall  -o p1 p1.c -lm
p2: p2.c
	gcc -Wall  -o p2 p2.c -lm
p3: p3.c
	gcc -Wall  -o p3 p3.c -lm

clean: 
	rm -fr *~  p1 p2 p3