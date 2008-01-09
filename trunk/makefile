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


#--------------------------------------------------
# bdmd.o: bdmd.cpp Student.h vkit.h add.o sub.o mlt.o Student.o vkit.o
# 	g++ -Wno-write-strings bdmd.cpp add.o sub.o mlt.o Student.o vkit.o -o bdmd.o
# 
# add.o: add.cpp Student.h
# 	g++ -Wno-write-strings -c add.cpp -o add.o
# 
# sub.o: sub.cpp Student.h
# 	g++ -Wno-write-strings -c sub.cpp -o sub.o
# 
# mlt.o: mlt.cpp Student.h
# 	g++ -Wno-write-strings -c mlt.cpp -o mlt.o
# 
# Student.o: Student.cpp Student.h vkit.h
# 	g++ -Wno-write-strings -c Student.cpp -o Student.o
# 
# vkit.o: vkit.cpp vkit.h
# 	g++ -Wno-write-strings -c vkit.cpp -o vkit.o
#-------------------------------------------------- 
