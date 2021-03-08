Programa: circle.o triangle.o rectangle.o
	g++ circle.o triangle.o rectangle.o main.cpp -o figuras.exe
	make clean

circle.o: circle.cpp circle.h
	g++ -c circle.cpp

triangle.o: triangle.cpp triangle.h
	g++ -c triangle.cpp

rectangle.o: rectangle.cpp rectangle.h
	g++ -c rectangle.cpp

clean: circle.o triangle.o rectangle.o
	rm circle.o triangle.o rectangle.o