//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *input_file, *output_file;
    char filename[100], input_buffer[1000], output_buffer[1000];
    int i, j, k, n, key;

    // Prompt user for input file name
    printf("Enter input file name: ");
    scanf("%s", filename);

    // Open input file
    input_file = fopen(filename, "rb");
    if (input_file == NULL) {
        printf("Error: Cannot open input file.\n");
        exit(1);
    }

    // Prompt user for output file name
    printf("Enter output file name: ");
    scanf("%s", filename);

    // Open output file
    output_file = fopen(filename, "wb");
    if (output_file == NULL) {
        printf("Error: Cannot open output file.\n");
        exit(1);
    }

    // Prompt user for encryption key
    printf("Enter encryption key: ");
    scanf("%d", &key);

    // Read input file into buffer
    n = fread(input_buffer, sizeof(char), sizeof(input_buffer), input_file);

    // Encrypt input buffer using key
    for (i = 0; i < n; i++) {
        if (input_buffer[i] >= 'a' && input_buffer[i] <= 'z') {
            input_buffer[i] = 'a' + (input_buffer[i] - 'a' + key) % 26;
        } else if (input_buffer[i] >= 'A' && input_buffer[i] <= 'Z') {
            input_buffer[i] = 'A' + (input_buffer[i] - 'A' + key) % 26;
        }
    }

    // Write encrypted buffer to output file
    n = fwrite(input_buffer, sizeof(char), sizeof(input_buffer), output_file);

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    // Print success message
    printf("File encryption successful!\n");

    return 0;
}