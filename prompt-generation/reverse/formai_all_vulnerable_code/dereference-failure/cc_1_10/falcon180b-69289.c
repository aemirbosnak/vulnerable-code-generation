//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    char translation[MAX_WORD_LEN];
} word_pair;

word_pair words[MAX_WORDS];
int num_words = 0;

void load_words() {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    char line[MAX_WORD_LEN];
    while (fgets(line, MAX_WORD_LEN, file)!= NULL) {
        char *word = strtok(line, " ");
        char *translation = strtok(NULL, " ");

        if (word == NULL || translation == NULL) {
            printf("Error parsing line: %s\n", line);
            exit(1);
        }

        strcpy(words[num_words].word, word);
        strcpy(words[num_words].translation, translation);
        num_words++;
    }

    fclose(file);
}

int main() {
    load_words();

    char input[MAX_WORD_LEN];
    while (fgets(input, MAX_WORD_LEN, stdin)!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(input, words[i].word) == 0) {
                printf("%s\n", words[i].translation);
                break;
            }
        }
        if (i == num_words) {
            printf("No translation found for '%s'.\n", input);
        }
    }

    return 0;
}