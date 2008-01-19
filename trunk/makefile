all: bdmd

clean:
	\rm *.o bdmd
	
bdmd:   bdmd.cpp add.o sub.o mlt.o div.o Student.o vkit.o vkit.h Student.h
	g++ bdmd.cpp add.o sub.o mlt.o div.o Student.o vkit.o -o bdmd

add.o:     add.cpp Student.h vkit.h 
	g++ -c add.cpp -o add.o

sub.o:     sub.cpp Student.h vkit.h
	g++ -c sub.cpp -o sub.o

mlt.o:     mlt.cpp Student.h vkit.h
	g++ -c mlt.cpp -o mlt.o

div.o:     div.cpp Student.h vkit.h
	g++ -c div.cpp -o div.o

Student.o: Student.cpp Student.h
	g++ -c Student.cpp -o Student.o

vkit.o:    vkit.cpp vkit.h Student.h
	g++ -c vkit.cpp -o vkit.o
