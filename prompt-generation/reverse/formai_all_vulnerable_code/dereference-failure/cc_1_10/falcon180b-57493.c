//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char *english;
    char *alien;
};

int main() {
    char input_sentence[1000];
    char *token;
    int num_words = 0;
    struct word words[MAX_WORDS];

    printf("Enter a sentence to translate to alien language: ");
    fgets(input_sentence, sizeof(input_sentence), stdin);

    token = strtok(input_sentence, " ");
    while (token!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: Too many words in sentence.\n");
            exit(1);
        }

        if (strlen(token) > MAX_WORD_LENGTH) {
            printf("Error: Word '%s' is too long.\n", token);
            exit(1);
        }

        words[num_words].english = strdup(token);
        words[num_words].alien = malloc(MAX_WORD_LENGTH * sizeof(char));
        strcpy(words[num_words].alien, "");

        num_words++;
        token = strtok(NULL, " ");
    }

    printf("Alien language translation:\n");
    for (int i = 0; i < num_words; i++) {
        printf("English: %s\n", words[i].english);
        printf("Alien: %s\n", words[i].alien);
        printf("\n");
    }

    return 0;
}