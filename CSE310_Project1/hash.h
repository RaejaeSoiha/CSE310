#ifndef HASH_H
#define HASH_H

#include <string>

struct Node {
    std::string text;
    Node* next;
    Node(const std::string &text, Node *next = nullptr) : text(text), next(next) {}
};

int hash_function(const std::string &text);

void insert(Node** hash_table, const std::string &text, int index);

void print_hash_table(Node** hash_table, int k);

void print_slot_lengths(Node** hash_table, int k);

double standard_deviation(Node** hash_table, int k);

#endif
