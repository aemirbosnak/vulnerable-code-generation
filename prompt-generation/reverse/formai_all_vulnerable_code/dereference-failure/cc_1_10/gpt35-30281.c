//FormAI DATASET v1.0 Category: Spell checking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_LINE_LEN 200

char *dictionary_path = "dictionary.txt";

void create_dictionary(char *path, bool *dictionary) {
    FILE *dict_file = fopen(path, "r");
    if (dict_file == NULL) {
        fprintf(stderr, "Error: Could not open dictionary file\n");
        exit(EXIT_FAILURE);
    }
    char word[MAX_WORD_LEN];
    while (fgets(word, MAX_WORD_LEN, dict_file) != NULL) {
        dictionary[strtol(word, NULL, 36) - 10] = true;
    }
    fclose(dict_file);
}

bool spell_check_word(char *word, bool *dictionary) {
    int word_val = strtol(word, NULL, 36) - 10;
    if (word_val < 0 || word_val > 256000) {
        return false;
    }
    return dictionary[word_val];
}

void check_line(char *line, bool *dictionary) {
    char *word = strtok(line, " \n");
    while (word != NULL) {
        if (!spell_check_word(word, dictionary)) {
            printf("Misspelled word: %s\n", word);
        }
        word = strtok(NULL, " \n");
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: Please provide file path to check\n");
        exit(EXIT_FAILURE);
    }
    char *file_path = argv[1];
    bool dictionary[256000] = {false};
    create_dictionary(dictionary_path, dictionary);
    FILE *input_file = fopen(file_path, "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Could not open input file\n");
        exit(EXIT_FAILURE);
    }
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, input_file) != NULL) {
        check_line(line, dictionary);
    }
    fclose(input_file);
    return 0;
}