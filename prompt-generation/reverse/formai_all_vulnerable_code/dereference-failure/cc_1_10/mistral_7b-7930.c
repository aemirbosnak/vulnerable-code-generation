//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DATA_SIZE 1000000
#define MAX_ALPHABET_SIZE 256
#define MAX_WORD_LENGTH 100

typedef struct {
    int count;
    char word[MAX_WORD_LENGTH];
} TWord;

TWord word_table[MAX_ALPHABET_SIZE];

void InitializeWordTable() {
    int i;
    for (i = 0; i < MAX_ALPHABET_SIZE; i++) {
        word_table[i].count = 0;
    }
}

int FindIndex(char c) {
    return (int) isalpha(c) - (int) 'a';
}

void IncrementWordCount(char *word) {
    int index = FindIndex(*word);
    word_table[index].count++;
}

void DataMine(char *data, int length) {
    int i;
    for (i = 0; i < length; i++) {
        if (isalpha(data[i])) {
            IncrementWordCount(&(data[i]));
        }
    }
}

void PrintWordTable() {
    int i;
    for (i = 0; i < MAX_ALPHABET_SIZE; i++) {
        if (word_table[i].count > 0) {
            printf("%c : %d\n", i + 'a', word_table[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    char data[MAX_DATA_SIZE];
    int length;

    if (argc < 2) {
        printf("Usage : %s <data>\n", argv[0]);
        return 1;
    }

    length = strlen(argv[1]);
    strcpy(data, argv[1]);

    InitializeWordTable();
    DataMine(data, length);
    PrintWordTable();

    return 0;
}