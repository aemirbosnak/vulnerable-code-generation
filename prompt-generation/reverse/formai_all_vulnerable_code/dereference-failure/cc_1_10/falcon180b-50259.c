//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10 MB

void encrypt_file(const char* input_file, const char* output_file, const char* key) {
    FILE* input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error: Failed to open input file.\n");
        exit(1);
    }

    FILE* output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error: Failed to open output file.\n");
        fclose(input);
        exit(1);
    }

    char key_buffer[256];
    strncpy(key_buffer, key, sizeof(key_buffer) - 1);

    char buffer[1024];
    int buffer_pos = 0;
    int buffer_len = 0;

    while (buffer_len < MAX_FILE_SIZE) {
        int bytes_read = fread(buffer + buffer_len, 1, sizeof(buffer) - buffer_len, input);
        if (bytes_read == 0) {
            break;
        }

        buffer_len += bytes_read;

        for (int i = 0; i < bytes_read; i++) {
            char c = tolower(buffer[i + buffer_pos]);
            if (isalpha(c)) {
                c = (c - 'a' + key_buffer[i % strlen(key_buffer)]) % 26 + 'a';
            }

            fwrite(&c, 1, 1, output);
        }
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        exit(1);
    }

    encrypt_file(argv[1], argv[2], argv[3]);

    printf("File encrypted successfully!\n");
    return 0;
}