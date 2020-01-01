CC=g++
CXXFLAGS=-g -std=c++11 -stdlib=libc++ -lgtest

ALL_DEPS = word_iterator.h
OBJ = main.o word_iterator.o

%.o: %.c $(ALL_DEPS)
	$(CC) -c -o $@ $< $(CXXFLAGS)

mylibrary: $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS)
