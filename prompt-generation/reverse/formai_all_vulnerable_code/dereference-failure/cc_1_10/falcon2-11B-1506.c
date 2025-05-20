//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

struct node {
    char *key;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void insert(char *key) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key = strdup(key);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void search(char *key) {
    struct node *current = head;
    while (current!= NULL) {
        if (strcmp(current->key, key) == 0) {
            printf("Found key: %s\n", current->key);
            return;
        }
        current = current->next;
    }
    printf("Key not found\n");
}

void delete(char *key) {
    struct node *current = head;
    struct node *prev = NULL;

    while (current!= NULL) {
        if (strcmp(current->key, key) == 0) {
            if (prev == NULL) {
                head = current->next;
                free(current->key);
                free(current);
                return;
            } else {
                prev->next = current->next;
                free(current->key);
                free(current);
                return;
            }
        }
        prev = current;
        current = current->next;
    }
    printf("Key not found\n");
}

int main() {
    char *keys[] = {"apple", "banana", "cherry", "date", "elderberry"};
    int numKeys = sizeof(keys) / sizeof(char*);

    for (int i = 0; i < numKeys; i++) {
        insert(keys[i]);
    }

    for (int i = 0; i < numKeys; i++) {
        search(keys[i]);
    }

    for (int i = 0; i < numKeys; i++) {
        delete(keys[i]);
    }

    return 0;
}