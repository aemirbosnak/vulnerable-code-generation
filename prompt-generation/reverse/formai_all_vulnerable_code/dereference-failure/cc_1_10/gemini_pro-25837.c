//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *input;
    char *output;
} Translation;

Translation translations[] = {
    {"HELLO", "XERV"},
    {"WORLD", "GUVE"},
    {"THE", "DIC"},
    {"IS", "TOK"},
    {"A", "EH"},
    {"BEAUTIFUL", "CIC"},
    {"PLACE", "REN"},
    {"FOR", "SOR"},
    {"YOU", "SU"},
    {"TO", "KK"},
    {"VISIT", "RUF"},
    {NULL, NULL}
};

char *translate(char *input) {
    int i;
    for (i = 0; translations[i].input != NULL; i++) {
        if (strcmp(input, translations[i].input) == 0) {
            return translations[i].output;
        }
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }

    char *input = argv[1];
    char *output = translate(input);

    if (output == NULL) {
        printf("No translation found for '%s'.\n", input);
        return 1;
    }

    printf("Translation: %s\n", output);
    return 0;
}