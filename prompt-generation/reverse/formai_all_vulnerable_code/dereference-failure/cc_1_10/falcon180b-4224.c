//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000 // maximum number of words in the dictionary
#define WORD_LENGTH 20 // maximum length of a word

struct word {
    char english[WORD_LENGTH];
    char cat[WORD_LENGTH];
};

struct word dictionary[MAX_WORDS]; // the dictionary of English-C Cat translations
int num_words = 0; // the number of words in the dictionary

void load_dictionary() {
    FILE *file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: dictionary is full.\n");
            exit(1);
        }

        char *english = strtok(line, " ");
        char *cat = strtok(NULL, " ");

        strncpy(dictionary[num_words].english, english, WORD_LENGTH);
        strncpy(dictionary[num_words].cat, cat, WORD_LENGTH);

        num_words++;
    }

    fclose(file);
}

void translate_text(char *text) {
    char *token = strtok(text, " ");
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

    char text[1000];
    printf("Enter some text to translate:\n");
    fgets(text, sizeof(text), stdin);

    translate_text(text);

    return 0;
}