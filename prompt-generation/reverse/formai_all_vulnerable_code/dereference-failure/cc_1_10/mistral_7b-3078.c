//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORD_LENGTH 50
#define NUM_BUCKETS 26
#define WORD_NOT_FOUND -1
typedef struct TrieNode {
    struct TrieNode *children[NUM_BUCKETS];
    int is_end_of_word;
} TrieNode;
TrieNode *root;
void add_word(char *word) {
    TrieNode *current = root;
    int index;
    for (int i = 0; i < strlen(word); i++) {
        index = tolower(word[i]) - 'a';
        if (!current->children[index]) {
            current->children[index] = calloc(1, sizeof(TrieNode));
        }
        current = current->children[index];
    }
    current->is_end_of_word = 1;
}
int search_word(char *word) {
    TrieNode *current = root;
    int index, i;
    for (i = 0; i < strlen(word); i++) {
        index = tolower(word[i]) - 'a';
        if (!current->children[index]) {
            return WORD_NOT_FOUND;
        }
        current = current->children[index];
    }
    return current->is_end_of_word;
}
int main() {
    int i, j, num_tests, word_length, word_found;
    char test_case[MAX_WORD_LENGTH][MAX_WORD_LENGTH];
    root = calloc(1, sizeof(TrieNode));
    root->is_end_of_word = 0;
    scanf("%d", &num_tests);
    for (i = 0; i < num_tests; i++) {
        scanf("%s", test_case[i]);
        add_word(test_case[i]);
    }
    for (i = 0; i < num_tests; i++) {
        word_length = strlen(test_case[i]);
        word_found = search_word(test_case[i]);
        if (word_found == WORD_NOT_FOUND) {
            printf("Misspelled word: %s\n", test_case[i]);
        }
    }
    free(root);
    return 0;
}