//FormAI DATASET v1.0 Category: File Synchronizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdbool.h>

void syncFiles(char *src, char *dst) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    char src_path[200];
    char dst_path[200];
    
    // Open source directory
    if ((dir = opendir(src)) == NULL) {
        perror("Error: Can't open the directory");
        exit(EXIT_FAILURE);
    }
    
    // Loop through all the files in the directory
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        sprintf(src_path, "%s/%s", src, entry->d_name);
        sprintf(dst_path, "%s/%s", dst, entry->d_name);
        
        // Get info about the file
        if (stat(src_path, &file_stat) < 0) {
            perror("Error: Couldn't get file info");
            exit(EXIT_FAILURE);
        }
        
        // Check if it's a directory
        if (S_ISDIR(file_stat.st_mode)) {
            // Create directory in destination if it doesn't exist
            if (access(dst_path, F_OK) == -1) {
                mkdir(dst_path, 0777);
            }
            syncFiles(src_path, dst_path);
        } else {
            // Check if file already exists in destination
            if (access(dst_path, F_OK) != -1) {
                // Check if file is different
                struct stat dst_file_stat;
                if (stat(dst_path, &dst_file_stat) < 0) {
                    perror("Error: Couldn't get file info");
                    exit(EXIT_FAILURE);
                }
                if (file_stat.st_mtime > dst_file_stat.st_mtime) {
                    // Copy file from source to destination
                    FILE *src_file, *dst_file;
                    src_file = fopen(src_path, "rb");
                    dst_file = fopen(dst_path, "wb");
                    if (src_file == NULL || dst_file == NULL) {
                        perror("Error: Couldn't open file");
                        exit(EXIT_FAILURE);
                    }
                    char buffer[100];
                    size_t n;
                    while ((n = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                        fwrite(buffer, 1, n, dst_file);
                    }
                    fclose(src_file);
                    fclose(dst_file);
                }
            } else {
                // Copy file from source to destination
                FILE *src_file, *dst_file;
                src_file = fopen(src_path, "rb");
                dst_file = fopen(dst_path, "wb");
                if (src_file == NULL || dst_file == NULL) {
                    perror("Error: Couldn't open file");
                    exit(EXIT_FAILURE);
                }
                char buffer[100];
                size_t n;
                while ((n = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                    fwrite(buffer, 1, n, dst_file);
                }
                fclose(src_file);
                fclose(dst_file);
            }
        }
    }
    closedir(dir);
}

int main() {
    // Sync files from source to destination
    char src[] = "./src";
    char dst[] = "./dst";
    syncFiles(src, dst);
    
    // Check if files are synced
    printf("Files synced!\n");
    return 0;
}