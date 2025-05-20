//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} word_pair;

word_pair dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH * 2];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char* word = strtok(line, " ");
        char* translation = strtok(NULL, "\n");

        if (word == NULL || translation == NULL) {
            printf("Error: invalid dictionary entry.\n");
            exit(1);
        }

        strncpy(dictionary[num_words].word, word, MAX_WORD_LENGTH);
        strncpy(dictionary[num_words].translation, translation, MAX_WORD_LENGTH);
        num_words++;
    }

    fclose(file);
}

void translate_text(char* text) {
    char* token = strtok(text, " ");

    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, dictionary[i].word) == 0) {
                printf("%s ", dictionary[i].translation);
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
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return 1;
    }

    load_dictionary(argv[1]);
    translate_text(argv[2]);

    return 0;
}