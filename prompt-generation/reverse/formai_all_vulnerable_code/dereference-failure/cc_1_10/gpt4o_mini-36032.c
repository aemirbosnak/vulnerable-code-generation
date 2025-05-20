//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_FILES 100
#define FILE_NAME_LEN 256
#define BUFFER_SIZE 1024

typedef struct {
    char filename[FILE_NAME_LEN];
    int thread_id;
} file_info;

void *recover_file(void *arg) {
    file_info *info = (file_info *)arg;
    printf("Thread %d: Attempting to recover file: %s...\n", info->thread_id, info->filename);
    
    // Simulate file recovery process
    sleep(1); // Simulate time taken to recover the file
    printf("Thread %d: Successfully recovered file: %s\n", info->thread_id, info->filename);
    
    pthread_exit(NULL);
}

void scan_directory(const char *dir_name) {
    DIR *dir;
    struct dirent *entry;
    pthread_t threads[MAX_FILES];
    file_info files[MAX_FILES];
    int file_count = 0;

    if ((dir = opendir(dir_name)) == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Only recover regular files
            if (file_count >= MAX_FILES) {
                fprintf(stderr, "Max file limit reached.\n");
                break;
            }
            strncpy(files[file_count].filename, entry->d_name, FILE_NAME_LEN);
            files[file_count].thread_id = file_count;
            pthread_create(&threads[file_count], NULL, recover_file, (void *)&files[file_count]);
            file_count++;
        }
    }

    // Close the directory
    closedir(dir);

    // Wait for all threads to complete
    for (int i = 0; i < file_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Starting data recovery tool...\n");
    scan_directory(argv[1]);
    printf("Data recovery process completed.\n");

    return EXIT_SUCCESS;
}