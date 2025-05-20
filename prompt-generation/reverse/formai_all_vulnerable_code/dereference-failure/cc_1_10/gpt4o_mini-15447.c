//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 100
#define MAX_WORDS 500

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void to_lowercase(char *str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int compare_word_count(const void *a, const void *b) {
    WordCount *wordA = (WordCount *)a;
    WordCount *wordB = (WordCount *)b;
    return wordB->count - wordA->count; // Sort in descending order
}

void process_text_file(const char *filename, WordCount *word_counts, int *unique_word_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " ,.!?;:\n");
        while (token != NULL) {
            to_lowercase(token); // Convert to lowercase
            // Check if the word already exists in the array
            int found = 0;
            for (int i = 0; i < *unique_word_count; i++) {
                if (strcmp(word_counts[i].word, token) == 0) {
                    word_counts[i].count++;
                    found = 1;
                    break;
                }
            }
            // If not found, add it to the list
            if (!found && *unique_word_count < MAX_WORDS) {
                strcpy(word_counts[*unique_word_count].word, token);
                word_counts[*unique_word_count].count = 1;
                (*unique_word_count)++;
            }
            token = strtok(NULL, " ,.!?;:\n");
        }
    }
    fclose(file);
}

void print_word_frequencies(WordCount *word_counts, int unique_word_count) {
    printf("Word Frequency Count:\n");
    for (int i = 0; i < unique_word_count; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

void print_top_words(WordCount *word_counts, int unique_word_count, int top_n) {
    printf("\nTop %d Words:\n", top_n);
    for (int i = 0; i < top_n && i < unique_word_count; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <top_n>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    int top_n = atoi(argv[2]);

    WordCount word_counts[MAX_WORDS];
    int unique_word_count = 0;

    process_text_file(filename, word_counts, &unique_word_count);

    // Sort word counts in descending order
    qsort(word_counts, unique_word_count, sizeof(WordCount), compare_word_count);

    print_word_frequencies(word_counts, unique_word_count);
    print_top_words(word_counts, unique_word_count, top_n);

    return EXIT_SUCCESS;
}