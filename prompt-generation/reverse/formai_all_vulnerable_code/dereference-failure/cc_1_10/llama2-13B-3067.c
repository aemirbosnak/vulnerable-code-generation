//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_WORD_LENGTH 50
#define MAX_HASH_TABLE_SIZE 10000

typedef struct word_frequency {
    char *word;
    int frequency;
} word_frequency;

typedef struct hash_table {
    word_frequency **table;
    int size;
} hash_table;

void init_hash_table(hash_table *ht) {
    ht->table = (word_frequency **) malloc(MAX_HASH_TABLE_SIZE * sizeof(word_frequency *));
    ht->size = 0;
}

void add_word_to_hash_table(hash_table *ht, char *word) {
    int i = word[0] % MAX_HASH_TABLE_SIZE;
    word_frequency *entry = ht->table[i];
    if (entry == NULL) {
        entry = (word_frequency *) malloc(sizeof(word_frequency));
        entry->word = word;
        entry->frequency = 1;
        ht->table[i] = entry;
    } else {
        entry->frequency++;
    }
    ht->size++;
}

void print_word_frequencies(hash_table *ht) {
    int i;
    for (i = 0; i < MAX_HASH_TABLE_SIZE; i++) {
        word_frequency *entry = ht->table[i];
        if (entry != NULL) {
            printf("%d: %s\n", entry->frequency, entry->word);
        }
    }
}

void calculate_statistics(hash_table *ht) {
    int i;
    int max_frequency = 0;
    char *max_word = NULL;
    double avg_word_length = 0;
    double shannon_entropy = 0;
    for (i = 0; i < MAX_HASH_TABLE_SIZE; i++) {
        word_frequency *entry = ht->table[i];
        if (entry != NULL) {
            int frequency = entry->frequency;
            if (frequency > max_frequency) {
                max_frequency = frequency;
                max_word = entry->word;
            }
            avg_word_length += strlen(entry->word);
            shannon_entropy += frequency * log(frequency) / log(2);
        }
    }
    printf("Most common word: %s (%d times)\n", max_word, max_frequency);
    printf("Average word length: %f\n", avg_word_length / (double) ht->size);
    printf("Shannon entropy: %f\n", shannon_entropy / (double) ht->size);
}

int main() {
    hash_table *ht = NULL;
    char text[] = "This is a sample text for testing the word count tool.";
    char word[MAX_WORD_LENGTH];
    int i;

    init_hash_table(&ht);

    // Tokenize the text and add each word to the hash table
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            word[i - 1] = text[i];
            add_word_to_hash_table(ht, word);
        }
    }

    // Print the word frequencies
    print_word_frequencies(ht);

    // Calculate the statistics
    calculate_statistics(ht);

    return 0;
}