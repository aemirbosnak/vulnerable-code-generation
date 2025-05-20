//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char *english;
    char *alien;
};

struct word dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH + 1];
    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: dictionary is full.\n");
            exit(1);
        }

        char *english_word = strtok(line, " ");
        char *alien_word = strtok(NULL, " ");

        if (english_word == NULL || alien_word == NULL) {
            printf("Error: invalid line in dictionary file.\n");
            exit(1);
        }

        dictionary[num_words].english = strdup(english_word);
        dictionary[num_words].alien = strdup(alien_word);

        num_words++;
    }

    fclose(fp);
}

void translate_sentence(char *sentence) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
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
    load_dictionary("dictionary.txt");

    char sentence[MAX_WORD_LENGTH * 10];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, MAX_WORD_LENGTH * 10, stdin);

    translate_sentence(sentence);

    return 0;
}