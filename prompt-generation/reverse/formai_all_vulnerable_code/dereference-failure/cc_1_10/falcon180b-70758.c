//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_FILE_SIZE 1000000
#define KEY "mysecretkey"

void encrypt_file(char *input_file_name, char *output_file_name) {
    FILE *input_file, *output_file;
    char input_buffer[MAX_FILE_SIZE];
    char output_buffer[MAX_FILE_SIZE];
    size_t bytes_read, bytes_written;
    int key_index = 0;

    input_file = fopen(input_file_name, "rb");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    while ((bytes_read = fread(input_buffer, 1, MAX_FILE_SIZE, input_file)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            output_buffer[i] = input_buffer[i] ^ KEY[key_index % strlen(KEY)];
            key_index++;
        }
        fwrite(output_buffer, 1, bytes_read, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    char input_file_name[MAX_FILE_NAME_LEN];
    char output_file_name[MAX_FILE_NAME_LEN];

    strcpy(input_file_name, argv[1]);
    strcpy(output_file_name, argv[2]);

    encrypt_file(input_file_name, output_file_name);

    printf("File encryption completed successfully\n");
    return 0;
}