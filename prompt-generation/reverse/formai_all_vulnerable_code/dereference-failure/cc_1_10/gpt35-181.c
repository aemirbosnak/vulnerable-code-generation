//FormAI DATASET v1.0 Category: Spell checking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_input(char *input_file) {
    FILE *fp;
    long size;
    char *buffer;

    fp = fopen(input_file, "r");
    if (fp == NULL) {
        printf("Error: Cannot open input file.\n");
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);

    fseek(fp, 0L, SEEK_SET);
    buffer = (char *) calloc(size, sizeof(char));
    if (buffer == NULL) {
        printf("Error: Cannot allocate memory.\n");
        exit(1);
    }

    fread(buffer, size, sizeof(char), fp);
    fclose(fp);

    return buffer;
}

char *read_dictionary(char *dictionary_file) {
    FILE *fp;
    long size;
    char *buffer;

    fp = fopen(dictionary_file, "r");
    if (fp == NULL) {
        printf("Error: Cannot open dictionary file.\n");
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);

    fseek(fp, 0L, SEEK_SET);
    buffer = (char *) calloc(size, sizeof(char));
    if (buffer == NULL) {
        printf("Error: Cannot allocate memory.\n");
        exit(1);
    }

    fread(buffer, size, sizeof(char), fp);
    fclose(fp);

    return buffer;
}

char **create_word_array(char *input, int *word_count) {
    char *token;
    char **words = (char **) calloc(1, sizeof(char *));
    int i = 0;
    token = strtok(input, " ,.-\n");

    while (token != NULL) {
        words[i] = (char *) calloc(strlen(token), sizeof(char));
        strcpy(words[i], token);
        i++;
        words = (char **) realloc(words, (i + 1) * sizeof(char *));
        token = strtok(NULL, " ,.-\n");
    }

    *word_count = i;

    return words;
}

void check_spelling(char **words, int word_count, char *dictionary) {
    char *token;
    int i, j, found;
    char temp_word[100];

    token = strtok(dictionary, "\n");
    while (token != NULL) {
        found = 0;
        for (i = 0; i < word_count; i++) {
            if (strcmp(words[i], token) == 0) {
                found = 1;
                break;
            }
        }

        if (!found) {
            for (j = 0; j < strlen(token); j++) {
                if (token[j] >= 'A' && token[j] <= 'Z') {
                    temp_word[j] = token[j] + 32;
                } else {
                    temp_word[j] = token[j];
                }
            }
            temp_word[j] = '\0';

            for (i = 0; i < word_count; i++) {
                if (strcmp(words[i], temp_word) == 0) {
                    printf("Did you mean: %s?\n", token);
                    break;
                }
            }
        }

        token = strtok(NULL, "\n");
    }
}

int main(int argc, char *argv[]) {
    char *input_file, *dictionary_file, *input, *dictionary;
    char **words;
    int i, word_count;

    if (argc != 3) {
        printf("Usage: %s input_file dictionary_file\n", argv[0]);
        exit(1);
    }

    input_file = argv[1];
    dictionary_file = argv[2];

    input = read_input(input_file);
    dictionary = read_dictionary(dictionary_file);

    words = create_word_array(input, &word_count);

    check_spelling(words, word_count, dictionary);

    for (i = 0; i < word_count; i++) {
        free(words[i]);
    }
    free(words);
    free(input);
    free(dictionary);

    return 0;
}