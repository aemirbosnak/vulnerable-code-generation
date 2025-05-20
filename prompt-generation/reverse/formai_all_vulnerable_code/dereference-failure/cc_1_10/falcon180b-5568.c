//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
} word_pair;

word_pair dictionary[MAX_WORDS];
int num_words;

void load_dictionary(char *filename) {
    FILE *fp;
    char line[MAX_WORD_LENGTH];
    char *word;
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        word = strtok(line, ",");
        strcpy(dictionary[i].english, word);
        word = strtok(NULL, ",");
        strcpy(dictionary[i].cat, word);
        i++;
        if (i >= MAX_WORDS) {
            printf("Error: Dictionary file is too large.\n");
            fclose(fp);
            exit(1);
        }
    }

    fclose(fp);
    num_words = i;
}

bool is_valid_word(char *word) {
    int i;

    for (i = 0; i < num_words; i++) {
        if (strcmp(word, dictionary[i].english) == 0) {
            return true;
        }
    }

    return false;
}

void translate_sentence(char *sentence) {
    char *word;
    char *cat_word;
    int i;

    word = strtok(sentence, " ");
    while (word!= NULL) {
        if (is_valid_word(word)) {
            cat_word = strtok(NULL, " ");
            while (cat_word == NULL) {
                printf("Error: Missing translation for '%s'.\n", word);
                exit(1);
            }
            printf("%s -> %s\n", word, cat_word);
        } else {
            printf("Error: Invalid word '%s'.\n", word);
        }
        word = strtok(NULL, " ");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <dictionary_file> <sentence>\n", argv[0]);
        return 1;
    }

    load_dictionary(argv[1]);
    translate_sentence(argv[2]);

    return 0;
}