//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    char *filename;
    int size;
    char *data;
} file_t;

typedef struct {
    file_t *file;
    char *signature;
    int signature_len;
} scan_args_t;

void *scan_thread(void *args) {
    scan_args_t *scan_args = (scan_args_t *)args;

    // Scan the file for the signature
    for (int i = 0; i < scan_args->file->size - scan_args->signature_len; i++) {
        if (memcmp(scan_args->file->data + i, scan_args->signature, scan_args->signature_len) == 0) {
            // Found the signature
            printf("Found signature in file %s at offset %d\n", scan_args->file->filename, i);
            break;
        }
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <signature> <files...>\n", argv[0]);
        return 1;
    }

    // Get the signature
    char *signature = argv[1];
    int signature_len = strlen(signature);

    // Create a thread for each file
    pthread_t threads[argc - 2];
    scan_args_t scan_args[argc - 2];

    for (int i = 2; i < argc; i++) {
        // Open the file
        file_t file;
        file.filename = argv[i];
        file.size = 0;
        file.data = NULL;

        FILE *fp = fopen(file.filename, "rb");
        if (fp == NULL) {
            printf("Error opening file %s\n", file.filename);
            continue;
        }

        // Get the file size
        fseek(fp, 0, SEEK_END);
        file.size = ftell(fp);
        fseek(fp, 0, SEEK_SET);

        // Read the file into memory
        file.data = malloc(file.size);
        if (file.data == NULL) {
            printf("Error allocating memory for file %s\n", file.filename);
            fclose(fp);
            continue;
        }

        fread(file.data, 1, file.size, fp);
        fclose(fp);

        // Create a scan_args_t struct
        scan_args[i - 2].file = &file;
        scan_args[i - 2].signature = signature;
        scan_args[i - 2].signature_len = signature_len;

        // Create a thread
        pthread_create(&threads[i - 2], NULL, scan_thread, &scan_args[i - 2]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < argc - 2; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}