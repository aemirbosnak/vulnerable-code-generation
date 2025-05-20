//Falcon-180B DATASET v1.0 Category: Text processing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 100

int main() {
    FILE *input_file;
    FILE *output_file;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int word_count = 0;
    char *word_list[MAX_WORD_LENGTH];

    // Open input file
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Read input file and count words
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            if (strlen(token) > MAX_WORD_LENGTH) {
                printf("Error: Word is too long.\n");
                exit(1);
            }
            strcpy(word_list[word_count], token);
            word_count++;
            if (word_count == MAX_WORD_LENGTH) {
                printf("Error: Too many words.\n");
                exit(1);
            }
            token = strtok(NULL, " ");
        }
    }

    // Open output file
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    // Write word list to output file
    for (int i = 0; i < word_count; i++) {
        fprintf(output_file, "%s\n", word_list[i]);
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}