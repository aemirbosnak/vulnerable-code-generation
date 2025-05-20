//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define N 10
#define M 5
#define MAX_SZ 100

// Structure to store a node in the trie
typedef struct node {
    char word[MAX_SZ];
    int len;
    struct node* children[N];
} node_t;

// Function to create a new node
node_t* new_node(char* word, int len) {
    node_t* node = (node_t*) malloc(sizeof(node_t));
    strcpy(node->word, word);
    node->len = len;
    for (int i = 0; i < N; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Function to insert a word into the trie
void insert(node_t** root, char* word) {
    int i;
    node_t* current = *root;
    for (i = 0; i < M; i++) {
        if (word[i] == '\0') {
            break;
        }
        if (current->children[word[i] - 'a'] == NULL) {
            current->children[word[i] - 'a'] = new_node(word + i, 1);
        }
        current = current->children[word[i] - 'a'];
    }
    current->len += 1;
}

// Function to search for a word in the trie
node_t* search(node_t** root, char* word) {
    int i;
    node_t* current = *root;
    for (i = 0; i < M; i++) {
        if (word[i] == '\0') {
            break;
        }
        if (current->children[word[i] - 'a'] == NULL) {
            return NULL;
        }
        current = current->children[word[i] - 'a'];
    }
    return current;
}

// Function to print the words in the trie
void print(node_t* root) {
    if (root == NULL) {
        return;
    }
    printf("%s (%d)\n", root->word, root->len);
    for (int i = 0; i < N; i++) {
        if (root->children[i] != NULL) {
            print(root->children[i]);
        }
    }
}

int main() {
    // Create the root node
    node_t* root = new_node("apple", 5);

    // Insert some words into the trie
    insert(&root, "apple");
    insert(&root, "banana");
    insert(&root, "cherry");
    insert(&root, "date");
    insert(&root, "elephant");

    // Search for a word in the trie
    node_t* result = search(&root, "e");
    if (result != NULL) {
        printf("Found %s (%d)\n", result->word, result->len);
    } else {
        printf("Not found\n");
    }

    // Print the words in the trie
    print(root);

    return 0;
}