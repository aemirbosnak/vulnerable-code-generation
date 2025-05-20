//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the file
void encrypt_file(FILE *input_file, FILE *output_file) {
    char ch;
    int key = 5; // Key to encrypt the file

    // Loop through each character in the file
    while ((ch = fgetc(input_file))!= EOF) {
        // Encrypt the character
        ch = ch + key;

        // Check if the character is uppercase
        if (isupper(ch)) {
            ch = ch - 32;
        }

        // Write the encrypted character to the output file
        fputc(ch, output_file);
    }
}

int main() {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];

    // Get the input and output file names from the user
    printf("Enter the input file name: ");
    scanf("%s", input_filename);

    printf("Enter the output file name: ");
    scanf("%s", output_filename);

    // Open the input and output files
    input_file = fopen(input_filename, "r");
    output_file = fopen(output_filename, "w");

    // Check if the files were opened successfully
    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Encrypt the file
    encrypt_file(input_file, output_file);

    // Close the files
    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");
    return 0;
}