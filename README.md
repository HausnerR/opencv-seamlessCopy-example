g++ -g3 -Wall -I/usr/local/include -std=c++0x -c -o test.o test.cpp
g++ `pkg-config --libs opencv --static` -o test test.o


g++ -g3 -Wall -I/usr/local/include `pkg-config --libs opencv --static` -std=c++0x -o test test.cpp
