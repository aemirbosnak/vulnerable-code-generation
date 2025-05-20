//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define NUM_ALIEN_WORDS 10

typedef struct {
    char *human_word;
    char *alien_word;
} Translation;

Translation words[NUM_ALIEN_WORDS] = {
    {"hello", "kliptik"},
    {"goodbye", "zorgon"},
    {"yes", "glorp"},
    {"no", "blort"},
    {"one", "zork"},
    {"two", "plorp"},
    {"three", "glorpik"},
    {"four", "blork"},
    {"five", "klork"},
    {"six", "plork"}
};

int main() {
    char input_word[MAX_WORD_LENGTH];
    int i;
    char *alien_word;

    printf("Welcome to the Alien Language Translator!\n");
    printf("Type a word in English and I will translate it to Alien for you:\n");

    while (1) {
        fgets(input_word, MAX_WORD_LENGTH, stdin);
        input_word[strcspn(input_word, "\n")] = '\0';

        for (i = 0; i < NUM_ALIEN_WORDS; i++) {
            if (strcasecmp(input_word, words[i].human_word) == 0) {
                alien_word = malloc(strlen(words[i].alien_word) + 1);
                strcpy(alien_word, words[i].alien_word);
                printf("The Alien word for '%s' is '%s'\n", input_word, alien_word);
                free(alien_word);
                goto next_input;
            }
        }

        printf("Sorry, I don't know the Alien word for '%s'\n", input_word);

next_input:
        continue;
    }

    return 0;
}