//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 1024

void sync_files(const char *src_dir, const char *dest_dir);
void copy_file(const char *src_file, const char *dest_file);
void create_directories(const char *dir_path);
void get_file_list(const char *dir, char files[][MAX_PATH], int *count);
int is_file_updated(const char *src_file, const char *dest_file);
int is_directory(const char *path);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    sync_files(argv[1], argv[2]);
    return EXIT_SUCCESS;
}

void sync_files(const char *src_dir, const char *dest_dir) {
    char src_files[BUFFER_SIZE][MAX_PATH];
    char dest_files[BUFFER_SIZE][MAX_PATH];
    int src_count = 0, dest_count = 0;
    
    get_file_list(src_dir, src_files, &src_count);
    get_file_list(dest_dir, dest_files, &dest_count);

    // Sync from source to destination
    for (int i = 0; i < src_count; i++) {
        char src_path[MAX_PATH], dest_path[MAX_PATH];
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, src_files[i]);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, src_files[i]);

        if (is_directory(src_path)) {
            create_directories(dest_path);
            sync_files(src_path, dest_path);
        } else {
            // Check if the file needs to be copied or updated
            if (!is_file_updated(src_path, dest_path)) {
                printf("Copying file: %s to %s\n", src_path, dest_path);
                copy_file(src_path, dest_path);
            }
        }
    }
}

void copy_file(const char *src_file, const char *dest_file) {
    FILE *src = fopen(src_file, "rb");
    if (src == NULL) {
        perror("Failed to open source file");
        return;
    }

    FILE *dest = fopen(dest_file, "wb");
    if (dest == NULL) {
        perror("Failed to open destination file");
        fclose(src);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    fclose(src);
    fclose(dest);
}

void create_directories(const char *dir_path) {
    char command[MAX_PATH * 2];
    snprintf(command, sizeof(command), "mkdir -p \"%s\"", dir_path);
    system(command);
}

void get_file_list(const char *dir, char files[][MAX_PATH], int *count) {
    struct dirent *entry;
    DIR *dp = opendir(dir);
    if (dp == NULL) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_name[0] != '.') { // Ignore hidden files
            strncpy(files[(*count)++], entry->d_name, MAX_PATH);
        }
    }
    closedir(dp);
}

int is_file_updated(const char *src_file, const char *dest_file) {
    struct stat src_stat, dest_stat;
    if (stat(src_file, &src_stat) != 0) {
        perror("stat error on source file");
        return 0; // consider as outdated
    }
    if (stat(dest_file, &dest_stat) != 0) {
        return 0; // destination does not exist
    }
    return difftime(src_stat.st_mtime, dest_stat.st_mtime) <= 0;
}

int is_directory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}