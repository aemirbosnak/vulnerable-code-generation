//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define N 1000
#define M 100

// Structure to store a node in the Trie
typedef struct {
    char *word;
    int freq;
    struct node *next[26];
} node_t;

// Function to create a new node
node_t *new_node(char *word) {
    node_t *n = malloc(sizeof(node_t));
    n->word = word;
    n->freq = 1;
    memset(n->next, 0, sizeof(n->next));
    return n;
}

// Function to insert a word into the Trie
void insert(node_t **root, char *word) {
    int i;
    node_t *n = *root;

    for (i = 0; i < strlen(word); i++) {
        int j = word[i] - 'a';
        if (n->next[j] == NULL) {
            n->next[j] = new_node(word + i);
        }
        n = n->next[j];
    }
    n->freq++;
}

// Function to search for a word in the Trie
node_t *search(node_t *root, char *word) {
    int i;
    node_t *n = root;

    for (i = 0; i < strlen(word); i++) {
        int j = word[i] - 'a';
        if (n->next[j] == NULL) {
            return NULL;
        }
        n = n->next[j];
    }
    return n;
}

// Function to print the Trie
void print(node_t *root) {
    int i;
    for (i = 0; i < 26; i++) {
        if (root->next[i] != NULL) {
            print(root->next[i]);
        }
        printf("%c%d ", i + 'a', root->freq);
    }
    printf("\n");
}

int main() {
    node_t *root = NULL;

    // Insert some words
    insert(&root, "apple");
    insert(&root, "ball");
    insert(&root, "cat");
    insert(&root, "dog");
    insert(&root, "elephant");

    // Search for some words
    node_t *apple = search(root, "apple");
    node_t *ball = search(root, "ball");
    node_t *cat = search(root, "cat");
    node_t *dog = search(root, "dog");
    node_t *elephant = search(root, "elephant");

    // Print the Trie
    print(root);

    return 0;
}