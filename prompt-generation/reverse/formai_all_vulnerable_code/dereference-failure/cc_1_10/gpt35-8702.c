//FormAI DATASET v1.0 Category: File Synchronizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>

#define MAX_FILES 1000

// Function to check if file exists
int file_exists(char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

// Function to recursively get all files in a directory
void get_files_from_directory(char *dirname, char **all_files, int *num_files) {
    DIR *dp;
    struct dirent *dir;

    dp = opendir(dirname);
    if (dp == NULL) {
        printf("Error opening directory: %s\n", dirname);
        return;
    }

    while ((dir = readdir(dp)) != NULL) {
        if (dir->d_type == DT_REG) { // Regular file
            char *filename = malloc(sizeof(char) * (strlen(dirname) + strlen(dir->d_name) + 2));
            sprintf(filename, "%s/%s", dirname, dir->d_name);
            all_files[*num_files] = filename;
            *num_files += 1;
        } else if (dir->d_type == DT_DIR && strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0) { // Directory
            char *subdir = malloc(sizeof(char) * (strlen(dirname) + strlen(dir->d_name) + 2));
            sprintf(subdir, "%s/%s", dirname, dir->d_name);
            get_files_from_directory(subdir, all_files, num_files);
        }
    }
    closedir(dp);
}

// Function to synchronize two directories by copying missing files
void synchronize_directories(char *source_dir, char *dest_dir) {
    char *all_files_source[MAX_FILES];
    char *all_files_dest[MAX_FILES];
    int num_files_source = 0, num_files_dest = 0;

    // Get all files in source and destination directories
    get_files_from_directory(source_dir, all_files_source, &num_files_source);
    get_files_from_directory(dest_dir, all_files_dest, &num_files_dest);

    // Copy missing files from source to destination directory
    for (int i = 0; i < num_files_source; i++) {
        char *filename = all_files_source[i];
        char *dest_filename = malloc(sizeof(char) * (strlen(dest_dir) + strlen(filename) - strlen(source_dir) + 2));
        sprintf(dest_filename, "%s/%s", dest_dir, filename + strlen(source_dir) + 1);
        if (!file_exists(dest_filename)) {
            // Copy file from source to destination
            FILE *source_file = fopen(filename, "rb");
            FILE *dest_file = fopen(dest_filename, "wb");
            if (source_file == NULL || dest_file == NULL) {
                printf("Error: cannot copy file %s to %s\n", filename, dest_filename);
                continue;
            }
            char buffer[1024];
            size_t bytes_read, bytes_written;
            while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file))) {
                bytes_written = fwrite(buffer, 1, bytes_read, dest_file);
                if (bytes_written != bytes_read) {
                    printf("Error: cannot copy file %s to %s\n", filename, dest_filename);
                    break;
                }
            }
            fclose(source_file);
            fclose(dest_file);
            printf("Copied file %s to %s\n", filename, dest_filename);
        }
        free(dest_filename);
    }

    // Free memory
    for (int i = 0; i < num_files_source; i++) {
        free(all_files_source[i]);
    }
    for (int i = 0; i < num_files_dest; i++) {
        free(all_files_dest[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return 0;
    }

    char *source_dir = realpath(argv[1], NULL);
    char *dest_dir = realpath(argv[2], NULL);
    if (source_dir == NULL || dest_dir == NULL) {
        printf("Invalid directory path\n");
        return 0;
    }

    printf("Synchronizing directories...\n");
    synchronize_directories(source_dir, dest_dir);
    printf("Done\n");

    free(source_dir);
    free(dest_dir);
    return 0;
}