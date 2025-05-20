//FormAI DATASET v1.0 Category: File Synchronizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

// Function to recursively synchronize all files and directories in the source directory to the destination directory
void sync_files(char *src_dir, char *dest_dir) {
    DIR *src_dp, *dest_dp;
    struct dirent *src_dent, *dest_dent;
    struct stat src_stat, dest_stat;
    char src_path[1024], dest_path[1024];

    // Open source and destination directories
    if ((src_dp = opendir(src_dir)) == NULL) {
        printf("Error opening source directory\n");
        exit(1);
    }
    if ((dest_dp = opendir(dest_dir)) == NULL) {
        mkdir(dest_dir, 0777);
        dest_dp = opendir(dest_dir);
    }
    
    // Iterate over all entries in source directory
    while ((src_dent = readdir(src_dp))) {
        if (strcmp(src_dent->d_name, ".") == 0 || strcmp(src_dent->d_name, "..") == 0) {
            continue; // Skip "." and ".." entries
        }

        // Construct full source and destination paths
        sprintf(src_path, "%s/%s", src_dir, src_dent->d_name);
        sprintf(dest_path, "%s/%s", dest_dir, src_dent->d_name);

        // Check if entry is a directory
        if (stat(src_path, &src_stat) == 0 && S_ISDIR(src_stat.st_mode)) {
            sync_files(src_path, dest_path); // Recursively synchronize subdirectory
        } else {
            // Check if file exists in destination directory
            if ((dest_dent = readdir(dest_dp))) {
                if (strcmp(dest_dent->d_name, ".") == 0 || strcmp(dest_dent->d_name, "..") == 0) {
                    dest_dent = readdir(dest_dp); // Skip "." and ".." entries
                }
                sprintf(dest_path, "%s/%s", dest_dir, dest_dent->d_name);
                stat(dest_path, &dest_stat);

                // Compare modification times of source and destination files
                if (src_stat.st_mtime >= dest_stat.st_mtime) {
                    // Overwrite destination file with source file
                    FILE *src_fp, *dest_fp;
                    char buffer[1024];
                    size_t bytes_read;

                    src_fp = fopen(src_path, "r");
                    dest_fp = fopen(dest_path, "w");

                    while ((bytes_read = fread(buffer, 1, 1024, src_fp)) > 0) {
                        fwrite(buffer, 1, bytes_read, dest_fp);
                    }

                    fclose(src_fp);
                    fclose(dest_fp);
                }
            } else {
                // Destination file does not exist, copy source file to destination directory
                FILE *src_fp, *dest_fp;
                char buffer[1024];
                size_t bytes_read;

                src_fp = fopen(src_path, "r");
                dest_fp = fopen(dest_path, "w");

                while ((bytes_read = fread(buffer, 1, 1024, src_fp)) > 0) {
                    fwrite(buffer, 1, bytes_read, dest_fp);
                }

                fclose(src_fp);
                fclose(dest_fp);
            }
        }
    }

    // Close directories
    closedir(src_dp);
    closedir(dest_dp);
}

int main() {
    char *src_dir = "/path/to/source/directory";
    char *dest_dir = "/path/to/destination/directory";

    sync_files(src_dir, dest_dir);

    return 0;
}