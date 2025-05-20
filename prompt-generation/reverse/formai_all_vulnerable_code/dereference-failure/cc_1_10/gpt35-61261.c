//FormAI DATASET v1.0 Category: File Synchronizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

// Function to synchronize files
void sync_files(char* source_dir, char* dest_dir) {
    DIR* source = opendir(source_dir);
    DIR* dest = opendir(dest_dir);
    struct dirent* src_file;
    struct dirent* dst_file;

    // Loop through the files in the source directory
    while ((src_file = readdir(source))) {
        char src_path[256];
        sprintf(src_path, "%s/%s", source_dir, src_file->d_name);

        if (src_file->d_type == DT_REG) {  // If it's a regular file
            struct stat src_stat;
            stat(src_path, &src_stat);

            // Check if the file exists in the destination directory
            int found = 0;
            rewinddir(dest);
            while ((dst_file = readdir(dest))) {
                if (strcmp(src_file->d_name, dst_file->d_name) == 0) {  // If the file exists
                    char dst_path[256];
                    sprintf(dst_path, "%s/%s", dest_dir, dst_file->d_name);

                    // Compare the modification times of the files
                    struct stat dst_stat;
                    stat(dst_path, &dst_stat);
                    if (difftime(src_stat.st_mtime, dst_stat.st_mtime) > 0) {  // If the source file is newer
                        printf("Copying %s to %s\n", src_path, dst_path);

                        // Open the files
                        FILE* src_file = fopen(src_path, "r");
                        FILE* dst_file = fopen(dst_path, "w");
                        char buf[256];
                        size_t n;

                        // Copy the contents of the file
                        while ((n = fread(buf, 1, sizeof(buf), src_file)) > 0) {
                            fwrite(buf, 1, n, dst_file);
                        }

                        // Close the files
                        fclose(src_file);
                        fclose(dst_file);
                    }
                    found = 1;
                    break;
                }
            }

            // If the file doesn't exist in the destination directory
            if (!found) {
                char dst_path[256];
                sprintf(dst_path, "%s/%s", dest_dir, src_file->d_name);
                printf("Copying %s to %s\n", src_path, dst_path);

                // Open the files
                FILE* src_file = fopen(src_path, "r");
                FILE* dst_file = fopen(dst_path, "w");
                char buf[256];
                size_t n;

                // Copy the contents of the file
                while ((n = fread(buf, 1, sizeof(buf), src_file)) > 0) {
                    fwrite(buf, 1, n, dst_file);
                }

                // Close the files
                fclose(src_file);
                fclose(dst_file);
            }
        }
    }

    // Close the directories
    closedir(source);
    closedir(dest);
}

int main() {
    char* source_dir = "/home/user/source";
    char* dest_dir = "/home/user/destination";

    sync_files(source_dir, dest_dir);

    return 0;
}