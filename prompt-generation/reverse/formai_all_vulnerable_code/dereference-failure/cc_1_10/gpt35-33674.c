//FormAI DATASET v1.0 Category: File Synchronizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void sync_files(char *src_dir, char *dest_dir);

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <src_dir> <dest_dir>\n", argv[0]);
        exit(1);
    }

    sync_files(argv[1], argv[2]);

    return 0;
}

void sync_files(char *src_dir, char *dest_dir) {
    // Open source directory
    DIR *src = opendir(src_dir);
    struct dirent *src_dirent;
    struct stat src_stat;

    // Check if destination directory exists. If not, create it.
    DIR *dest = opendir(dest_dir);
    if (dest == NULL) {
        mkdir(dest_dir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        dest = opendir(dest_dir);
    }
    
    // Loop through all files in source directory
    while ((src_dirent = readdir(src)) != NULL) {
        // Ignore "." and ".." directories
        if (strcmp(src_dirent->d_name, ".") == 0 || strcmp(src_dirent->d_name, "..") == 0) {
            continue;
        }

        // Get source file information
        char src_path[1000];
        strcpy(src_path, src_dir);
        strcat(src_path, "/");
        strcat(src_path, src_dirent->d_name);
        stat(src_path, &src_stat);

        // Check if file is a directory. If so, recursively sync it.
        if (S_ISDIR(src_stat.st_mode)) {
            char dest_path[1000];
            strcpy(dest_path, dest_dir);
            strcat(dest_path, "/");
            strcat(dest_path, src_dirent->d_name);
            sync_files(src_path, dest_path);
        } else {
            // Get destination file information
            char dest_path[1000];
            strcpy(dest_path, dest_dir);
            strcat(dest_path, "/");
            strcat(dest_path, src_dirent->d_name);
            struct stat dest_stat;
            int dest_exists = stat(dest_path, &dest_stat) == 0;

            // Check if file exists in destination
            if (dest_exists) {
                // Check if file is newer in source than in destination
                if (src_stat.st_mtime > dest_stat.st_mtime) {
                    printf("Updating %s\n", src_path);
                    // Copy source file to destination
                    FILE *src_file = fopen(src_path, "r");
                    FILE *dest_file = fopen(dest_path, "w");
                    int c;
                    while ((c = fgetc(src_file)) != EOF) {
                        fputc(c, dest_file);
                    }
                    fclose(src_file);
                    fclose(dest_file);
                }
            } else {
                printf("Copying %s\n", src_path);
                // Copy source file to destination
                FILE *src_file = fopen(src_path, "r");
                FILE *dest_file = fopen(dest_path, "w");
                int c;
                while ((c = fgetc(src_file)) != EOF) {
                    fputc(c, dest_file);
                }
                fclose(src_file);
                fclose(dest_file);
            }
        }
    }

    closedir(src);
    closedir(dest);
}