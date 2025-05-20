//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define MAX_THREADS 10

typedef struct {
    char path[MAX_PATH_LENGTH];
    long total_size;
} DiskSpaceInfo;

void* analyze_directory(void* arg) {
    DiskSpaceInfo* info = (DiskSpaceInfo*)arg;
    struct dirent* entry;
    struct stat file_stat;

    DIR* dir = opendir(info->path);
    if (dir == NULL) {
        perror("opendir failed");
        return NULL;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char full_path[MAX_PATH_LENGTH];
            snprintf(full_path, sizeof(full_path), "%s/%s", info->path, entry->d_name);

            if (stat(full_path, &file_stat) == 0) {
                if (S_ISREG(file_stat.st_mode)) {
                    info->total_size += file_stat.st_size;
                } else if (S_ISDIR(file_stat.st_mode)) {
                    DiskSpaceInfo* sub_info = malloc(sizeof(DiskSpaceInfo));
                    strcpy(sub_info->path, full_path);
                    sub_info->total_size = 0;

                    analyze_directory(sub_info);
                    info->total_size += sub_info->total_size;
                    free(sub_info);
                }
            }
        }
    }
    closedir(dir);
    return NULL;
}

void print_disk_usage(const char *path) {
    pthread_t threads[MAX_THREADS];
    DiskSpaceInfo disk_space_infos[MAX_THREADS];
    int thread_count = 0;

    snprintf(disk_space_infos[thread_count].path, sizeof(disk_space_infos[thread_count].path), "%s", path);
    disk_space_infos[thread_count].total_size = 0;

    pthread_create(&threads[thread_count], NULL, analyze_directory, &disk_space_infos[thread_count]);
    thread_count++;

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
        printf("Directory: %s, Total Size: %ld bytes\n", disk_space_infos[i].path, disk_space_infos[i].total_size);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    print_disk_usage(argv[1]);
    return EXIT_SUCCESS;
}