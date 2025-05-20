//FormAI DATASET v1.0 Category: Spell checking ; Style: safe
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50

typedef struct node {
    char word[MAX_WORD_LENGTH + 1];
    struct node* left;
    struct node* right;
} node;

int is_valid_char(char c) {
    return isalpha(c) || c == '\'' || c == '-';
}

void to_lower_case(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

node* create_node(char* word) {
    node* new_node = malloc(sizeof(node));
    if (new_node) {
        strcpy(new_node->word, word);
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

node* insert_node(node* root, char* word) {
    if (!root) {
        return create_node(word);
    }
    int cmp = strcmp(root->word, word);
    if (cmp == 0) {
        return root; // Already in tree;
    }
    if (cmp > 0) {
        root->left = insert_node(root->left, word);
    } else {
        root->right = insert_node(root->right, word);
    }
    return root;
}

node* populate_tree(char* dictionary_file) {
    FILE* file = fopen(dictionary_file, "r");
    if (!file) {
        return NULL;
    }
    node* root = NULL;
    char word[MAX_WORD_LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF) {
        to_lower_case(word);
        root = insert_node(root, word);
    }
    return root;
}

int is_word_in_tree(node* root, char* word) {
    if (!root) {
        return 0;
    }
    int cmp = strcmp(root->word, word);
    if (cmp == 0) {
        return 1;
    }
    if (cmp > 0) {
        return is_word_in_tree(root->left, word);
    }
    return is_word_in_tree(root->right, word);
}

void spell_check(char* text_file, node* dictionary) {
    FILE* file = fopen(text_file, "r");
    if (!file) {
        printf("Could not open file %s!\n", text_file);
        return;
    }
    char c;
    int line = 1;
    char current_word[MAX_WORD_LENGTH + 1];
    int current_word_pos = 0;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            line++;
        }
        if (current_word_pos == 0 && !is_valid_char(c)) {
            continue; // Skips whitespace
        }
        if (is_valid_char(c)) {
            if (current_word_pos < MAX_WORD_LENGTH) {
                current_word[current_word_pos++] = tolower(c);
            }
        } else {
            current_word[current_word_pos] = '\0';
            if (strlen(current_word) > 0 && !is_word_in_tree(dictionary, current_word)) {
                printf("Potential spelling error in line %d: %s\n", line, current_word);
            }
            current_word_pos = 0;
        }
    }
}

int main() {
    node* dictionary = populate_tree("dictionary.txt");
    spell_check("text.txt", dictionary);
    return 0;
}