//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encrypt(char* input_file, char* output_file, char* key) {
    FILE* input = fopen(input_file, "rb");
    FILE* output = fopen(output_file, "wb");

    if (input == NULL || output == NULL) {
        printf("Error: could not open file(s).\n");
        exit(1);
    }

    char key_buffer[strlen(key) + 1];
    strcpy(key_buffer, key);

    int key_index = 0;

    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] ^= key_buffer[key_index % strlen(key)];
            key_index++;
        }

        fwrite(buffer, 1, bytes_read, output);
    }

    fclose(input);
    fclose(output);
}

int main() {
    char input_file[100];
    char output_file[100];
    char key[100];

    printf("Enter input file name: ");
    scanf("%s", input_file);

    printf("Enter output file name: ");
    scanf("%s", output_file);

    printf("Enter encryption key: ");
    scanf("%s", key);

    encrypt(input_file, output_file, key);

    printf("File encrypted successfully!\n");

    return 0;
}