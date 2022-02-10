CXXFLAGS=-Wall
DEPS=Makefile
EXE=utf8chars

all: $(EXE)

utf8chars: utf8chars.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) utf8chars.cpp -o $@

clean:
	rm $(EXE)
