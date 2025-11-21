all: Main.o Graph.o Edge.o Vertex.o 
	g++ -g -Wall Main.o Graph.o Edge.o Vertex.o -o dijkstra

Main.o: Main.cpp Graph.h
	g++ -g -Wall -c Main.cpp

Graph.o: Graph.cpp Graph.h
	g++ -g -Wall -c Graph.cpp

Edge.o: Edge.cpp Edge.h
	g++ -g -Wall -c Edge.cpp

Vertex.o: Vertex.cpp Vertex.h
	g++ -g -Wall -c Vertex.cpp

# Clean up inetermediate files and executable
# For the make use this line 	
clean:
	rm -f *.o dijkstra


# Windows system use this line
#clean:
#	del *.o dijkstra.exe
