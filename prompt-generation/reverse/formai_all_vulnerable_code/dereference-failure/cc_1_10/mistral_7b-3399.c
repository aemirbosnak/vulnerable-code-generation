//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALIEN_ABC "XaYz"
#define ALPHABET_SIZE 26

typedef struct {
    char symbol;
    char alien_symbol;
} TranslationTable;

void loadTranslationTable(FILE *file, TranslationTable *table) {
    int i;
    for (i = 0; i < ALPHABET_SIZE; i++) {
        fscanf(file, "%c%c", &table[i].symbol, &table[i].alien_symbol);
    }
}

void translateText(char *text, TranslationTable *table) {
    int i, j;
    for (i = 0; text[i] != '\0'; i++) {
        for (j = 0; j < ALPHABET_SIZE; j++) {
            if (text[i] == table[j].symbol) {
                text[i] = table[j].alien_symbol;
                break;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *inputText;
    TranslationTable table[ALPHABET_SIZE];
    int i;

    if (argc != 3) {
        printf("Usage: %s <translation_file> <text_to_translate>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening translation file");
        return 1;
    }

    inputText = malloc(strlen(argv[3]) + 1);
    strcpy(inputText, argv[3]);

    loadTranslationTable(file, table);
    fclose(file);

    translateText(inputText, table);

    printf("Translated text: %s\n", inputText);

    free(inputText);

    return 0;
}