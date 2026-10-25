CC=g++

all: main.o address.o credit_card.o person.o product.o store.o transaction.o
	$(CC) -std=c++11 main.o address.o credit_card.o person.o product.o store.o transaction.o

main: main.o
	$(CC) -c -std=c++11 main.cpp

person: person.cpp
	$(CC) -c -std=c++11 person.cpp
 
store: store.cpp
	$(CC) -c -std=c++11 store.cpp
 
credit_card: credit_card.cpp
	$(CC) -c -std=c++11 credit_card.cpp
 
address: address.cpp
	$(CC) -c -std=c++11 address.cpp
 
product: product.cpp
	$(CC) -c -std=c++11 product.cpp
 
transaction: transaction.cpp
	$(CC) -c -std=c++11 transaction.cpp
 
clean:
	rm *.o *.out
