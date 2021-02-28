all:
	gcc  date.c code.c move.c key.c  main.c -g -o robot -lm -lpthread
