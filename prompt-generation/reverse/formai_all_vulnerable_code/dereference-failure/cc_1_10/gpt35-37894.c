//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

#define MAX_PATH_LEN 1024
#define MAX_DIR_ENTRIES 1024
#define MAX_STR_LEN 1024

struct Directory {
    char path[MAX_PATH_LEN];
    long long size;
};

struct Directory* directories;
int num_directories = 0;

void append_directory(const char* path, long long size) {
    strcpy(directories[num_directories].path, path);
    directories[num_directories].size = size;
    num_directories++;
}

void get_directory_size(const char* path) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        perror("opendir failed");
        exit(EXIT_FAILURE);
    }

    long long total_size = 0;
    struct dirent* entry;
    struct stat file_info;

    while ((entry = readdir(dir)) != NULL) {
        char full_path[MAX_PATH_LEN];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (stat(full_path, &file_info) == -1) {
            perror("stat failed");
            exit(EXIT_FAILURE);
        }

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                get_directory_size(full_path);
            }
        } else {
            total_size += file_info.st_size;
        }
    }

    append_directory(path, total_size);

    if (closedir(dir) == -1) {
        perror("closedir failed");
        exit(EXIT_FAILURE);
    }
}

void print_size(long long size) {
    if (size >= 1024 * 1024 * 1024) {
        printf("%.2f GB\n", size / (1024.0 * 1024.0 * 1024.0));
    } else if (size >= 1024 * 1024) {
        printf("%.2f MB\n", size / (1024.0 * 1024.0));
    } else if (size >= 1024) {
        printf("%.2f KB\n", size / 1024.0);
    } else {
        printf("%lld bytes\n", size);
    }
}

int compare_directories(const void* p1, const void* p2) {
    struct Directory* d1 = (struct Directory*) p1;
    struct Directory* d2 = (struct Directory*) p2;
    return d2->size - d1->size;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    directories = (struct Directory*) malloc(MAX_DIR_ENTRIES * sizeof(struct Directory));
    if (directories == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    get_directory_size(argv[1]);

    qsort(directories, num_directories, sizeof(struct Directory), compare_directories);

    printf("Disk space usage (descending order):\n");
    for (int i = 0; i < num_directories; i++) {
        printf("%s: ", directories[i].path);
        print_size(directories[i].size);
    }

    free(directories);

    return 0;
}