//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>

#define BUF_SIZE 1024

struct file_info {
    char filename[256];
    off_t size;
};

void process_dir(char *path, struct file_info *files, int *num_files, off_t *total_size);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    struct file_info files[1024];
    int num_files = 0;
    off_t total_size = 0;

    process_dir(argv[1], files, &num_files, &total_size);

    printf("\n-----------------------------\n");
    printf("| Directory: %s             |\n", argv[1]);
    printf("|-----------------------------|\n");
    printf("| Total number of files: %d   |\n", num_files);
    printf("| Total size: %lld bytes     |\n", (long long)total_size);
    printf("-----------------------------|\n\n");

    for (int i = 0; i < num_files; i++) {
        printf("| %-25s | %lld bytes |\n", files[i].filename, files[i].size);
    }

    return 0;
}

void process_dir(char *path, struct file_info *files, int *num_files, off_t *total_size) {
    DIR *dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[BUF_SIZE];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        struct stat st;
        if (lstat(full_path, &st) == -1) {
            perror("lstat");
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            process_dir(full_path, files, num_files, total_size);
        } else {
            for (int i = 0; i < *num_files; i++) {
                if (strcmp(files[i].filename, entry->d_name) == 0) {
                    goto skip;
                }
            }

            strcpy(files[*num_files].filename, entry->d_name);
            files[*num_files].size = st.st_size;
            (*num_files)++;
            (*total_size) += st.st_size;

        skip: {};
        }
    }

    closedir(dir);
}