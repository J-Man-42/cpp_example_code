# Variables and lists.
######################################################################
HEADERS := \
	linked_list.h \
	node.h \
	../move_cursor/move_cursor.h \
	../random/random.h
OBJECTS := \
	out/move_cursor.o \
	out/random.o
TEMPLATES := \
	linked_list.cpp \
	linked_list.h \
	node.cpp \
	node.h
UPDATES := out/ out/main.o $(OBJECTS) $(HEADERS)



# Commands.
######################################################################
main:  $(UPDATES)
	g++ -Wall out/main.o $(OBJECTS) -o main

out/main.o:  main.cpp $(TEMPLATES)
	g++ -Wall -c main.cpp -o out/main.o

out/move_cursor.o:  ../move_cursor/move_cursor.cpp ../move_cursor/move_cursor.h
	g++ -Wall -c ../move_cursor/move_cursor.cpp -o out/move_cursor.o

out/random.o:  ../random/random.cpp ../random/random.h
	g++ -Wall -c ../random/random.cpp -o out/random.o

out/:
	mkdir -p out

run:  main
	./main

output:  main
	./main > output.txt

clean:
	rm -rf out main output.txt