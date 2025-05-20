//Falcon-180B DATASET v1.0 Category: Text processing ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_line[MAX_LINE_LENGTH];
    char output_line[MAX_LINE_LENGTH];
    char *word;
    size_t word_len;
    int word_count = 0;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        return 1;
    }

    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", argv[2]);
        return 1;
    }

    while (fgets(input_line, MAX_LINE_LENGTH, input_file)!= NULL) {
        word = strtok(input_line, ",.?!;:");
        while (word!= NULL) {
            word_len = strlen(word);
            if (word_len > MAX_WORD_LENGTH) {
                fprintf(stderr, "Warning: truncating word '%s' to %d characters\n", word, MAX_WORD_LENGTH - 1);
                word_len = MAX_WORD_LENGTH - 1;
            }
            strncpy(output_line, word, word_len);
            output_line[word_len] = '\0';
            fprintf(output_file, "%s ", output_line);
            word_count++;
            word = strtok(NULL, ",.?!;:");
        }
        fprintf(output_file, "\n");
    }

    fclose(input_file);
    fclose(output_file);

    printf("Processed %d words in %s\n", word_count, argv[1]);

    return 0;
}