
all:
	g++ -fPIC -I /usr/include/python3.8 main.cpp -c
	g++ -L /lib64 -shared main.o -o main.so -I /usr/include/python3.8 -lpython3.8 -I /usr/include/boost/
