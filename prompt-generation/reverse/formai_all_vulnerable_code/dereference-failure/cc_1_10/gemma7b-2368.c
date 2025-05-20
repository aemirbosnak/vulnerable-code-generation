//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_NAME_LENGTH 255
#define MAX_INDEX_ENTRIES 1000

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
} Node;

typedef struct IndexEntry {
    char name[MAX_NAME_LENGTH];
    int index;
    struct IndexEntry* next;
} IndexEntry;

Node* insertNode(Node* head, char* name)
{
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    return head;
}

IndexEntry* insertIndexEntry(IndexEntry* head, char* name, int index)
{
    IndexEntry* newEntry = malloc(sizeof(IndexEntry));
    strcpy(newEntry->name, name);
    newEntry->index = index;
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        IndexEntry* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newEntry;
    }

    return head;
}

void searchForName(Node* head, char* name)
{
    Node* current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            printf("Found name: %s\n", current->name);
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Name not found: %s\n", name);
    }
}

void searchForIndex(IndexEntry* head, char* name)
{
    IndexEntry* current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            printf("Index for name: %s is: %d\n", current->name, current->index);
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Name not found: %s\n", name);
    }
}

int main()
{
    Node* head = NULL;
    IndexEntry* indexHead = NULL;

    insertNode(head, "Romeo");
    insertNode(head, "Juliet");
    insertNode(head, "Benvolio");
    insertNode(head, " Mercutio");

    insertIndexEntry(indexHead, "Romeo", 1);
    insertIndexEntry(indexHead, "Juliet", 2);
    insertIndexEntry(indexHead, "Benvolio", 3);
    insertIndexEntry(indexHead, "Mercutio", 4);

    searchForName(head, "Romeo");
    searchForIndex(indexHead, "Romeo");

    return 0;
}