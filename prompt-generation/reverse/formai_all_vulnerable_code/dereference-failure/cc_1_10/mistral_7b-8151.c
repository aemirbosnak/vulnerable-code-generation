//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 256

typedef struct hashNode {
    int count;
    char key;
    struct hashNode *next;
} HashNode;

HashNode *hashTable[TABLE_SIZE];

unsigned long hash(char *str, int length) {
    unsigned long hash = 5381;
    int i;

    for (i = 0; i < length; i++) {
        hash = ((hash << 5) + hash) + (int)str[i];
    }

    return hash % TABLE_SIZE;
}

void insert(char key) {
    unsigned long index = hash((char*)&key, sizeof(key));

    HashNode *newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->count = 1;
    newNode->key = key;
    newNode->next = hashTable[index];

    hashTable[index] = newNode;
}

void incrementCount(char key) {
    unsigned long index = hash((char*)&key, sizeof(key));

    HashNode *currentNode = hashTable[index];

    while (currentNode != NULL) {
        if (currentNode->key == key) {
            currentNode->count++;
            return;
        }
        currentNode = currentNode->next;
    }

    insert(key);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char str[1024];
    strcpy(str, argv[1]);

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            incrementCount(tolower(str[i]));
        }
    }

    printf("====== Happy C Word Frequency Counter ======\n");
    printf("Count of character 'c' in the given string:\n");

    int count = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != NULL) {
            if (hashTable[i]->key == 'c' || hashTable[i]->key == 'C') {
                count = hashTable[i]->count;
                break;
            }
        }
    }

    if (count > 0) {
        printf("Total occurrences: %d\n", count);
        printf("In a happy world, every 'c' brings joy and success!\n");
    } else {
        printf("Character 'c' or 'C' not found in the string.\n");
    }

    return 0;
}