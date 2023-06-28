#ifndef HASH_H
#define HASH_H

#include <iostream>
#include "vector.h"
#include "list.h"
#include "pair.h"

template<typename KeyType, typename ValueType>
class HashTable {
private:
    Vector<List<Pair<KeyType, ValueType>>> table;
    int size;

public:
    HashTable(int tableSize) : size(tableSize) {
        table.resize(size);
    }

    int hashFunction(KeyType key) {
        // Implement your custom hash function here
        // For demonstration purposes, we'll use a simple hash function
        return static_cast<int>(key) % size;
    }

    void insert(KeyType key, ValueType value) {
        int index = hashFunction(key);
        table[index].push_back(std::make_pair(key, value));
    }

    bool search(KeyType key) {
        int index = hashFunction(key);
        std::list<std::pair<KeyType, ValueType>>& bucket = table[index];
        for (const auto& element : bucket) {
            if (element.first == key) {
                return true;
            }
        }
        return false;
    }

    void remove(KeyType key) {
        int index = hashFunction(key);
        std::list<std::pair<KeyType, ValueType>>& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                break;
            }
        }
    }

    void printTable() {
        for (int i = 0; i < size; ++i) {
            std::cout << "Bucket " << i << ": ";
            for (const auto& element : table[i]) {
                std::cout << "(" << element.first << ", " << element.second << ") ";
            }
            std::cout << std::endl;
        }
    }
};

#endif