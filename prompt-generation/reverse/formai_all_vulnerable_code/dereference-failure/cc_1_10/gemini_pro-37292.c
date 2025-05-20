//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH 1024

// Ensure that the destination directory exists.
int ensure_directory_exists(const char *path) {
    struct stat st;
    if (stat(path, &st) == -1) {
        if (mkdir(path, 0755) == -1) {
            return -1;
        }
    } else if (!S_ISDIR(st.st_mode)) {
        return -1;
    }

    return 0;
}

// Synchronize the files in the specified directories.
int sync_directories(const char *src_dir, const char *dst_dir) {
    DIR *src_ptr, *dst_ptr;
    struct dirent *src_entry, *dst_entry;
    char src_path[MAX_PATH], dst_path[MAX_PATH];

    // Open the source and destination directories.
    if ((src_ptr = opendir(src_dir)) == NULL) {
        return -1;
    }

    if ((dst_ptr = opendir(dst_dir)) == NULL) {
        return -1;
    }

    // Iterate over the files in the source directory.
    while ((src_entry = readdir(src_ptr)) != NULL) {
        if (src_entry->d_name[0] == '.') {
            continue;
        }

        // Construct the full paths for the source and destination files.
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, src_entry->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst_dir, src_entry->d_name);

        // Check if the file exists in the destination directory.
        if (access(dst_path, F_OK) == -1) {
            // If the file does not exist, copy it from the source directory.
            if (copy_file(src_path, dst_path) == -1) {
                return -1;
            }
        } else {
            // If the file already exists, compare its modification times.
            struct stat src_st, dst_st;
            if (stat(src_path, &src_st) == -1 || stat(dst_path, &dst_st) == -1) {
                return -1;
            }

            // If the source file is newer, copy it to the destination directory.
            if (src_st.st_mtime > dst_st.st_mtime) {
                if (copy_file(src_path, dst_path) == -1) {
                    return -1;
                }
            }
        }
    }

    // Close the source and destination directories.
    if (closedir(src_ptr) == -1 || closedir(dst_ptr) == -1) {
        return -1;
    }

    return 0;
}

// Copy the specified file from the source path to the destination path.
int copy_file(const char *src_path, const char *dst_path) {
    FILE *src_fp, *dst_fp;
    char buffer[1024];
    size_t bytes_read;

    // Open the source and destination files.
    if ((src_fp = fopen(src_path, "rb")) == NULL) {
        return -1;
    }

    if ((dst_fp = fopen(dst_path, "wb")) == NULL) {
        fclose(src_fp);
        return -1;
    }

    // Copy the data from the source file to the destination file.
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_fp)) > 0) {
        if (fwrite(buffer, 1, bytes_read, dst_fp) != bytes_read) {
            fclose(src_fp);
            fclose(dst_fp);
            return -1;
        }
    }

    // Close the source and destination files.
    if (fclose(src_fp) == -1 || fclose(dst_fp) == -1) {
        return -1;
    }

    return 0;
}

// Entry point for the program.
int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source directory> <destination directory>\n", argv[0]);
        return 1;
    }

    // Ensure that the destination directory exists.
    if (ensure_directory_exists(argv[2]) == -1) {
        fprintf(stderr, "Error: Failed to create destination directory\n");
        return 1;
    }

    // Synchronize the files in the two directories.
    if (sync_directories(argv[1], argv[2]) == -1) {
        fprintf(stderr, "Error: Failed to synchronize files\n");
        return 1;
    }

    return 0;
}