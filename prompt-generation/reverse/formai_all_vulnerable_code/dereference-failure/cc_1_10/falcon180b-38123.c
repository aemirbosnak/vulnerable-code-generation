//Falcon-180B DATASET v1.0 Category: Text processing ; Style: inquisitive
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
        buffer[index++] = ch;
    }
    buffer[index] = '\0';
}

int isWord(char *word) {
    int i;

    for (i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }
    return 1;
}

void countWords(char *buffer, WordCount words[]) {
    char *token;
    int i;

    token = strtok(buffer, ",.?!;:");
    while (token!= NULL) {
        if (isWord(token)) {
            for (i = 0; i < MAX_WORDS; i++) {
                if (strcmp(words[i].word, token) == 0) {
                    words[i].count++;
                    break;
                }
            }
        }
        token = strtok(NULL, ",.?!;:");
    }
}

void printWords(WordCount words[]) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *file;
    char buffer[100000];
    WordCount words[MAX_WORDS];

    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    readFile(file, buffer);
    countWords(buffer, words);
    printWords(words);

    fclose(file);
    return 0;
}