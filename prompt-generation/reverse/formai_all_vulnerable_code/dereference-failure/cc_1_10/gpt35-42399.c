//FormAI DATASET v1.0 Category: Database Indexing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum number of keys and values
#define MAX_KEYS 20
#define MAX_VALUES 20

// define the structure for each node in the index tree
typedef struct node {
    char keys[MAX_KEYS][50];
    int num_keys;
    struct node *children[MAX_VALUES + 1];
} Node;

// function to create a new child node
Node *create_child_node() {
    Node *child_node = (Node *)malloc(sizeof(Node));
    child_node->num_keys = 0;
    
    for (int i = 0; i < MAX_VALUES + 1; i++) {
        child_node->children[i] = NULL;
    }
    
    return child_node;
}

// function to insert a new key into the index tree
void insert_key(Node *parent_node, char new_key[50]) {
    Node *current_node = parent_node;
    int i = 0;
    
    while (i < current_node->num_keys && strcmp(new_key, current_node->keys[i]) > 0) {
        i++;
    }
    
    if (current_node->children[i] == NULL) {
        current_node->children[i] = create_child_node();
    }
    
    // if node is full, split it into two
    if (current_node->children[i]->num_keys == MAX_KEYS) {
        Node *new_node = create_child_node();
        memcpy(new_node->keys, current_node->children[i]->keys + MAX_KEYS/2, (MAX_KEYS - MAX_KEYS/2)*sizeof(char[50]));
        new_node->num_keys = (MAX_KEYS - MAX_KEYS/2);
        current_node->children[i]->num_keys = MAX_KEYS/2;
        
        for (int j = current_node->num_keys; j >= i + 1; j--) {
            current_node->children[j + 1] = current_node->children[j];
        }
        
        current_node->children[i + 1] = new_node;
        
        for (int j = current_node->num_keys - 1; j >= i; j--) {
            strcpy(current_node->keys[j + 1], current_node->keys[j]);
        }
        
        strcpy(current_node->keys[i], new_node->keys[0]);
        current_node->num_keys++;
        return insert_key(current_node, new_key);
    }
    
    if (strcmp(new_key, current_node->keys[i]) == 0) {
        return; // duplicate key
    }
    
    for (int j = current_node->num_keys - 1; j >= i; j--) {
        strcpy(current_node->keys[j + 1], current_node->keys[j]);
    }
    
    strcpy(current_node->keys[i], new_key);
    current_node->num_keys++;
}

// function to search for a key in the index tree
Node *search_key(Node *parent_node, char key[50]) {
    Node *current_node = parent_node;
    int i = 0;
    
    while (i < current_node->num_keys && strcmp(key, current_node->keys[i]) > 0) {
        i++;
    }
    
    if (strcmp(key, current_node->keys[i]) == 0) {
        return current_node;
    }
    
    if (current_node->children[i] != NULL) {
        return search_key(current_node->children[i], key);
    }
    
    return NULL;
}

// main function to test the index tree
int main() {
    Node *root = create_child_node();
    
    insert_key(root, "apple");
    insert_key(root, "banana");
    insert_key(root, "cherry");
    insert_key(root, "date");
    insert_key(root, "elderberry");
    insert_key(root, "fig");
    insert_key(root, "grape");
    
    Node *found_node = search_key(root, "date");
    
    if (found_node != NULL) {
        printf("Key found!\n");
    } else {
        printf("Key not found.\n");
    }
    
    return 0;
}