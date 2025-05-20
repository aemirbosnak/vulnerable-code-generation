//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

struct word {
    char *english;
    char *alien;
};

int main() {
    FILE *dict_file;
    struct word words[MAX_WORDS];
    int num_words = 0;
    char line[100];
    char *token;
    char *english_word;
    char *alien_word;

    // Open dictionary file
    dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }

    // Read words from dictionary file
    while (fgets(line, sizeof(line), dict_file)!= NULL) {
        token = strtok(line, " ");
        english_word = token;
        alien_word = strtok(NULL, " ");

        // Check if there is enough space for the new word
        if (num_words >= MAX_WORDS) {
            printf("Dictionary is full.\n");
            exit(1);
        }

        // Add word to dictionary
        words[num_words].english = strdup(english_word);
        words[num_words].alien = strdup(alien_word);
        num_words++;
    }

    fclose(dict_file);

    // Translate sentence
    printf("Enter a sentence to translate: ");
    fgets(line, sizeof(line), stdin);

    // Tokenize sentence
    token = strtok(line, " ");
    while (token!= NULL) {
        // Look up word in dictionary
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                // Word found, print alien translation
                printf("%s ", words[i].alien);
                break;
            }
        }

        // Word not found, print original word
        if (i == num_words) {
            printf("%s ", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}