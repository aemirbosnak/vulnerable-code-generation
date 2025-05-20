//FormAI DATASET v1.0 Category: File Encyptor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define BLOCK_SIZE 128

/* Function prototypes */
void *encrypt(void *filename);
char *get_encrypted_filename(const char *filename);

int main(int argc, char *argv[]) {
    pthread_t threads[argc - 1];
    int i;

    /* Create a thread for each file passed in arguments */
    for (i = 1; i < argc; i++) {
        pthread_create(&threads[i - 1], NULL, encrypt, (void *) argv[i]);
    }

    /* Wait for all threads to finish */
    for (i = 0; i < argc - 1; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *encrypt(void *filename) {
    char *encrypted_filename;
    FILE *file, *encrypted_file;
    unsigned char block[BLOCK_SIZE];
    int bytes_read, i;

    /* Get encrypted filename */
    encrypted_filename = get_encrypted_filename((const char *) filename);

    /* Open file and encrypted file */
    file = fopen((const char *) filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    encrypted_file = fopen(encrypted_filename, "w");
    if (encrypted_file == NULL) {
        perror("Error creating encrypted file");
        fclose(file);
        return NULL;
    }

    /* Read data from file in blocks and encrypt it */
    while ((bytes_read = fread(block, 1, BLOCK_SIZE, file)) > 0) {
        for (i = 0; i < bytes_read; i++) {
            /* Simple Caesar cipher encryption */
            block[i] += 3;
        }

        fwrite(block, 1, bytes_read, encrypted_file);
    }

    /* Close files and free memory */
    fclose(file);
    fclose(encrypted_file);
    free(encrypted_filename);

    return NULL;
}

char *get_encrypted_filename(const char *filename) {
    char *encrypted_filename, *ext;
    int length;

    /* Get file extension */
    ext = strrchr(filename, '.');
    if (ext == NULL) {
        length = strlen(filename);
    } else {
        length = ext - filename;
    }

    /* Allocate memory for encrypted filename */
    encrypted_filename = (char *) malloc(length + 11); /* ".encrypted" + '\0' */

    /* Copy filename without extension */
    strncpy(encrypted_filename, filename, length);

    /* Add ".encrypted" extension */
    strcpy(encrypted_filename + length, ".encrypted");

    return encrypted_filename;
}