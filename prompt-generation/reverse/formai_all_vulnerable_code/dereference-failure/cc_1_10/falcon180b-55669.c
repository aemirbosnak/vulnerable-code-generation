//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 1000
#define MAX_LINE_LENGTH 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount *) a;
    WordCount *wordB = (WordCount *) b;
    return strcmp(wordA->word, wordB->word);
}

char* extractWord(char *line) {
    char *word = line;
    while (*word!= '\0' &&!isspace(*word)) {
        word++;
    }
    if (*word == '\0') {
        return NULL;
    }
    *word = '\0';
    return line;
}

void countWords(char *filename) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    WordCount *wordCounts = (WordCount *) malloc(sizeof(WordCount) * 100000);
    int numWords = 0;
    int i;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *word = extractWord(line);
        if (word!= NULL) {
            for (i = 0; i < numWords; i++) {
                if (strcmp(wordCounts[i].word, word) == 0) {
                    wordCounts[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                strcpy(wordCounts[numWords].word, word);
                wordCounts[numWords].count = 1;
                numWords++;
            }
        }
    }

    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    free(wordCounts);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }
    countWords(argv[1]);
    return 0;
}