//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

void analyze_directory(const char *path, int level);

void print_size(double size) {
    char *units[] = {"B", "KB", "MB", "GB", "TB", "PB"};
    int i;
    for (i = 0; i < 6 && size >= 1024; i++, size /= 1024)
        ;
    printf("%.1f %s", size, units[i]);
}

void print_file(const char *path, double size, int level) {
    printf("|");
    for (int i = 0; i < level * 4; i++) printf("-");
    printf("%s", path);
    for (int i = strlen(path) + level * 4; i < 60; i++) printf(" ");
    print_size(size);
    printf("\n"); 
}

void analyze_directory(const char *path, int level) {
    double total_size = 0.0;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror(path);
        return;
    }
    struct dirent *dp;
    while ((dp = readdir(dir)) != NULL) {
        char filepath[1024];
        struct stat statbuf;
        snprintf(filepath, sizeof(filepath), "%s/%s", path, dp->d_name);
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
            continue;
        if (lstat(filepath, &statbuf) == -1)
            continue;
        if (S_ISDIR(statbuf.st_mode))
            analyze_directory(filepath, level + 1);
        else
            total_size += (double) statbuf.st_size;
    }
    closedir(dir);
    print_file(path, total_size, level);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s [directory path]\n", argv[0]);
        return 1;
    }
    if (strlen(argv[1]) > 1024) {
        fprintf(stderr, "Error: Path too long\n");
        return 1;
    }
    printf("Analyzing disk usage for %s...\n", argv[1]);
    printf("|%59s| %7s\n", "Name", "Size");
    printf("|------------------------------------------------|--------\n");
    analyze_directory(argv[1], 0);
    return 0;
}