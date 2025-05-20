//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 512
#define MALICIOUS_STRING "virus"

typedef struct {
    char *file_path;
} FileScanArg;

void* scan_file(void* args) {
    FileScanArg *file_arg = (FileScanArg*)args;
    FILE *file = fopen(file_arg->file_path, "r");
    if (file == NULL) {
        perror("Failed to open file");
        free(file_arg->file_path);
        free(file_arg);
        return NULL;
    }

    char buffer[4096];
    while (fgets(buffer, sizeof(buffer), file)) {
        if (strstr(buffer, MALICIOUS_STRING) != NULL) {
            printf("Malicious content found in %s\n", file_arg->file_path);
            fclose(file);
            free(file_arg->file_path);
            free(file_arg);
            return NULL;
        }
    }

    fclose(file);
    printf("Scanned %s: No malicious content found.\n", file_arg->file_path);
    free(file_arg->file_path);
    free(file_arg);
    return NULL;
}

void scan_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);
    if (dp == NULL) {
        perror("Failed to open directory");
        return;
    }
    
    pthread_t threads[100];
    int thread_count = 0;

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Regular file
            char file_path[MAX_PATH_LENGTH];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);

            FileScanArg *file_arg = malloc(sizeof(FileScanArg));
            file_arg->file_path = strdup(file_path); // Duplicate the file_path string

            if (pthread_create(&threads[thread_count], NULL, scan_file, file_arg) != 0) {
                perror("Failed to create thread");
                free(file_arg->file_path);
                free(file_arg);
            } else {
                thread_count++;
                if (thread_count >= 100) {
                    break; // Limit to 100 threads
                }
            }
        }
    }
    closedir(dp);

    // Join threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory_path = argv[1];
    scan_directory(directory_path);

    return EXIT_SUCCESS;
}