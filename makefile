CC=clang++
CXXFLAGS=-g -std=c++14 -stdlib=libc++ 
LD_FLAGS = -lgtest -l pthread

DEPS=word_iterator.h zip_iterator.h
OBJ=main.o word_iterator.o zip_iterator.o word_iterator_test.o zip_iterator_test.o
TARGET=mylibrary

%.o: %.cpp $(DEPS)
	$(CC) -o $@ -c $< $(CXXFLAGS) -I.

$(TARGET): $(OBJ)
	$(CC) -o $@  $^ $(CXXFLAGS) $(LD_FLAGS)

clean:
	rm *.o $(TARGET)
