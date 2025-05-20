//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

struct node {
    char key[MAX_LENGTH];
    struct node* next;
};

struct node* head = NULL;

void create_index(char* key) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    strcpy(new_node->key, key);
    new_node->next = head;
    head = new_node;
}

void search_index(char* key) {
    struct node* current = head;
    while (current!= NULL) {
        if (strcmp(current->key, key) == 0) {
            printf("Key Found: %s\n", key);
            return;
        }
        current = current->next;
    }
    printf("Key Not Found\n");
}

int main() {
    char* key1 = "apple";
    char* key2 = "banana";
    char* key3 = "cherry";

    create_index(key1);
    create_index(key2);
    create_index(key3);

    search_index(key1);
    search_index(key2);
    search_index(key3);

    search_index("grape");

    return 0;
}