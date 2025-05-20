//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct {
    char *english;
    char *alien;
} Word;

int main() {
    FILE *dictionary;
    char line[100];
    Word words[MAX_WORDS];
    int num_words = 0;

    dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }

    while (fgets(line, 100, dictionary)!= NULL) {
        if (num_words == MAX_WORDS) {
            printf("Error: Dictionary is full.\n");
            fclose(dictionary);
            return 1;
        }

        char *token = strtok(line, " ");
        words[num_words].english = strdup(token);

        token = strtok(NULL, " ");
        words[num_words].alien = strdup(token);

        num_words++;
    }

    fclose(dictionary);

    char input[100];
    printf("Enter a sentence to translate: ");
    fgets(input, 100, stdin);

    char *token = strtok(input, " ");
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