//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <dirent.h>
#include <sys/types.h>

#define MAX_THREADS 4
#define MAX_PATH 1024
#define BUFFER_SIZE 256

typedef struct {
    char directory[MAX_PATH];
    char file_extension[10];
    int thread_id;
} ThreadData;

void *extract_metadata(void *arg);
void get_file_metadata(const char *filename);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <directory> <file_extension>\n", argv[0]);
        return EXIT_FAILURE;
    }

    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];
    int ret;

    for (int i = 0; i < MAX_THREADS; i++) {
        thread_data[i].thread_id = i;
        strncpy(thread_data[i].directory, argv[1], MAX_PATH);
        strncpy(thread_data[i].file_extension, argv[2], sizeof(thread_data[i].file_extension));
        
        ret = pthread_create(&threads[i], NULL, extract_metadata, (void *)&thread_data[i]);
        if (ret) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return EXIT_SUCCESS;
}

void *extract_metadata(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    DIR *dir;
    struct dirent *ent;
    char filepath[MAX_PATH];

    if ((dir = opendir(data->directory)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            // Check for the correct file extension
            if (strstr(ent->d_name, data->file_extension) != NULL) {
                snprintf(filepath, MAX_PATH, "%s/%s", data->directory, ent->d_name);
                get_file_metadata(filepath);
            }
        }
        closedir(dir);
    } else {
        perror("Could not open directory");
        pthread_exit(NULL);
    }

    pthread_exit(NULL);
}

void get_file_metadata(const char *filename) {
    printf("Reading metadata for file: %s\n", filename);

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    // Simulating metadata extraction
    char buffer[BUFFER_SIZE];
    size_t file_size;

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (fread(buffer, 1, sizeof(buffer) - 1, file) > 0) {
        buffer[sizeof(buffer) - 1] = '\0'; // Null terminate for safety
    }
    
    printf("File: %s\nSize: %lu bytes\nFirst few bytes: %.20s\n", filename, file_size, buffer);
    
    fclose(file);
}