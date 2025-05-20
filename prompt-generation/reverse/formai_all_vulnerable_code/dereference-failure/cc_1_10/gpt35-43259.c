//FormAI DATASET v1.0 Category: File Synchronizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LEN 1024

typedef struct file {
    char filename[MAX_PATH_LEN];
    long long size;
} file_t;

// Functions to retrieve list of files from directories
bool is_regular_file(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

bool is_directory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

int get_file_count(const char *dir_path) {
    int count = 0;
    DIR *dirp = opendir(dir_path);
    struct dirent *entry;
    while ((entry = readdir(dirp)) != NULL) {
        if (entry->d_type == DT_REG) {
            count++;
        }
    }
    closedir(dirp);
    return count;
}

file_t *get_files_in_directory(const char *dir_path, int *num_files) {
    int file_count = get_file_count(dir_path);
    file_t *file_list = (file_t *)malloc(file_count * sizeof(file_t));
    DIR *dirp = opendir(dir_path);
    struct dirent *entry;
    int index = 0;
    while ((entry = readdir(dirp)) != NULL) {
        if (entry->d_type == DT_REG) {
            // Only get regular files
            file_t file;
            strcpy(file.filename, entry->d_name);
            char full_path[MAX_PATH_LEN];
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, file.filename);
            if (is_regular_file(full_path)) {
                struct stat st;
                stat(full_path, &st);
                file.size = st.st_size;
                file_list[index++] = file;
            }
        }
    }
    closedir(dirp);
    *num_files = index;
    return file_list;
}

// Function to compare two lists of files and generate a synchronization plan
void generate_sync_plan(file_t *local_files, int local_num_files, file_t *remote_files, int remote_num_files) {
    printf("Comparing local and remote file lists...\n");
    int i = 0;
    int j = 0;
    while (i < local_num_files && j < remote_num_files) {
        int cmp = strcmp(local_files[i].filename, remote_files[j].filename);
        if (cmp == 0) {
            // File exists in both local and remote directories
            if (local_files[i].size == remote_files[j].size) {
                printf("%s OK\n", local_files[i].filename);
            } else {
                printf("%s OUT OF SYNC\n", local_files[i].filename);
            }
            i++;
            j++;
        } else if (cmp < 0) {
            // File exists only in local directory
            printf("%s MISSING FROM REMOTE\n", local_files[i].filename);
            i++;
        } else {
            // File exists only in remote directory
            printf("%s MISSING FROM LOCAL\n", remote_files[j].filename);
            j++;
        }
    }
    while (i < local_num_files) {
        printf("%s MISSING FROM REMOTE\n", local_files[i++].filename);
    }
    while (j < remote_num_files) {
        printf("%s MISSING FROM LOCAL\n", remote_files[j++].filename);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <local_dir_path> <remote_dir_path>\n", argv[0]);
        return 1;
    }
    int local_num_files;
    file_t *local_files = get_files_in_directory(argv[1], &local_num_files);
    printf("Local directory %s:\n", argv[1]);
    for (int i = 0; i < local_num_files; i++) {
        printf("%s (%lld bytes)\n", local_files[i].filename, local_files[i].size);
    }
    printf("\n");
    int remote_num_files;
    file_t *remote_files = get_files_in_directory(argv[2], &remote_num_files);
    printf("Remote directory %s:\n", argv[2]);
    for (int i = 0; i < remote_num_files; i++) {
        printf("%s (%lld bytes)\n", remote_files[i].filename, remote_files[i].size);
    }
    printf("\n");
    generate_sync_plan(local_files, local_num_files, remote_files, remote_num_files);
    free(local_files);
    free(remote_files);
    return 0;
}