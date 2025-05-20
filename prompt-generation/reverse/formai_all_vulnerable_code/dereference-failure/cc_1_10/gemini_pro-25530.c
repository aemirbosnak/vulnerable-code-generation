//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_DICTIONARY_SIZE 1000

typedef struct {
    char *alien_word;
    char *english_word;
} dictionary_entry;

dictionary_entry dictionary[MAX_DICTIONARY_SIZE];
int dictionary_size = 0;

void load_dictionary() {
    FILE *fp = fopen("alien_dictionary.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening dictionary file.\n");
        exit(1);
    }

    char line[256];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *alien_word = strtok(line, ",");
        char *english_word = strtok(NULL, ",");

        if (alien_word == NULL || english_word == NULL) {
            fprintf(stderr, "Error parsing dictionary file.\n");
            exit(1);
        }

        dictionary[dictionary_size].alien_word = strdup(alien_word);
        dictionary[dictionary_size].english_word = strdup(english_word);
        dictionary_size++;
    }

    fclose(fp);
}

void translate_sentence(char *sentence) {
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        int i;
        for (i = 0; i < dictionary_size; i++) {
            if (strcmp(word, dictionary[i].alien_word) == 0) {
                printf("%s ", dictionary[i].english_word);
                break;
            }
        }

        if (i == dictionary_size) {
            printf("[%s] ", word);
        }

        word = strtok(NULL, " ");
    }

    printf("\n");
}

int main() {
    load_dictionary();

    char sentence[256];
    printf("Enter an alien sentence: ");
    gets(sentence);

    translate_sentence(sentence);

    return 0;
}