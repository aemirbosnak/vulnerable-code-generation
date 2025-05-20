//Falcon-180B DATASET v1.0 Category: Text processing ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readFile(FILE* file, char* buffer) {
    int ch;
    while ((ch = fgetc(file))!= EOF) {
        if (isspace(ch)) {
            buffer[strlen(buffer) - 1] = '\0';
            strcat(buffer, " ");
        } else {
            strcat(buffer, &ch);
        }
    }
}

void tokenize(char* buffer, WordCount words[MAX_WORDS]) {
    char* word = strtok(buffer, " ");
    int i = 0;

    while (word!= NULL && i < MAX_WORDS) {
        strcpy(words[i].word, word);
        words[i].count = 1;
        i++;
        word = strtok(NULL, " ");
    }
}

void printWords(WordCount words[MAX_WORDS]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char buffer[1024];
    readFile(file, buffer);

    WordCount words[MAX_WORDS];
    tokenize(buffer, words);

    printWords(words);

    fclose(file);
    return 0;
}