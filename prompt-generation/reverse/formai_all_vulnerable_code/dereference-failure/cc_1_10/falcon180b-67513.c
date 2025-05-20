//Falcon-180B DATASET v1.0 Category: Text processing ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readFile(FILE *file, char *buffer) {
    int ch;
    int index = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (index >= strlen(buffer)) {
            printf("Buffer overflow!\n");
            exit(1);
        }

        buffer[index++] = ch;
    }

    buffer[index] = '\0';
}

void tokenize(char *buffer, char delimiter, WordCount words[]) {
    char *word = strtok(buffer, delimiter);
    int count = 0;

    while (word!= NULL && count < MAX_WORDS) {
        strcpy(words[count].word, word);
        words[count].count = 1;
        count++;

        word = strtok(NULL, delimiter);
    }
}

void printWords(WordCount words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input file> <delimiter>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char delimiter = argv[2][0];

    char buffer[MAX_WORD_LENGTH];
    readFile(file, buffer);

    WordCount words[MAX_WORDS];
    tokenize(buffer, delimiter, words);

    printWords(words, MAX_WORDS);

    fclose(file);
    return 0;
}