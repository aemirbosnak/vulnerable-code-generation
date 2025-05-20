//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct WordCount {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int compare_word_counts(const void *a, const void *b) {
    WordCount *wc_a = (WordCount *)a;
    WordCount *wc_b = (WordCount *)b;
    return wc_b->count - wc_a->count; // Sort descending by count
}

void print_word_counts(WordCount *wordCounts, int totalWords) {
    printf("Word Frequency Count:\n");
    for (int i = 0; i < totalWords; i++) {
        if (wordCounts[i].count > 0) {
            printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }
}

void add_word(WordCount *wordCounts, int *totalWords, const char *word) {
    for (int i = 0; i < *totalWords; i++) {
        if (strcmp(wordCounts[i].word, word) == 0) {
            wordCounts[i].count++;
            return;
        }
    }

    if (*totalWords < MAX_WORDS) {
        strcpy(wordCounts[*totalWords].word, word);
        wordCounts[*totalWords].count = 1;
        (*totalWords)++;
    }
}

void process_text(const char *text) {
    WordCount wordCounts[MAX_WORDS] = { { "", 0 } };
    int totalWords = 0;
    
    char *copy = strdup(text);
    char *token = strtok(copy, " \n\t.,;:\"()!?");
    
    while (token != NULL) {
        if (strlen(token) > 0) {
            to_lowercase(token);
            add_word(wordCounts, &totalWords, token);
        }
        token = strtok(NULL, " \n\t.,;:\"()!?");
    }
    
    free(copy);
    qsort(wordCounts, totalWords, sizeof(WordCount), compare_word_counts);
    print_word_counts(wordCounts, totalWords);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <text-file>\n", argv[0]);
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char *buffer = (char *)malloc(fileSize + 1);
    if (!buffer) {
        perror("Failed to allocate memory");
        fclose(file);
        return 1;
    }

    fread(buffer, 1, fileSize, file);
    buffer[fileSize] = '\0';
    fclose(file);
    
    process_text(buffer);
    free(buffer);
    
    return 0;
}