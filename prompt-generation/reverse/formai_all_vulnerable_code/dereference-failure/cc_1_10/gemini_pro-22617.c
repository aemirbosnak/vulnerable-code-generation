//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

// Linus Torvalds style: no curly braces for single-line statements
#define null 0

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    // Get the size of the specified directory
    struct stat st;
    if (stat(argv[1], &st) != 0) {
        perror("stat");
        return 2;
    }

    // Traverse the directory tree and print the size of each file
    DIR *dir = opendir(argv[1]);
    if (dir == null) {
        perror("opendir");
        return 3;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != null) {
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", argv[1], entry->d_name);

        // Ignore "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        if (lstat(path, &st) != 0) {
            perror("lstat");
            continue;
        }

        printf("%s: %ld\n", path, st.st_size);
    }

    closedir(dir);

    return 0;
}