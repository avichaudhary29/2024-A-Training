#include <iostream>
#include <vector>
#include <list>

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    std::vector<std::list<std::pair<int, int>>> table;

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {
        table.resize(TABLE_SIZE);
    }

    void insert(int key, int value) {
        int index = hashFunction(key);
        table[index].push_back(std::make_pair(key, value));
    }

    int search(int key) {
        int index = hashFunction(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return -1; // Key not found
    }

    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove_if([key](const std::pair<int, int>& pair) {
            return pair.first == key;
        });
    }
};

int main() {
    HashTable ht;

    ht.insert(1, 100);
    ht.insert(11, 200);
    ht.insert(21, 300);

    std::cout << "Value at key 1: " << ht.search(1) << std::endl; // Should print 100
    std::cout << "Value at key 11: " << ht.search(11) << std::endl; // Should print 200
    std::cout << "Value at key 21: " << ht.search(21) << std::endl; // Should print 300

    ht.remove(11);
    std::cout << "Value at key 11 after removal: " << ht.search(11) << std::endl; // Should print -1

    return 0;
}
