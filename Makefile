all: Room.o Reservation.o Date.o Hotel.o main

main : main.cc Room.o Reservation.o Date.o Hotel.o
	g++ -o a1 main.cc Room.o Reservation.o Date.o Hotel.o

Room.o: Room.h Room.cc
	g++ -c Room.cc

Reservation.o: Reservation.h Reservation.cc
	g++ -c Reservation.cc

Date.o:	Date.h Date.cc
	g++ -c Date.cc

Hotel.o: Hotel.h Hotel.cc
	g++ -c Hotel.cc

clean:
	rm -f a1 *.o
