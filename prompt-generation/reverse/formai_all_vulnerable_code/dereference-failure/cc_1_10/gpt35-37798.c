//FormAI DATASET v1.0 Category: File Synchronizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

char *root_src_dir = "/path/to/source/directory"; // Change this to your source directory
char *root_dest_dir = "/path/to/destination/directory"; // Change this to your destination directory

void sync_files(char *src_path, char *dest_path) {

    DIR *src_dir = opendir(src_path);
    struct dirent *src_entry;

    while ((src_entry = readdir(src_dir)) != NULL) {
        if (strcmp(src_entry->d_name, ".") == 0 || strcmp(src_entry->d_name, "..") == 0) {
            // Ignore files with names "." and ".."
            continue;
        }

        char *src_file_path = malloc(strlen(src_path) + strlen(src_entry->d_name) + 2);
        strcpy(src_file_path, src_path);
        strcat(src_file_path, "/");
        strcat(src_file_path, src_entry->d_name);

        // Construct destination file path
        char *dest_file_path = malloc(strlen(dest_path) + strlen(src_entry->d_name) + 2);
        strcpy(dest_file_path, dest_path);
        strcat(dest_file_path, "/");
        strcat(dest_file_path, src_entry->d_name);

        struct stat src_file_stat;
        stat(src_file_path, &src_file_stat);

        if (S_ISDIR(src_file_stat.st_mode)) {
            // If file is a directory, recursively determine and create sub-directories in destination
            mkdir(dest_file_path, 0777);
            sync_files(src_file_path, dest_file_path); // Recursively call sync_files() on sub-directory
        } else {
            // If file is not a directory, copy file to destination
            FILE *src_file = fopen(src_file_path, "rb");
            FILE *dest_file = fopen(dest_file_path, "wb");

            if (src_file == NULL || dest_file == NULL) {
                printf("Failed to open file.\n");
                continue;
            }

            // Copy file contents
            char buffer[1024];
            size_t read_size;

            while ((read_size = fread(buffer, 1, 1024, src_file)) > 0) {
                fwrite(buffer, 1, read_size, dest_file);
            }

            fclose(src_file);
            fclose(dest_file);
        }

        free(src_file_path);
        free(dest_file_path);
    }

    closedir(src_dir);
}

int main() {

    sync_files(root_src_dir, root_dest_dir);

    printf("File synchronization complete.\n");

    return 0;
}