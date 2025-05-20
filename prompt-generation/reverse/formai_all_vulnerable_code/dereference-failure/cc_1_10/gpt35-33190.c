//FormAI DATASET v1.0 Category: File Synchronizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define BUF_SIZE 1024 // Size of buffer for copying files

void sync_files(char *source_dir, char *dest_dir) {
    DIR *sourcep, *destp;
    struct dirent *source_entry, *dest_entry;
    char source_path[PATH_MAX], dest_path[PATH_MAX];
    FILE *src_file, *dest_file;
    char buf[BUF_SIZE];
    size_t nread;

    // Open source and destination directories
    sourcep = opendir(source_dir);
    if (sourcep == NULL) {
        fprintf(stderr, "Error: Could not open source directory\n");
        exit(EXIT_FAILURE);
    }
    destp = opendir(dest_dir);
    if (destp == NULL) {
        fprintf(stderr, "Error: Could not open destination directory\n");
        exit(EXIT_FAILURE);
    }

    // Iterate through source directory
    while ((source_entry = readdir(sourcep)) != NULL) {
        if (strcmp(source_entry->d_name, ".") == 0 || strcmp(source_entry->d_name, "..") == 0) {
            // Ignore current and parent directories
            continue;
        }

        // Construct source file path
        snprintf(source_path, PATH_MAX, "%s/%s", source_dir, source_entry->d_name);

        // Check if file already exists in destination directory
        int file_found = 0;
        rewinddir(destp);
        while ((dest_entry = readdir(destp)) != NULL) {
            if (strcmp(dest_entry->d_name, ".") == 0 || strcmp(dest_entry->d_name, "..") == 0) {
                // Ignore current and parent directories
                continue;
            }

            // Construct destination file path
            snprintf(dest_path, PATH_MAX, "%s/%s", dest_dir, dest_entry->d_name);

            if (strcmp(source_entry->d_name, dest_entry->d_name) == 0) {
                // File exists in destination directory
                file_found = 1;
                break;
            }
        }

        if (!file_found) {
            // File does not exist in destination directory
            printf("Copying %s to %s\n", source_path, dest_dir);

            // Open source file for reading
            src_file = fopen(source_path, "r");
            if (src_file == NULL) {
                fprintf(stderr, "Error: Could not open source file %s\n", source_path);
                continue;
            }

            // Construct destination file path
            snprintf(dest_path, PATH_MAX, "%s/%s", dest_dir, source_entry->d_name);

            // Open destination file for writing
            dest_file = fopen(dest_path, "w");
            if (dest_file == NULL) {
                fprintf(stderr, "Error: Could not open destination file %s\n", dest_path);
                fclose(src_file);
                continue;
            }

            // Copy file contents
            while ((nread = fread(buf, 1, BUF_SIZE, src_file)) > 0) {
                fwrite(buf, 1, nread, dest_file);
            }

            // Clean up
            fclose(src_file);
            fclose(dest_file);
        }
    }

    // Clean up
    closedir(sourcep);
    closedir(destp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s source_dir dest_dir\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sync_files(argv[1], argv[2]);

    printf("File synchronization complete!\n");

    return 0;
}