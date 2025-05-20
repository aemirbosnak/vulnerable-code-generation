//LLAMA2-13B DATASET v1.0 Category: Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 1024
#define MAX_DEPTH 5

typedef struct node {
    char word[MAX_LENGTH];
    int frequency;
    struct node* children[MAX_DEPTH];
} node_t;

node_t* build_trie(char* words[], int count) {
    node_t* root = malloc(sizeof(node_t));
    root->word[0] = '\0';
    root->frequency = 0;
    for (int i = 0; i < count; i++) {
        node_t* current = root;
        for (int j = 0; j < strlen(words[i]); j++) {
            int index = strchr(words[i], words[i][j]) - words[i];
            if (current->children[index] == NULL) {
                current->children[index] = malloc(sizeof(node_t));
                current = current->children[index];
            }
            current = current->children[index];
        }
        current->word[strlen(words[i])] = '\0';
        current->frequency = 1;
    }
    return root;
}

void print_trie(node_t* root) {
    if (root == NULL) {
        return;
    }
    printf("%s (%d)\n", root->word, root->frequency);
    for (int i = 0; i < MAX_DEPTH; i++) {
        if (root->children[i] != NULL) {
            print_trie(root->children[i]);
        }
    }
}

int main() {
    char words[][MAX_LENGTH] = {"the", "cat", "in", "the", "hat", "sat"};
    int count = sizeof(words) / sizeof(words[0]);
    node_t* root = build_trie(words, count);
    print_trie(root);
    return 0;
}