//FormAI DATASET v1.0 Category: File handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 100

int main(int argc, char *argv[]) {
    FILE *input_file;
    FILE *output_file;
    char old_word[MAX_WORD_LENGTH];
    char new_word[MAX_WORD_LENGTH];
    char line[MAX_LINE_LENGTH];
    int line_number = 0;

    if (argc < 4) {
        printf("Usage: %s <input_file> <output_file> <old_word> <new_word>\n", argv[0]);
        exit(1);
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file '%s'\n", argv[1]);
        exit(1);
    }

    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file '%s'\n", argv[2]);
        exit(1);
    }

    strcpy(old_word, argv[3]);
    strcpy(new_word, argv[4]);

    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        line_number++;
        char *word = strtok(line, " ");
        while (word != NULL) {
            if (strcmp(word, old_word) == 0) {
                strcpy(word, new_word);
            }
            word = strtok(NULL, " ");
        }
        fputs(line, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("File '%s' successfully modified!\n", argv[1]);

    return 0;
}