//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int is_word_character(char c) {
    return isalpha(c) || c == '\''; // Allow letters and apostrophes
}

void process_text(const char *filename, WordCount *wordCounts, int *wordCountSize) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%49s", word) == 1) {
        to_lowercase(word);
        
        // Remove punctuation from the end
        size_t len = strlen(word);
        while (len > 0 && !is_word_character(word[len - 1])) {
            word[len - 1] = '\0';
            len--;
        }

        // Increment count for the word
        int found = 0;
        for (int i = 0; i < *wordCountSize; i++) {
            if (strcmp(wordCounts[i].word, word) == 0) {
                wordCounts[i].count++;
                found = 1;
                break;
            }
        }

        // If the word isn't found yet, add it
        if (!found && *wordCountSize < MAX_WORDS) {
            strcpy(wordCounts[*wordCountSize].word, word);
            wordCounts[*wordCountSize].count = 1;
            (*wordCountSize)++;
        }
    }
    fclose(file);
}

void sort_word_counts(WordCount *wordCounts, int wordCountSize) {
    for (int i = 0; i < wordCountSize - 1; i++) {
        for (int j = 0; j < wordCountSize - i - 1; j++) {
            if (wordCounts[j].count < wordCounts[j + 1].count) {
                WordCount temp = wordCounts[j];
                wordCounts[j] = wordCounts[j + 1];
                wordCounts[j + 1] = temp;
            }
        }
    }
}

void write_summary(const char *filename, WordCount *wordCounts, int wordCountSize, int topN) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < topN && i < wordCountSize; i++) {
        fprintf(file, "%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> [top_n]\n", argv[0]);
        return 1;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    int topN = (argc > 3) ? atoi(argv[3]) : 10; // Default to top 10 words

    WordCount wordCounts[MAX_WORDS];
    int wordCountSize = 0;

    process_text(inputFile, wordCounts, &wordCountSize);
    sort_word_counts(wordCounts, wordCountSize);
    write_summary(outputFile, wordCounts, wordCountSize, topN);

    printf("Summary written to %s\n", outputFile);
    return 0;
}