//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ALIEN_ALPHABET_SIZE 26
#define MAX_WORD_LENGTH 50

typedef struct AlienWord {
    char *english;
    char *alien;
} AlienWord;

void createAlienDictionary(AlienWord **dictionary, int numWords) {
    AlienWord *words = calloc(numWords, sizeof(AlienWord));
    for (int i = 0; i < numWords; i++) {
        words[i].english = malloc(MAX_WORD_LENGTH * sizeof(char));
        words[i].alien = malloc(MAX_WORD_LENGTH * sizeof(char));
        scanf("%s%s", words[i].english, words[i].alien);
    }
    *dictionary = words;
}

void translateEnglishToAlien(AlienWord *dictionary, int numWords, char *english) {
    for (int i = 0; i < numWords; i++) {
        int lenEng = strlen(dictionary[i].english);
        int lenAlien = strlen(dictionary[i].alien);
        if (strncmp(dictionary[i].english, english, lenEng) == 0) {
            printf("%.*s\n", lenAlien, dictionary[i].alien);
            return;
        }
    }
    printf("Unknown English word: %s\n", english);
}

void generateRandomAlienWord(char *alienWord, int length) {
    char alienChars[] = "XYZqujklmñoprwftghbvæðíçrσ²åñé";
    for (int i = 0; i < length; i++) {
        alienWord[i] = alienChars[rand() % ALIEN_ALPHABET_SIZE];
    }
    alienWord[length] = '\0';
}

int main() {
    srand(time(NULL));
    int numWords;
    printf("Enter number of words in the dictionary: ");
    scanf("%d", &numWords);

    AlienWord *dictionary;
    createAlienDictionary(&dictionary, numWords);

    char english[MAX_WORD_LENGTH];
    printf("Enter English word to translate: ");
    scanf("%s", english);
    translateEnglishToAlien(dictionary, numWords, english);

    char alienWord[MAX_WORD_LENGTH];
    int length = rand() % 10 + 5;
    generateRandomAlienWord(alienWord, length);

    printf("Random Alien word: %s\n", alienWord);

    for (int i = 0; i < numWords; i++) {
        free(dictionary[i].english);
        free(dictionary[i].alien);
    }
    free(dictionary);

    return 0;
}