//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Alien Language Struct
typedef struct AlienLanguage {
    char *symbols;
    char *translations;
    int length;
} AlienLanguage;

void readFile(char *fileName, AlienLanguage *alienLanguage) {
    FILE *file = fopen(fileName, "r");
    char line[1024];
    char *token = NULL;
    int capacity = 0, currentIndex = 0;

    // Reading symbols and translations
    while (fgets(line, sizeof(line), file) != NULL) {
        token = strtok(line, " \t\n");
        alienLanguage->symbols = (char *)realloc(alienLanguage->symbols, sizeof(char) * (capacity + strlen(token) + 1));
        strcpy(&alienLanguage->symbols[capacity], token);
        capacity += strlen(token) + 1;

        token = strtok(NULL, " \t\n");
        alienLanguage->translations = (char *)realloc(alienLanguage->translations, sizeof(char) * (capacity + strlen(token) + 1));
        strcpy(&alienLanguage->translations[capacity], token);
        capacity += strlen(token) + 1;
    }
    alienLanguage->length = capacity;
    fclose(file);
}

int translate(char c, AlienLanguage alienLanguage) {
    for (int i = 0; i < alienLanguage.length; i += 2) {
        if (alienLanguage.symbols[i] == c)
            return i + 1;
    }
    return -1;
}

int main() {
    AlienLanguage zorkianLanguage;
    readFile("zorkian.txt", &zorkianLanguage);

    char input[10];
    printf("Enter text in Zorkian: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    for (int i = 0; i < strlen(input); i++) {
        int index = translate(input[i], zorkianLanguage);
        if (index == -1) {
            printf("Invalid character: %c\n", input[i]);
            return 1;
        }
        printf("%c -> %c\n", input[i], zorkianLanguage.translations[index]);
    }

    return 0;
}