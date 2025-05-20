//FormAI DATASET v1.0 Category: Encryption ; Style: distributed
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <openssl/aes.h>
#include <pthread.h>

#define BLOCK_SIZE AES_BLOCK_SIZE
#define MAX_THREADS 10

typedef struct {
    char *in_file;
    char *out_file;
    unsigned char *key;
} ThreadArgs;

void *encrypt(void *thread_args) {
    ThreadArgs *args = (ThreadArgs *)thread_args;

    FILE *in_fp, *out_fp;
    unsigned char iv[BLOCK_SIZE];

    AES_KEY aes_key;
    AES_set_encrypt_key(args->key, 128, &aes_key);

    in_fp = fopen(args->in_file, "rb");
    out_fp = fopen(args->out_file, "wb");

    fread(iv, sizeof(iv), 1, in_fp);
    fwrite(iv, sizeof(iv), 1, out_fp);

    unsigned char in_buf[BLOCK_SIZE * 10];
    unsigned char out_buf[BLOCK_SIZE * 10];
    int bytes_read;

    while ((bytes_read = fread(in_buf, 1, sizeof(in_buf), in_fp)) > 0) {
        AES_cbc_encrypt(in_buf, out_buf, bytes_read, &aes_key, iv, AES_ENCRYPT);
        fwrite(out_buf, 1, bytes_read, out_fp);
    }

    fclose(in_fp);
    fclose(out_fp);
}

int main(int argc, char **argv) {
    char *in_file = argv[1];
    char *out_file = argv[2];

    unsigned char key[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

    // Split input file into chunks for each thread
    FILE *fp = fopen(in_file, "rb");
    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    int chunk_size = size / MAX_THREADS;
    if (chunk_size % BLOCK_SIZE != 0) {
        chunk_size += BLOCK_SIZE - (chunk_size % BLOCK_SIZE);
    }

    pthread_t threads[MAX_THREADS];
    ThreadArgs *thread_args;

    for (int i = 0; i < MAX_THREADS; i++) {
        thread_args = malloc(sizeof(ThreadArgs));
        thread_args->in_file = in_file;
        thread_args->out_file = out_file;
        thread_args->key = key;

        if (i == 0) {
            thread_args->in_file = "-";
        } else if (i == MAX_THREADS - 1) {
            chunk_size = size - (chunk_size * i);
        } else {
            fseek(fp, i * chunk_size - BLOCK_SIZE, SEEK_SET);
        }

        thread_args->in_file = malloc(strlen(in_file) + 3);
        sprintf(thread_args->in_file, "%s.%d", in_file, i);

        thread_args->out_file = malloc(strlen(out_file) + 3);
        sprintf(thread_args->out_file, "%s.%d", out_file, i);

        thread_args->key = key;

        pthread_create(&threads[i], NULL, encrypt, (void *)thread_args);
    }

    fclose(fp);

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // reconstruct output file
    FILE *out_fp = fopen(out_file, "wb");

    for (int i = 0; i < MAX_THREADS; i++) {
        FILE *f = fopen(thread_args[i].out_file, "rb");
        unsigned char buf[4096];
        int bytes_read;

        while ((bytes_read = fread(buf, 1, sizeof(buf), f)) > 0) {
            fwrite(buf, 1, bytes_read, out_fp);
        }

        fclose(f);
        remove(thread_args[i].in_file);
        remove(thread_args[i].out_file);
    }

    fclose(out_fp);

    return 0;
}