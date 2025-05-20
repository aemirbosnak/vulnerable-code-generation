//FormAI DATASET v1.0 Category: Spell checking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50 // Maximum length of a word
#define DICT_SIZE 109583 // Number of words in the dictionary

// Hash function (djb2 algorithm)
unsigned int hash(char *str)
{
    unsigned int hashval = 5381;
    int c;

    while ((c = *str++))
        hashval = ((hashval << 5) + hashval) + c; /* hashval * 33 + c */

    return hashval;
}

// Node of the hash table
struct node {
    char *word;
    struct node *next;
};

// Create a new node
struct node *new_node(char *word)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->word = strdup(word);
    new_node->next = NULL;
    return new_node;
}

// Add a word to the hash table
void add_word(char *word, struct node **hash_table)
{
    // Hash the word
    unsigned int index = hash(word) % DICT_SIZE;

    // Check if the word is already in the hash table
    struct node *current = hash_table[index];
    while (current != NULL) {
        if (strcmp(current->word, word) == 0)
            return;
        current = current->next;
    }

    // Add the word to the hash table
    struct node *new = new_node(word);
    new->next = hash_table[index];
    hash_table[index] = new;
}

// Load the dictionary file and add all the words to the hash table
void load_dict(char *path, struct node **hash_table)
{
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file\n");
        exit(1);
    }

    char line[MAX_WORD_LEN + 1];
    while (fgets(line, MAX_WORD_LEN + 1, file) != NULL) {
        line[strlen(line) - 1] = '\0'; // Remove newline character
        add_word(line, hash_table);
    }

    fclose(file);
}

// Convert a word to lowercase
void to_lower(char *word)
{
    for (int i = 0; word[i]; i++)
        word[i] = tolower(word[i]);
}

// Check if a word is in the dictionary
int check_word(char *word, struct node **hash_table)
{
    // Convert the word to lowercase
    to_lower(word);

    // Hash the word
    unsigned int index = hash(word) % DICT_SIZE;

    // Check if the word is in the hash table
    struct node *current = hash_table[index];
    while (current != NULL) {
        if (strcmp(current->word, word) == 0)
            return 1;
        current = current->next;
    }

    return 0;
}

// Spell check a file
void spell_check(char *path, struct node **hash_table)
{
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    int line_num = 0;
    char line[MAX_WORD_LEN + 1];
    while (fgets(line, MAX_WORD_LEN + 1, file) != NULL) {
        line_num++;

        char *word;
        for (word = strtok(line, " \t\n"); word != NULL; word = strtok(NULL, " \t\n")) {
            if (!check_word(word, hash_table)) {
                printf("Line %d: %s\n", line_num, word);
            }
        }
    }

    fclose(file);
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: spell_check dict_file input_file\n");
        exit(1);
    }

    // Create the hash table
    struct node **hash_table = malloc(sizeof(struct node *) * DICT_SIZE);
    for (int i = 0; i < DICT_SIZE; i++)
        hash_table[i] = NULL;

    // Load the dictionary
    load_dict(argv[1], hash_table);

    // Spell check the input file
    spell_check(argv[2], hash_table);

    return 0;
}