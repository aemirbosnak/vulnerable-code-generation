//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWordCount(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;
    return strcmp(wc1->word, wc2->word);
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }

    char buffer[1024];
    int bufferSize = sizeof(buffer);
    char *words[1000];
    int wordCount = 0;

    while (fgets(buffer, bufferSize, file) != NULL) {
        char *word = strtok(buffer, " ");
        while (word != NULL) {
            int found = 0;
            for (int i = 0; i < wordCount; i++) {
                if (strcmp(word, words[i]) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                words[wordCount] = strdup(word);
                wordCount++;
            }
            word = strtok(NULL, " ");
        }
    }

    WordCount wordCounts[wordCount];
    for (int i = 0; i < wordCount; i++) {
        wordCounts[i].word = words[i];
        wordCounts[i].count = 0;
    }

    fseek(file, 0, SEEK_SET);
    while (fgets(buffer, bufferSize, file) != NULL) {
        char *word = strtok(buffer, " ");
        while (word != NULL) {
            for (int i = 0; i < wordCount; i++) {
                if (strcmp(word, wordCounts[i].word) == 0) {
                    wordCounts[i].count++;
                    break;
                }
            }
            word = strtok(NULL, " ");
        }
    }

    fclose(file);

    qsort(wordCounts, wordCount, sizeof(WordCount), compareWordCount);

    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    for (int i = 0; i < wordCount; i++) {
        free(words[i]);
    }

    return 0;
}