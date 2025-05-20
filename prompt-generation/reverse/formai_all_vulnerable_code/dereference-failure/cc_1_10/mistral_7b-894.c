//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

typedef struct {
    char name[256];
    off_t size;
} entry_t;

void analyze_directory(const char *path, int depth) {
    DIR *dir;
    struct dirent *entry;
    struct stat info;

    dir = opendir(path);
    if (!dir) {
        printf("Error opening directory: %s\n", path);
        return;
    }

    printf("%*s%s:\n", depth * 4, "", path);

    while ((entry = readdir(dir))) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(path, sizeof(path), "%s/%s", path, entry->d_name);
        analyze_directory(path, depth + 1);
        snprintf(path, sizeof(path), "%s/%s", path, entry->d_name);

        if (lstat(path, &info) < 0) {
            perror("Error getting file status");
            continue;
        }

        if (S_ISDIR(info.st_mode)) {
            printf("%*s  <DIR>\n", depth * 4 + 4, "");
            continue;
        }

        printf("%*s%10ld bytes (%3.1f%%): %s\n", depth * 4 + 12, "", info.st_size, (double) info.st_size / (double) (1LL << 30), entry->d_name);

        free(path);
    }

    closedir(dir);
}

int main() {
    const char *path = "/";
    char path_buf[1024];

    analyze_directory(path, 0);

    return 0;
}