CC=g++ -std=c++11
OBJ=main.cpp DnaTranslator.cpp UnsignedToDna.cpp
DEPS=DnaTranslator.h UnsignedToDna.h
CONF=-g

%.o:%..cpp $(DEPS)
	$(CC) $(CONF) -c -o $@ $<

main:$(OBJ)
	$(CC) $(CONF) -o $@ $^

run:
	./main fugue.txt
