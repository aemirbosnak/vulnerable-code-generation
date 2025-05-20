//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if correct number of arguments were given
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    // Read input file
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Read file contents into memory
    fseek(input_file, 0, SEEK_END);
    long file_size = ftell(input_file);
    rewind(input_file);
    char *file_contents = (char*)malloc(file_size + 1);
    if (file_contents == NULL) {
        perror("Error allocating memory for file contents");
        return 1;
    }
    fread(file_contents, 1, file_size, input_file);
    file_contents[file_size] = '\0';

    // Close input file
    fclose(input_file);

    // Create output file
    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        perror("Error opening output file");
        return 1;
    }

    // Encrypt file contents
    for (int i = 0; i < file_size; i++) {
        file_contents[i] = (file_contents[i] ^ 0x20) ^ 0x2f;
    }

    // Write encrypted file contents to output file
    fwrite(file_contents, 1, file_size, output_file);

    // Close output file
    fclose(output_file);

    // Free memory
    free(file_contents);

    printf("File encryption successful\n");
    return 0;
}