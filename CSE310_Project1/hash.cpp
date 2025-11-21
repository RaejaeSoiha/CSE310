#include <iostream>
#include <string>
#include <cmath>
#include "hash.h"

int hash_function(const std::string &text) {
    // A simple hash function that sorts strings based on the first letter
    char first_letter = std::tolower(text[0]); // Convert to lowercase for uniformity
    if (std::isalpha(first_letter)) {
        return first_letter - 'a';
    } else {
        // Default case for non-alphabetic characters
        return 0;
    }
}

void insert(Node** hash_table, const std::string &text, int index) {
    Node* newNode = new Node(text);
    if (hash_table[index] == nullptr) {
        hash_table[index] = newNode;
    } else {
        // Handle collision by chaining
        Node* current = hash_table[index];
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void print_hash_table(Node** hash_table, int k) {
    for (int i = 0; i < k; ++i) {
        std::cout << "Slot " << i << ": ";
        Node* current = hash_table[i];
        while (current != nullptr) {
            std::cout << current->text << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}

void print_slot_lengths(Node** hash_table, int k) {
    for (int i = 0; i < k; ++i) {
        int length = 0;
        Node* current = hash_table[i];
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        std::cout << "Slot " << i << ": " << length << std::endl;
    }
}

double standard_deviation(Node** hash_table, int k) {
    double sum = 0;
    double mean = 0;
    int total_lengths = 0;

    // Calculate the total sum of slot lengths
    for (int i = 0; i < k; ++i) {
        Node* current = hash_table[i];
        while (current != nullptr) {
            sum += current->text.length();
            total_lengths++;
            current = current->next;
        }
    }

    // Calculate the mean slot length
    mean = sum / total_lengths;

    // Calculate the sum of squared differences from the mean
    double squared_diff_sum = 0;
    for (int i = 0; i < k; ++i) {
        Node* current = hash_table[i];
        while (current != nullptr) {
            double diff = current->text.length() - mean;
            squared_diff_sum += diff * diff;
            current = current->next;
        }
    }

    // Calculate the standard deviation
    double variance = squared_diff_sum / total_lengths;
    return std::sqrt(variance);
}
