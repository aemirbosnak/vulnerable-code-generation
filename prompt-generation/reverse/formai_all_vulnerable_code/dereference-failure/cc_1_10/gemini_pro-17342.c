//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(void) {
    // Get the input file name from the user.
    char input_file_name[MAX_LINE_LENGTH];
    printf("Enter the name of the file you want to encrypt: ");
    scanf("%s", input_file_name);

    // Get the output file name from the user.
    char output_file_name[MAX_LINE_LENGTH];
    printf("Enter the name of the file you want to save the encrypted data to: ");
    scanf("%s", output_file_name);

    // Get the encryption key from the user.
    char encryption_key[MAX_LINE_LENGTH];
    printf("Enter the encryption key: ");
    scanf("%s", encryption_key);

    // Open the input file.
    FILE *input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error opening the input file.\n");
        return EXIT_FAILURE;
    }

    // Open the output file.
    FILE *output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error opening the output file.\n");
        return EXIT_FAILURE;
    }

    // Read the input file line by line.
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        // Encrypt the line.
        int line_length = strlen(line);
        for (int i = 0; i < line_length; i++) {
            line[i] ^= encryption_key[i % strlen(encryption_key)];
        }

        // Write the encrypted line to the output file.
        fputs(line, output_file);
    }

    // Close the input file.
    fclose(input_file);

    // Close the output file.
    fclose(output_file);

    // Let the user know that the encryption was successful.
    printf("Encryption successful.\n");

    return EXIT_SUCCESS;
}