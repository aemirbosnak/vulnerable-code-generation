//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 10000

// Node structure for linked list
typedef struct Node {
    char word[MAX_WORD_LENGTH];
    struct Node *next;
} Node;

Node *dictionary[DICTIONARY_SIZE];

// Hash function to get index for a word
unsigned int hash(const char *word) {
    unsigned int hash = 0;
    while (*word) {
        hash = (hash << 2) ^ (unsigned char)(*word);
        word++;
    }
    return hash % DICTIONARY_SIZE;
}

// Load the dictionary into memory
int load_dictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open dictionary file.\n");
        return 0;
    }
    
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%99s", word) != EOF) {
        // Normalize word to lowercase
        for (int i = 0; word[i]; i++) {
            word[i] = tolower((unsigned char)word[i]);
        }
        unsigned int index = hash(word);
        Node *new_node = (Node *)malloc(sizeof(Node));
        strcpy(new_node->word, word);
        new_node->next = dictionary[index];
        dictionary[index] = new_node;
    }
    
    fclose(file);
    return 1;
}

// Check if a word is in the dictionary
int check_word(const char *word) {
    unsigned int index = hash(word);
    Node *current = dictionary[index];
    while (current) {
        if (strcmp(current->word, word) == 0) {
            return 1; // Found
        }
        current = current->next;
    }
    return 0; // Not found
}

// Free memory used by the dictionary
void free_dictionary() {
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        Node *current = dictionary[i];
        while (current) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
}

// Normalize input text to words
void normalize_input_text(const char *input, char words[][MAX_WORD_LENGTH], int *word_count) {
    char temp[MAX_WORD_LENGTH];
    int index = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            temp[index++] = tolower((unsigned char)input[i]);
        } else {
            if (index > 0) {
                temp[index] = '\0';
                strcpy(words[*word_count], temp);
                (*word_count)++;
                index = 0;
            }
        }
    }
    // Add last word if there is one
    if (index > 0) {
        temp[index] = '\0';
        strcpy(words[*word_count], temp);
        (*word_count)++;
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <input_text>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Load dictionary
    if (!load_dictionary(argv[1])) {
        return EXIT_FAILURE;
    }

    // Read input text
    FILE *input_file = fopen(argv[2], "r");
    if (!input_file) {
        fprintf(stderr, "Could not open input file.\n");
        free_dictionary();
        return EXIT_FAILURE;
    }

    char line[256];
    while (fgets(line, sizeof(line), input_file)) {
        char words[100][MAX_WORD_LENGTH];
        int word_count = 0;

        // Normalize input line and split into words
        normalize_input_text(line, words, &word_count);

        // Check each word against the dictionary
        for (int i = 0; i < word_count; i++) {
            if (!check_word(words[i])) {
                printf("Misspelled: %s\n", words[i]);
            }
        }
    }

    fclose(input_file);
    free_dictionary();
    return EXIT_SUCCESS;
}