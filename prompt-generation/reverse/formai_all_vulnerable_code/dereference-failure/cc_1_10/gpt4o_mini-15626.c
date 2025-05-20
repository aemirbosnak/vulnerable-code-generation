//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define AES_KEY_SIZE 128
#define BLOCK_SIZE 16
#define BUFFER_SIZE 1024

typedef struct {
    unsigned char *input;
    int length;
    unsigned char *key;
    unsigned char *output;
} thread_data_t;

void *encrypt_block(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    AES_KEY enc_key;
    
    if (AES_set_encrypt_key(data->key, AES_KEY_SIZE, &enc_key) < 0) {
        fprintf(stderr, "Could not set encryption key.\n");
        pthread_exit(NULL);
    }
    
    for (int i = 0; i < data->length; i += BLOCK_SIZE) {
        unsigned char in[BLOCK_SIZE], out[BLOCK_SIZE];
        memset(in, 0, BLOCK_SIZE);
        memset(out, 0, BLOCK_SIZE);
        
        int remaining = data->length - i;
        int to_encrypt = remaining < BLOCK_SIZE ? remaining : BLOCK_SIZE;
        memcpy(in, data->input + i, to_encrypt);
        
        AES_encrypt(in, out, &enc_key);
        
        memcpy(data->output + i, out, BLOCK_SIZE);
    }
    
    pthread_exit(NULL);
}

void generate_key(unsigned char *key) {
    if (!RAND_bytes(key, AES_KEY_SIZE / 8)) {
        fprintf(stderr, "Error generating random key.\n");
        exit(EXIT_FAILURE);
    }
}

void encrypt_file(const char *input_file, const char *output_file) {
    FILE *fin = fopen(input_file, "rb");
    if (!fin) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }
    
    fseek(fin, 0, SEEK_END);
    int file_size = ftell(fin);
    fseek(fin, 0, SEEK_SET);
    
    unsigned char *buffer = malloc(BUFFER_SIZE);
    unsigned char *key = malloc(AES_KEY_SIZE / 8);
    unsigned char *output = malloc(file_size + BLOCK_SIZE);
    
    generate_key(key);
    
    thread_data_t thread_data;
    while (file_size > 0) {
        int read_size = (file_size < BUFFER_SIZE) ? file_size : BUFFER_SIZE;
        fread(buffer, 1, read_size, fin);

        thread_data.input = buffer;
        thread_data.length = read_size;
        thread_data.key = key;
        thread_data.output = output;

        pthread_t encrypt_thread;
        pthread_create(&encrypt_thread, NULL, encrypt_block, &thread_data);
        pthread_join(encrypt_thread, NULL);

        FILE *fout = fopen(output_file, "ab");
        if (!fout) {
            perror("Failed to open output file");
            free(buffer);
            free(key);
            free(output);
            fclose(fin);
            exit(EXIT_FAILURE);
        }
        
        fwrite(output, 1, read_size, fout);
        fclose(fout);

        file_size -= read_size;
    }
    
    free(buffer);
    free(key);
    free(output);
    fclose(fin);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    encrypt_file(argv[1], argv[2]);

    printf("File encrypted successfully to %s\n", argv[2]);
    return EXIT_SUCCESS;
}