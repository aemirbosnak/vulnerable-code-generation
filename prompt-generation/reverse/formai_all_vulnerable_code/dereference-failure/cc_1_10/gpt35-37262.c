//FormAI DATASET v1.0 Category: Data recovery tool ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 1000

int main() {
    FILE *fp;
    char input_file[50], output_file[50], ch;
    int char_count = 0, lines_count = 0;

    // Get the name of the input file from user
    printf("Enter the name of input file: ");
    scanf("%s", input_file);

    // Open input file in read mode
    fp = fopen(input_file, "r");

    // Check if file exists
    if (fp == NULL) {
        printf("Error: Input file does not exist.\n");
        exit(0);
    }

    // Get the name of the output file from user
    printf("Enter the name of output file: ");
    scanf("%s", output_file);

    // Open output file in write mode
    fp = fopen(output_file, "w");

    // Check if file exists
    if (fp == NULL) {
        printf("Error: Failed to create output file.\n");
        exit(0);
    }

    // Read input file character by character
    while ((ch = fgetc(fp)) != EOF) {
        char_count++;

        // Check if the character is newline
        if (ch == '\n') {
            lines_count++;
        }

        // Write the character to the output file
        fputc(ch, fp);
    }

    // Close both the files
    fclose(fp);

    // Print the statistics of the data recovered
    printf("Data recovery successful.\n");
    printf("Total characters recovered: %d\n", char_count);
    printf("Total lines recovered: %d\n", lines_count);

    return 0;
}