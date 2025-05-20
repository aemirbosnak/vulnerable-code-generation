//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define TABLE_SIZE 26

typedef struct Word {
    char word[MAX_WORD_LEN];
    int count;
} Word;

void toLower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int hashFunction(char c) {
    return (int)toupper(c) - 'A';
}

Word *createTable() {
    Word *table = malloc(TABLE_SIZE * sizeof(Word));

    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].count = 0;
        strcpy(table[i].word, "");
    }

    return table;
}

void insertWord(Word *table, char *word) {
    int hashIndex = hashFunction((word[0]));

    for (int i = 0; i < strlen(word); i++) {
        toLower(&word[i]);
    }

    int index = 0;

    if (strcmp(table[hashIndex].word, word) == 0) {
        table[hashIndex].count++;
    } else {
        for (index = 0; index < strlen(table[hashIndex].word); index++) {
            if (strcmp(&table[hashIndex].word[index], word) == 0) {
                break;
            }
        }

        if (index == strlen(table[hashIndex].word)) {
            strcat(table[hashIndex].word, word);
            table[hashIndex].count++;
        } else {
            Word newWord;
            strcpy(newWord.word, &table[hashIndex].word[index]);
            strncpy(table[hashIndex].word, word, MAX_WORD_LEN);
            table[hashIndex].count += 2;

            Word newTableWord = newWord;
            newTableWord.count = 1;

            int newIndex = hashFunction((word[0]));
            table[newIndex] = newTableWord;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    Word *table = createTable();

    char word[MAX_WORD_LEN];

    while (fscanf(file, "%s", word) != EOF) {
        toLower(word);
        insertWord(table, word);
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%c: %s - %d\n", 'A' + i, table[i].word, table[i].count);
    }

    fclose(file);
    free(table);

    return 0;
}