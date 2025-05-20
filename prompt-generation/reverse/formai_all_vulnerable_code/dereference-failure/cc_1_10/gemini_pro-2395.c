//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORDS 10000

//Create a node for the trie
typedef struct trie_node {
    int is_word;
    struct trie_node *children[26];
} trie_node;

//Create a new trie node
trie_node *create_trie_node() {
    trie_node *new_node = malloc(sizeof(trie_node));
    new_node->is_word = 0;
    for (int i = 0; i < 26; i++) {
        new_node->children[i] = NULL;
    }
    return new_node;
}

//Insert a word into the trie
void insert_word(trie_node *root, char *word) {
    trie_node *current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = tolower(word[i]) - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = create_trie_node();
        }
        current = current->children[index];
    }
    current->is_word = 1;
}

//Load the dictionary into the trie
void load_dictionary(trie_node *root, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        exit(EXIT_FAILURE);
    }
    char word[100];
    while (fscanf(fp, "%s", word) != EOF) {
        insert_word(root, word);
    }
    fclose(fp);
}

//Check if a word is in the trie
int is_word_in_trie(trie_node *root, char *word) {
    trie_node *current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = tolower(word[i]) - 'a';
        if (current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }
    return current->is_word;
}

//Check spelling of words in a text file
void check_spelling(trie_node *root, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening text file");
        exit(EXIT_FAILURE);
    }
    char word[100];
    while (fscanf(fp, "%s", word) != EOF) {
        if (!is_word_in_trie(root, word)) {
            printf("%s is not a word\n", word);
        }
    }
    fclose(fp);
}

//Free the trie
void free_trie(trie_node *root) {
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            free_trie(root->children[i]);
        }
    }
    free(root);
}

int main() {
    //Create the root of the trie
    trie_node *root = create_trie_node();

    //Load the dictionary into the trie
    load_dictionary(root, "dictionary.txt");

    //Check spelling of words in a text file
    check_spelling(root, "text.txt");

    //Free the trie
    free_trie(root);

    return 0;
}