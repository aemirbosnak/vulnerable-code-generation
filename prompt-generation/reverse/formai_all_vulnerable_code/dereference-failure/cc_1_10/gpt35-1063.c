//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <pthread.h>

#define MAX_SIZE 1024*1024*1024 //1GB
#define THREADS 4

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int total_size = 0;

void analyze_files(char *path){
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(path)))
        return;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char sub_path[MAX_SIZE];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            sprintf(sub_path, "%s/%s", path, entry->d_name);
            analyze_files(sub_path);
        } else {
            int size = 0;
            char file_path[MAX_SIZE];
            sprintf(file_path, "%s/%s", path, entry->d_name);
            FILE *file = fopen(file_path, "rb");
            if (file) {
                fseek(file, 0L, SEEK_END);
                size = ftell(file);
                fclose(file);
            }
            pthread_mutex_lock(&lock);
            total_size += size;
            pthread_mutex_unlock(&lock);
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]){
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 0;
    }

    int threads = THREADS;
    if (argc > 2) {
        threads = atoi(argv[2]);
    }

    pthread_t thread[threads];
    for(int i = 0; i < threads; i++) {
        pthread_create(&thread[i], NULL, analyze_files, argv[1]);
    }
    for(int i = 0; i < threads; i++) {
        pthread_join(thread[i], NULL);
    }

    printf("Total size of directory: %d bytes\n", total_size);
    return 0;
}