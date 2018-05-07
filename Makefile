CCX=g++ -std=c++11


a.out: Board.o Index.o play.o Exceptions.o 
		$(CCX) main.cpp *.o
		
Board.o: Board.cpp Board.h
		$(CCX) -c Board.cpp
		
Index.o: Index.cpp Index.h
		$(CCX) -c Index.cpp
		
play.o: play.cpp play.hpp
		$(CCX) -c play.cpp

Exceptions.o: Exceptions.cpp Exceptions.hpp
		$(CCX) -c Exceptions.cpp
		
Clean:
		rm *.o a.out
