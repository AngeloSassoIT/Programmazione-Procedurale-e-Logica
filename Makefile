test: Makefile lista_dc.o test.o lista_dc.h
	gcc	-ansi	-Wall	-O	lista_dc.o test.o -o test -lm
lista_dc.o:	Makefile lista_dc.c lista_dc.h
	gcc	-ansi	-Wall	-c lista_dc.c -lm
test.o:	Makefile lista_dc.o test.c lista_dc.h
	gcc	-ansi	-Wall	-c	test.c	-lm
pulisci:
	rm -f *.o
pulisci_tutto:
	rm -f test *.o
