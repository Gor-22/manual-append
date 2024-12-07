CXX = g++
CXXFLAGS = -std=c++11

TARGET = manual-append

all: $(TARGET)

$(TARGET): manual-append.o
	$(CXX) $(CXXFLAGS) -o manual-append manual-append.o

manual-append.o: manual-append.cpp
	$(CXX) $(CXXFLAGS) -c manual-append.cpp

clean:
	rm -f manual-append.o manual-append
