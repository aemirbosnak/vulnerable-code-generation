//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;

    return strcasecmp(wc1->word, wc2->word);
}

char* readLine(FILE *file) {
    char line[MAX_WORD_LENGTH];
    char* result = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = fgetc(file))!= EOF) {
        if (read == '\n') {
            line[len] = '\0';
            result = strdup(line);
            break;
        } else if (len >= MAX_WORD_LENGTH - 1) {
            fprintf(stderr, "Line too long: %s\n", line);
            exit(EXIT_FAILURE);
        } else {
            line[len++] = tolower(read);
        }
    }

    return result;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    FILE* outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    WordCount words[MAX_WORDS];
    int numWords = 0;

    char* line = NULL;
    while ((line = readLine(inputFile))!= NULL) {
        char* word = strtok(line, ",.!?;:");
        while (word!= NULL) {
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                if (numWords >= MAX_WORDS) {
                    fprintf(stderr, "Too many unique words: %s\n", word);
                    exit(EXIT_FAILURE);
                }
                strncpy(words[numWords].word, word, MAX_WORD_LENGTH - 1);
                words[numWords].word[MAX_WORD_LENGTH - 1] = '\0';
                words[numWords].count = 1;
                numWords++;
            }
            word = strtok(NULL, ",.!?;:");
        }
        free(line);
    }

    qsort(words, numWords, sizeof(WordCount), compareWords);

    fprintf(outputFile, "Word Count:\n");
    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s: %d\n", words[i].word, words[i].count);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}