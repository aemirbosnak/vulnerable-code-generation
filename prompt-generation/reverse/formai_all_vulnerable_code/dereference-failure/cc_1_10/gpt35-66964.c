//FormAI DATASET v1.0 Category: Database Indexing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 256

typedef struct Node {
    int key;
    char value[20];
    struct Node* next;
}Node;

Node* hashTable[HASHSIZE];

void insert(int key, char* value);
void search(int key);
void delete(int key);
void display();

int main() {
    insert(10, "apple");
    insert(20, "banana");
    insert(30, "orange");
    
    display();
    
    search(10);
    search(20);
    search(30);
    
    delete(20);
    
    display();
    
    return 0;
}

void insert(int key, char* value)
{
    int index = key % HASHSIZE;
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->key = key;
    strcpy(newNode->value, value);
    
    if(hashTable[index] == NULL) {
        hashTable[index] = newNode;
    }
    else {
        Node* temp = hashTable[index];
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void search(int key)
{
    int index = key % HASHSIZE;
    Node* temp = hashTable[index];
    while(temp != NULL) {
        if(temp->key == key) {
            printf("Key: %d, Value: %s\n", key, temp->value);
            return;
        }
        temp = temp->next;
    }
    printf("%d not found in the hash table.\n", key);
}

void delete(int key)
{
    int index = key % HASHSIZE;
    Node* temp = hashTable[index];
    Node* prev = NULL;
    while(temp != NULL) {
        if(temp->key == key) {
            if(prev == NULL) {
                hashTable[index] = temp->next;
            }
            else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Key: %d has been deleted.\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("%d not found in the hash table.\n", key);
}

void display()
{
    printf("\nHashTable:\n");
    for(int i=0; i<HASHSIZE; i++) {
        Node* temp = hashTable[i];
        while(temp != NULL) {
            printf("Index: %d, Key: %d, Value: %s\n", i, temp->key, temp->value);
            temp = temp->next;
        }
    }
}