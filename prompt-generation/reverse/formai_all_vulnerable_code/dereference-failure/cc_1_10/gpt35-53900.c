//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

// function to convert bytes to human-readable format
void print_size(long long size) {
    char units[] = {'B', 'KB', 'MB', 'GB', 'TB', 'PB', 'EB', 'ZB', 'YB'};
    int unit = 0;
    while (size >= 1024) {
        size /= 1024;
        unit++;
    }
    printf("%lld %c\n", size, units[unit]);
}

// function to recursively traverse directory and analyze disk space
void analyze_dir(char *path, long long *total_size) {
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    dir = opendir(path);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        // skip "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char child_path[PATH_MAX];
        snprintf(child_path, PATH_MAX, "%s/%s", path, entry->d_name);
        if (lstat(child_path, &st) == -1) {
            perror("Error getting file stats");
            continue;
        }
        if (S_ISREG(st.st_mode)) {
            // regular file
            *total_size += st.st_size;
        } else if (S_ISDIR(st.st_mode)) {
            // directory
            analyze_dir(child_path, total_size);
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    char *path = argv[1];
    long long total_size = 0;
    analyze_dir(path, &total_size);
    printf("Total size of %s: ", path);
    print_size(total_size);
    return 0;
}