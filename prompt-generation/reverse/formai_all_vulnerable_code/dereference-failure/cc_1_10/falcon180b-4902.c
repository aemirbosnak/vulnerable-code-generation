//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 64

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

typedef struct {
    WordFrequency *words;
    int numWords;
    int maxWords;
} WordFrequencyTable;

void initializeTable(WordFrequencyTable *table, int maxWords) {
    table->numWords = 0;
    table->maxWords = maxWords;
    table->words = (WordFrequency *)malloc(sizeof(WordFrequency) * maxWords);
    for (int i = 0; i < maxWords; i++) {
        table->words[i].word = NULL;
        table->words[i].frequency = 0;
    }
}

void addWord(WordFrequencyTable *table, char *word) {
    if (table->numWords >= table->maxWords) {
        printf("Error: table is full.\n");
        return;
    }
    table->words[table->numWords].word = strdup(word);
    table->words[table->numWords].frequency = 1;
    table->numWords++;
}

void printTable(WordFrequencyTable *table) {
    for (int i = 0; i < table->numWords; i++) {
        printf("%s: %d\n", table->words[i].word, table->words[i].frequency);
    }
}

void freeTable(WordFrequencyTable *table) {
    for (int i = 0; i < table->numWords; i++) {
        free(table->words[i].word);
    }
    free(table->words);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    WordFrequencyTable table;
    initializeTable(&table, 1000);

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *word = strtok(line, " \t\n\r\f\v.,!?;:\"'()[]{}<>");
        while (word!= NULL) {
            addWord(&table, word);
            word = strtok(NULL, " \t\n\r\f\v.,!?;:\"'()[]{}<>");
        }
    }

    fclose(file);
    printTable(&table);

    freeTable(&table);
    return 0;
}