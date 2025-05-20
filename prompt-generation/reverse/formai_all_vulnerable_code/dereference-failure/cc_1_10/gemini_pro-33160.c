//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

void fairVerona(const char *path);
void traverse(const char *name, int depth);
void iMeasureEveryTree(char *name, long long *size);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    fairVerona(argv[1]);

    return EXIT_SUCCESS;
}

void fairVerona(const char *path) {
    if (path == NULL) {
        printf("Invalid path\n");
        return;
    }

    struct stat st;
    if (stat(path, &st) < 0) {
        printf("Failed to stat path\n");
        return;
    }

    if (!S_ISDIR(st.st_mode)) {
        printf("%s is not a directory\n", path);
        return;
    }

    long long total = 0;
    traverse(path, 0);

    printf("Total size: %lld bytes\n", total);
}

void traverse(const char *name, int depth) {
    DIR *dir;
    struct dirent *entry;
    char path[PATH_MAX];
    long long size = 0;

    if ((dir = opendir(name)) == NULL) {
        printf("Failed to open directory: %s\n", name);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
        if (entry->d_type == DT_DIR) {
            traverse(path, depth + 1);
        } else if (entry->d_type == DT_REG) {
            iMeasureEveryTree(path, &size);
            printf("%s - %lld bytes\n", path, size);
        }
    }

    closedir(dir);
}

void iMeasureEveryTree(char *name, long long *size) {
    struct stat st;

    if (stat(name, &st) < 0) {
        printf("Failed to stat path\n");
        return;
    }

    if (!S_ISREG(st.st_mode)) {
        printf("%s is not a regular file\n", name);
        return;
    }

    *size += st.st_size;
}