CC=g++

all: main.o address.o credit_card.o person.o product.o store.o transaction.o
	$(CC) -std=c++11 main.o address.o credit_card.o person.o product.o store.o transaction.o

main.o: main.cpp
	$(CC) -c -std=c++11 main.cpp

person.o: person.cpp
	$(CC) -c -std=c++11 person.cpp
 
store.o: store.cpp
	$(CC) -c -std=c++11 store.cpp
 
credit_card.o: credit_card.cpp
	$(CC) -c -std=c++11 credit_card.cpp
 
address.o: address.cpp
	$(CC) -c -std=c++11 address.cpp
 
product.o: product.cpp
	$(CC) -c -std=c++11 product.cpp
 
transaction.o: transaction.cpp
	$(CC) -c -std=c++11 transaction.cpp
 
clean:
	rm *.o *.out
