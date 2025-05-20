//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: intelligent
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

void readFile(FILE *file, char *buffer) {
    int ch;
    int index = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (index >= strlen(buffer)) {
            printf("Buffer overflow\n");
            exit(1);
        }
        buffer[index++] = tolower(ch);
    }
    buffer[index] = '\0';
}

void tokenize(char *buffer, WordCount words[]) {
    char *token;
    int i = 0;

    token = strtok(buffer, " \t\n\r\f\v,.?!;:");
    while (token!= NULL && i < MAX_WORDS) {
        strcpy(words[i].word, token);
        words[i].count = 1;
        i++;
        token = strtok(NULL, " \t\n\r\f\v,.?!;:");
    }
}

void printWords(WordCount words[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[10000];
    WordCount words[MAX_WORDS];

    if (argc!= 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    readFile(file, buffer);
    fclose(file);

    tokenize(buffer, words);

    printWords(words, MAX_WORDS);

    return 0;
}