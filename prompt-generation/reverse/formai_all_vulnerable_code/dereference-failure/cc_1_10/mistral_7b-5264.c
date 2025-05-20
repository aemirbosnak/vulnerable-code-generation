//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DICTIONARY_SIZE 10000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
} dictionary;

void load_dictionary(dictionary dict[], const char *filename) {
    FILE *fp = fopen(filename, "r");
    int i = 0;

    if (fp == NULL) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fgets(dict[i].word, WORD_LENGTH, fp) != NULL) {
        size_t len = strlen(dict[i].word);
        dict[i].word[len - 1] = '\0'; // Remove newline character
        i++;
    }

    fclose(fp);
}

int check_word(const char *word, const dictionary dict[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (strcasecmp(word, dict[i].word) == 0) {
            return 1;
        }
    }

    return 0;
}

int main(int argc, const char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <text_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    dictionary dict[DICTIONARY_SIZE];
    load_dictionary(dict, "dictionary.txt");

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        fprintf(stderr, "Could not open file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char word[WORD_LENGTH];
    int num_words = 0;

    while (fscanf(fp, "%s%*[^\n]", word) != EOF) {
        int is_misspelled = 1;

        if (strlen(word) > WORD_LENGTH - 1) {
            fprintf(stderr, "Word too long: %s\n", word);
            continue;
        }

        for (int i = 0; i < 26; i++) {
            word[0] = toupper(word[0] + i);
            is_misspelled &= !check_word(word, dict, DICTIONARY_SIZE);

            if (!is_misspelled) {
                printf("Corrected: %s -> %s\n", word, word);
                break;
            }
        }

        if (is_misspelled) {
            printf("Misspelled: %s\n", word);
            num_words++;
        }
    }

    fclose(fp);

    printf("Total misspelled words: %d\n", num_words);

    return EXIT_SUCCESS;
}