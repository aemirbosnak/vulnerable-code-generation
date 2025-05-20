//FormAI DATASET v1.0 Category: File Synchronizer ; Style: protected
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdbool.h>

#define BUFFER_SIZE 2048
#define MAX_FILES 1000
#define MAX_THREADS 5

struct file_data {
    char* source_file;
    char* dest_file;
};

bool check_if_directory_exists(char* path) {
    struct stat path_stat;
    if (stat(path, &path_stat) || !S_ISDIR(path_stat.st_mode)) {
        return false;
    }
    return true;
}

void sync_files(char* source_file, char* dest_file) {
    char buffer[BUFFER_SIZE];
    int source_fd, dest_fd, read_bytes;
    source_fd = open(source_file, O_RDONLY);
    dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    while ((read_bytes = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        write(dest_fd, buffer, read_bytes);
    }
    close(source_fd);
    close(dest_fd);
}

void* sync_single_file(void* data) {
    struct file_data* file = (struct file_data*) data;
    sync_files(file->source_file, file->dest_file);
}

void sync_directory(char* source_dir, char* dest_dir) {
    pthread_t threads[MAX_THREADS];
    struct file_data* file_data_array[MAX_FILES];
    DIR* source_dp, * dest_dp;
    struct dirent* source_entry, * dest_entry;
    char source_path[BUFFER_SIZE], dest_path[BUFFER_SIZE];
    int i = 0, num_threads = 0;
    source_dp = opendir(source_dir);
    dest_dp = opendir(dest_dir);

    while ((source_entry = readdir(source_dp))) {
        if (source_entry->d_ino == 0) continue;
        if (strcmp(source_entry->d_name, ".") == 0 || strcmp(source_entry->d_name, "..") == 0) continue;
        sprintf(source_path, "%s/%s", source_dir, source_entry->d_name);
        sprintf(dest_path, "%s/%s", dest_dir, source_entry->d_name);
        if (check_if_directory_exists(source_path)) {
            if (!check_if_directory_exists(dest_path)) {
                mkdir(dest_path, 0755);
            }
            sync_directory(source_path, dest_path);
        } else {
            file_data_array[i] = (struct file_data*) malloc(sizeof(struct file_data));
            file_data_array[i]->source_file = strdup(source_path);
            file_data_array[i]->dest_file = strdup(dest_path);
            int rc = pthread_create(&threads[num_threads], NULL, sync_single_file, (void*) file_data_array[i]);
            if (rc) {
                printf("Error: Couldn't create thread\n");
                exit(-1);
            }
            i++;
            num_threads++;
            if (num_threads >= MAX_THREADS) {
                for (int j = 0; j < num_threads; j++) {
                    pthread_join(threads[j], NULL);
                }
                num_threads = 0;
            }
        }
    }
    closedir(source_dp);
    closedir(dest_dp);

    for (int j = 0; j < num_threads; j++) {
        pthread_join(threads[j], NULL);
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <source_dir> <dest_dir>\n", argv[0]);
        exit(1);
    }

    if (!check_if_directory_exists(argv[1])) {
        printf("Error: Source directory does not exist\n");
        exit(1);
    }

    if (!check_if_directory_exists(argv[2])) {
        printf("Error: Destination directory does not exist\n");
        exit(1);
    }

    sync_directory(argv[1], argv[2]);

    return 0;
}