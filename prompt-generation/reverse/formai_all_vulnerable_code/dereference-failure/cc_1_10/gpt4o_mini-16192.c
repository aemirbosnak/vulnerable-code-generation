//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_WORDS 1000

struct WordCount {
    char word[MAX_WORD_LEN];
    int count;
};

void to_lowercase(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

void add_word(struct WordCount *word_counts, int *num_words, const char *word) {
    for (int i = 0; i < *num_words; i++) {
        if (strcmp(word_counts[i].word, word) == 0) {
            word_counts[i].count++;
            return;
        }
    }
    
    if (*num_words < MAX_WORDS) {
        strcpy(word_counts[*num_words].word, word);
        word_counts[*num_words].count = 1;
        (*num_words)++;
    } else {
        printf("Exceeded maximum word count of %d\n", MAX_WORDS);
    }
}

void process_input(FILE *fp, struct WordCount *word_counts, int *num_words) {
    char buffer[MAX_WORD_LEN + 1];
    while (fscanf(fp, "%100s", buffer) == 1) {
        to_lowercase(buffer);
        // Remove punctuation from the start and end of the word
        char *start = buffer;
        char *end = buffer + strlen(buffer) - 1;

        while (ispunct((unsigned char)*start)) start++;
        while (end > start && ispunct((unsigned char)*end)) end--;

        if (start <= end) {
            *++end = '\0'; // Null-terminate the cleaned string
            add_word(word_counts, num_words, start);
        }
    }
}

void print_word_counts(struct WordCount *word_counts, int num_words) {
    printf("Word Frequency Count:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    struct WordCount word_counts[MAX_WORDS];
    int num_words = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    process_input(fp, word_counts, &num_words);
    fclose(fp);

    print_word_counts(word_counts, num_words);

    return 0;
}