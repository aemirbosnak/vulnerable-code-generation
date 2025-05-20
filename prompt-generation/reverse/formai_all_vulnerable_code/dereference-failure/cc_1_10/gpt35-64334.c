//FormAI DATASET v1.0 Category: File Synchronizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void sync_files(char* src, char* dest);
void copy_file(char* src_file_path, char* dest_file_path);

int main() {
    char* src_dir = "/home/user/source_directory";
    char* dest_dir = "/home/user/destination_directory";

    sync_files(src_dir, dest_dir);

    return 0;
}

/*
 * Recursively synchronizes all files from the source directory to the destination directory
 * If a file in the source directory is not present in the destination directory, it is copied over
 * If a file is present in both directories but its modification time is newer in the source directory,
 * it is copied over
 */
void sync_files(char* src, char* dest) {
    DIR* src_dir = opendir(src);
    if (!src_dir) {
        printf("Error opening source directory\n");
        return;
    }

    DIR* dest_dir = opendir(dest);
    if (!dest_dir) {
        printf("Error opening destination directory\n");
        closedir(src_dir);
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(src_dir)) != NULL) {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            // Recursively synchronize subdirectories
            char src_subdir[256], dest_subdir[256];
            sprintf(src_subdir, "%s/%s", src, entry->d_name);
            sprintf(dest_subdir, "%s/%s", dest, entry->d_name);
            sync_files(src_subdir, dest_subdir);
        } else if (entry->d_type == DT_REG) {
            // Regular file, check if it needs to be copied over
            char src_file_path[256], dest_file_path[256];
            sprintf(src_file_path, "%s/%s", src, entry->d_name);
            sprintf(dest_file_path, "%s/%s", dest, entry->d_name);

            struct stat src_stat, dest_stat;
            stat(src_file_path, &src_stat);
            stat(dest_file_path, &dest_stat);

            if (dest_stat.st_mtime < src_stat.st_mtime) {
                // Source file is newer, copy over
                copy_file(src_file_path, dest_file_path);
            }
        }
    }

    closedir(src_dir);
    closedir(dest_dir);
}

/*
 * Copies a file from source path to destination path
 */
void copy_file(char* src_file_path, char* dest_file_path) {
    FILE* src_file = fopen(src_file_path, "rb");
    if (!src_file) {
        printf("Error opening source file %s\n", src_file_path);
        return;
    }

    FILE* dest_file = fopen(dest_file_path, "wb");
    if (!dest_file) {
        printf("Error opening destination file %s\n", dest_file_path);
        fclose(src_file);
        return;
    }

    // Copy contents of file from source to dest
    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, 1024, src_file)) > 0) {
        fwrite(buffer, 1, bytes_read, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
}