//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Claude Shannon
/*
 * File synchronizer program using Claude Shannon's principles
 * Minimum 50 lines of code
 * Be creative!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

/* Compare files based on their last modification times */
int compare_files(char *path1, char *path2) {
    struct stat stat1, stat2;
    if (stat(path1, &stat1) == -1 || stat(path2, &stat2) == -1) {
        return -1;
    }
    return difftime(stat1.st_mtim.tv_sec, stat2.st_mtim.tv_sec);
}

/* Recursively synchronize directory trees */
void sync_directories(char *src, char *dst) {
    struct dirent *entry;
    DIR *dir = opendir(src);
    if (!dir) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }
    while ((entry = readdir(dir))) {
        if (entry->d_type == DT_DIR) {
            /* Skip . and .. directories */
            if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) {
                continue;
            }
            char new_src[256], new_dst[256];
            sprintf(new_src, "%s/%s", src, entry->d_name);
            sprintf(new_dst, "%s/%s", dst, entry->d_name);
            mkdir(new_dst, 0777);
            sync_directories(new_src, new_dst);
        } else {
            /* Check if the file needs to be synchronized */
            char src_path[256], dst_path[256];
            sprintf(src_path, "%s/%s", src, entry->d_name);
            sprintf(dst_path, "%s/%s", dst, entry->d_name);
            if (compare_files(src_path, dst_path) > 0) {
                /* File on source is newer than destination file, copy it over */
                FILE *src_file = fopen(src_path, "rb");
                FILE *dst_file = fopen(dst_path, "wb");
                if (!src_file || !dst_file) {
                    perror("fopen");
                    exit(EXIT_FAILURE);
                }
                char buffer[1024];
                size_t num_read;
                while ((num_read = fread(buffer, 1, sizeof(buffer), src_file))) {
                    fwrite(buffer, num_read, 1, dst_file);
                }
                fclose(src_file);
                fclose(dst_file);
            }
        }
    }
    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s source_directory destination_directory\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Starting file synchronization from %s to %s...\n", argv[1], argv[2]);
    sync_directories(argv[1], argv[2]);
    printf("File synchronization complete!\n");
    return EXIT_SUCCESS;
}