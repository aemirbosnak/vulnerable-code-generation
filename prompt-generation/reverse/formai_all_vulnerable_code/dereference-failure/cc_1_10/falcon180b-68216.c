//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define MAX_WORD_LENGTH 10

typedef struct {
    char *word;
    int length;
} Word;

int main(int argc, char *argv[]) {
    FILE *input_file;
    FILE *output_file;
    char input_filename[MAX_LENGTH];
    char output_filename[MAX_LENGTH];
    char line[MAX_LENGTH];
    Word words[MAX_LENGTH];
    int num_words = 0;
    int i;

    printf("Enter input filename: ");
    scanf("%s", input_filename);

    printf("Enter output filename: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LENGTH, input_file)!= NULL) {
        if (strlen(line) > MAX_WORD_LENGTH) {
            printf("Warning: Line %d is too long and will be truncated.\n", num_words + 1);
        }

        words[num_words].word = strdup(line);
        words[num_words].length = strlen(line);
        num_words++;
    }

    fclose(input_file);
    fclose(output_file);

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    for (i = 0; i < num_words; i++) {
        fprintf(output_file, "%s\n", words[i].word);
    }

    fclose(output_file);

    printf("Done.\n");

    return 0;
}