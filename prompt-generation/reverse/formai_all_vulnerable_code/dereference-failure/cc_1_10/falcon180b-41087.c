//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} word_t;

word_t words[MAX_WORDS];
int num_words = 0;

void load_words(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char* word = strtok(line, " ");
        char* translation = strtok(NULL, " ");

        if (word == NULL || translation == NULL) {
            printf("Error: Invalid line in file '%s'\n", filename);
            exit(1);
        }

        strcpy(words[num_words].word, word);
        strcpy(words[num_words].translation, translation);
        num_words++;
    }

    fclose(file);
}

void translate_sentence(char* sentence) {
    char* token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].word) == 0) {
                printf("%s ", words[i].translation);
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

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <dictionary_file> <sentence>\n", argv[0]);
        exit(1);
    }

    load_words(argv[1]);
    translate_sentence(argv[2]);

    return 0;
}