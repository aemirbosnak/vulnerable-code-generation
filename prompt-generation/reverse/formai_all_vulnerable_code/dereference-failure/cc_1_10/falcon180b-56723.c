//Falcon-180B DATASET v1.0 Category: Text processing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, char *buffer) {
    int ch;
    int index = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (index >= strlen(buffer)) {
            printf("Error: Buffer overflow\n");
            exit(1);
        }
        buffer[index++] = ch;
    }
    buffer[index] = '\0';
}

void tokenize(char *buffer, WordCount words[MAX_WORDS]) {
    char *word = strtok(buffer, ",.?!;:");
    int i = 0;

    while (word!= NULL && i < MAX_WORDS) {
        strcpy(words[i].word, word);
        words[i].count = 1;
        i++;
        word = strtok(NULL, ",.?!;:");
    }
}

void print_word_counts(WordCount words[MAX_WORDS]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    char buffer[1024];
    read_file(file, buffer);

    WordCount words[MAX_WORDS];
    tokenize(buffer, words);

    print_word_counts(words);

    fclose(file);
    return 0;
}