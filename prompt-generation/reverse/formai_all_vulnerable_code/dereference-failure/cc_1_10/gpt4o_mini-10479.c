//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define DICTIONARY_SIZE 10000

// A node structure for the binary search tree
typedef struct Node {
    char word[MAX_WORD_LEN];
    struct Node *left, *right;
} Node;

// Gratefully maintaining a dictionary as a binary search tree
Node* insert(Node* node, const char* word) {
    if (node == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        strncpy(newNode->word, word, MAX_WORD_LEN);
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (strcmp(word, node->word) < 0)
        node->left = insert(node->left, word);
    else if (strcmp(word, node->word) > 0)
        node->right = insert(node->right, word);
    
    return node;
}

int search(Node* node, const char* word) {
    if (node == NULL)
        return 0;
    if (strcmp(word, node->word) == 0)
        return 1; // Word found!
    else if (strcmp(word, node->word) < 0)
        return search(node->left, word);
    else
        return search(node->right, word);
}

// Function to create and populate the dictionary
void createDictionary(Node** root) {
    const char* words[DICTIONARY_SIZE] = {
        "apple", "banana", "grape", "orange", "mango", 
        "kiwi", "peach", "pear", "cherry", "strawberry",
        // ... (list can be extended)
    };

    for (int i = 0; i < 10; i++) { // Using 10 for simplicity
        *root = insert(*root, words[i]);
    }
}

// Function to clean up and free memory
void freeDictionary(Node* node) {
    if (node == NULL)
        return;
    freeDictionary(node->left);
    freeDictionary(node->right);
    free(node);
}

// Main function to check spelling
int main() {
    printf("Thank you for using the Spell Checker!\n");
    
    Node* dictionary = NULL;
    createDictionary(&dictionary);
    
    char input[MAX_WORD_LEN];
    while (1) {
        printf("Please enter a word to check (type 'exit' to quit): ");
        scanf("%s", input);
        
        if (strcmp(input, "exit") == 0) {
            printf("Thank you for using the Spell Checker! Goodbye!\n");
            break;
        }
        
        if (search(dictionary, input)) {
            printf("The word '%s' is spelled correctly!\n", input);
        } else {
            printf("The word '%s' is not found in the dictionary.\n", input);
        }
    }

    // Free allocated memory for the dictionary
    freeDictionary(dictionary);
    return 0;
}