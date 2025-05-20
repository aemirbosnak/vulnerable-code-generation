//FormAI DATASET v1.0 Category: Spell checking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 20 // Maximum length of a word
#define HASH_TABLE_SIZE 5000 // Size of the hash table
#define CORRECT 0 // Return value if word is spelled correctly
#define MISSPELLED 1 // Return value if word is misspelled

// Node for each word in the hash table
typedef struct node {
    char *word;
    struct node *next;
} Node;

// Hash table for words
Node *hash_table[HASH_TABLE_SIZE];

// Hash function
int hash(char *word) {
    int hash = 0;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        hash = hash * 31 + word[i];
    }
    return hash % HASH_TABLE_SIZE;
}

// Add word to the hash table
void add_word(char *word) {
    int index = hash(word);
    Node *new_node = malloc(sizeof(Node));
    new_node->word = word;
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}

// Load dictionary words into the hash table
void load_dictionary(char *filename) {
    FILE *fp = fopen(filename, "r");
    char word[MAX_WORD_LEN + 1];

    if (!fp) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(word, MAX_WORD_LEN + 1, fp)) {
        int len = strlen(word);
        if (len > 0 && word[len - 1] == '\n') {
            word[len - 1] = '\0';
        }
        add_word(strdup(word));
    }

    fclose(fp);
}

// Check if word is spelled correctly
int check_spelling(char *word) {
    int index = hash(word);
    Node *node = hash_table[index];
    while (node) {
        if (strcmp(node->word, word) == 0) {
            return CORRECT;
        }
        node = node->next;
    }
    return MISSPELLED;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <dictionary-file> <input-file>\n", argv[0]);
        return 1;
    }

    char *dict_filename = argv[1];
    char *input_filename = argv[2];

    load_dictionary(dict_filename);

    FILE *fp = fopen(input_filename, "r");

    if (!fp) {
        printf("Error opening file.\n");
        exit(1);
    }

    char word[MAX_WORD_LEN + 1];
    int line_number = 1;
    int misspellings = 0;

    while (fgets(word, MAX_WORD_LEN + 1, fp)) {
        int len = strlen(word);
        if (len > 0 && word[len - 1] == '\n') {
            word[len - 1] = '\0';
        }

        for (int i = 0; i < len; i++) {
            if (ispunct(word[i])) {
                word[i] = '\0';
            }
            word[i] = tolower(word[i]);
        }

        if (check_spelling(word) == MISSPELLED) {
            printf("Misspelled word \"%s\" found on line %d.\n", word, line_number);
            misspellings++;
        }

        if (word[len - 1] == '\0') {
            line_number++;
        }
    }

    fclose(fp);

    printf("\n%d misspellings found.\n", misspellings);

    return 0;
}