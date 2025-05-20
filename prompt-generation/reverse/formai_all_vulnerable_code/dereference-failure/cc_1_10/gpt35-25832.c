//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

// Define the paths to synchronize
#define ROMEO_PATH "/home/romeo/"
#define JULIET_PATH "/home/juliet/"

// Function prototypes
void sync_files(char* src_dir, char* dest_dir);
void copy_file(char* src_file, char* dest_dir);
int is_newer(char* src_file, char* dest_file);

// Main function
int main() {
    printf("Welcome to the C File Synchronizer, Romeo and Juliet Edition\n");

    // Synchronize Romeo's files with Juliet's directory
    sync_files(ROMEO_PATH, JULIET_PATH);

    // Celebrate the successful synchronization
    printf("Sync complete! Romeo and Juliet are now perfectly in sync.\n");

    return 0;
}

// Syncs files from src_dir to dest_dir
void sync_files(char* src_dir, char* dest_dir) {
    DIR* dir;
    struct dirent* entry;

    // Open the source directory
    dir = opendir(src_dir);

    // Check for errors
    if (dir == NULL) {
        fprintf(stderr, "Unable to open directory %s: %s\n", src_dir, strerror(errno));
        exit(1);
    }

    // Loop through all files in the source directory
    while ((entry = readdir(dir)) != NULL) {
        // Ignore "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the full path of the source file
        char src_file[4096];
        snprintf(src_file, sizeof(src_file), "%s%s", src_dir, entry->d_name);

        // Construct the full path of the destination file
        char dest_file[4096];
        snprintf(dest_file, sizeof(dest_file), "%s%s", dest_dir, entry->d_name);

        // Check if the file is a directory
        struct stat st_buf;
        stat(src_file, &st_buf);
        if (S_ISDIR(st_buf.st_mode)) {
            // Recursively sync the subdirectory
            char sub_src_dir[4096];
            snprintf(sub_src_dir, sizeof(sub_src_dir), "%s%s/", src_dir, entry->d_name);

            char sub_dest_dir[4096];
            snprintf(sub_dest_dir, sizeof(sub_dest_dir), "%s%s/", dest_dir, entry->d_name);

            sync_files(sub_src_dir, sub_dest_dir);
        } else {
            // Check if the file needs to be copied
            if (is_newer(src_file, dest_file)) {
                // Copy the file to the destination directory
                copy_file(src_file, dest_dir);
            }
        }
    }

    // Close the directory
    closedir(dir);
}

// Copies a file to dest_dir
void copy_file(char* src_file, char* dest_dir) {
    char dest_file[4096];
    snprintf(dest_file, sizeof(dest_file), "%s%s", dest_dir, basename(src_file));

    // Open the source file and destination file
    FILE* src = fopen(src_file, "rb");
    FILE* dest = fopen(dest_file, "wb");

    // Check for errors
    if (src == NULL || dest == NULL) {
        fprintf(stderr, "Unable to open file: %s\n", strerror(errno));
        exit(1);
    }

    // Copy the contents of the file
    char buffer[4096];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes_read, dest);
    }

    // Close the files
    fclose(src);
    fclose(dest);

    // Print a message indicating the file has been copied
    printf("%s has been synchronized.\n", basename(src_file));
}

// Determines if src_file is newer than dest_file
int is_newer(char* src_file, char* dest_file) {
    struct stat src_buf, dest_buf;

    // Get the stats for both files
    stat(src_file, &src_buf);
    stat(dest_file, &dest_buf);

    // Compare the modification times
    return difftime(src_buf.st_mtime, dest_buf.st_mtime) > 0;
}