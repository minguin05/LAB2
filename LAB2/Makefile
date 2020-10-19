calculate : main.o ./lib/add.o ./lib/subtract.o ./lib/devide.o ./lib/multiply.o
	gcc -o calculate main.o ./lib/add.o ./lib/subtract.o ./lib/devide.o ./lib/multiply.o -I./lib -L./lib

main.o : main.c
	gcc -c main.c -I./lib

./lib/add.o : ./lib/add.c
	gcc -c ./lib/add.c

./lib/devide.o : ./lib/devide.c
	gcc -c ./lib/devide.c

./lib/multiply.o : ./lib/multiply.c
	gcc -c ./lib/multiply.c

./lib/subtract.o : ./lib/subtract.c
	gcc -c ./lib/subtract.c

clean :
	rm -f calculate main.o ./lib/add.o ./lib/subtract.o ./lib/devide.o ./lib/multiply.o
