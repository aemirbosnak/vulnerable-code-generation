//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

void print_size(off_t size);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <dirname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            char path[1000];
            sprintf(path, "%s/%s", argv[1], entry->d_name);
            struct stat st;
            if (stat(path, &st) != -1) {
                print_size(st.st_size);
                printf(" %s\n", entry->d_name);
            }
        }
    }

    if (closedir(dir) == -1) {
        perror("closedir");
        exit(EXIT_FAILURE);
    }

    return 0;
}

void print_size(off_t size) {
    if (size >= 1000000000) {
        printf("%.1f GB", size / 1000000000.0);
    } else if (size >= 1000000) {
        printf("%.1f MB", size / 1000000.0);
    } else if (size >= 1000) {
        printf("%.1f KB", size / 1000.0);
    } else {
        printf("%ld B", size);
    }
}