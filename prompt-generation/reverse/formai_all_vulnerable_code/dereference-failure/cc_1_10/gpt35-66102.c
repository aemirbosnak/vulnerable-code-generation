//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <math.h>

#define KB_BYTES 1024
#define MB_BYTES 1048576
#define GB_BYTES 1073741824

void print_size(double size) {
    if (size >= GB_BYTES)
        printf("%.2f GB\n", size / GB_BYTES);
    else if (size >= MB_BYTES)
        printf("%.2f MB\n", size / MB_BYTES);
    else if (size >= KB_BYTES)
        printf("%.2f KB\n", size / KB_BYTES);
    else
        printf("%.2f bytes\n", size);
}

double calculate_size(char *path) {
    struct dirent *entry;
    DIR *dir = opendir(path);
    double total_size = 0;

    if (dir == NULL) {
        fprintf(stderr, "Cannot open directory '%s'\n", path);
        return 0;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char subpath[1000];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            sprintf(subpath, "%s/%s", path, entry->d_name);
            total_size += calculate_size(subpath);
        }
        else {
            char filepath[1000];
            sprintf(filepath, "%s/%s", path, entry->d_name);
            FILE *file = fopen(filepath, "rb");
            if (file != NULL) {
                fseek(file, 0, SEEK_END);
                long fsize = ftell(file);
                fclose(file);
                total_size += fsize;
            }
        }
    }

    closedir(dir);
    return total_size;
}

int main(int argc, char *argv[]) {
    char *path = ".";
    if (argc > 1)
        path = argv[1];

    printf("Calculating disk usage in '%s'. Please wait...\n", path);
    double total_size = calculate_size(path);

    printf("\nTotal disk usage in '%s': ", path);
    print_size(total_size);

    return 0;
}