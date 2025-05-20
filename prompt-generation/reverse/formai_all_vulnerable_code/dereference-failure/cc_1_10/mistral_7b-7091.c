//MISTRAL-7B DATASET v1.0 Category: Database Indexing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define TABLE_SIZE 101
#define HASH_FUNCTION(x) (abs((int)(x) % TABLE_SIZE))

typedef struct Node {
    int key;
    char value[100];
    struct Node *next;
} Node;

Node **hashTable;

void createHashTable() {
    int i;
    hashTable = calloc(TABLE_SIZE, sizeof(Node*));
    for (i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

void put(int key, char *value) {
    int index = HASH_FUNCTION(key);
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->key = key;
    strcpy(newNode->value, value);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

Node *get(int key) {
    int index = HASH_FUNCTION(key);
    Node *currentNode = hashTable[index];

    while (currentNode != NULL) {
        if (currentNode->key == key) {
            return currentNode;
        }
        currentNode = currentNode->next;
    }

    return NULL;
}

void saveDataToFile(char *filename) {
    int i;
    FILE *file = fopen(filename, "w");

    for (i = 0; i < TABLE_SIZE; i++) {
        Node *currentNode = hashTable[i];

        while (currentNode != NULL) {
            fprintf(file, "%d %s\n", currentNode->key, currentNode->value);
            currentNode = currentNode->next;
        }
    }

    fclose(file);
}

void loadDataFromFile(char *filename) {
    int i, j;
    FILE *file = fopen(filename, "r");
    char line[100];
    char *token;

    createHashTable();

    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, " ");
        int key = atoi(token);
        token = strtok(NULL, " ");
        strcpy(hashTable[HASH_FUNCTION(key)]->value, token);
    }

    fclose(file);
}

int main() {
    createHashTable();

    put(1, "apple");
    put(2, "banana");
    put(1, "orange"); // This will override the previous value for key 1

    Node *node = get(1);
    if (node != NULL) {
        printf("Value for key 1: %s\n", node->value);
    }

    saveDataToFile("data.txt");
    loadDataFromFile("data.txt");

    return 0;
}