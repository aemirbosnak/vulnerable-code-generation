//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 16

int main() {
    char input_file[100], output_file[100];
    char key[KEY_LENGTH];
    FILE *input, *output;
    int i, j;

    // Get input file name
    printf("Enter input file name: ");
    scanf("%s", input_file);

    // Get output file name
    printf("Enter output file name: ");
    scanf("%s", output_file);

    // Get encryption key
    printf("Enter encryption key: ");
    scanf("%s", key);

    // Open input file
    input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Open output file
    output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Read input file contents into memory
    char *input_data = NULL;
    fseek(input, 0, SEEK_END);
    long input_size = ftell(input);
    rewind(input);
    input_data = (char*) malloc(input_size);
    if (input_data == NULL) {
        printf("Error allocating memory for input data.\n");
        exit(1);
    }
    fread(input_data, 1, input_size, input);
    fclose(input);

    // Encrypt input data
    for (i = 0; i < input_size; i++) {
        input_data[i] ^= key[i % KEY_LENGTH];
    }

    // Write encrypted data to output file
    fwrite(input_data, 1, input_size, output);
    fclose(output);

    // Free memory
    free(input_data);

    printf("File encrypted successfully.\n");

    return 0;
}