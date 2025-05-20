//FormAI DATASET v1.0 Category: File Synchronizer ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to recursively copy all files and directories from source to destination
void copy_directory(char *src, char *dst) {
    char src_path[512], dst_path[512], buffer[512];
    struct stat st;

    // Open the source directory provided by user
    DIR *dir = opendir(src);
    if (dir == NULL) {
        printf("Error opening source directory!\n");
        exit(1);
    }

    // Create the destination directory provided by user if it doesn't exist
    if (stat(dst, &st) == -1) {
        mkdir(dst, 0700);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip '.' and '..' directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the full path of the source file/directory
        sprintf(src_path, "%s/%s", src, entry->d_name);

        // Construct the full path of the destination file/directory
        sprintf(dst_path, "%s/%s", dst, entry->d_name);

        if (stat(src_path, &st) == -1) {
            printf("Error getting file stats!\n");
            exit(1);
        }

        if (S_ISDIR(st.st_mode)) { // If the entry is a directory
            mkdir(dst_path, 0700);
            copy_directory(src_path, dst_path); // Recursively copy the directory
        } else { // If the entry is a file
            // Open the source file for reading
            FILE *in_file = fopen(src_path, "r");
            if (in_file == NULL) {
                printf("Error opening source file!\n");
                exit(1);
            }

            // Open the destination file for writing
            FILE *out_file = fopen(dst_path, "w");
            if (out_file == NULL) {
                printf("Error opening destination file!\n");
                exit(1);
            }

            // Copy the source file to the destination file
            while (fgets(buffer, sizeof(buffer), in_file)) {
                fprintf(out_file, "%s", buffer);
            }

            // Close the files
            fclose(in_file);
            fclose(out_file);
        }
    }

    // Close the directory
    closedir(dir);
}

int main(int argc, char *argv[]) {
    // Check if the user has provided the correct arguments
    if (argc < 3) {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        exit(1);
    }

    printf("\n--- Welcome to File Synchronizer program! ---\n");

    char *src_dir = argv[1];
    char *dst_dir = argv[2];

    printf("\nSynchronizing files from '%s' to '%s'...\n", src_dir, dst_dir);

    copy_directory(src_dir, dst_dir);

    printf("\nSynchronization successful!\n");

    return 0;
}