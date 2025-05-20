//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50

typedef struct {
    char *from;
    char *to;
} Translation;

Translation translations[] = {
    {"hello", "yob"},
    {"world", "geh"},
    {"and", "na"},
    {"thank", "meh"},
    {"you", "nak"},
    {NULL, NULL}
};

char *translate(char *word) {
    for (int i = 0; translations[i].from; i++) {
        if (strcmp(translations[i].from, word) == 0) {
            return translations[i].to;
        }
    }
    return NULL;
}

int main() {
    char *input = "Hello world, and thank you.";
    char output[MAX_WORD_LEN];
    char *word;

    printf("Input: %s\n", input);
    printf("Output: ");

    word = strtok(input, " ");
    while (word) {
        char *translation = translate(word);
        if (translation) {
            strcat(output, translation);
        } else {
            strcat(output, word);
        }
        strcat(output, " ");
        word = strtok(NULL, " ");
    }

    printf("%s\n", output);

    return 0;
}