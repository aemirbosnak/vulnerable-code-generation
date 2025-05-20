//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct {
    char *english;
    char *cat;
} Word;

int main() {
    FILE *dict;
    char line[1024];
    int num_words = 0;
    Word words[MAX_WORDS];

    dict = fopen("dictionary.txt", "r");
    if (dict == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), dict)!= NULL) {
        char *token = strtok(line, " ");
        if (token == NULL)
            continue;

        if (num_words >= MAX_WORDS) {
            printf("Error: Dictionary is too large.\n");
            fclose(dict);
            return 1;
        }

        Word *word = &words[num_words];
        word->english = strdup(token);
        token = strtok(NULL, " ");
        if (token == NULL) {
            printf("Error: Missing translation for word '%s'.\n", word->english);
            fclose(dict);
            return 1;
        }
        word->cat = strdup(token);
        num_words++;
    }

    fclose(dict);

    char input[1024];
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
            printf("unknown word: %s ", token);
        }
        token = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}