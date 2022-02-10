CXXFLAGS=-Wall
DEPS=Makefile
EXE=utf8chars locale

all: $(EXE)

locale: locale.cpp $(DEPS)
	$(CXX) locale.cpp -o $@

utf8chars: utf8chars.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) utf8chars.cpp -o $@

clean:
	rm $(EXE)
