//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/statvfs.h>
#include <unistd.h>

#define MAX_DIRS 100
#define MAX_PATH_LEN 512

typedef struct {
    char path[MAX_PATH_LEN];
    unsigned long total_bytes;
} DirectoryData;

DirectoryData dirs[MAX_DIRS];
int dir_count = 0;
pthread_mutex_t lock;

void* analyze_directory(void* arg) {
    DirectoryData* dir_data = (DirectoryData*)arg;
    struct statvfs stat;

    if (statvfs(dir_data->path, &stat) != 0) {
        perror("Failed to get filesystem statistics");
        return NULL;
    }

    unsigned long total = (stat.f_blocks * stat.f_frsize) / (1024 * 1024);  // Convert to MB
    pthread_mutex_lock(&lock);
    dir_data->total_bytes = total;
    pthread_mutex_unlock(&lock);

    printf("Directory: %s, Total Disk Space: %lu MB\n", dir_data->path, dir_data->total_bytes);
    return NULL;
}

void display_results() {
    unsigned long overall_total = 0;

    for (int i = 0; i < dir_count; i++) {
        overall_total += dirs[i].total_bytes;
    }

    printf("Total Disk Space Used Across All Directories: %lu MB\n", overall_total);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory1> <directory2> ... <directoryN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    dir_count = argc - 1;
    if (dir_count > MAX_DIRS) {
        fprintf(stderr, "Error: A maximum of %d directories can be analyzed.\n", MAX_DIRS);
        return EXIT_FAILURE;
    }

    pthread_t threads[MAX_DIRS];
    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < dir_count; i++) {
        strncpy(dirs[i].path, argv[i + 1], MAX_PATH_LEN);
        dirs[i].total_bytes = 0;
        if (pthread_create(&threads[i], NULL, analyze_directory, &dirs[i]) != 0) {
            perror("Failed to create thread");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < dir_count; i++) {
        pthread_join(threads[i], NULL);
    }

    display_results();
    pthread_mutex_destroy(&lock);
    return EXIT_SUCCESS;
}