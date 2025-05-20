//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 32

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWordCounts(const void *a, const void *b) {
    const WordCount *wordCountA = (const WordCount *)a;
    const WordCount *wordCountB = (const WordCount *)b;

    return wordCountB->count - wordCountA->count;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *logFile = fopen(argv[1], "r");
    if (logFile == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    WordCount *wordCounts = NULL;

    while (fgets(line, sizeof(line), logFile) != NULL) {
        int wordLength = 0;
        for (int i = 0; i < strlen(line); i++) {
            char character = line[i];
            if (isalpha(character)) {
                word[wordLength++] = tolower(character);
            } else if (wordLength > 0) {
                word[wordLength] = '\0';
                wordCount++;

                // Reallocate memory for wordCounts if necessary
                if (wordCount > wordCount) {
                    wordCounts = realloc(wordCounts, wordCount * sizeof(WordCount));
                }

                // Check if word is already in wordCounts
                int found = 0;
                for (int j = 0; j < wordCount; j++) {
                    if (strcmp(wordCounts[j].word, word) == 0) {
                        wordCounts[j].count++;
                        found = 1;
                        break;
                    }
                }

                // Add word to wordCounts if not found
                if (!found) {
                    wordCounts[wordCount - 1].word = malloc(wordLength + 1);
                    strcpy(wordCounts[wordCount - 1].word, word);
                    wordCounts[wordCount - 1].count = 1;
                }

                wordLength = 0;
            }
        }
    }

    fclose(logFile);

    qsort(wordCounts, wordCount, sizeof(WordCount), compareWordCounts);

    printf("Word\tCount\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s\t%d\n", wordCounts[i].word, wordCounts[i].count);
    }

    for (int i = 0; i < wordCount; i++) {
        free(wordCounts[i].word);
    }
    free(wordCounts);

    return EXIT_SUCCESS;
}