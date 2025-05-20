//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

struct word {
    char *english;
    char *cat;
};

int main() {
    struct word words[MAX_WORDS];
    int num_words = 0;

    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open words.txt\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        if (token == NULL) {
            continue;
        }

        char *english = strdup(token);
        char *cat = strdup(strtok(NULL, ","));

        words[num_words++] = (struct word) {
           .english = english,
           .cat = cat
        };
    }

    fclose(fp);

    char input[100];
    printf("Enter a sentence to translate:\n");
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].cat);
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