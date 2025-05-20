//FormAI DATASET v1.0 Category: File Synchronizer ; Style: artistic
/*
 * C File Synchronizer
 * By: Your Name Here
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_PATH_LENGTH 1024
#define MAX_FILE_SIZE 1048576

char* src_path;
char* dest_path;

void synchronize_files(char* src_file, char* dest_file) {
    FILE* src_fp;
    FILE* dest_fp;

    if ((src_fp = fopen(src_file, "r")) == NULL) {
        printf("Error: Unable to open file %s. Skipping.\n", src_file);
        return;
    }

    if ((dest_fp = fopen(dest_file, "w")) == NULL) {
        printf("Error: Unable to create file %s. Skipping.\n", dest_file);
        fclose(src_fp);
        return;
    }

    char* buffer = malloc(MAX_FILE_SIZE);

    size_t read_len = fread(buffer, sizeof(char), MAX_FILE_SIZE, src_fp);

    fwrite(buffer, sizeof(char), read_len, dest_fp);

    free(buffer);

    fclose(src_fp);
    fclose(dest_fp);

    printf("Synchronized file: %s\n", src_file);
}

void synchronize_directories(char* src_dir, char* dest_dir) {
    struct dirent* entry;
    DIR* dir;
    char src_path[MAX_PATH_LENGTH];
    char dest_path[MAX_PATH_LENGTH];

    if ((dir = opendir(src_dir)) == NULL) {
        printf("Error: Unable to open directory %s. Skipping.\n", src_dir);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(src_path, MAX_PATH_LENGTH, "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, MAX_PATH_LENGTH, "%s/%s", dest_dir, entry->d_name);

        struct stat src_stat;

        if (stat(src_path, &src_stat) == -1) {
            printf("Error: Unable to get stats for file %s. Skipping.\n", src_path);
            continue;
        }

        if (S_ISREG(src_stat.st_mode)) {
            synchronize_files(src_path, dest_path);
        } else if (S_ISDIR(src_stat.st_mode)) {
            mkdir(dest_path, 0777);
            synchronize_directories(src_path, dest_path);
        }
    }

    closedir(dir);

    printf("Synchronized directory: %s\n", src_dir);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: ./cfSync <src_path> <dest_path>\n");
        return 1;
    }

    src_path = argv[1];
    dest_path = argv[2];

    synchronize_directories(src_path, dest_path);

    printf("Synchronization complete!\n");

    return 0;
}