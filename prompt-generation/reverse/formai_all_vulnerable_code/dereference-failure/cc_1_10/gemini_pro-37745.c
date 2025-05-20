//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* word;
    int count;
} WordCount;

int compareWordCount(const void* a, const void* b) {
    WordCount* wordCountA = (WordCount*)a;
    WordCount* wordCountB = (WordCount*)b;
    return strcmp(wordCountA->word, wordCountB->word);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char** words = NULL;
    int numWords = 0;
    char* line = NULL;
    size_t lineLength = 0;
    while (getline(&line, &lineLength, fp) != -1) {
        char* word = strtok(line, " ");
        while (word != NULL) {
            int found = 0;
            for (int i = 0; i < numWords; i++) {
                if (strcmp(word, words[i]) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                words = realloc(words, (numWords + 1) * sizeof(char*));
                words[numWords++] = strdup(word);
            }
            word = strtok(NULL, " ");
        }
    }
    fclose(fp);

    WordCount* wordCounts = malloc(numWords * sizeof(WordCount));
    for (int i = 0; i < numWords; i++) {
        wordCounts[i].word = words[i];
        wordCounts[i].count = 0;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    while (getline(&line, &lineLength, fp) != -1) {
        char* word = strtok(line, " ");
        while (word != NULL) {
            for (int i = 0; i < numWords; i++) {
                if (strcmp(word, words[i]) == 0) {
                    wordCounts[i].count++;
                    break;
                }
            }
            word = strtok(NULL, " ");
        }
    }
    fclose(fp);

    qsort(wordCounts, numWords, sizeof(WordCount), compareWordCount);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
        free(words[i]);
    }
    free(words);
    free(wordCounts);
    free(line);

    return EXIT_SUCCESS;
}