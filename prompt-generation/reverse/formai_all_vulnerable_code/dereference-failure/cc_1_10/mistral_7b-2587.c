//MISTRAL-7B DATASET v1.0 Category: Cryptographic hash function ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASH_SIZE 10

typedef struct HashTable {
    int data[HASH_SIZE];
    int index;
} HashTable;

HashTable* createHashTable() {
    HashTable* table = malloc(sizeof(HashTable));
    table->index = 0;
    memset(table->data, -1, HASH_SIZE * sizeof(int));
    return table;
}

unsigned int hashFunction(char* str, int len) {
    unsigned int hash = 0;
    for (int i = 0; i < len; i++) {
        hash += str[i];
    }
    return hash % HASH_SIZE;
}

void addToHashTable(HashTable* table, char* str, int len) {
    int index = hashFunction(str, len) % HASH_SIZE;
    while (table->data[index] != -1) {
        index++;
        if (index >= HASH_SIZE) {
            index = 0;
        }
    }
    strcpy(table->data[index], str);
    table->index++;
}

void printHashTable(HashTable* table) {
    printf("Hash Table:\n");
    for (int i = 0; i < HASH_SIZE; i++) {
        if (table->data[i] != NULL) {
            printf("| %s |", table->data[i]);
        } else {
            printf("|   |");
        }
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
}

int main() {
    HashTable* table = createHashTable();

    char* inputStr = "This is a simple hash function";
    addToHashTable(table, inputStr, strlen(inputStr) + 1);

    char* testStr1 = "This is a test string";
    addToHashTable(table, testStr1, strlen(testStr1) + 1);

    char* testStr2 = "Another test string";
    addToHashTable(table, testStr2, strlen(testStr2) + 1);

    printHashTable(table);

    free(table);

    return 0;
}