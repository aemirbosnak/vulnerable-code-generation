//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 100

typedef struct node {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
    struct node *next;
} node;

node* create_node(const char* key, const char* value) {
    node* new_node = (node*)malloc(sizeof(node));
    strncpy(new_node->key, key, MAX_KEY_SIZE - 1);
    strncpy(new_node->value, value, MAX_VALUE_SIZE - 1);
    new_node->next = NULL;
    return new_node;
}

void insert(node** table, const char* key, const char* value) {
    node* temp = *table;
    int found = 0;
    while (temp!= NULL) {
        if (strcmp(key, temp->key) == 0) {
            strncpy(temp->value, value, MAX_VALUE_SIZE - 1);
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if (!found) {
        temp = create_node(key, value);
        *table = temp;
    }
}

int main() {
    node* table = NULL;
    insert(&table, "apple", "fruit");
    insert(&table, "banana", "fruit");
    insert(&table, "carrot", "vegetable");
    insert(&table, "apple", "computer");
    insert(&table, "banana", "computer");
    insert(&table, "carrot", "computer");
    printf("After inserting 'carrot', the table contains:\n");
    node* temp = table;
    while (temp!= NULL) {
        printf("%s: %s\n", temp->key, temp->value);
        temp = temp->next;
    }
    return 0;
}