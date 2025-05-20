//FormAI DATASET v1.0 Category: Spell checking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 5000

int get_words(char *fname, char **words);
int spell_check(char **words, int num_words, char **dict, int num_dict_words);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <file-to-check> <dictionary-file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *words[MAX_WORDS];
    int num_words = get_words(argv[1], words);

    char *dict[MAX_WORDS];
    int num_dict_words = get_words(argv[2], dict);

    int misspelled = spell_check(words, num_words, dict, num_dict_words);

    if (misspelled == 0) {
        printf("No misspelled words found!\n");
    } else {
        printf("%d misspelled words found.\n", misspelled);
    }

    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }

    for (int i = 0; i < num_dict_words; i++) {
        free(dict[i]);
    }

    return 0;
}

int get_words(char *fname, char **words) {
    FILE *fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", fname);
        exit(EXIT_FAILURE);
    }

    int num_words = 0;
    char *word = (char*) malloc(MAX_WORD_LENGTH * sizeof(char));
    while (fscanf(fp, "%s", word) != EOF) {
        words[num_words] = (char*) malloc(MAX_WORD_LENGTH * sizeof(char));
        strcpy(words[num_words], word);
        num_words++;
    }

    free(word);
    fclose(fp);
    return num_words;
}

int spell_check(char **words, int num_words, char **dict, int num_dict_words) {
    int misspelled = 0;

    for (int i = 0; i < num_words; i++) {
        char *word = words[i];
        int found = 0;

        for (int j = 0; j < num_dict_words; j++) {
            char *dict_word = dict[j];
            if (strcmp(word, dict_word) == 0) {
                found = 1;
                break;
            }
        }

        if (!found) {
            misspelled++;
            printf("Misspelled word: %s\n", word);
        }
    }

    return misspelled;
}