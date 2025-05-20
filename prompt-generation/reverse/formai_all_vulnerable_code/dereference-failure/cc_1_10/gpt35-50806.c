//FormAI DATASET v1.0 Category: File Synchronizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void sync_directories(const char *src_path, const char *dst_path) {
    DIR *src_dir = opendir(src_path);
    if (src_dir == NULL) {
        fprintf(stderr, "Error: Failed to open directory: %s\n", src_path);
        return;
    }
    
    DIR *dst_dir = opendir(dst_path);
    if (dst_dir == NULL) {
        fprintf(stderr, "Error: Failed to open directory: %s\n", dst_path);
        closedir(src_dir);
        return;
    }
    
    struct dirent *file;
    while ((file = readdir(src_dir)) != NULL) {
        if (strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0) {
            continue;
        }

        struct stat src_stat;
        char src_file_path[PATH_MAX];
        sprintf(src_file_path, "%s/%s", src_path, file->d_name);
        if (stat(src_file_path, &src_stat) < 0) {
            fprintf(stderr, "Error: Failed to stat file: %s\n", src_file_path);
            continue;
        }
        
        struct stat dst_stat;
        char dst_file_path[PATH_MAX];
        sprintf(dst_file_path, "%s/%s", dst_path, file->d_name);
        if (stat(dst_file_path, &dst_stat) >= 0) {
            // File exists in destination directory
            if (dst_stat.st_mtime == src_stat.st_mtime) {
                // File is up-to-date
                continue;
            }
            
            if (!S_ISREG(dst_stat.st_mode)) {
                fprintf(stderr, "Error: Destination file is a directory: %s\n", dst_file_path);
                continue;
            }
        }
        
        if (S_ISDIR(src_stat.st_mode)) {
            // Source file is a directory
            if (mkdir(dst_file_path, src_stat.st_mode) < 0) {
                fprintf(stderr, "Error: Failed to create directory: %s\n", dst_file_path);
                continue;
            }
            sync_directories(src_file_path, dst_file_path);
        } else {
            // Source file is a regular file
            FILE *src_file = fopen(src_file_path, "rb");
            if (src_file == NULL) {
                fprintf(stderr, "Error: Failed to open file for reading: %s\n", src_file_path);
                continue;
            }

            FILE *dst_file = fopen(dst_file_path, "wb");
            if (dst_file == NULL) {
                fprintf(stderr, "Error: Failed to open file for writing: %s\n", dst_file_path);
                fclose(src_file);
                continue;
            }
            
            unsigned char buffer[BUFSIZ];
            size_t bytes_read;
            while ((bytes_read = fread(buffer, 1, BUFSIZ, src_file)) > 0) {
                fwrite(buffer, 1, bytes_read, dst_file);
            }
            
            fclose(src_file);
            fclose(dst_file);
        }
    }
    
    closedir(src_dir);
    closedir(dst_dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [src] [dst]\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    sync_directories(argv[1], argv[2]);
    
    return EXIT_SUCCESS;
}