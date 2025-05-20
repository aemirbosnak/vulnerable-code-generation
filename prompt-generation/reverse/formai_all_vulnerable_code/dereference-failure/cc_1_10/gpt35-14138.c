//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_PATH_LENGTH 4096
#define MAX_FILES 100000

struct file_info {
    char path[MAX_PATH_LENGTH];
    off_t size;
};

// Global variables
volatile bool done;
volatile bool terminate;
volatile pthread_mutex_t mutex;

sem_t directory_semaphore;

struct file_info files[MAX_FILES];
int num_files = 0;

void search_directory(const char *path);
void process_directory(const char *path);
void process_file(const char *path);

void *file_processor(void *arg);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s directory\n", argv[0]);
        return 1;
    }

    done = false;
    terminate = false;

    pthread_mutex_init(&mutex, NULL);

    sem_init(&directory_semaphore, 0, 1);

    search_directory(argv[1]);

    // Signal all the worker threads that we are done
    pthread_mutex_lock(&mutex);
    done = true;
    pthread_mutex_unlock(&mutex);

    sem_post(&directory_semaphore);

    // Wait for all the worker threads to finish
    while (1) {
        pthread_mutex_lock(&mutex);
        if (num_files == 0 && done) {
            terminate = true;
        }
        pthread_mutex_unlock(&mutex);

        if (terminate) {
            break;
        }

        usleep(10000);
    }

    // Print out all the file information
    for (int i = 0; i < num_files; i++) {
        printf("%s %ld\n", files[i].path, files[i].size);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&directory_semaphore);

    return 0;
}

void search_directory(const char *path) {
    DIR *dirp = opendir(path);

    if (dirp == NULL) {
        return;
    }

    // Process all files and sub-directories in the directory
    struct dirent *entry;
    while ((entry = readdir(dirp))) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char fullpath[MAX_PATH_LENGTH];
        snprintf(fullpath, MAX_PATH_LENGTH, "%s/%s", path, entry->d_name);

        sem_wait(&directory_semaphore);

        if (entry->d_type == DT_DIR) {
            process_directory(fullpath);
        } else {
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, file_processor, strdup(fullpath));
            pthread_detach(thread_id);
        }

        sem_post(&directory_semaphore);
    }

    closedir(dirp);
}

void process_directory(const char *path) {
    // Recursively process the sub-directory
    search_directory(path);
}

void process_file(const char *path) {
    // Get the file size
    struct stat statbuf;
    stat(path, &statbuf);

    // Add the file information to the global array
    pthread_mutex_lock(&mutex);
    strncpy(files[num_files].path, path, MAX_PATH_LENGTH);
    files[num_files].size = statbuf.st_size;
    num_files++;
    pthread_mutex_unlock(&mutex);
}

void *file_processor(void *arg) {
    char *path = (char *) arg;

    process_file(path);

    free(path);

    return NULL;
}