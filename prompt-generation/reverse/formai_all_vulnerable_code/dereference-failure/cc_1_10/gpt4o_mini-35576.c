//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define HASH_TABLE_SIZE 1000

typedef struct WordCount {
    char word[MAX_WORD_LENGTH];
    int count;
    struct WordCount* next;
} WordCount;

unsigned long hash(const char* word) {
    unsigned long hash = 5381;
    int c;
    while ((c = *word++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % HASH_TABLE_SIZE;
}

WordCount* create_word_count(const char* word) {
    WordCount* new_word_count = (WordCount*)malloc(sizeof(WordCount));
    if (new_word_count) {
        strncpy(new_word_count->word, word, MAX_WORD_LENGTH);
        new_word_count->word[MAX_WORD_LENGTH - 1] = '\0';
        new_word_count->count = 1;
        new_word_count->next = NULL;
    }
    return new_word_count;
}

void insert_word(WordCount** hash_table, const char* word) {
    unsigned long index = hash(word);
    WordCount* entry = hash_table[index];

    while (entry != NULL) {
        if (strcmp(entry->word, word) == 0) {
            entry->count++;
            return;
        }
        entry = entry->next;
    }

    WordCount* new_entry = create_word_count(word);
    new_entry->next = hash_table[index];
    hash_table[index] = new_entry;
}

void free_word_counts(WordCount** hash_table) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        WordCount* entry = hash_table[i];
        while (entry != NULL) {
            WordCount* temp = entry;
            entry = entry->next;
            free(temp);
        }
    }
}

void print_word_counts(WordCount** hash_table) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        WordCount* entry = hash_table[i];
        while (entry != NULL) {
            printf("%s: %d\n", entry->word, entry->count);
            entry = entry->next;
        }
    }
}

void process_file(const char* filename, WordCount** hash_table) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%99s", word) == 1) {
        // Convert word to lowercase
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }
        insert_word(hash_table, word);
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    WordCount* hash_table[HASH_TABLE_SIZE] = { NULL };

    process_file(argv[1], hash_table);
    print_word_counts(hash_table);
    free_word_counts(hash_table);

    return EXIT_SUCCESS;
}