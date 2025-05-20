//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define MAX_THREAD 10

typedef struct {
    char path[MAX_PATH];
    long long total_size;
    int file_count;
} Directory;

void *analyze_directory(void *arg) {
    Directory *dir = (Directory *)arg;
    struct dirent *entry;
    struct stat entry_stat;
    DIR *dp = opendir(dir->path);
    
    if (dp == NULL) {
        perror("opendir");
        pthread_exit(NULL);
    }

    while ((entry = readdir(dp))) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char full_path[MAX_PATH];
            snprintf(full_path, MAX_PATH, "%s/%s", dir->path, entry->d_name);
            if (stat(full_path, &entry_stat) == 0) {
                if (S_ISDIR(entry_stat.st_mode)) {
                    Directory sub_dir = {.total_size = 0, .file_count = 0};
                    strncpy(sub_dir.path, full_path, MAX_PATH);
                    analyze_directory(&sub_dir);
                    dir->total_size += sub_dir.total_size;
                    dir->file_count += sub_dir.file_count;
                } else {
                    dir->total_size += entry_stat.st_size;
                    dir->file_count += 1;
                }
            }
        }
    }

    closedir(dp);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory1> <directory2> ... <directoryN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int thread_count = argc - 1;
    if (thread_count > MAX_THREAD) {
        fprintf(stderr, "Max thread count is %d. Please reduce the number of directories.\n", MAX_THREAD);
        return EXIT_FAILURE;
    }

    pthread_t threads[MAX_THREAD];
    Directory directories[MAX_THREAD];

    for (int i = 0; i < thread_count; i++) {
        strncpy(directories[i].path, argv[i + 1], MAX_PATH);
        directories[i].total_size = 0;
        directories[i].file_count = 0;

        if (pthread_create(&threads[i], NULL, analyze_directory, (void *)&directories[i]) != 0) {
            perror("pthread_create");
            return EXIT_FAILURE;
        }
    }

    long long total_size = 0;
    int total_files = 0;

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
        total_size += directories[i].total_size;
        total_files += directories[i].file_count;
    }

    printf("Total size of files: %lld bytes\n", total_size);
    printf("Total number of files: %d\n", total_files);

    return EXIT_SUCCESS;
}