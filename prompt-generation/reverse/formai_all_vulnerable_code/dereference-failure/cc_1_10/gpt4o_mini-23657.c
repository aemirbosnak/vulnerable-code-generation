//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000
#define HASH_SIZE 1000

typedef struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
    struct Word *next;
} Word;

unsigned int hash(const char *str) {
    unsigned int hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % HASH_SIZE;
}

Word *create_word(const char *str) {
    Word *new_word = malloc(sizeof(Word));
    if (!new_word) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(new_word->word, str, MAX_WORD_LENGTH);
    new_word->word[MAX_WORD_LENGTH - 1] = '\0'; // Ensure null-termination
    new_word->count = 1;
    new_word->next = NULL;
    return new_word;
}

void add_word(Word **hash_table, const char *str) {
    unsigned int index = hash(str);
    Word *current = hash_table[index];

    while (current) {
        if (strcmp(current->word, str) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }

    // Word not found, add it to the hash table
    Word *new_word = create_word(str);
    new_word->next = hash_table[index];
    hash_table[index] = new_word;
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

void clean_word(char *str) {
    char *start = str;
    char *end;

    // Trim leading whitespace
    while (isspace((unsigned char)*start)) {
        start++;
    }

    // Trim trailing punctuation
    end = start + strlen(start) - 1;
    while (end > start && (ispunct((unsigned char)*end) || isspace((unsigned char)*end))) {
        end--;
    }
    
    end[1] = '\0'; // Null-terminate the cleaned string

    // Update clean word
    if (start != str) {
        memmove(str, start, end - start + 2); // +2 for the null-terminator
    }
}

void print_word_counts(Word **hash_table) {
    for (int i = 0; i < HASH_SIZE; i++) {
        Word *current = hash_table[i];
        while (current) {
            printf("%s: %d\n", current->word, current->count);
            current = current->next;
        }
    }
}

void free_memory(Word **hash_table) {
    for (int i = 0; i < HASH_SIZE; i++) {
        Word *current = hash_table[i];
        while (current) {
            Word *temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    Word *hash_table[HASH_SIZE] = {0};
    char buffer[MAX_WORD_LENGTH];

    while (fscanf(file, "%99s", buffer) == 1) {
        clean_word(buffer);
        to_lowercase(buffer);
        if (strlen(buffer) > 0) {
            add_word(hash_table, buffer);
        }
    }

    fclose(file);

    print_word_counts(hash_table);
    free_memory(hash_table);

    return EXIT_SUCCESS;
}