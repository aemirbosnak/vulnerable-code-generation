//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: curious
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
    WordCount *wordA = (WordCount *) a;
    WordCount *wordB = (WordCount *) b;

    return strcmp(wordA->word, wordB->word);
}

void loadWords(WordCount *words, FILE *file) {
    char line[MAX_WORD_LENGTH];
    char *word = NULL;
    size_t len = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (line[0] == '\n' || line[0] == '\r') {
            continue;
        }

        word = strtok_r(line, " \t\n\r\f\v", &line);

        while (word!= NULL && len < MAX_WORDS) {
            int wordLen = strlen(word);

            if (wordLen > MAX_WORD_LENGTH) {
                wordLen = MAX_WORD_LENGTH;
            }

            strncpy(words[len].word, word, wordLen);
            words[len].word[wordLen] = '\0';
            words[len].count = 1;

            len++;

            word = strtok_r(NULL, " \t\n\r\f\v", &line);
        }
    }

    qsort(words, len, sizeof(WordCount), compareWords);
}

void saveWords(WordCount *words, int count, FILE *file) {
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile = fopen(argv[2], "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    WordCount words[MAX_WORDS];
    int wordCount = 0;

    loadWords(words, inputFile);
    saveWords(words, wordCount, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}