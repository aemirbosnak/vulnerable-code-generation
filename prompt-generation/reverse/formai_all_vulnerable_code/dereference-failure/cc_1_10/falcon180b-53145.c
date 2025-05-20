//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 100

struct word {
    char *english;
    char *alien;
};

int main() {
    FILE *dict;
    struct word words[MAX_WORDS];
    int num_words = 0;
    char line[MAX_WORD_LEN];

    // Open dictionary file
    dict = fopen("dictionary.txt", "r");
    if (dict == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    // Read words from file
    while (fgets(line, MAX_WORD_LEN, dict)!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: Dictionary is too large.\n");
            exit(1);
        }
        words[num_words].english = strdup(line);
        words[num_words].alien = malloc(strlen(line) + 1);
        strcpy(words[num_words].alien, line);
        num_words++;
    }

    // Close dictionary file
    fclose(dict);

    // Translate sentence
    char sentence[MAX_WORD_LEN];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, MAX_WORD_LEN, stdin);

    // Tokenize sentence
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        // Look up word in dictionary
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                // Found match, translate word
                printf("%s -> %s\n", token, words[i].alien);
                break;
            }
        }

        // If word not found, print error message
        if (i == num_words) {
            printf("%s not found in dictionary.\n", token);
        }

        // Move to next token
        token = strtok(NULL, " ");
    }

    return 0;
}