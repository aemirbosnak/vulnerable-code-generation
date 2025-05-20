//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 64

typedef struct {
    char *word;
    int count;
} WordCount;

int main(int argc, char **argv) {
    FILE *file;
    char line[MAX_LINE_SIZE];
    char word[MAX_WORD_SIZE];
    WordCount *word_counts = NULL;
    int num_words = 0;
    int total_words = 0;
    int i;

    // Open the file
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    // Count the words
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        total_words += count_words(line, &word_counts, &num_words);
    }

    // Print the results
    printf("Total words: %d\n", total_words);
    printf("Unique words: %d\n", num_words);
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    // Clean up
    for (i = 0; i < num_words; i++) {
        free(word_counts[i].word);
    }
    free(word_counts);
    fclose(file);

    return 0;
}

int count_words(char *line, WordCount **word_counts, int *num_words) {
    char *word;
    char *end;
    int count;

    // Count the words in the line
    word = strtok_r(line, " \t\n\r\f", &end);
    while (word!= NULL) {
        count = 0;
        while (*word == '-' || *word == '\'') {
            count++;
            word++;
        }
        if (count > 0) {
            word += count;
        }
        if (strlen(word) > MAX_WORD_SIZE) {
            word[MAX_WORD_SIZE - 1] = '\0';
        }
        // Add the word to the hash table
        WordCount *word_count = NULL;
        for (int i = 0; i < *num_words; i++) {
            if (strcmp(word, (*word_counts)[i].word) == 0) {
                word_count = &(*word_counts)[i];
                break;
            }
        }
        if (word_count == NULL) {
            word_count = malloc(sizeof(WordCount));
            word_count->word = strdup(word);
            word_count->count = 1;
            (*num_words)++;
            (*word_counts) = realloc(*word_counts, sizeof(WordCount) * (*num_words));
            (*word_counts)[*num_words - 1] = *word_count;
        } else {
            word_count->count++;
        }
        word = strtok_r(NULL, " \t\n\r\f", &end);
    }
    return *num_words;
}