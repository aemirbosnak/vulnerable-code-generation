//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

// Function to encrypt the file
void encrypt_file(FILE *input_file, FILE *output_file) {
    char line[MAX_LINE_LENGTH];

    // Read the first line
    fgets(line, MAX_LINE_LENGTH, input_file);

    // Encrypt the first line
    for (int i = 0; i < strlen(line); i++) {
        line[i] = line[i] + 3;
    }

    // Write the encrypted first line to output file
    fprintf(output_file, "%s", line);

    // Recursively encrypt the rest of the file
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        for (int i = 0; i < strlen(line); i++) {
            line[i] = line[i] + 3;
        }
        fprintf(output_file, "%s", line);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file_path output_file_path key\n", argv[0]);
        return 1;
    }

    // Open the input file
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Open the output file
    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    // Get the key
    int key = atoi(argv[3]);

    // Encrypt the file
    encrypt_file(input_file, output_file);

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}