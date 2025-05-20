//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH 4096
#define MAX_THREADS 10

typedef struct {
    char path[MAX_PATH];
    long total_size;
    int file_count;
} DirInfo;

DirInfo dir_info[MAX_THREADS];
int dir_count = 0;
pthread_mutex_t lock;

void* analyze_directory(void* arg) {
    DirInfo* info = (DirInfo*)arg;
    struct stat st;
    struct dirent* entry;
    DIR* dp;
    
    dp = opendir(info->path);
    if (dp == NULL) {
        perror("opendir failed");
        return NULL;
    }
    
    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char full_path[MAX_PATH];
            snprintf(full_path, sizeof(full_path), "%s/%s", info->path, entry->d_name);
            
            if (stat(full_path, &st) == 0) {
                if (S_ISDIR(st.st_mode)) {
                    // If it's a directory, create a new thread to analyze it
                    if (dir_count < MAX_THREADS) {
                        DirInfo new_info;
                        strcpy(new_info.path, full_path);
                        new_info.total_size = 0;
                        new_info.file_count = 0;
                        
                        pthread_mutex_lock(&lock);
                        dir_info[dir_count++] = new_info;
                        pthread_mutex_unlock(&lock);
                    }
                } else {
                    // If it's a file, update this thread's info
                    info->total_size += st.st_size;
                    info->file_count++;
                }
            }
        }
    }
    
    closedir(dp);
    return NULL;
}

void analyze_filesystem(const char* start_path) {
    pthread_t threads[MAX_THREADS];
    
    DirInfo start_info;
    strcpy(start_info.path, start_path);
    start_info.total_size = 0;
    start_info.file_count = 0;
    dir_info[0] = start_info;
    dir_count = 1;

    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < dir_count; i++) {
        // Create threads for each directory
        pthread_create(&threads[i], NULL, analyze_directory, &dir_info[i]);
    }

    // Join threads
    for (int i = 0; i < dir_count; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print results
    printf("Directory Analysis Results:\n");
    for (int i = 0; i < dir_count; i++) {
        printf("Path: %s\n", dir_info[i].path);
        printf("Total Size: %ld bytes\n", dir_info[i].total_size);
        printf("File Count: %d\n", dir_info[i].file_count);
        printf("-------------------------------\n");
    }
    
    pthread_mutex_destroy(&lock);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path_to_analyze>\n", argv[0]);
        return 1;
    }

    analyze_filesystem(argv[1]);
    
    return 0;
}