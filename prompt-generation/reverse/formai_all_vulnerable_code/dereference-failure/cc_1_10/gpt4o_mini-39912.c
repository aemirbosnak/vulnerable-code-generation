//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define LOG_FILE "error_log.txt"

void log_error(const char *message) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        printf("Failed to open log file for writing: %s\n", strerror(errno));
        return;
    }
    fprintf(log_file, "Error: %s\n", message);
    fclose(log_file);
}

void *file_copy(void *arg) {
    char **files = (char **)arg;
    const char *source = files[0];
    const char *destination = files[1];

    FILE *src_file = fopen(source, "r");
    if (src_file == NULL) {
        log_error(strerror(errno));
        pthread_exit((void *)1);
    }

    FILE *dest_file = fopen(destination, "w");
    if (dest_file == NULL) {
        log_error(strerror(errno));
        fclose(src_file);
        pthread_exit((void *)2);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, src_file) != NULL) {
        if (fputs(buffer, dest_file) == EOF) {
            log_error(strerror(errno));
            fclose(src_file);
            fclose(dest_file);
            pthread_exit((void *)3);
        }
    }

    fclose(src_file);
    fclose(dest_file);
    pthread_exit((void *)0);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source file> <destination file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pthread_t thread;
    char *files[2] = {argv[1], argv[2]};
    
    int rc = pthread_create(&thread, NULL, file_copy, (void *)files);
    if (rc) {
        fprintf(stderr, "Error creating thread: %s\n", strerror(rc));
        exit(EXIT_FAILURE);
    }

    void *status;
    rc = pthread_join(thread, &status);
    if (rc) {
        fprintf(stderr, "Error joining thread: %s\n", strerror(rc));
        exit(EXIT_FAILURE);
    }

    if ((long)status != 0) {
        fprintf(stderr, "File copy failed with error code: %ld\n", (long)status);
        exit(EXIT_FAILURE);
    }

    printf("File copied successfully from %s to %s\n", argv[1], argv[2]);
    return EXIT_SUCCESS;
}