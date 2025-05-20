//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <time.h>
#include <alloca.h>
#define BUF_SIZE 1024

struct file_info {
    char filename[128];
    off_t size;
};

void traverse_directory(const char *path, struct file_info files[], int *num_files, int depth) {
    DIR *dir;
    struct dirent *entry;
    struct stat st;

    if (!(dir = opendir(path))) {
        return;
    }

    while ((entry = readdir(dir))) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(files[*num_files].filename, sizeof(files[*num_files].filename), "%s/%s", path, entry->d_name);
        if (stat(files[*num_files].filename, &st) == -1) {
            perror("Error statting file");
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            if (depth < 5) {
                traverse_directory(files[*num_files].filename, files, num_files, depth + 1);
            }
        } else {
            files[*num_files].size = st.st_size;
            (*num_files)++;
        }
    }

    closedir(dir);
}

void print_files_size(struct file_info files[], int num_files) {
    struct file_info *current_file;
    double total_size = 0;

    for (int i = 0; i < num_files; i++) {
        current_file = &files[i];
        printf("%.*s %lld bytes\n", (int)strlen(current_file->filename) - 1, current_file->filename, current_file->size);
        total_size += current_file->size;
    }

    printf("\nTotal size of files: %lld bytes\n", (long long)total_size);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    struct file_info files[1024];
    int num_files = 0;

    traverse_directory(argv[1], files, &num_files, 0);
    print_files_size(files, num_files);

    for (int i = 0; i < num_files; i++) {
        free(files[i].filename);
    }

    return 0;
}