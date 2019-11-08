CXX = g++
CXXFLAGS = -Wall -g

OBJECTS = action.o battle.o item.o main.o pokemon.o pokemon_enums.o team_build.o trainer.o
EXEC = battle

all: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJECTS)

clean:
	rm *.o; r, battle	
