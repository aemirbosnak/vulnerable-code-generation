//FormAI DATASET v1.0 Category: Spell checking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50

/*
 * This program checks a text file for misspelled words,
 * using a dictionary file as reference.
 *
 * The dictionary file should be in the following format:
 *      - One word per line
 *      - All words should be in lowercase
 *
 * Usage:
 *      ./spellcheck <dictionary_file> <input_file>
 */

// Node structure for the dictionary trie
struct Node {
    struct Node* child[26];
    int is_word;
};

// Function to initialize a new trie node
struct Node* createNode() {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->is_word = 0;
    for (int i = 0; i < 26; i++) {
        node->child[i] = NULL;
    }
    return node;
}

// Function to insert a new word into the trie
void insert(struct Node* root, const char* word) {
    struct Node* cur = root;
    int idx;

    for (int i = 0; i < strlen(word); i++) {
        idx = tolower(word[i]) - 'a';
        if (!cur->child[idx]) {
            cur->child[idx] = createNode();
        }
        cur = cur->child[idx];
    }
    cur->is_word = 1;
}

// Function to recursively search the trie for a word
int search(struct Node* node, const char* word) {
    if (!node) {
        return 0;
    }

    if (*word == '\0') {
        return node->is_word;
    }

    int idx = tolower(*word) - 'a';
    return search(node->child[idx], word+1);
}

// Function to validate a word
int isValidWord(const char* word) {
    int len = strlen(word);
    if (len > MAX_WORD_LEN) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <dictionary_file> <input_file>\n", argv[0]);
        return 1;
    }

    // Load dictionary into trie
    FILE* dict_file = fopen(argv[1], "r");
    if (dict_file == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }
    struct Node* root = createNode();
    char buffer[MAX_WORD_LEN+1];
    while (fgets(buffer, MAX_WORD_LEN+1, dict_file) != NULL) {
        int len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        }
        if (isValidWord(buffer)) {
            insert(root, buffer);
        }
    }
    fclose(dict_file);

    // Check input file for misspelled words
    FILE* input_file = fopen(argv[2], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    int line_num = 0;
    while (fgets(buffer, MAX_WORD_LEN+1, input_file) != NULL) {
        line_num++;
        char* word = strtok(buffer, " \t\n");
        while (word != NULL) {
            if (!search(root, word)) {
                printf("Line %d: Misspelled word: '%s'\n", line_num, word);
            }
            word = strtok(NULL, " \t\n");
        }
    }
    fclose(input_file);

    return 0;
}