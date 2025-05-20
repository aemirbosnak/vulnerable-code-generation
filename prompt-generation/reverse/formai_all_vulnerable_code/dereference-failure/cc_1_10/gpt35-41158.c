//FormAI DATASET v1.0 Category: Spell checking ; Style: Ken Thompson
// Ken Thompson style spell checker implementation in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define dictionary array size and max word length
#define DICT_SIZE 10000
#define MAX_WORD_LENGTH 50

// Define node structure for dictionary trie
typedef struct trie_node {
    int is_word_end;
    struct trie_node* children[26];
} trie_node;

// Create root node for dictionary trie
trie_node* create_node() {
    trie_node* new_node = (trie_node*) malloc(sizeof(trie_node));
    int i;
    new_node->is_word_end = 0;
    for (i = 0; i < 26; i++) {
        new_node->children[i] = NULL;
    }
    return new_node;
}

// Insert word into dictionary trie
void insert_word(trie_node* root, char* word) {
    int length = strlen(word);
    int i, index;
    trie_node* node = root;

    for (i = 0; i < length; i++) {
        index = word[i] - 'a';
        if (node->children[index] == NULL) {
            node->children[index] = create_node();
        }
        node = node->children[index];
    }
    node->is_word_end = 1;
}

// Search for word in dictionary trie
int search_word(trie_node* root, char* word) {
    int length = strlen(word);
    int i, index;
    trie_node* node = root;

    for (i = 0; i < length; i++) {
        index = word[i] - 'a';
        if (node->children[index] == NULL) {
            return 0;
        }
        node = node->children[index];
    }
    return node != NULL && node->is_word_end;
}

// Check if character is a valid letter
int is_valid_letter(char c) {
    return isalpha(c) && islower(c);
}

// Remove non-letter characters from word
void sanitize_word(char* word) {
    int i, j = 0;
    int length = strlen(word);
    char sanitized_word[MAX_WORD_LENGTH];
    for (i = 0; i < length; i++) {
        if (is_valid_letter(word[i])) {
            sanitized_word[j++] = tolower(word[i]);
        }
    }
    sanitized_word[j] = '\0';
    strcpy(word, sanitized_word);
}

int main() {
    trie_node* dictionary = create_node(); // create dictionary trie root node

    // Open dictionary file and insert words into trie
    FILE* dict_file = fopen("dictionary.txt", "r");
    char word[MAX_WORD_LENGTH];
    while (fscanf(dict_file, "%s", word) != EOF) {
        sanitize_word(word);
        insert_word(dictionary, word);
    }
    fclose(dict_file);

    // Open input file and check spellings
    FILE* input_file = fopen("input.txt", "r");
    int line_number = 1;
    char line[500];
    while (fgets(line, 500, input_file) != NULL) {
        int i, j = 0, length = strlen(line);
        char word_buffer[MAX_WORD_LENGTH];

        for (i = 0; i < length; i++) {
            if (line[i] == ' ' || line[i] == '\n' || line[i] == '\t') {
                if (j > 0) {
                    word_buffer[j] = '\0';
                    sanitize_word(word_buffer);
                    if (!search_word(dictionary, word_buffer)) {
                        printf("Spelling error detected at line %d: %s\n", line_number, word_buffer);
                    }
                    j = 0;
                }
            }
            else {
                word_buffer[j++] = line[i];
            }
        }
        line_number++;
    }
    fclose(input_file);

    return 0;
}