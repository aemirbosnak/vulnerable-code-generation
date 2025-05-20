//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16

typedef struct {
    char key[KEY_SIZE];
    FILE* input_file;
    FILE* output_file;
} encryption_params;

void generate_key(char* key) {
    // Generate a random key
    for(int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_SIZE - 1] = '\0';
}

int encrypt_file(encryption_params* params) {
    char input_buffer[1024];
    char output_buffer[1024];
    int input_bytes_read;
    int output_bytes_written;

    while((input_bytes_read = fread(input_buffer, 1, 1024, params->input_file)) > 0) {
        for(int i = 0; i < input_bytes_read; i++) {
            char c = input_buffer[i];
            if(isalpha(c)) {
                c = (c - 'a' + params->key[i % KEY_SIZE]) % 26 + 'a';
            }
            output_buffer[i] = c;
        }
        output_bytes_written = fwrite(output_buffer, 1, input_bytes_read, params->output_file);
        if(output_bytes_written!= input_bytes_read) {
            return -1;
        }
    }

    return 0;
}

int main(int argc, char* argv[]) {
    if(argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return 1;
    }

    encryption_params params;
    memset(&params, 0, sizeof(encryption_params));

    params.input_file = fopen(argv[1], "rb");
    if(params.input_file == NULL) {
        printf("Error opening input file: %s\n", argv[1]);
        return 1;
    }

    params.output_file = fopen(argv[2], "wb");
    if(params.output_file == NULL) {
        printf("Error opening output file: %s\n", argv[2]);
        return 1;
    }

    generate_key(params.key);

    int result = encrypt_file(&params);

    if(result!= 0) {
        printf("Error encrypting file\n");
    } else {
        printf("File encrypted successfully\n");
    }

    fclose(params.input_file);
    fclose(params.output_file);

    return 0;
}