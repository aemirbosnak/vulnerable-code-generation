//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define FILE_PATH_MAX 260

typedef struct {
    char *file_path;
} file_info;

void *scan_file(void *arg) {
    file_info *info = (file_info *)arg;
    char buffer[BUFFER_SIZE];
    FILE *file = fopen(info->file_path, "r");
    if (file == NULL) {
        printf("Could not open file: %s\n", info->file_path);
        free(info);
        return NULL;
    }

    // Simulated virus check for demo purposes
    int found_virus = 0;
    while (fgets(buffer, BUFFER_SIZE, file)) {
        if (strstr(buffer, "virus_signature") != NULL) {
            found_virus = 1;
            break;
        }
    }

    fclose(file);
    if (found_virus) {
        printf("Virus found in: %s\n", info->file_path);
    } else {
        printf("No virus found in: %s\n", info->file_path);
    }

    free(info);
    return NULL;
}

void scan_directory(const char *dir_path) {
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }

    struct dirent *entry;
    pthread_t threads[100]; // Arbitrary limit for simultaneous threads
    int thread_count = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            char *file_path = malloc(FILE_PATH_MAX);
            snprintf(file_path, FILE_PATH_MAX, "%s/%s", dir_path, entry->d_name);

            file_info *info = malloc(sizeof(file_info));
            info->file_path = file_path;

            pthread_create(&threads[thread_count++], NULL, scan_file, (void *)info);

            // Ensure we don't exceed the number of threads we allocated space for
            if (thread_count >= 100) {
                for (int i = 0; i < 100; i++) {
                    pthread_join(threads[i], NULL);
                }
                thread_count = 0; // Reset thread count after joining
            }
        }
    }

    // Join remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    scan_directory(argv[1]);

    return EXIT_SUCCESS;
}