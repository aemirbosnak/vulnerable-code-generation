//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: optimized
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// define hash function
unsigned int hash(char *key, int len) {
    unsigned int hash = 0;
    for (int i = 0; i < len; i++) {
        hash = (hash * 31) ^ key[i];
    }
    return hash;
}

// define hash table
struct node {
    char *key;
    int value;
    struct node *next;
};

struct node *hashTable[100];

// define hash function for string keys
unsigned int hashString(char *key) {
    unsigned int hash = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash = (hash * 31) ^ key[i];
    }
    return hash % 100;
}

// define insertion function
void insert(char *key, int value) {
    int index = hash(key, strlen(key)) % 100;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// define deletion function
void delete(char *key) {
    int index = hashString(key) % 100;
    struct node *prev = NULL;
    struct node *curr = hashTable[index];
    while (curr!= NULL && strcmp(curr->key, key)!= 0) {
        prev = curr;
        curr = curr->next;
    }
    if (curr!= NULL) {
        if (prev == NULL) {
            hashTable[index] = curr->next;
        } else {
            prev->next = curr->next;
        }
        free(curr->key);
        free(curr);
    }
}

// define search function
int search(char *key) {
    int index = hashString(key) % 100;
    struct node *curr = hashTable[index];
    while (curr!= NULL) {
        if (strcmp(curr->key, key) == 0) {
            return curr->value;
        }
        curr = curr->next;
    }
    return -1;
}

// define main function
int main() {
    insert("apple", 10);
    insert("banana", 20);
    insert("cherry", 30);
    printf("Value of apple: %d\n", search("apple"));
    printf("Value of banana: %d\n", search("banana"));
    printf("Value of cherry: %d\n", search("cherry"));
    delete("banana");
    printf("Value of banana after deletion: %d\n", search("banana"));
    return 0;
}