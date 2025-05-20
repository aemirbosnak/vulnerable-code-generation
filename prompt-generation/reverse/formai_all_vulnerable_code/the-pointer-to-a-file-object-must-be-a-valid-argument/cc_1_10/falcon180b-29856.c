//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define DICTIONARY_FILE "dictionary.txt"

struct word {
    char *english;
    char *alien;
};

struct word dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary() {
    FILE *file = fopen(DICTIONARY_FILE, "r");
    char line[MAX_WORD_LENGTH];
    char *token;
    int i = 0;

    while (fgets(line, sizeof(line), file)!= NULL && i < MAX_WORDS) {
        token = strtok(line, ",");
        dictionary[i].english = strdup(token);
        token = strtok(NULL, ",");
        dictionary[i].alien = strdup(token);
        i++;
    }

    fclose(file);
    num_words = i;
}

void translate_sentence(char *sentence) {
    char *token;
    int i;

    token = strtok(sentence, " ");
    while (token!= NULL) {
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, dictionary[i].english) == 0) {
                printf("%s ", dictionary[i].alien);
                break;
            }
        }

        if (i == num_words) {
            printf("%s ", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");
}

int main() {
    load_dictionary();

    char sentence[1000];
    printf("Enter a sentence to translate: ");
    fgets(sentence, sizeof(sentence), stdin);

    translate_sentence(sentence);

    return 0;
}