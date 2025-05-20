//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void to_lower_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int compare(const void *a, const void *b) {
    return ((WordCount *)b)->count - ((WordCount *)a)->count;
}

void add_word(WordCount *words, int *total_count, const char *new_word) {
    for (int i = 0; i < *total_count; i++) {
        if (strcmp(words[i].word, new_word) == 0) {
            words[i].count++;
            return;
        }
    }
    strcpy(words[*total_count].word, new_word);
    words[*total_count].count = 1;
    (*total_count)++;
}

void print_summary(WordCount *words, int total_count, int summary_size) {
    printf("Top %d words:\n", summary_size);
    for (int i = 0; i < summary_size && i < total_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

void summarize_text(const char *filename, int summary_size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    WordCount words[MAX_WORDS];
    int total_count = 0;
    char buffer[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", buffer) != EOF) {
        to_lower_case(buffer);
        // Remove punctuation (simplified version)
        char *end = buffer + strlen(buffer) - 1;
        while (end >= buffer && ispunct(*end)) *end-- = '\0';
        if (strlen(buffer) > 0) {
            add_word(words, &total_count, buffer);
        }
    }
    
    fclose(file);

    qsort(words, total_count, sizeof(WordCount), compare);
    print_summary(words, total_count, summary_size);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <summary_size>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *filename = argv[1];
    int summary_size = atoi(argv[2]);
    
    if (summary_size <= 0 || summary_size > MAX_WORDS) {
        fprintf(stderr, "Error: Summary size must be a positive integer and less than %d.\n", MAX_WORDS);
        return EXIT_FAILURE;
    }
    
    summarize_text(filename, summary_size);
    
    return EXIT_SUCCESS;
}