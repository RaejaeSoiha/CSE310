Name: Raejae Soiha
CSE 310
Professor: Yiran "Lawrence" Luo
Date: 04/20/2024


# Dijkstra's Shortest Path Algorithm Implementation

This program implements Dijkstra's shortest path algorithm to find the shortest paths from odd-degree vertices in a graph.

## How to Run

1. **Compile the Code:**
   - Make sure you have `g++` installed on your system.
   - Open a terminal and navigate to the directory containing the source code files (`Main.cpp`, `Graph.cpp`, `Edge.cpp`, `Vertex.cpp`, `Graph.h`, `Edge.h`, `Vertex.h`, `Makefile`).
   - Run the following command to compile the code: on Mac and Linux and Windows system.
     ```
     make
     ```

2. **Execute the Program:**
   - After successful compilation, execute the program by running the following command:
     ```
     ./dijkstra
     ```

   - You will be prompted to enter the graph details through the terminal. Input the number of vertices and edges, followed by the edge connections as described in the prompt.
   WARNING: for windows machine system Example: copy number from input_file.txt and past on here

   NOTE: if you execute the program on Mac or Linux machine system 
         run commend 
         ./dijkstra < small-networt.txt

         if you are no windowns machine system
         ./dijkstra small-network.txt or  Get-Content small-network.txt | .\dijkstra

3. **View the Output:**
   - The program will generate the adjacency matrix of the loaded graph, list the odd degree vertices, and display the shortest path lengths from each odd-degree vertex.

   Output display: Example 
The adjacency matrix of G:
 0  1  0  1  1  0  0  0 
 1  0  1  1  0  0  0  0 
 0  1  0  1  1  1  0  0 
 1  1  1  0  0  0  0  0 
 1  0  1  0  0  0  0  0 
 0  0  1  0  0  0  1  1 
 0  0  0  0  0  1  0  1 
 0  0  0  0  0  1  1  0 

    The odd degree vertices in G:
O = { 1 2 4 6 }

Single source shortest path lengths from node 1
  1: 0
  2: 1
  3: 2
  4: 1
  5: 1
  6: 3
  7: 4
  8: 4

Single source shortest path lengths from node 2
  1: 1
  2: 0
  3: 1
  4: 1
  5: 2
  6: 2
  7: 3
  8: 3

Single source shortest path lengths from node 4
  1: 1
  2: 1
  3: 1
  4: 0
  5: 2
  6: 2
  7: 3
  8: 3

Single source shortest path lengths from node 6
  1: 3
  2: 2
  3: 1
  4: 2
  5: 2
  6: 0
  7: 1
  8: 1





WARMING:
    After run the project you can clean all .o file if you don't need it. to clean that file you need to use comment $make clean
    This project desinge on MAC OS system and Linux. However if you run on windows mechaine please change the Makefile clean: del *.o encoders otherwhile you are not able to $make clean.


Mac and Linux version Makefile

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
clean:
	rm -f *.o dijkstra




Windows machine version

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

# Windows system use this line
clean:
	del *.o dijkstra.exe