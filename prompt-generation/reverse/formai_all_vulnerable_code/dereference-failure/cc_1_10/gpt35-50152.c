//FormAI DATASET v1.0 Category: File Synchronizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILENAME_LEN 256
#define MAX_PATH_LEN 1024
#define BUF_SIZE 1024

int sync_dir(const char* src_dir, const char* des_dir);

int main(void) {
    const char* src_dir = "/home/user/Documents/folder1/";
    const char* des_dir = "/home/user/Documents/folder2/";

    int ret = sync_dir(src_dir, des_dir);

    if (ret == 0) {
        printf("Successfully synchronized files.\n");
    } else {
        printf("Error: Failed to synchronize files.\n");
    }

    return 0;
}

// Synchronize files between two directories
int sync_dir(const char* src_dir, const char* des_dir) {
    DIR* src_dp = opendir(src_dir);
    DIR* des_dp = opendir(des_dir);

    struct dirent* src_de = NULL;
    struct dirent* des_de = NULL;

    struct stat src_sb, des_sb;

    char src_file[MAX_PATH_LEN];
    char des_file[MAX_PATH_LEN];

    char buf[BUF_SIZE];

    while ((src_de = readdir(src_dp)) != NULL) {
        if (strcmp(src_de->d_name, ".") == 0 || strcmp(src_de->d_name, "..") == 0) {
            continue;
        }

        snprintf(src_file, MAX_PATH_LEN, "%s%s", src_dir, src_de->d_name);
        snprintf(des_file, MAX_PATH_LEN, "%s%s", des_dir, src_de->d_name);

        if (stat(src_file, &src_sb) == -1) {
            printf("Error: Failed to get file status of %s.\n", src_file);
            return -1;
        }

        if (S_ISDIR(src_sb.st_mode)) {
            if (mkdir(des_file, src_sb.st_mode) == -1) {
                printf("Error: Failed to create directory %s.\n", des_file);
                return -1;
            }

            sync_dir(src_file, des_file);
        } else {
            if (stat(des_file, &des_sb) == -1) {
                // Destination file doesn't exist, copy source file to destination file
                FILE* src_fp = fopen(src_file, "rb");
                FILE* des_fp = fopen(des_file, "wb");

                int bytes_read = 0;

                while ((bytes_read = fread(buf, sizeof(char), BUF_SIZE, src_fp)) > 0) {
                    fwrite(buf, sizeof(char), bytes_read, des_fp);
                }

                fclose(src_fp);
                fclose(des_fp);
            } else {
                // Compare modification time between source and destination file
                if (src_sb.st_mtime > des_sb.st_mtime) {
                    FILE* src_fp = fopen(src_file, "rb");
                    FILE* des_fp = fopen(des_file, "wb");

                    int bytes_read = 0;

                    while ((bytes_read = fread(buf, sizeof(char), BUF_SIZE, src_fp)) > 0) {
                        fwrite(buf, sizeof(char), bytes_read, des_fp);
                    }

                    fclose(src_fp);
                    fclose(des_fp);
                }
            }
        }
    }

    closedir(src_dp);
    closedir(des_dp);

    return 0;
}