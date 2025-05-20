//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_CHAR 26
#define TRIE_SIZE 27
typedef struct TrieNode {
    struct TrieNode *children[MAX_CHAR];
    int is_word;
} TrieNode;
TrieNode *root;
void add_word(TrieNode *node, char *word) {
    int len = strlen(word);
    TrieNode *current = node;
    for (int i = 0; i < len; i++) {
        int index = tolower(word[i]) - 'a';
        if (!current->children[index]) {
            current->children[index] = calloc(1, sizeof(TrieNode));
        }
        current = current->children[index];
    }
    current->is_word = 1;
}
int search_word(TrieNode *node, char *word) {
    int len = strlen(word);
    TrieNode *current = node;
    for (int i = 0; i < len; i++) {
        int index = tolower(word[i]) - 'a';
        if (!current->children[index]) {
            return 0;
        }
        current = current->children[index];
    }
    return current->is_word;
}
int main() {
    int num_words;
    scanf("%d", &num_words);
    root = calloc(1, sizeof(TrieNode));
    for (int i = 0; i < num_words; i++) {
        char word[50];
        scanf("%s", word);
        add_word(root, word);
    }
    char check_word[50];
    while (1) {
        printf("Enter a word to check spelling (type 'quit' to exit): ");
        scanf("%s", check_word);
        if (strcmp(check_word, "quit") == 0) {
            break;
        }
        int result = search_word(root, check_word);
        if (result) {
            printf("The word '%s' is spelled correctly.\n", check_word);
        } else {
            printf("The word '%s' is not in the dictionary.\n", check_word);
        }
    }
    return 0;
}