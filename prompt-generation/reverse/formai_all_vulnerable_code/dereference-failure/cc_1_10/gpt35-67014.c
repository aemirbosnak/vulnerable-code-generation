//FormAI DATASET v1.0 Category: File Synchronizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

// Function to recursively copy directories and files from source to destination
void copy_directory(const char *src_path, const char *dest_path) {
    DIR *dir;
    struct dirent *entry;
    struct stat dir_stats;

    // Open directory at source path
    dir = opendir(src_path);
    if (dir == NULL) {
        printf("Unable to open directory %s\n", src_path);
        return;
    }

    // Create directory at destination path
    if (stat(dest_path, &dir_stats) == -1) {
        mkdir(dest_path, 0700);
    }

    // Traverse directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Ignore current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct full path for current directory entry
        char src_entry_path[PATH_MAX];
        char dest_entry_path[PATH_MAX];
        snprintf(src_entry_path, PATH_MAX, "%s/%s", src_path, entry->d_name);
        snprintf(dest_entry_path, PATH_MAX, "%s/%s", dest_path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // Recursively copy directory
            copy_directory(src_entry_path, dest_entry_path);
        }
        else if (entry->d_type == DT_REG) {
            // Copy file
            FILE *src_file, *dest_file;
            int c;

            src_file = fopen(src_entry_path, "r");
            dest_file = fopen(dest_entry_path, "w");

            while ((c = fgetc(src_file)) != EOF) {
                fputc(c, dest_file);
            }

            fclose(src_file);
            fclose(dest_file);
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    // Ensure correct number of arguments
    if (argc != 3) {
        printf("Usage: %s <source path> <destination path>\n", argv[0]);
        return -1;
    }

    // Copy source directory to destination directory
    copy_directory(argv[1], argv[2]);

    printf("Files synchronized successfully!\n");
    return 0;
}