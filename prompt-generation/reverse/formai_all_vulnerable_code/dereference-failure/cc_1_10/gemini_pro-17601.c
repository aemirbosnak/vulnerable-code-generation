//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Create a node for the trie
typedef struct node {
    char letter;
    int is_word;
    struct node* children[26];
} node;

// Create a new node
node* new_node(char letter) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->letter = letter;
    new_node->is_word = 0;
    for (int i = 0; i < 26; i++) {
        new_node->children[i] = NULL;
    }
    return new_node;
}

// Insert a word into the trie
void insert(node* root, char* word) {
    int len = strlen(word);
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int index = tolower(word[i]) - 'a';
        if (curr->children[index] == NULL) {
            curr->children[index] = new_node(word[i]);
        }
        curr = curr->children[index];
    }
    curr->is_word = 1;
}

// Check if a word is in the trie
int search(node* root, char* word) {
    int len = strlen(word);
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int index = tolower(word[i]) - 'a';
        if (curr->children[index] == NULL) {
            return 0;
        }
        curr = curr->children[index];
    }
    return curr->is_word;
}

// Free the trie
void free_trie(node* root) {
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            free_trie(root->children[i]);
        }
    }
    free(root);
}

// Load the dictionary into the trie
node* load_dictionary() {
    FILE* fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error opening dictionary file\n");
        exit(1);
    }
    node* root = new_node(' ');
    char word[100];
    while (fscanf(fp, "%s", word) != EOF) {
        insert(root, word);
    }
    fclose(fp);
    return root;
}

// Check the spelling of a word
void check_spelling(node* root, char* word) {
    int len = strlen(word);
    int is_correct = search(root, word);
    if (is_correct) {
        printf("%s is spelled correctly\n", word);
    } else {
        printf("%s is spelled incorrectly\n", word);
    }
}

// Main function
int main() {
    // Load the dictionary into the trie
    node* root = load_dictionary();

    // Check the spelling of a word
    char word[100];
    printf("Enter a word to check the spelling: ");
    scanf("%s", word);
    check_spelling(root, word);

    // Free the trie
    free_trie(root);

    return 0;
}