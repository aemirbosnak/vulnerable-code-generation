//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_WORD_LENGTH 20
#define MAX_LEVEL 5

// Structure to represent a node in the trie
typedef struct node {
    char word[MAX_WORD_LENGTH];
    struct node* children[MAX_LEVEL];
} node_t;

// Function to create a new node
node_t* new_node(char* word) {
    node_t* node = (node_t*) malloc(sizeof(node_t));
    strcpy(node->word, word);
    for (int i = 0; i < MAX_LEVEL; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Function to insert a word into the trie
void insert(node_t** root, char* word) {
    node_t* current = *root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = new_node(word + i + 1);
        }
        current = current->children[index];
    }
    current->word[strlen(word) - 1] = '\0';
}

// Function to search for a word in the trie
node_t* search(node_t** root, char* word) {
    node_t* current = *root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            return NULL;
        }
        current = current->children[index];
    }
    return current;
}

// Function to print the words in the trie
void print(node_t* root) {
    if (root != NULL) {
        printf("%s\n", root->word);
        for (int i = 0; i < MAX_LEVEL; i++) {
            if (root->children[i] != NULL) {
                print(root->children[i]);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    node_t* root = NULL;
    for (int i = 0; i < 100; i++) {
        char word[MAX_WORD_LENGTH];
        int len = rand() % (MAX_WORD_LENGTH - 1) + 1;
        for (int j = 0; j < len; j++) {
            word[j] = 'a' + rand() % 26;
        }
        word[len] = '\0';
        insert(&root, word);
    }
    print(root);
    return 0;
}