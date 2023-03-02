CFLAGS = -Werror -Wall -g -fsanitize=address undefined

run: task2
	./task2

task2: main.o str.o
	g++ ${CFLAGS} main.o str.o -o task2

main.o: main.cpp str.h
	g++ ${CFLAGS} -c main.cpp -o main.o

str.o: str.cpp str.h
	g++ ${CFLAGS} -c str.cpp -o str.o

clean:
	rm *.o task2

