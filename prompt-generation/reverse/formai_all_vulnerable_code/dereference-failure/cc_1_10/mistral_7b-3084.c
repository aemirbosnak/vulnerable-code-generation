//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to reverse a string
void reverse_string(char *str) {
    int i = 0, j = strlen(str) - 1;
    char temp;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char line[MAX_LINE_LENGTH];

    // Check if input file is provided as an argument
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    // Open input and output files
    input_file = fopen(argv[1], "r");
    output_file = fopen("output.txt", "w");

    // Check if files were opened successfully
    if (input_file == NULL || output_file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        // Remove newline character from the line
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        // Reverse the line
        reverse_string(line);

        // Write the reversed line to output file
        fprintf(output_file, "%s\n", line);
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    printf("Reversed lines have been written to output.txt\n");

    return 0;
}