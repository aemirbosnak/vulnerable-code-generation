//GEMINI-pro DATASET v1.0 Category: Educational ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a string
#define MAX_STRING_LENGTH 1024

// Define the number of characters in the alphabet
#define ALPHABET_SIZE 26

// Create a struct to represent a node in a trie
typedef struct trie_node {
    // The character stored in this node
    char character;

    // The children of this node, indexed by the character they represent
    struct trie_node *children[ALPHABET_SIZE];

    // The number of times this node has been visited
    int count;
} trie_node;

// Create a new trie node with the given character
trie_node *create_trie_node(char character) {
    // Allocate memory for the new node
    trie_node *node = malloc(sizeof(trie_node));

    // Initialize the new node
    node->character = character;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    node->count = 0;

    // Return the new node
    return node;
}

// Insert a string into a trie
void insert_string_into_trie(trie_node *root, char *string) {
    // Get the length of the string
    int length = strlen(string);

    // Iterate over the characters in the string
    for (int i = 0; i < length; i++) {
        // Get the index of the current character in the alphabet
        int index = string[i] - 'a';

        // If the child node for this character does not exist, create it
        if (root->children[index] == NULL) {
            root->children[index] = create_trie_node(string[i]);
        }

        // Move to the child node for this character
        root = root->children[index];

        // Increment the count of this node
        root->count++;
    }
}

// Search for a string in a trie
int search_string_in_trie(trie_node *root, char *string) {
    // Get the length of the string
    int length = strlen(string);

    // Iterate over the characters in the string
    for (int i = 0; i < length; i++) {
        // Get the index of the current character in the alphabet
        int index = string[i] - 'a';

        // If the child node for this character does not exist, the string is not in the trie
        if (root->children[index] == NULL) {
            return 0;
        }

        // Move to the child node for this character
        root = root->children[index];
    }

    // If the count of this node is greater than 0, the string is in the trie
    return root->count > 0;
}

// Print the contents of a trie
void print_trie(trie_node *root, char *prefix) {
    // If the root node is NULL, there is nothing to print
    if (root == NULL) {
        return;
    }

    // If the count of this node is greater than 0, print the prefix and the character stored in this node
    if (root->count > 0) {
        printf("%s%c (%d)\n", prefix, root->character, root->count);
    }

    // Iterate over the children of this node
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        // If the child node for this character exists, print the prefix and the character stored in this node
        if (root->children[i] != NULL) {
            char new_prefix[MAX_STRING_LENGTH];
            strcpy(new_prefix, prefix);
            new_prefix[strlen(new_prefix)] = root->children[i]->character;
            print_trie(root->children[i], new_prefix);
        }
    }
}

// Free the memory allocated for a trie
void free_trie(trie_node *root) {
    // If the root node is NULL, there is nothing to free
    if (root == NULL) {
        return;
    }

    // Iterate over the children of this node
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        // If the child node for this character exists, free it
        if (root->children[i] != NULL) {
            free_trie(root->children[i]);
        }
    }

    // Free the root node
    free(root);
}

// Main function
int main() {
    // Create a new trie
    trie_node *root = create_trie_node('\0');

    // Insert some strings into the trie
    insert_string_into_trie(root, "apple");
    insert_string_into_trie(root, "banana");
    insert_string_into_trie(root, "cherry");
    insert_string_into_trie(root, "dog");
    insert_string_into_trie(root, "elephant");

    // Search for some strings in the trie
    printf("apple: %d\n", search_string_in_trie(root, "apple"));
    printf("banana: %d\n", search_string_in_trie(root, "banana"));
    printf("cherry: %d\n", search_string_in_trie(root, "cherry"));
    printf("dog: %d\n", search_string_in_trie(root, "dog"));
    printf("elephant: %d\n", search_string_in_trie(root, "elephant"));

    // Print the contents of the trie
    print_trie(root, "");

    // Free the memory allocated for the trie
    free_trie(root);

    return 0;
}