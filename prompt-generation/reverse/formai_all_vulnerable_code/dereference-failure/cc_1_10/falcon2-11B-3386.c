//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FILE_SIZE 10000000

char encrypted_data[FILE_SIZE];

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        fprintf(stderr, "Could not open input file.\n");
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    long file_size = ftell(input_file);
    rewind(input_file);

    if (file_size > FILE_SIZE) {
        fprintf(stderr, "File too large to encrypt.\n");
        fclose(input_file);
        return 1;
    }

    encrypted_data[0] = 0x00;
    int bytes_read = fread(encrypted_data, 1, file_size, input_file);

    if (bytes_read!= file_size) {
        fprintf(stderr, "Error reading file.\n");
        fclose(input_file);
        return 1;
    }

    fclose(input_file);

    char output_file[strlen(argv[1]) + 8];
    sprintf(output_file, "%s.enc", argv[1]);

    FILE *output_file_descriptor = fopen(output_file, "wb");
    if (!output_file_descriptor) {
        fprintf(stderr, "Could not open output file.\n");
        return 1;
    }

    int encrypted_data_size = strlen(encrypted_data);
    int bytes_written = fwrite(encrypted_data, 1, encrypted_data_size, output_file_descriptor);

    if (bytes_written!= encrypted_data_size) {
        fprintf(stderr, "Error writing output file.\n");
        fclose(output_file_descriptor);
        return 1;
    }

    fclose(output_file_descriptor);

    printf("Encrypted data saved to %s.\n", output_file);

    return 0;
}