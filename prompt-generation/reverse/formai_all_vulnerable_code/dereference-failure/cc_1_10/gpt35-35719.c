//FormAI DATASET v1.0 Category: File Encyptor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 1000000

int main() {
    FILE *file_in, *file_out;
    char input_file[100], output_file[100], key;
    int i, file_size;

    // Get input file name from user
    printf("Enter name of file to encrypt: ");
    scanf("%s", input_file);

    // Get output file name from user
    printf("Enter name of output file: ");
    scanf("%s", output_file);

    // Get encryption key from user
    printf("Enter an encryption key: ");
    scanf(" %c", &key);

    // Open input file for reading
    file_in = fopen(input_file, "rb");
    if (file_in == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open output file for writing
    file_out = fopen(output_file, "wb");
    if (file_out == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Get size of input file
    fseek(file_in, 0L, SEEK_END);
    file_size = ftell(file_in);
    rewind(file_in);

    // Make sure input file is not too big
    if (file_size > MAX_FILE_SIZE) {
        printf("Error: Input file too big.\n");
        return 1;
    }

    // Create buffer to hold file contents
    char *buffer = (char *) malloc(sizeof(char) * file_size);

    // Read input file into buffer
    fread(buffer, sizeof(char), file_size, file_in);

    // Encrypt buffer
    for (i = 0; i < file_size; i++) {
        buffer[i] = buffer[i] ^ key;
    }

    // Write encrypted buffer to output file
    fwrite(buffer, sizeof(char), file_size, file_out);

    // Cleanup
    free(buffer);
    fclose(file_in);
    fclose(file_out);

    printf("Encryption complete.\n");

    return 0;
}