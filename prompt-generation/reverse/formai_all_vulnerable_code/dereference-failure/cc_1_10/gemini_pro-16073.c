//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFF_SIZE 4096

// Function to check if a file exists
int file_exists(const char *filename) {
    struct stat buf;
    return (stat(filename, &buf) == 0);
}

// Function to create a directory
int create_directory(const char *dirname) {
    return mkdir(dirname, 0777);
}

// Function to copy a file
int copy_file(const char *src, const char *dest) {
    FILE *fsrc, *fdest;
    char buf[BUFF_SIZE];
    int nbytes;

    // Open the source file
    fsrc = fopen(src, "rb");
    if (fsrc == NULL) {
        perror("fopen");
        return -1;
    }

    // Open the destination file
    fdest = fopen(dest, "wb");
    if (fdest == NULL) {
        perror("fopen");
        fclose(fsrc);
        return -1;
    }

    // Copy the file
    while ((nbytes = fread(buf, sizeof(char), BUFF_SIZE, fsrc)) > 0) {
        fwrite(buf, sizeof(char), nbytes, fdest);
    }

    // Close the files
    fclose(fsrc);
    fclose(fdest);

    return 0;
}

// Function to delete a file
int delete_file(const char *filename) {
    return remove(filename);
}

// Function to backup a directory
int backup_directory(const char *src_dir, const char *dest_dir) {
    DIR *dir;
    struct dirent *dirent;
    char src_path[256], dest_path[256];
    int result;

    // Create the destination directory if it does not exist
    if (!file_exists(dest_dir)) {
        if (create_directory(dest_dir) != 0) {
            perror("mkdir");
            return -1;
        }
    }

    // Open the source directory
    dir = opendir(src_dir);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    // Iterate over the files in the source directory
    while ((dirent = readdir(dir)) != NULL) {
        // Skip the current and parent directories
        if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
            continue;
        }

        // Get the source and destination paths
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, dirent->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, dirent->d_name);

        // If the source is a directory, recurse
        if (dirent->d_type == DT_DIR) {
            result = backup_directory(src_path, dest_path);
            if (result != 0) {
                closedir(dir);
                return result;
            }
        } else {
            // Copy the file
            result = copy_file(src_path, dest_path);
            if (result != 0) {
                closedir(dir);
                return result;
            }
        }
    }

    // Close the source directory
    closedir(dir);

    return 0;
}

int main(int argc, char *argv[]) {
    int result;

    // Check the number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source directory> <destination directory>\n", argv[0]);
        return 1;
    }

    // Backup the directory
    result = backup_directory(argv[1], argv[2]);
    if (result != 0) {
        perror("backup_directory");
        return 1;
    }

    return 0;
}