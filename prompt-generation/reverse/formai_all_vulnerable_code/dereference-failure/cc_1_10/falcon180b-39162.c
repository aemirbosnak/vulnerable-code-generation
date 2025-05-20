//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 32
#define MAX_FILE_NAME_LEN 256
#define MAX_FILE_SIZE (1024 * 1024 * 1024) // 1GB

typedef struct {
    char key[MAX_KEY_LEN];
    int num_rounds;
} encryption_params;

void generate_key(char* key, int len) {
    for(int i=0; i<len; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[len] = '\0';
}

void encrypt_file(FILE* input_file, FILE* output_file, encryption_params* params) {
    char buffer[1024];
    int buffer_len;
    char* file_data = malloc(MAX_FILE_SIZE);
    int file_data_len = 0;

    fseek(input_file, 0, SEEK_END);
    file_data_len = ftell(input_file);
    rewind(input_file);

    while((buffer_len = fread(buffer, 1, 1024, input_file)) > 0) {
        for(int i=0; i<buffer_len; i++) {
            buffer[i] ^= params->key[i % strlen(params->key)];
        }
        fwrite(buffer, 1, buffer_len, output_file);
    }

    free(file_data);
}

int main(int argc, char** argv) {
    if(argc!= 6) {
        printf("Usage: %s input_file output_file key_file num_rounds\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "rb");
    if(input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE* output_file = fopen(argv[2], "wb");
    if(output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    encryption_params params;
    memset(&params, 0, sizeof(params));

    FILE* key_file = fopen(argv[3], "r");
    if(key_file == NULL) {
        printf("Error opening key file.\n");
        return 1;
    }

    fscanf(key_file, "%s", params.key);
    params.num_rounds = atoi(argv[4]);

    encrypt_file(input_file, output_file, &params);

    fclose(input_file);
    fclose(output_file);
    fclose(key_file);

    return 0;
}