//FormAI DATASET v1.0 Category: File Synchronizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void synchronize_files(char *src_path, char *dest_path) {
    DIR *src_dir = opendir(src_path);
    DIR *dest_dir = opendir(dest_path);

    // If either source or destination directory doesn't exist, exit function
    if (!src_dir || !dest_dir) {
        return;
    }

    struct dirent *entry;
    struct stat src_stat, dest_stat;

    while ((entry = readdir(src_dir)) != NULL) {

        char src_file_path[256];
        char dest_file_path[256];

        // Build file paths for both source and destination
        sprintf(src_file_path, "%s/%s", src_path, entry->d_name);
        sprintf(dest_file_path, "%s/%s", dest_path, entry->d_name);

        // Ignore directory entries "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Check if file exists in destination directory
        if (stat(dest_file_path, &dest_stat) == 0) {

            // If file is a directory, synchronize the directory recursively
            if (S_ISDIR(src_stat.st_mode)) {
                // Synchronize the subdirectories
                synchronize_files(src_file_path, dest_file_path);
            }
            // If file is not a directory, compare modification times and copy the newer file to destination
            else {
                stat(src_file_path, &src_stat);
                if (src_stat.st_mtime > dest_stat.st_mtime) {
                    FILE *src_file = fopen(src_file_path, "rb");
                    FILE *dest_file = fopen(dest_file_path, "wb");
                    if (!src_file || !dest_file) {
                        continue;
                    }
                    char buffer[1024];
                    size_t length;
                    while ((length = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                        fwrite(buffer, 1, length, dest_file);
                    }
                    fclose(src_file);
                    fclose(dest_file);
                }
            }
        }
        // If file does not exist in destination directory, copy it over
        else {
            FILE *src_file = fopen(src_file_path, "rb");
            FILE *dest_file = fopen(dest_file_path, "wb");
            if (!src_file || !dest_file) {
                continue;
            }
            char buffer[1024];
            size_t length;
            while ((length = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                fwrite(buffer, 1, length, dest_file);
            }
            fclose(src_file);
            fclose(dest_file);
        }
    }

    closedir(src_dir);
    closedir(dest_dir);
}

int main() {
    char *src_path = "/home/user/source";
    char *dest_path = "/home/user/destination";

    synchronize_files(src_path, dest_path);

    return 0;
}