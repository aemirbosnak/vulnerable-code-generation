//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char *english;
    char *cat;
} word_pair;

word_pair dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary() {
    // Load dictionary from file
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: dictionary file not found.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        char *english = strtok(line, " ");
        char *cat = strtok(NULL, " ");

        if (english == NULL || cat == NULL) {
            printf("Error: malformed line in dictionary file.\n");
            exit(1);
        }

        num_words++;
        if (num_words > MAX_WORDS) {
            printf("Error: dictionary too large.\n");
            exit(1);
        }

        dictionary[num_words - 1].english = strdup(english);
        dictionary[num_words - 1].cat = strdup(cat);
    }

    fclose(fp);
}

void translate_sentence(char *sentence) {
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
}

int main() {
    load_dictionary();

    char sentence[MAX_WORD_LENGTH];
    printf("Enter a sentence to translate to Cat:\n");
    fgets(sentence, MAX_WORD_LENGTH, stdin);

    translate_sentence(sentence);

    return 0;
}