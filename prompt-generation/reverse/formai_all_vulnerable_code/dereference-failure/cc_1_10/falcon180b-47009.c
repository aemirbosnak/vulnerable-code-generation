//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

struct word {
    char *english;
    char *alien;
};

int main() {
    FILE *dict_file;
    char line[MAX_WORD_LEN];
    struct word words[MAX_WORDS];
    int num_words = 0;

    dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LEN, dict_file)!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: dictionary is too large.\n");
            exit(1);
        }

        char *english_word = strtok(line, " ");
        char *alien_word = strtok(NULL, " ");

        if (english_word == NULL || alien_word == NULL) {
            printf("Error: invalid line in dictionary file.\n");
            exit(1);
        }

        words[num_words].english = strdup(english_word);
        words[num_words].alien = strdup(alien_word);

        num_words++;
    }

    fclose(dict_file);

    char input_line[MAX_WORD_LEN];
    printf("Enter a sentence to translate:\n");
    fgets(input_line, MAX_WORD_LEN, stdin);

    char *token = strtok(input_line, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].alien);
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