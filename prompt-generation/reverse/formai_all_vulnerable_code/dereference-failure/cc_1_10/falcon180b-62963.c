//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// Function to compare two files based on their size and modification time
int compare_files(const struct dirent *file1, const struct dirent *file2) {
    struct stat stat1, stat2;
    stat(file1->d_name, &stat1);
    stat(file2->d_name, &stat2);

    // Compare file sizes
    if (stat1.st_size!= stat2.st_size) {
        return 1;
    }

    // Compare modification times
    if (stat1.st_mtime!= stat2.st_mtime) {
        return 1;
    }

    return 0;
}

// Function to synchronize files between two directories
void sync_files(const char *src_dir, const char *dest_dir) {
    DIR *src_dir_ptr = opendir(src_dir);
    DIR *dest_dir_ptr = opendir(dest_dir);

    if (!src_dir_ptr ||!dest_dir_ptr) {
        printf("Error: One or both directories do not exist.\n");
        exit(1);
    }

    struct dirent *src_file = NULL;
    struct dirent *dest_file = NULL;

    while ((src_file = readdir(src_dir_ptr))!= NULL && (dest_file = readdir(dest_dir_ptr))!= NULL) {
        if (compare_files(src_file, dest_file)) {
            // Files are different, copy from source to destination
            char src_file_path[256];
            char dest_file_path[256];

            sprintf(src_file_path, "%s/%s", src_dir, src_file->d_name);
            sprintf(dest_file_path, "%s/%s", dest_dir, src_file->d_name);

            if (rename(src_file_path, dest_file_path)!= 0) {
                printf("Error: Failed to copy file '%s'.\n", src_file->d_name);
            }
        }
    }

    closedir(src_dir_ptr);
    closedir(dest_dir_ptr);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage:./file_sync <source_directory> <destination_directory> <mode>\n");
        printf("Mode options:\n");
        printf("-c : Copy files from source to destination\n");
        printf("-s : Synchronize files between source and destination\n");
        exit(1);
    }

    const char *src_dir = argv[1];
    const char *dest_dir = argv[2];
    const char *mode = argv[3];

    if (strcmp(mode, "-c") == 0) {
        // Copy mode
        sync_files(src_dir, dest_dir);
    } else if (strcmp(mode, "-s") == 0) {
        // Sync mode
        sync_files(src_dir, dest_dir);
        sync_files(dest_dir, src_dir);
    } else {
        printf("Error: Invalid mode.\n");
        exit(1);
    }

    return 0;
}