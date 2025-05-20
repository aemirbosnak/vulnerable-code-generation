//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

struct word {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
};

int main() {
    printf("Welcome to the C Cat Language Translator!\n");

    // Load dictionary
    FILE *dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }

    struct word dict[MAX_WORDS];
    int num_words = 0;

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, dict_file)!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: Dictionary too large.\n");
            return 1;
        }

        char *english = strtok(line, ",");
        char *cat = strtok(NULL, ",");

        strcpy(dict[num_words].english, english);
        strcpy(dict[num_words].cat, cat);

        num_words++;
    }

    fclose(dict_file);

    // Translate input
    char input[MAX_WORD_LENGTH];
    printf("Enter a sentence to translate:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

    char output[MAX_WORD_LENGTH];
    output[0] = '\0';

    char *token = strtok(input, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(dict[i].english, token) == 0) {
                strcat(output, dict[i].cat);
                strcat(output, " ");
                break;
            }
        }

        if (i == num_words) {
            printf("Error: Unknown word '%s'.\n", token);
            return 1;
        }

        token = strtok(NULL, " ");
    }

    printf("Translation: %s\n", output);

    return 0;
}