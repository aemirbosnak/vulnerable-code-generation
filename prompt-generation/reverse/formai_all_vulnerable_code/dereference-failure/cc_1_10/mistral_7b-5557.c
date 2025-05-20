//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALIEN_ABC "XÆÄÇÈÉÌÍÒÓÔÖÙÚÛÜ"
#define ENGLISH_ABC "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

typedef struct AlienWord {
    char *english;
    char *alien;
} AlienWord;

void createAlienDictionary(AlienWord *dictionary, int size) {
    for (int i = 0; i < size; ++i) {
        char *englishWord = malloc(20 * sizeof(char));
        char *alienWord = malloc(10 * sizeof(char));
        scanf("%s", englishWord);
        for (int j = 0; englishWord[j] != '\0'; ++j) {
            if (englishWord[j] >= 'A' && englishWord[j] <= 'Z') {
                int index = englishWord[j] - 'A';
                alienWord[j] = ALIEN_ABC[index];
            } else {
                alienWord[j] = englishWord[j];
            }
        }
        alienWord[strlen(alienWord)] = '\0';
        dictionary[i].english = englishWord;
        dictionary[i].alien = alienWord;
    }
}

int findWordIndex(AlienWord *dictionary, int size, char *alienWord) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(dictionary[i].alien, alienWord) == 0) {
            return i;
        }
    }
    return -1;
}

void translateWord(AlienWord *dictionary, int size, char *alienWord) {
    int index = findWordIndex(dictionary, size, alienWord);
    if (index != -1) {
        printf("%s\n", dictionary[index].english);
    } else {
        printf("Unknown word\n");
    }
}

int main(int argc, char *argv[]) {
    int size = argc - 1;
    if (size <= 0) {
        printf("Usage: %s WORD1 WORD2 ...\n", argv[0]);
        return 1;
    }

    AlienWord *dictionary = malloc(size * sizeof(AlienWord));
    createAlienDictionary(dictionary, size);

    for (int i = 1; i < argc; ++i) {
        translateWord(dictionary, size, argv[i]);
    }

    for (int i = 0; i < size; ++i) {
        free(dictionary[i].english);
        free(dictionary[i].alien);
    }
    free(dictionary);

    return 0;
}