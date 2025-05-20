//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#define BUF_SIZE 4096

struct file_info {
    char name[256];
    off_t size;
};

void analyze_directory(char *path, struct file_info files[1024], int *num_files) {
    DIR *dir;
    struct dirent *entry;
    int i = 0;

    if (!(dir = opendir(path))) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (i >= 1024) {
            printf("Too many files in directory %s\n", path);
            break;
        }

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            analyze_directory(entry->d_name, files, num_files);
        } else {
            struct stat st;
            if (stat(entry->d_name, &st) == -1) {
                perror("stat");
                continue;
            }

            strcpy(files[i].name, entry->d_name);
            files[i].size = st.st_size;
            i++;
        }
    }

    closedir(dir);
    *num_files = i;
}

int main() {
    char cwd[256];
    getcwd(cwd, sizeof(cwd));

    struct file_info files[1024];
    int num_files = 0;

    analyze_directory(".", files, &num_files);

    printf("Total number of files: %d\n", num_files);
    printf("Disk usage:\n");

    off_t total_size = 0;
    for (int i = 0; i < num_files; i++) {
        total_size += files[i].size;
        printf("%-24s %llu bytes\n", files[i].name, files[i].size);
    }

    printf("Total disk usage: %llu bytes\n", total_size);

    return 0;
}