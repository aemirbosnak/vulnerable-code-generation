//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_filename[MAX_LINE_LENGTH], output_filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    int i, j, key, encrypted_char;

    // Get the input and output file names from the command line arguments
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return 1;
    }
    strcpy(input_filename, argv[1]);
    strcpy(output_filename, argv[2]);
    key = atoi(argv[3]);

    // Open the input and output files
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file: %s\n", input_filename);
        return 1;
    }
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file: %s\n", output_filename);
        fclose(input_file);
        return 1;
    }

    // Read the input file line by line and encrypt each line
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                encrypted_char = (key + tolower(line[i]) - 97) % 26 + 97;
                if (isupper(line[i])) {
                    encrypted_char += 'A' - 'a';
                }
                line[i] = encrypted_char;
            } else if (isdigit(line[i])) {
                encrypted_char = (key + line[i] - 48) % 10 + 48;
                line[i] = encrypted_char;
            }
        }
        fputs(line, output_file);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    printf("File encryption complete.\n");

    return 0;
}