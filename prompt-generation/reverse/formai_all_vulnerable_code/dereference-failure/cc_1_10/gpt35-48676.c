//FormAI DATASET v1.0 Category: Spell checking ; Style: detailed
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100  // Maximum length of a word in the dictionary
#define MAX_LINE_LEN 1000  // Maximum length of a line in the input file

void toLowercase(char *word) {
    int i = 0;
    while (word[i]) {
        word[i] = tolower(word[i]);
        i++;
    }
}

int lookup(char *word, char **dict, int dict_size) {
    int i;
    for (i = 0; i < dict_size; i++) {
        if (strcmp(word, dict[i]) == 0) {
            return 1;  // the word was found in the dictionary
        }
    }
    return 0;  // the word was not found in the dictionary
}

int main() {
    FILE *dict_file, *input_file, *output_file;
    char *dict[MAX_WORD_LEN];
    char input[MAX_LINE_LEN];
    char word[MAX_WORD_LEN];
    int dict_size = 0, line_num = 0, word_num = 0, error_count = 0;

    // Load the dictionary into memory
    dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error: could not open the dictionary file.\n");
        return 1;
    }
    while (fgets(word, MAX_WORD_LEN, dict_file) != NULL) {
        word[strcspn(word, "\n")] = 0;  // remove the trailing newline
        toLowercase(word);
        dict[dict_size] = malloc(strlen(word) + 1);
        strcpy(dict[dict_size], word);
        dict_size++;
    }
    fclose(dict_file);

    // Open the input and output files
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open the input file.\n");
        return 1;
    }
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: could not open the output file.\n");
        return 1;
    }

    // Check each line of the input file for spelling errors
    while (fgets(input, MAX_LINE_LEN, input_file) != NULL) {
        line_num++;
        word_num = 0;
        int len = strlen(input);
        if (input[len - 1] == '\n') {
            input[len - 1] = '\0';  // remove the trailing newline
        }

        char *tok = strtok(input, " \t");
        while (tok != NULL) {
            word_num++;
            strcpy(word, tok);
            toLowercase(word);
            if (!lookup(word, dict, dict_size)) {
                error_count++;
                fprintf(output_file, "Error in line %d, word %d: %s\n", line_num, word_num, word);
            }
            tok = strtok(NULL, " \t");
        }
    }

    // Close the files
    fclose(input_file);
    fclose(output_file);

    // Free the memory used by the dictionary
    int i;
    for (i = 0; i < dict_size; i++) {
        free(dict[i]);
    }

    printf("Spell checking complete. %d errors found.\n", error_count);
    return 0;
}