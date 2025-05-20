//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *english;
    char *alien;
} TranslationPair;

TranslationPair translations[MAX_WORDS];
int numTranslations = 0;

void addTranslation(char *english, char *alien) {
    if (numTranslations >= MAX_WORDS) {
        printf("Error: Too many translations\n");
        exit(1);
    }
    translations[numTranslations].english = strdup(english);
    translations[numTranslations].alien = strdup(alien);
    numTranslations++;
}

void loadTranslations() {
    FILE *file = fopen("translations.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open translations file\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char *english = strtok(line, ",");
        char *alien = strtok(NULL, ",");
        addTranslation(english, alien);
    }

    fclose(file);
}

bool translate(char *word) {
    for (int i = 0; i < numTranslations; i++) {
        if (strcmp(word, translations[i].english) == 0) {
            printf("%s -> %s\n", word, translations[i].alien);
            return true;
        }
    }
    printf("No translation found\n");
    return false;
}

int main() {
    loadTranslations();

    char input[MAX_WORD_LENGTH];
    while (fgets(input, MAX_WORD_LENGTH, stdin)!= NULL) {
        char *word = strtok(input, " ");
        while (word!= NULL) {
            translate(word);
            word = strtok(NULL, " ");
        }
    }

    return 0;
}