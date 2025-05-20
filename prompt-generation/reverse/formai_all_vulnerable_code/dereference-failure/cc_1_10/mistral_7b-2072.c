//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct AlienWord {
    char *original;
    char *translation;
} AlienWord;

AlienWord words[] = {
    {"ZXQ", "Hello"},
    {"FXP", "How are you?"},
    {"GLM", "I am fine"},
    {"NQR", "What is your name?"},
    {"PQS", "My name is"},
    {"RST", "Nice to meet you"},
    {"UVW", "Goodbye"},
    {"XYZ", "Please help me"},
    {NULL, NULL}
};

int findWordIndex(char *word) {
    int i = 0;
    while (words[i].original != NULL) {
        if (strcmp(words[i].original, word) == 0) {
            return i;
        }
        i++;
    }
    return -1;
}

void translate(char *alienWord) {
    int index = findWordIndex(alienWord);
    if (index >= 0) {
        printf("%s: %s\n", alienWord, words[index].translation);
    } else {
        printf("Unrecognized alien word: %s\n", alienWord);
    }
}

int main(int argc, char *argv[]) {
    char alienWord[32];

    if (argc < 2) {
        printf("Usage: %s <alien word>\n", argv[0]);
        return 1;
    }

    strcpy(alienWord, argv[1]);

    for (int i = 0; i < strlen(alienWord); i++) {
        alienWord[i] = toupper(alienWord[i]);
    }

    translate(alienWord);

    return 0;
}