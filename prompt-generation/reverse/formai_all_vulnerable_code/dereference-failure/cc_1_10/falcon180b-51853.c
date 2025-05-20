//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_TREE_DEPTH 20
#define MAX_INDEX_SIZE 1000

// Define the structure for each node in the tree
typedef struct tree_node {
    char word[MAX_WORD_LENGTH];
    int count;
    struct tree_node* children[26];
} tree_node_t;

// Define the structure for the index
typedef struct index {
    tree_node_t* root;
    int num_entries;
} index_t;

// Function to create a new tree node
tree_node_t* create_node(char* word) {
    tree_node_t* node = (tree_node_t*) malloc(sizeof(tree_node_t));
    strcpy(node->word, word);
    node->count = 0;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Function to insert a word into the tree
void insert_word(tree_node_t* node, char* word) {
    if (node->children[(int) toupper(word[0]) - 65] == NULL) {
        node->children[(int) toupper(word[0]) - 65] = create_node(word);
    } else {
        insert_word(node->children[(int) toupper(word[0]) - 65], word);
    }
    node->count++;
}

// Function to search for a word in the tree
tree_node_t* search_word(tree_node_t* node, char* word) {
    if (node == NULL) {
        return NULL;
    }
    if (strcmp(node->word, word) == 0) {
        return node;
    }
    int index = (int) toupper(word[0]) - 65;
    if (node->children[index] == NULL) {
        return NULL;
    }
    return search_word(node->children[index], word);
}

// Function to print the tree
void print_tree(tree_node_t* node, int depth) {
    if (node == NULL) {
        return;
    }
    if (node->count > 0) {
        printf("%*s (%d)\n", depth * 4, node->word, node->count);
    }
    for (int i = 0; i < 26; i++) {
        if (node->children[i]!= NULL) {
            print_tree(node->children[i], depth + 1);
        }
    }
}

// Function to create a new index
index_t* create_index() {
    index_t* index = (index_t*) malloc(sizeof(index_t));
    index->root = create_node("");
    index->num_entries = 0;
    return index;
}

// Function to insert a word into the index
void insert_word_index(index_t* index, char* word) {
    tree_node_t* node = search_word(index->root, word);
    if (node == NULL) {
        insert_word(index->root, word);
        index->num_entries++;
    }
}

// Function to search for a word in the index
tree_node_t* search_word_index(index_t* index, char* word) {
    return search_word(index->root, word);
}

// Function to print the index
void print_index(index_t* index) {
    print_tree(index->root, 0);
}

int main() {
    index_t* index = create_index();
    insert_word_index(index, "apple");
    insert_word_index(index, "banana");
    insert_word_index(index, "cherry");
    print_index(index);
    tree_node_t* node = search_word_index(index, "apple");
    printf("Count for 'apple': %d\n", node->count);
    return 0;
}