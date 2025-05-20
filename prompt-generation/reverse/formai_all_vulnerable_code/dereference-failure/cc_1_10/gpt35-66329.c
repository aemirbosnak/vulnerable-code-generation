//FormAI DATASET v1.0 Category: File Synchronizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>

#include <pthread.h>

#define MAX_THREADS 5
#define MAX_BUFFER_SIZE 1024

typedef struct {
    char* src_path;
    char* dest_path;
} SynchronizedPath;

char buffer[MAX_BUFFER_SIZE];

void synchronizeFiles(SynchronizedPath* sp) {
    FILE* src_file, *dest_file;
    struct stat src_stat, dest_stat;
    time_t src_modified_time, dest_modified_time;

    if (stat(sp->src_path, &src_stat) < 0) {
        printf("Error: Unable to obtain file %s statistics\n", sp->src_path);
        return;
    }

    if (stat(sp->dest_path, &dest_stat) < 0) {
        printf("Error: Unable to obtain file %s statistics\n", sp->dest_path);
        return;
    }

    src_modified_time = src_stat.st_mtime;
    dest_modified_time = dest_stat.st_mtime;

    if (difftime(src_modified_time, dest_modified_time) > 0) {
        src_file = fopen(sp->src_path, "rb");
        dest_file = fopen(sp->dest_path, "wb");

        if (src_file == NULL) {
            printf("Error: Unable to open file %s for reading\n", sp->src_path);
            return;
        }

        if (dest_file == NULL) {
            printf("Error: Unable to open file %s for writing\n", sp->dest_path);
            fclose(src_file);
            return;
        }

        while (!feof(src_file)) {
            int bytes_read = fread(buffer, 1, MAX_BUFFER_SIZE, src_file);
            fwrite(buffer, 1, bytes_read, dest_file);
        }

        printf("Synchronized %s -> %s\n", sp->src_path, sp->dest_path);

        fclose(src_file);
        fclose(dest_file);

        return;
    }
}

void* synchronizeThread(void* arg) {
    SynchronizedPath* sp = (SynchronizedPath*) arg;
    synchronizeFiles(sp);
    free(arg);
    return NULL;
}

void synchronizeDirectories(char* src_path, char* dest_path, int parallel) {
    DIR *src_dir, *dest_dir;
    struct dirent *src_dir_entry, *dest_dir_entry;
    char src_entry_path[MAX_BUFFER_SIZE], dest_entry_path[MAX_BUFFER_SIZE];

    if ((src_dir = opendir(src_path)) != NULL) {
        if ((dest_dir = opendir(dest_path)) != NULL) {
            while ((src_dir_entry = readdir(src_dir)) != NULL) {
                if (strcmp(src_dir_entry->d_name, ".") == 0 || strcmp(src_dir_entry->d_name, "..") == 0) {
                    continue;
                }

                snprintf(src_entry_path, MAX_BUFFER_SIZE, "%s/%s", src_path, src_dir_entry->d_name);
                snprintf(dest_entry_path, MAX_BUFFER_SIZE, "%s/%s", dest_path, src_dir_entry->d_name);

                if (dest_dir_entry = readdir(dest_dir)) {
                    closedir(dest_dir);
                    synchronizeDirectories(src_entry_path, dest_entry_path, parallel);
                    continue;
                }

                SynchronizedPath* sp = (SynchronizedPath*) malloc(sizeof(SynchronizedPath));
                sp->src_path = strdup(src_entry_path);
                sp->dest_path = strdup(dest_entry_path);

                if (parallel) {
                    pthread_t t;

                    if (pthread_create(&t, NULL, synchronizeThread, sp) != 0) {
                        printf("Error: Unable to create thread\n");
                    }
                }
                else {
                    synchronizeFiles(sp);
                    free(sp);
                }
            }
            closedir(dest_dir);
        }
        else {
            printf("Error: Unable to open directory %s\n", dest_path);
        }
        closedir(src_dir);
    }
    else {
        printf("Error: Unable to open directory %s\n", src_path);
    }
}

int main(int argc, char** argv) {
    int parallel = 0;
    char* src_path, *dest_path;

    if (argc < 3) {
        printf("Usage: %s <source directory> <destination directory> [-p]\n", argv[0]);
        printf("-p : Synchronize files in parallel\n");
        return 0;
    }

    src_path = argv[1];
    dest_path = argv[2];

    if (argc == 4 && strcmp(argv[3], "-p") == 0) {
        parallel = 1;
    }

    synchronizeDirectories(src_path, dest_path, parallel);

    return 0;
}