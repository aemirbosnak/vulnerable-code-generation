//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_CHILDREN 5

typedef struct {
    char *word;
    int count;
    struct node *children[MAX_CHILDREN];
} node;

node *create_node(char *word) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->word = strdup(word);
    new_node->count = 0;
    for (int i = 0; i < MAX_CHILDREN; i++) {
        new_node->children[i] = NULL;
    }
    return new_node;
}

void insert_word(node *root, char *word) {
    node *current_node = root;
    while (current_node!= NULL) {
        if (strcmp(current_node->word, word) == 0) {
            current_node->count++;
            return;
        }
        int index = 0;
        while (index < MAX_CHILDREN && current_node->children[index]!= NULL) {
            index++;
        }
        if (index < MAX_CHILDREN) {
            current_node->children[index] = create_node(word);
        }
        current_node = current_node->children[index];
    }
}

void delete_tree(node *root) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < MAX_CHILDREN; i++) {
        if (root->children[i]!= NULL) {
            delete_tree(root->children[i]);
        }
    }
    free(root->word);
    free(root);
}

void search_word(node *root, char *word) {
    node *current_node = root;
    while (current_node!= NULL) {
        if (strcmp(current_node->word, word) == 0) {
            printf("Found word: %s\n", word);
            printf("Count: %d\n", current_node->count);
            return;
        }
        int index = 0;
        while (index < MAX_CHILDREN && current_node->children[index]!= NULL) {
            current_node = current_node->children[index];
            if (strcmp(current_node->word, word) == 0) {
                printf("Found word: %s\n", word);
                printf("Count: %d\n", current_node->count);
                return;
            }
        }
        current_node = NULL;
    }
    printf("Word not found.\n");
}

int main() {
    node *root = create_node("root");
    insert_word(root, "apple");
    insert_word(root, "banana");
    insert_word(root, "cherry");
    insert_word(root, "date");
    insert_word(root, "elderberry");
    search_word(root, "banana");
    search_word(root, "grape");
    delete_tree(root);
    return 0;
}