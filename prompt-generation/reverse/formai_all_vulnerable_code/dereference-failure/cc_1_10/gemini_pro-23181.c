//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

// Function to create a hash table
struct node {
    char word[MAX_WORD_LENGTH];
    struct node *next;
};

struct hash_table {
    struct node **table;
    int size;
};

struct hash_table *create_hash_table(int size) {
    struct hash_table *hash_table = (struct hash_table *)malloc(sizeof(struct hash_table));
    hash_table->table = (struct node **)malloc(sizeof(struct node *) * size);
    hash_table->size = size;
    for (int i = 0; i < size; i++) {
        hash_table->table[i] = NULL;
    }
    return hash_table;
}

// Function to insert a word into the hash table
void insert_word(struct hash_table *hash_table, char *word) {
    int index = hash_function(word, hash_table->size);
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->word, word);
    new_node->next = hash_table->table[index];
    hash_table->table[index] = new_node;
}

// Function to hash a word
int hash_function(char *word, int size) {
    int hash = 0;
    for (int i = 0; i < strlen(word); i++) {
        hash += tolower(word[i]);
    }
    return hash % size;
}

// Function to check if a word is in the hash table
int is_word_in_hash_table(struct hash_table *hash_table, char *word) {
    int index = hash_function(word, hash_table->size);
    struct node *current_node = hash_table->table[index];
    while (current_node != NULL) {
        if (strcmp(current_node->word, word) == 0) {
            return 1;
        }
        current_node = current_node->next;
    }
    return 0;
}

// Function to load the dictionary into the hash table
void load_dictionary(struct hash_table *hash_table, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        insert_word(hash_table, word);
    }
    fclose(file);
}

// Function to check the spelling of a word
int check_spelling(struct hash_table *hash_table, char *word) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j <= len; j++) {
            char subword[MAX_WORD_LENGTH];
            strncpy(subword, word + i, j - i);
            subword[j - i] = '\0';
            if (is_word_in_hash_table(hash_table, subword)) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to print the misspelled words in a sentence
void check_sentence(struct hash_table *hash_table, char *sentence) {
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        if (!check_spelling(hash_table, word)) {
            printf("%s ", word);
        }
        word = strtok(NULL, " ");
    }
}

int main() {
    struct hash_table *hash_table = create_hash_table(MAX_WORDS);
    load_dictionary(hash_table, "dictionary.txt");
    char sentence[100];
    printf("Enter a sentence: ");
    gets(sentence);
    check_sentence(hash_table, sentence);
    return 0;
}