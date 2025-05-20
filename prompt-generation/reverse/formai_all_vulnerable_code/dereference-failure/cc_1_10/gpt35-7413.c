//FormAI DATASET v1.0 Category: File Synchronizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pthread.h>
#include <time.h>

#define MAX_FILES 1024 // Maximum number of files that can be handled by program
#define MAX_NAME_LENGTH 256 // Maximum length of file name

// Structure representing the properties of a file
typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t last_modified;
    size_t size;
} file_props;

// Global variables for storing file lists for synchronization
file_props old_files[MAX_FILES];
file_props new_files[MAX_FILES];
int old_count = 0;
int new_count = 0;

// Function for getting the last modified time and size of a file
void get_file_props(char* file, time_t* last_modified, size_t* size) {
    struct stat sb;
    if (stat(file, &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }
    *last_modified = sb.st_mtime;
    *size = sb.st_size;
}

// Function for comparing two files based on their properties
int compare_files(file_props f1, file_props f2) {
    if (strcmp(f1.name, f2.name)) return -1;
    if (f1.last_modified != f2.last_modified) return -1;
    if (f1.size != f2.size) return -1;
    return 0;
}

// Function for synchronizing old and new file lists
void synchronize_files() {
    int i, j;
    for (i = 0; i < old_count; i++) {
        for (j = 0; j < new_count; j++) {
            if (!compare_files(old_files[i], new_files[j])) break;
        }
        if (j == new_count) {
            printf("Deleting file: %s\n", old_files[i].name);
            if (remove(old_files[i].name) != 0) {
                printf("Error deleting file: %s\n", old_files[i].name);
            }
        }
    }

    for (i = 0; i < new_count; i++) {
        for (j = 0; j < old_count; j++) {
            if (!compare_files(new_files[i], old_files[j])) break;
        }
        if (j == old_count) {
            printf("Copying file: %s\n", new_files[i].name);
            FILE* f_old = fopen(new_files[i].name, "rb");
            FILE* f_new = fopen(old_files[i].name, "wb");
            if (f_old == NULL || f_new == NULL) {
                printf("Error opening file: %s\n", new_files[i].name);
                continue;
            }
            char buffer[1024];
            size_t bytes_read;
            while ((bytes_read = fread(buffer, 1, sizeof(buffer), f_old))) {
                fwrite(buffer, 1, bytes_read, f_new);
            }
            fclose(f_old);
            fclose(f_new);
        }
    }
}

// Thread function for scanning a directory and populating file list
void* scan_directory(void* arg) {
    char* directory = (char*) arg;
    DIR* dp = opendir(directory);
    struct dirent* entry;

    while ((entry = readdir(dp))) {
        char path[MAX_NAME_LENGTH];
        snprintf(path, MAX_NAME_LENGTH, "%s/%s", directory, entry->d_name);
        if (entry->d_type == DT_REG) {
            if (new_count >= MAX_FILES) {
                printf("Maximum number of files reached\n");
                break;
            }
            get_file_props(path, &new_files[new_count].last_modified, &new_files[new_count].size);
            strcpy(new_files[new_count].name, path);
            new_count++;
        }
    }
    closedir(dp);
    pthread_exit(NULL);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage:\n%s [old_directory] [new_directory]\n", argv[0]);
        return 0;
    }

    pthread_t threads[2];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    // Scan old directory in separate thread
    int rc = pthread_create(&threads[0], &attr, scan_directory, (void*) argv[1]);
    if (rc) {
        printf("Error creating thread for %s\n", argv[1]);
        return 1;
    }

    // Scan new directory in main thread
    DIR* dp = opendir(argv[2]);
    struct dirent* entry;
    while ((entry = readdir(dp))) {
        char path[MAX_NAME_LENGTH];
        snprintf(path, MAX_NAME_LENGTH, "%s/%s", argv[2], entry->d_name);
        if (entry->d_type == DT_REG) {
            if (old_count >= MAX_FILES) {
                printf("Maximum number of files reached\n");
                break;
            }
            get_file_props(path, &old_files[old_count].last_modified, &old_files[old_count].size);
            strcpy(old_files[old_count].name, path);
            old_count++;
        }
    }
    closedir(dp);

    // Wait for threads to finish
    pthread_attr_destroy(&attr);
    void* status;
    rc = pthread_join(threads[0], &status);
    if (rc) {
        printf("Error joining thread %s\n", argv[1]);
        return 1;
    }

    // Synchronize files in both directories
    synchronize_files();

    pthread_exit(NULL);
}