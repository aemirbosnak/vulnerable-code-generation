//FormAI DATASET v1.0 Category: Compression algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024
#define CHUNK_SIZE 8

void *compress(void *args);
void *decompress(void *args);

typedef struct {
    char input_file[100];
    char output_file[100];
    int input_len;
    int output_len;
    int chunk_size;
    char buffer[BUFFER_SIZE];
} compressor_args;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }
    char *input_file = argv[1];
    char *output_file = argv[2];
    FILE *fp = fopen(input_file, "rb");
    if (!fp) {
        fprintf(stderr, "Failed to open input_file: %s\n", input_file);
        exit(1);
    }
    fseek(fp, 0L, SEEK_END);
    int input_len = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    char *input_buffer = (char *) malloc(input_len * sizeof(char));
    fread(input_buffer, sizeof(char), input_len, fp);
    fclose(fp);

    // Compression
    pthread_t thread[MAX_THREADS];
    compressor_args args[MAX_THREADS];

    int num_threads = input_len / BUFFER_SIZE;
    if (input_len % BUFFER_SIZE) {
        num_threads++;
    }
    int current_index = 0;
    for (int i = 0; i < num_threads; i++) {
        compressor_args *compress_args = &args[i];
        compress_args->chunk_size = CHUNK_SIZE;
        compress_args->input_len = BUFFER_SIZE;
        compress_args->output_len = BUFFER_SIZE;
        memcpy(compress_args->buffer, &input_buffer[current_index], BUFFER_SIZE);
        snprintf(compress_args->input_file, sizeof(compress_args->input_file), "%s-%d", input_file, i);
        snprintf(compress_args->output_file, sizeof(compress_args->output_file), "%s-%d.compressed", output_file, i);

        pthread_create(&thread[i], NULL, compress, (void *) compress_args);
        current_index += BUFFER_SIZE;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(thread[i], NULL);
    }

    // Merge files
    fp = fopen(output_file, "wb");
    for (int i = 0; i < num_threads; i++) {
        compressor_args *compress_args = &args[i];
        char filename[100];
        snprintf(filename, sizeof(filename), "%s-%d.compressed", output_file, i);
        FILE *tmp_fp = fopen(filename, "rb");
        if (!tmp_fp) {
            fprintf(stderr, "Failed to open compressed file: %s\n", filename);
            exit(1);
        }
        fread(compress_args->buffer, sizeof(char), compress_args->output_len, tmp_fp);
        fwrite(compress_args->buffer, sizeof(char), compress_args->output_len, fp);
        fclose(tmp_fp);
        remove(filename);
    }
    fclose(fp);

    // Decompression
    fp = fopen(output_file, "rb");
    if (!fp) {
        fprintf(stderr, "Failed to open compressed file: %s\n", output_file);
        exit(1);
    }
    fseek(fp, 0L, SEEK_END);
    int output_len = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    char *output_buffer = (char *) malloc(output_len * sizeof(char));
    fread(output_buffer, sizeof(char), output_len, fp);
    fclose(fp);

    num_threads = output_len / BUFFER_SIZE;
    if (output_len % BUFFER_SIZE) {
        num_threads++;
    }
    current_index = 0;
    for (int i = 0; i < num_threads; i++) {
        compressor_args *decompress_args = &args[i];
        decompress_args->chunk_size = CHUNK_SIZE;
        decompress_args->input_len = BUFFER_SIZE;
        decompress_args->output_len = BUFFER_SIZE;
        memcpy(decompress_args->buffer, &output_buffer[current_index], BUFFER_SIZE);
        snprintf(decompress_args->input_file, sizeof(decompress_args->input_file), "%s-%d.compressed", output_file, i);
        snprintf(decompress_args->output_file, sizeof(decompress_args->output_file), "%s-%d", input_file, i);

        pthread_create(&thread[i], NULL, decompress, (void *) decompress_args);
        current_index += BUFFER_SIZE;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(thread[i], NULL);
    }

    // Merge files
    fp = fopen(input_file, "wb");
    for (int i = 0; i < num_threads; i++) {
        compressor_args *decompress_args = &args[i];
        char filename[100];
        snprintf(filename, sizeof(filename), "%s-%d", input_file, i);
        FILE *tmp_fp = fopen(filename, "rb");
        if (!tmp_fp) {
            fprintf(stderr, "Failed to open decompressed file: %s\n", filename);
            exit(1);
        }
        fread(decompress_args->buffer, sizeof(char), decompress_args->output_len, tmp_fp);
        fwrite(decompress_args->buffer, sizeof(char), decompress_args->output_len, fp);
        fclose(tmp_fp);
        remove(filename);
    }
    fclose(fp);

    return 0;
}

void *compress(void *args) {
    compressor_args *compress_args = (compressor_args *) args;

    FILE *fp = fopen(compress_args->input_file, "wb");
    if (!fp) {
        fprintf(stderr, "Failed to open input file: %s\n", compress_args->input_file);
        exit(1);
    }
    fwrite(compress_args->buffer, sizeof(char), compress_args->input_len, fp);
    fclose(fp);

    // TODO: Add compression algorithm here

    fp = fopen(compress_args->output_file, "wb");
    if (!fp) {
        fprintf(stderr, "Failed to open output file: %s\n", compress_args->output_file);
        exit(1);
    }
    fwrite(compress_args->buffer, sizeof(char), compress_args->output_len, fp);
    fclose(fp);

    pthread_exit(NULL);
}

void *decompress(void *args) {
    compressor_args *decompress_args = (compressor_args *) args;

    FILE *fp = fopen(decompress_args->input_file, "rb");
    if (!fp) {
        fprintf(stderr, "Failed to open input file: %s\n", decompress_args->input_file);
        exit(1);
    }
    fread(decompress_args->buffer, sizeof(char), decompress_args->input_len, fp);
    fclose(fp);

    // TODO: Add decompression algorithm here

    fp = fopen(decompress_args->output_file, "wb");
    if (!fp) {
        fprintf(stderr, "Failed to open output file: %s\n", decompress_args->output_file);
        exit(1);
    }
    fwrite(decompress_args->buffer, sizeof(char), decompress_args->output_len, fp);
    fclose(fp);

    pthread_exit(NULL);
}