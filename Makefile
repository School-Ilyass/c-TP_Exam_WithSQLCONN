# Define compiler flags
CFLAGS = -lmysqlcppconn
all: main

main:main.cpp
	g++ main.cpp -o main $(CFLAGS) && ./main

clean: 
	echo " Cleaning Files "
	rm ./main

read:main
	./main
