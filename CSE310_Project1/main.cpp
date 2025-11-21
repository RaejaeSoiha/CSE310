/*
CSE 310 Hash Function DIY Contest
Instructor: Yiran "Lawrence" Luo
Your name: Raejae Soiha
Your team alias: 
*/

#include <iostream>
#include <string>
#include "hash.h"

int main() {
    int k = 0;
    int n = 0;
    std::string texts[500];

    // WARNING: Start of the tokenizer that loads the input from std::cin, DO NOT change this part!
    std::cin >> k;
    std::string line;
    std::getline(std::cin, line);

    while (std::getline(std::cin, line)) {
        texts[n] = line;
        n++;
    }
    // WARNING: End of the tokenizer, DO NOT change this part!

    // By this point, k is the # of slots, and n is the # of tokens to fit in
    // texts[] stores the input sequence of tokens/keys to be inserted into your hash table

    // Your time to shine starts now

    Node** hash_table = new Node*[k]; // Declare hash table

    // Initialize hash table
    for (int i = 0; i < k; ++i) {
        hash_table[i] = nullptr;
    }

    // Insert words into hash table
    for (int i = 0; i < n; ++i) {
        int index = hash_function(texts[i]) % k; // Get hash index
        insert(hash_table, texts[i], index); // Insert word into hash table
    }

    // Print hash table contents
    std::cout << "==== Printing the contents of the first 5 slots ====" << std::endl;
    print_hash_table(hash_table, k);

    // Print slot lengths
    std::cout << "==== Printing the slot lengths ====" << std::endl;
    print_slot_lengths(hash_table, k);

    // Print standard deviation
    std::cout << "==== Printing the standard variance ====" << std::endl;
    std::cout << standard_deviation(hash_table, k) << std::endl;

    // Clean up memory
    delete[] hash_table;

    return 0;
}
