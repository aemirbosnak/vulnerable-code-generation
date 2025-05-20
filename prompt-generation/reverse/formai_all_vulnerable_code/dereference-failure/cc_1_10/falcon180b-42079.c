//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LEN 50

struct word {
    char word[MAX_WORD_LEN];
    int count;
};

struct word *load_words(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    struct word *words = malloc(MAX_WORDS * sizeof(struct word));
    int num_words = 0;

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Reached maximum number of words\n");
            exit(1);
        }

        words[num_words].word[0] = tolower(word[0]);
        strcpy(words[num_words].word + 1, word + 1);
        words[num_words].count = 1;
        num_words++;
    }

    fclose(file);
    return words;
}

void save_words(const struct word *words, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < MAX_WORDS && words[i].count > 0; i++) {
        fprintf(file, "%s\n", words[i].word);
    }

    fclose(file);
}

int main() {
    char text[MAX_WORD_LEN * 100];
    printf("Enter text to spell check:\n");
    fgets(text, sizeof(text), stdin);

    struct word *words = load_words("dictionary.txt");

    char *word = strtok(text, ",.?!;:");
    while (word!= NULL) {
        bool found_match = false;

        for (int i = 0; i < MAX_WORDS && words[i].count > 0; i++) {
            if (strcmp(word, words[i].word) == 0) {
                found_match = true;
                break;
            }
        }

        if (!found_match) {
            printf("Unknown word: %s\n", word);
        }

        word = strtok(NULL, ",.?!;:");
    }

    save_words(words, "dictionary.txt");
    free(words);

    return 0;
}