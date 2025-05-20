//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char* element;
    int count;
} HashTable;

void createHashTable(HashTable* table) {
    for (int i = 0; i < MAX_SIZE; i++) {
        table[i].element = NULL;
        table[i].count = 0;
    }
}

int hashFunction(char* key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }
    return sum % MAX_SIZE;
}

void insertElement(HashTable* table, char* element) {
    int index = hashFunction(element);
    if (table[index].element == NULL) {
        table[index].element = element;
        table[index].count = 1;
    } else {
        table[index].count++;
    }
}

void traverseHashTable(HashTable* table) {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (table[i].element!= NULL) {
            printf("Key: %s, Count: %d\n", table[i].element, table[i].count);
        }
    }
}

int main() {
    HashTable table;
    createHashTable(&table);

    insertElement(&table, "apple");
    insertElement(&table, "banana");
    insertElement(&table, "orange");
    insertElement(&table, "apple");

    traverseHashTable(&table);

    return 0;
}