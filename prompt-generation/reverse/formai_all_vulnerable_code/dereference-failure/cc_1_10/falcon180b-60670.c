//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

struct word {
    char *english;
    char *cat;
};

int main() {
    printf("Welcome to the C Cat Language Translator!\n");

    // Load dictionary
    struct word dictionary[MAX_WORDS];
    int num_words = 0;

    FILE *dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }

    char line[MAX_WORD_LENGTH + 1];
    while (fgets(line, MAX_WORD_LENGTH, dict_file)!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: dictionary is too large.\n");
            return 1;
        }

        char *english_word = strtok(line, ",");
        char *cat_word = strtok(NULL, ",");

        if (english_word == NULL || cat_word == NULL) {
            printf("Error: malformed dictionary entry.\n");
            return 1;
        }

        dictionary[num_words].english = strdup(english_word);
        dictionary[num_words].cat = strdup(cat_word);

        num_words++;
    }

    fclose(dict_file);

    // Translate sentences
    char sentence[MAX_WORD_LENGTH * 10];
    printf("Enter a sentence to translate: ");
    fgets(sentence, MAX_WORD_LENGTH * 10, stdin);

    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, dictionary[i].english) == 0) {
                printf("%s ", dictionary[i].cat);
                break;
            }
        }

        if (i == num_words) {
            printf("%s ", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}