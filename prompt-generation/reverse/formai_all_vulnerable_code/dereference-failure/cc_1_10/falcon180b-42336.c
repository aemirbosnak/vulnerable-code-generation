//Falcon-180B DATASET v1.0 Category: Text processing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50

int main() {
    FILE *input_file;
    FILE *output_file;
    char input_file_name[MAX_LINE_LENGTH];
    char output_file_name[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];

    printf("Enter the name of the input file: ");
    scanf("%s", input_file_name);
    printf("Enter the name of the output file: ");
    scanf("%s", output_file_name);

    input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        int word_count = 0;
        char *token = strtok(line, " ");
        while (token!= NULL) {
            strcpy(word, token);
            if (strlen(word) > MAX_WORD_LENGTH) {
                printf("Warning: Word '%s' truncated to %d characters.\n", word, MAX_WORD_LENGTH);
            }
            fprintf(output_file, "%s ", word);
            token = strtok(NULL, " ");
            word_count++;
        }
        if (word_count == 0) {
            fprintf(output_file, "\n");
        }
    }

    fclose(input_file);
    fclose(output_file);

    printf("Done.\n");
    return 0;
}