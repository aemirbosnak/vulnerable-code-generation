//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt/decrypt a file
void process_file(const char *input_file, const char *output_file, char key) {
    FILE *infile, *outfile;
    char ch;

    infile = fopen(input_file, "rb");
    if (infile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    outfile = fopen(output_file, "wb");
    if (outfile == NULL) {
        perror("Error opening output file");
        fclose(infile);
        exit(EXIT_FAILURE);
    }

    // Read each character from the input file and XOR it with the key
    while ((ch = fgetc(infile)) != EOF) {
        fputc(ch ^ key, outfile);
    }

    printf("Processing completed: %s -> %s\n", input_file, output_file);

    fclose(infile);
    fclose(outfile);
}

// Function to display the usage of the program
void display_usage() {
    printf("File Encryptor/Decryptor\n");
    printf("Usage: ./file_encryptor <action> <input_file> <output_file> <key>\n");
    printf("Actions:\n");
    printf("  encrypt   - Encrypt the input file\n");
    printf("  decrypt   - Decrypt the input file\n");
    printf("Key: Any single character used for XOR encryption\n");
}

int main(int argc, char *argv[]) {
    // Ensure the correct number of arguments is provided
    if (argc != 5) {
        display_usage();
        return EXIT_FAILURE;
    }

    char *action = argv[1];
    const char *input_file = argv[2];
    const char *output_file = argv[3];
    char key = argv[4][0]; // Use the first character of the key

    // Perform the requested action
    if (strcmp(action, "encrypt") == 0) {
        process_file(input_file, output_file, key);
    } else if (strcmp(action, "decrypt") == 0) {
        process_file(input_file, output_file, key);
    } else {
        printf("Invalid action: use 'encrypt' or 'decrypt'.\n");
        display_usage();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}