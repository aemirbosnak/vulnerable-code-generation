//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char **words;
    int count;
} WordCount;

void initializeWordCount(WordCount *wc) {
    wc->words = malloc(MAX_WORDS * sizeof(char *));
    for (int i = 0; i < MAX_WORDS; i++) {
        wc->words[i] = malloc(MAX_WORD_LENGTH * sizeof(char));
    }
    wc->count = 0;
}

void freeWordCount(WordCount *wc) {
    for (int i = 0; i < wc->count; i++) {
        free(wc->words[i]);
    }
    free(wc->words);
}

void addWord(WordCount *wc, const char *word) {
    if (wc->count < MAX_WORDS) {
        strncpy(wc->words[wc->count], word, MAX_WORD_LENGTH - 1);
        wc->words[wc->count][MAX_WORD_LENGTH - 1] = '\0';  // Null-terminate
        wc->count++;
    }
}

void countWordsInLine(WordCount *wc, const char *line) {
    char *token;
    char *lineCopy = strdup(line);  // Duplicate line to tokenize
    token = strtok(lineCopy, " \t\n");  // Split using space, tab and newline as delimiters

    while (token != NULL) {
        addWord(wc, token);
        token = strtok(NULL, " \t\n");
    }
    
    free(lineCopy);
}

void printWordCount(WordCount *wc) {
    printf("Total word count: %d\n", wc->count);
    printf("Words:\n");
    for (int i = 0; i < wc->count; i++) {
        printf("%s\n", wc->words[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    WordCount wc;
    initializeWordCount(&wc);

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        countWordsInLine(&wc, line);
    }

    fclose(file);

    printWordCount(&wc);
    freeWordCount(&wc);
    return EXIT_SUCCESS;
}