//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define TABLE_SIZE 11

typedef struct Element {
    int key;
    struct Element *next;
} Element;

Element *hashTable[TABLE_SIZE] = {NULL};

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int hashIndex = hashFunction(key);
    Element *newNode = (Element *)malloc(sizeof(Element));
    newNode->key = key;
    newNode->next = hashTable[hashIndex];
    hashTable[hashIndex] = newNode;
}

int search(int key) {
    int hashIndex = hashFunction(key);
    Element *current = hashTable[hashIndex];

    while (current != NULL) {
        if (current->key == key)
            return 1;
        current = current->next;
    }

    return 0;
}

int main() {
    int array[MAX_SIZE];
    int i;

    srand(time(NULL));

    for (i = 0; i < MAX_SIZE; i++) {
        array[i] = rand() % 100;
        insert(array[i]);
    }

    int target;
    printf("Enter the target number: ");
    scanf("%d", &target);

    if (search(target))
        printf("Found!\n");
    else
        printf("Not found.\n");

    for (i = 0; i < TABLE_SIZE; i++) {
        Element *current = hashTable[i];
        while (current != NULL) {
            printf("Index %d: %d -> ", i, current->key);
            current = current->next;
        }
        printf("NULL\n");
    }

    return 0;
}