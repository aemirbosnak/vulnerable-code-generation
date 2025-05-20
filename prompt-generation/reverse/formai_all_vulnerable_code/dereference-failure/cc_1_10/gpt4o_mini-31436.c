//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_THREADS 4
#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    long long total_size;
} ThreadData;

void* analyze_directory(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    DIR* dir;
    struct dirent* entry;
    struct stat info;

    dir = opendir(data->path);
    if (dir == NULL) {
        perror("opendir");
        pthread_exit(NULL);
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        char full_path[MAX_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", data->path, entry->d_name);
        if (stat(full_path, &info) == -1) {
            perror("stat");
            continue;
        }

        // If it's a directory, create a new thread for it
        if (S_ISDIR(info.st_mode)) {
            ThreadData* new_data = malloc(sizeof(ThreadData));
            strncpy(new_data->path, full_path, MAX_PATH);
            new_data->total_size = 0;

            // Create a new thread for the subdirectory
            pthread_t thread;
            pthread_create(&thread, NULL, analyze_directory, new_data);
            pthread_detach(thread);
        } else {
            // Accumulate the file size
            data->total_size += info.st_size;
        }
    }

    closedir(dir);
    return NULL;
}

void start_analysis(const char* start_path) {
    ThreadData* data = malloc(sizeof(ThreadData));
    strncpy(data->path, start_path, MAX_PATH);
    data->total_size = 0;

    pthread_t main_thread;
    pthread_create(&main_thread, NULL, analyze_directory, data);
    pthread_detach(main_thread);

    // Sleep to allow threads to complete work
    sleep(5);

    printf("Finished analyzing directory: %s\n", data->path);
    printf("Total size in directory: %lld bytes\n", data->total_size);
    free(data);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    start_analysis(argv[1]);

    // Keep the program running while threads finish their work
    while (1) {
        sleep(1);
    }

    return EXIT_SUCCESS;
}