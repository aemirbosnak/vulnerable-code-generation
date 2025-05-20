//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <alloca.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define TABLE_SIZE 100003
#define WORD_LENGTH_MAX 64

typedef struct hash_node {
    char *word;
    int count;
    struct hash_node *next;
} hash_node;

unsigned long hash(const char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;

    return hash % TABLE_SIZE;
}

hash_node *create_node(const char *word) {
    hash_node *new_node = (hash_node *)calloc(1, sizeof(hash_node));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

void add_word(hash_node **table, const char *word) {
    unsigned long index = hash(word);

    if (!table[index])
        table[index] = create_node(word);
    else {
        hash_node *current = table[index];
        while (current->next)
            current = current->next;

        current->next = create_node(word);
    }
}

void load_file(const char *filename, hash_node **table) {
    FILE *file = fopen(filename, "r");
    char buffer[WORD_LENGTH_MAX];
    size_t bytes_read;

    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (getline(&buffer, sizeof(buffer), file) > 0) {
        char *word_start = buffer;

        // Skip leading whitespace
        while (isspace(*word_start))
            word_start++;

        // Extract word
        size_t word_length = strcspn(word_start, " \t\n");

        // Convert word to lowercase
        for (size_t i = 0; i < word_length; i++)
            word_start[i] = tolower(word_start[i]);

        add_word(table, word_start);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    hash_node *table[TABLE_SIZE] = { NULL };

    load_file(argv[1], table);

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!table[i])
            continue;

        printf("%s: %d\n", table[i]->word, table[i]->count);

        free(table[i]->word);
        free(table[i]);
    }

    return EXIT_SUCCESS;
}