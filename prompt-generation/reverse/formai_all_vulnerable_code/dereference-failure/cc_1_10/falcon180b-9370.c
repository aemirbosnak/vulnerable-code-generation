//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

typedef struct {
    WordTranslation *words;
    int numWords;
} TranslationTable;

TranslationTable loadTranslationTable(const char *filename) {
    FILE *file;
    TranslationTable table;
    WordTranslation wordTranslation;
    char line[MAX_LINE_LENGTH];

    table.numWords = 0;
    table.words = NULL;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading translation table.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *word = strtok(line, " ");
        char *translation = strtok(NULL, " ");

        if (word == NULL || translation == NULL) {
            printf("Error parsing line in translation table.\n");
            exit(1);
        }

        strcpy(wordTranslation.word, word);
        strcpy(wordTranslation.translation, translation);
        if (table.numWords >= MAX_WORDS) {
            printf("Translation table is full.\n");
            exit(1);
        }

        table.words[table.numWords++] = wordTranslation;
    }

    fclose(file);
    return table;
}

void printTranslationTable(TranslationTable table) {
    printf("Translation Table:\n");
    for (int i = 0; i < table.numWords; i++) {
        printf("%s -> %s\n", table.words[i].word, table.words[i].translation);
    }
}

void translate(TranslationTable table, char *text) {
    char *token = strtok(text, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < table.numWords; i++) {
            if (strcmp(table.words[i].word, token) == 0) {
                printf("%s ", table.words[i].translation);
                break;
            }
        }
        if (i == table.numWords) {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    TranslationTable table = loadTranslationTable("translation_table.txt");
    printTranslationTable(table);

    char text[MAX_LINE_LENGTH];
    printf("Enter text to translate:\n");
    fgets(text, MAX_LINE_LENGTH, stdin);

    translate(table, text);

    return 0;
}