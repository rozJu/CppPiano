EXEC=exe
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
CC = g++ -std=c++11 -g
CLIBS= -L/usr/local/include/SFML -lsfml-graphics  -lsfml-window -lsfml-system -lsfml-audio
INCDIR=-I/usr/local/include/SFML
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) $(CLIBS)  -o $(EXEC)
%.o: %.cpp
	$(CC) -Wall $(INCDIR)  -c $< -o $@

.depend: $(SOURCES)
	g++ -std=c++11 -MM $(SOURCES) > .depend
-include .depend
clean:
	rm -f $(OBJECTS) $(EXEC)
