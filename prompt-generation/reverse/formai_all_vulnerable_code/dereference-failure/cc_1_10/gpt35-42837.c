//FormAI DATASET v1.0 Category: File Synchronizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define MAX_PATH_LEN 256

char root_dir[MAX_PATH_LEN];
char sync_dir[MAX_PATH_LEN];

void sync_files(const char *dir_path, const char *sync_path) {
    DIR *dir = opendir(dir_path);
    if (!dir) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    while ((entry = readdir(dir))) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        char file_path[MAX_PATH_LEN];
        char sync_file_path[MAX_PATH_LEN];
        sprintf(file_path, "%s/%s", dir_path, entry->d_name);
        sprintf(sync_file_path, "%s/%s", sync_path, entry->d_name);

        struct stat st;
        if (stat(file_path, &st) < 0) {
            perror("stat");
            exit(EXIT_FAILURE);
        }

        if (S_ISREG(st.st_mode)) {
            FILE *fp = fopen(sync_file_path, "r");
            if (fp) {
                fclose(fp);

                // Puzzle here: How to determine if two files are identical?
                // Hint: Use a buffer and read from both files in chunks.

                continue;
            }

            // Puzzle here: How to copy a file to a different directory?
            // Hint: Use fopen, fread, and fwrite.

            printf("Copied file %s to %s\n", file_path, sync_file_path);
        }
        else if (S_ISDIR(st.st_mode)) {
            mkdir(sync_file_path, st.st_mode & 0777);
            sync_files(file_path, sync_file_path);
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <directory> <sync_dir>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    realpath(argv[1], root_dir);
    realpath(argv[2], sync_dir);
    printf("Synchronizing %s with %s\n", root_dir, sync_dir);

    sync_files(root_dir, sync_dir);
    printf("Done!\n");

    return 0;
}