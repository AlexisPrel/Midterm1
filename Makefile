# Makefile for Midterm I project

CC = clang
CFLAGS = -Wall -O0 -g
LFLAGS = -O0 -g
LIBS = -lm

main1: main1.c pi_leibniz.o pi_bbp.o 
	${CC} $(LFLAGS) -o main1 main1.c pi_leibniz.o pi_bbp.o ${LIBS}

main1.c pi_leibniz.o pi_bbp.o: pi_funs.h precision_timer_leibniz.c precision_timer_bbp.c

clean:
	rm -f *.o

veryclean: clean
	rm -f main1
