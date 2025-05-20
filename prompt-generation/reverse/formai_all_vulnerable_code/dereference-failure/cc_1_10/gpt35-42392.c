//FormAI DATASET v1.0 Category: File Synchronizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define MAX_THREADS 10
#define MAX_SIZE 1024

pthread_t tid[MAX_THREADS];
int thread_counter = 0;

char source[MAX_SIZE], destination[MAX_SIZE];

void copy_file(char *src_file, char *dest_file) {
    FILE *src, *dest;
    src = fopen(src_file, "r");
    dest = fopen(dest_file, "w");
    if (src == NULL) {
        printf("Could not open source file: %s\n", strerror(errno));
        return;
    }
    if (dest == NULL) {
        printf("Could not open destination file: %s\n", strerror(errno));
        return;
    }
    char ch;
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }
    printf("Copying file %s to %s\n", src_file, dest_file);
    fclose(src);
    fclose(dest);
}

void copy_directory(char *src_dir, char *dest_dir) {
    DIR *src, *dest;
    struct dirent *entry;
    struct stat statbuf;
    src = opendir(src_dir);
    if (src == NULL) {
        printf("Could not open source directory: %s\n", strerror(errno));
        return;
    }
    mkdir(dest_dir, 0777);
    while ((entry = readdir(src)) != NULL) {
        if (strcmp(entry->d_name, "..") != 0 && strcmp(entry->d_name, ".") != 0) {
            char src_path[MAX_SIZE];
            char dest_path[MAX_SIZE];
            sprintf(src_path, "%s/%s", src_dir, entry->d_name);
            sprintf(dest_path, "%s/%s", dest_dir, entry->d_name);

            if (lstat(src_path, &statbuf) == -1) {
                printf("Could not access file: %s\n", strerror(errno));
            } else {
                if (S_ISDIR(statbuf.st_mode)) {
                    copy_directory(src_path, dest_path);
                } else {
                    copy_file(src_path, dest_path);
                }
            }
        }
    }
    closedir(src);
}

void *synchronize_directory(void *arg) {
    char *directory = (char *) arg;
    char src_directory[MAX_SIZE], dest_directory[MAX_SIZE];
    sprintf(src_directory, "%s/%s", source, directory);
    sprintf(dest_directory, "%s/%s", destination, directory);

    pthread_mutex_lock(&(tid[thread_counter % MAX_THREADS]));
    thread_counter++;
    pthread_mutex_unlock(&(tid[thread_counter % MAX_THREADS]));

    copy_directory(src_directory, dest_directory);

    pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
    if (argc < 3) {
        printf("Usage: file_sync <source_directory> <destination_directory>\n");
        return 1;
    }

    strcpy(source, argv[1]);
    strcpy(destination, argv[2]);

    DIR *dir = opendir(source);
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, "..") != 0 && strcmp(entry->d_name, ".") != 0) {
            char directory[MAX_SIZE];
            strcpy(directory, entry->d_name);
            pthread_create(&(tid[thread_counter % MAX_THREADS]), NULL, &synchronize_directory, (void *) directory);
            thread_counter++;
        }
    }
    closedir(dir);

    for (int i = 0; i < MAX_THREADS; i++) {
        if (pthread_join(tid[i], NULL) != 0) {
            printf("Could not join thread %lu\n", tid[i]);
        }
    }
    printf("Synchronization complete!\n");
    return 0;
}