//Falcon-180B DATASET v1.0 Category: Text processing ; Style: expert-level
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

void read_file(FILE *file, char *buffer) {
    int ch;
    int index = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (index >= sizeof(buffer) - 1) {
            printf("Error: buffer overflow\n");
            exit(1);
        }
        buffer[index++] = ch;
    }

    buffer[index] = '\0';
}

void tokenize(char *buffer, char delimiter, WordCount words[MAX_WORDS]) {
    char *token;
    int i = 0;

    token = strtok(buffer, delimiter);
    while (token!= NULL) {
        if (i >= MAX_WORDS) {
            printf("Error: too many words\n");
            exit(1);
        }
        strcpy(words[i].word, token);
        words[i].count = 1;
        i++;
        token = strtok(NULL, delimiter);
    }
}

void print_word_counts(WordCount words[MAX_WORDS]) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[MAX_WORD_LENGTH * 1000];
    char delimiter;
    WordCount words[MAX_WORDS];

    if (argc!= 3) {
        printf("Usage: %s <filename> <delimiter>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }

    delimiter = argv[2][0];

    read_file(file, buffer);
    fclose(file);

    tokenize(buffer, delimiter, words);
    print_word_counts(words);

    return 0;
}