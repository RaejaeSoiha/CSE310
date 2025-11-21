# CSE_310_Project_01

Hash Table Encoder

Description:
This program implements a hash table to encode a list of words into slots based on their hash values. It then prints the contents of each slot, their lengths, and calculates the standard variance of the slot lengths.

To compile and run the encoder program, follow these steps:

1. Make sure you have a C++ compiler installed on your system.

2. Download the provided files: main.cpp, hash.cpp, hash.h.

3. Open a terminal and navigate to the directory containing the downloaded files.

4. Compile the program by running the following command:
   g++ -o encoder main.cpp hash.cpp    or   if you want to use make feel free to use. that program work both method worked.
5. Run the program using the following command:
   ./encoder < inputs/sample_input.txt



Usage:
1. Compile the program using the provided Makefile.
2. Run the compiled executable 'encoder' with the desired input file as standard input.
   Example: ./encoder <inputs/sample_input.txt The program will read the input from sample_input.txt, process it, and print the output to the terminal.

    ==== Printing the contents of the first 5 slots ====
Slot 0: Amazon apple Applebee abandon 
Slot 1: Boeing banana boring barbaric 
Slot 2: 
Slot 3: 
Slot 4: elephant  
==== Printing the slot lengths ====
Slot 0: 4
Slot 1: 4
Slot 2: 0
Slot 3: 0
Slot 4: 1
==== Printing the standard variance ====
1.22726

if you want to test another file you can run by ./encoder <inputs/file_name.tx

   - Ensure that the input file contains a list of words separated by spaces or newline characters.

Files:
- main.cpp: Contains the main logic of the program, including the hash table implementation and output functions.
- hash.h: Header file containing the declarations of functions and structs used in main.cpp.
- hash.cpp: Source file containing the definitions of functions declared in hash.h.
- Makefile: Makefile for compiling the program.

Compilation:
To compile the program, simply run 'make' in the terminal. This will generate an executable named 'encoder'.

Note:
- The program currently does not support words with spaces within them.
- The hash function and collision resolution method used can be found in hash.cpp.
- Ensure that the input file exists and is properly formatted before running the program.

Author:
Raejae Soiha
