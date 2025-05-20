//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word_t {
    char *english;
    char *alien;
};

int main() {
    struct word_t words[MAX_WORDS];
    int num_words = 0;
    char input[MAX_WORD_LENGTH + 1];
    char *english_word;
    char *alien_word;

    printf("Welcome to the Alien Language Translator!\n");

    while (num_words < MAX_WORDS) {
        printf("Enter an English word (or type 'done' to finish): ");
        fgets(input, sizeof(input), stdin);

        english_word = strtok(input, "\n");
        if (strcmp(english_word, "done") == 0) {
            break;
        }

        alien_word = malloc(strlen(english_word) + 1);
        strcpy(alien_word, english_word);
        for (int i = 0; i < strlen(alien_word); i++) {
            if (isalpha(alien_word[i])) {
                alien_word[i] = toupper(alien_word[i]);
            }
        }

        words[num_words].english = strdup(english_word);
        words[num_words].alien = alien_word;
        num_words++;
    }

    printf("\nEnglish   Alien\n");
    for (int i = 0; i < num_words; i++) {
        printf("%-20s %s\n", words[i].english, words[i].alien);
    }

    return 0;
}