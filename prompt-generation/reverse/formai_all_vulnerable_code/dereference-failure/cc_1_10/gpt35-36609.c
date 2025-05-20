//FormAI DATASET v1.0 Category: File Synchronizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void sync_files(const char* source_dir, const char* dest_dir);

int main(int argc, char *argv[]) {

    if(argc != 3) {
        printf("Usage: %s [source_dir] [dest_dir]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char* source_dir = argv[1];
    char* dest_dir = argv[2];

    sync_files(source_dir, dest_dir);

    printf("Files synchronized successfully!\n");

    return 0;
}

void sync_files(const char* source_dir, const char* dest_dir) {

    DIR* source_dp = opendir(source_dir);
    DIR* dest_dp = opendir(dest_dir);

    if(source_dp == NULL || dest_dp == NULL) {
        printf("Error: Could not open directories.\n");
        exit(EXIT_FAILURE);
    }

    struct dirent* source_ep;
    while((source_ep = readdir(source_dp)) != NULL) {

        if(strcmp(source_ep->d_name, ".") == 0 || strcmp(source_ep->d_name, "..") == 0) {
            continue;
        }

        char source_path[PATH_MAX];
        char dest_path[PATH_MAX];
        sprintf(source_path, "%s/%s", source_dir, source_ep->d_name);
        sprintf(dest_path, "%s/%s", dest_dir, source_ep->d_name);

        struct stat source_sb;
        if(stat(source_path, &source_sb) == -1) {
            printf("Error: Could not stat file: %s\n", source_path);
            continue;
        }

        if(S_ISDIR(source_sb.st_mode)) {
            // Recursive call to sync directories
            sync_files(source_path, dest_path);
        }
        else {
            struct stat dest_sb;
            int dest_exists = (stat(dest_path, &dest_sb) != -1);

            // If destination file exists, compare modification times
            if(dest_exists) {
                if(source_sb.st_mtime > dest_sb.st_mtime) {
                    // Update destination file with source file contents
                    FILE* source_fp = fopen(source_path, "rb");
                    FILE* dest_fp = fopen(dest_path, "wb");
                    if(source_fp == NULL || dest_fp == NULL) {
                        printf("Error: Could not open files for update.\n");
                        continue;
                    }

                    // Copy contents of source file to destination file
                    char buffer[BUFSIZ];
                    size_t n;
                    while((n = fread(buffer, 1, sizeof(buffer), source_fp)) > 0) {
                        fwrite(buffer, 1, n, dest_fp);
                    }

                    fclose(source_fp);
                    fclose(dest_fp);

                    printf("Updated file: %s\n", dest_path);
                }
            }
            // If destination file does not exist, copy source file to destination
            else {
                FILE* source_fp = fopen(source_path, "rb");
                FILE* dest_fp = fopen(dest_path, "wb");
                if(source_fp == NULL || dest_fp == NULL) {
                    printf("Error: Could not open files for copy.\n");
                    continue;
                }

                // Copy contents of source file to destination file
                char buffer[BUFSIZ];
                size_t n;
                while((n = fread(buffer, 1, sizeof(buffer), source_fp)) > 0) {
                    fwrite(buffer, 1, n, dest_fp);
                }

                fclose(source_fp);
                fclose(dest_fp);

                printf("Copied file: %s\n", dest_path);
            }
        }
    }

    closedir(source_dp);
    closedir(dest_dp);
}