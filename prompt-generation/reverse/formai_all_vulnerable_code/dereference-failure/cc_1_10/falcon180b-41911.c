//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if file name is provided
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    // Open input file
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Get file size
    fseek(input_file, 0, SEEK_END);
    long file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    // Allocate memory for input file content
    char *input_content = (char *) malloc(file_size + 1);
    if (input_content == NULL) {
        printf("Error allocating memory.\n");
        fclose(input_file);
        return 1;
    }

    // Read input file content
    fread(input_content, file_size, 1, input_file);
    fclose(input_file);

    // Add encryption key to input content
    char *encryption_key = "HAPPY PROGRAMMING";
    int key_length = strlen(encryption_key);
    for (int i = 0; i < file_size; i++) {
        input_content[i] = input_content[i] ^ encryption_key[i % key_length];
    }

    // Open output file
    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        free(input_content);
        return 1;
    }

    // Write encrypted content to output file
    fwrite(input_content, file_size, 1, output_file);
    fclose(output_file);

    // Free allocated memory
    free(input_content);

    printf("File encrypted successfully!\n");

    return 0;
}