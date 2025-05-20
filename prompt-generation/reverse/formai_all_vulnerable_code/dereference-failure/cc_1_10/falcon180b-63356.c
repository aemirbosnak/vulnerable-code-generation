//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

struct word {
    char *english;
    char *cat;
};

int main() {
    struct word words[MAX_WORDS];
    int num_words = 0;
    char input[MAX_WORD_LENGTH];
    char *english_word;
    char *cat_word;

    printf("Welcome to the C Cat Language Translator!\n");

    while (1) {
        printf("Enter an English word (or type 'quit' to exit): ");
        fgets(input, MAX_WORD_LENGTH, stdin);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        english_word = strtok(input, " ");
        cat_word = strtok(NULL, " ");

        if (english_word == NULL || cat_word == NULL) {
            printf("Invalid input. Please enter an English word followed by its Cat translation.\n");
            continue;
        }

        for (int i = 0; i < num_words; i++) {
            if (strcmp(words[i].english, english_word) == 0) {
                printf("Duplicate entry for '%s'.\n", english_word);
                break;
            }
        }

        if (num_words >= MAX_WORDS) {
            printf("Maximum number of words (%d) reached. Exiting...\n", MAX_WORDS);
            exit(0);
        }

        words[num_words].english = strdup(english_word);
        words[num_words].cat = strdup(cat_word);
        num_words++;

        printf("'%s' added to the dictionary.\n", english_word);
    }

    printf("\nDictionary:\n");

    for (int i = 0; i < num_words; i++) {
        printf("%s -> %s\n", words[i].english, words[i].cat);
    }

    return 0;
}