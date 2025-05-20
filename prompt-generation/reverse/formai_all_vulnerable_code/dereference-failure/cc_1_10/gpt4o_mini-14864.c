//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/statvfs.h>
#include <unistd.h>

#define MAX_DIRS 10
#define MAX_PATH_LEN 256

typedef struct {
    char path[MAX_PATH_LEN];
    unsigned long used_space;
    unsigned long free_space;
    unsigned long total_space;
} DiskSpaceInfo;

void* analyze_disk_space(void* arg) {
    DiskSpaceInfo* info = (DiskSpaceInfo*)arg;
    
    struct statvfs stat;
    if (statvfs(info->path, &stat) != 0) {
        perror("statvfs failed");
        return NULL;
    }
    
    // Calculate used, free, and total space
    info->total_space = stat.f_blocks * stat.f_frsize;
    info->free_space = stat.f_bfree * stat.f_frsize;
    info->used_space = info->total_space - info->free_space;
    
    printf("Analyzing: %s\n", info->path);
    printf("Used space: %lu bytes\n", info->used_space);
    printf("Free space: %lu bytes\n", info->free_space);
    printf("Total space: %lu bytes\n\n", info->total_space);
    
    return NULL;
}

void initialize_disk_info(DiskSpaceInfo* info, const char* path) {
    strncpy(info->path, path, MAX_PATH_LEN);
    info->used_space = 0;
    info->free_space = 0;
    info->total_space = 0;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory1> <directory2> ... <directoryN>\n", argv[0]);
        return 1;
    }

    pthread_t threads[MAX_DIRS];
    DiskSpaceInfo disk_info[MAX_DIRS];
    int num_dirs = argc - 1;

    if (num_dirs > MAX_DIRS) {
        fprintf(stderr, "Error: Maximum of %d directories allowed.\n", MAX_DIRS);
        return 1;
    }

    for (int i = 0; i < num_dirs; i++) {
        initialize_disk_info(&disk_info[i], argv[i + 1]);
        if (pthread_create(&threads[i], NULL, analyze_disk_space, (void*)&disk_info[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_dirs; i++) {
        pthread_join(threads[i], NULL);
    }

    // Summarize total usage
    unsigned long total_used = 0, total_free = 0, total_space = 0;
    for (int i = 0; i < num_dirs; i++) {
        total_used += disk_info[i].used_space;
        total_free += disk_info[i].free_space;
        total_space += disk_info[i].total_space;
    }

    printf("Overall disk space information:\n");
    printf("Total used space: %lu bytes\n", total_used);
    printf("Total free space: %lu bytes\n", total_free);
    printf("Total space: %lu bytes\n", total_space);

    return 0;
}