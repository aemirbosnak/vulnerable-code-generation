//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define GB (1024 * 1024 * 1024)
#define MB (1024 * 1024)
#define KB (1024)

typedef struct {
    char name[256];
    unsigned long long size;
} file_info;

int compare_func(const void *a, const void *b) {
    file_info *fa = (file_info *)a;
    file_info *fb = (file_info *)b;

    return fb->size - fa->size;
}

void read_directory(const char *path, file_info **files, int *count) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    struct stat stat_entry;
    char full_path[512];

    while ((entry = readdir(dir)) != NULL) {
        sprintf(full_path, "%s/%s", path, entry->d_name);

        if (stat(full_path, &stat_entry) == 0 && S_ISREG(stat_entry.st_mode)) {
            (*files)[*count].size = stat_entry.st_size;
            strcpy((*files)[*count].name, full_path);
            (*count)++;
            *files = realloc(*files, (*count + 1) * sizeof(file_info));
        } else if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            read_directory(full_path, files, count);
        }
    }

    closedir(dir);
}

void print_size(unsigned long long size) {
    if (size >= GB) {
        printf("%.2f GB", (float)size / GB);
    } else if (size >= MB) {
        printf("%.2f MB", (float)size / MB);
    } else if (size >= KB) {
        printf("%.2f KB", (float)size / KB);
    } else {
        printf("%llu B", size);
    }
}

void print_usage(file_info *files, int count) {
    unsigned long long total_size = 0;

    for (int i = 0; i < count; i++) {
        total_size += files[i].size;
    }

    printf("Total size: ");
    print_size(total_size);
    printf("\n\n");

    printf("%-60s %s\n", "File", "Size");
    printf("%-60s %s\n", "----", "----");

    qsort(files, count, sizeof(file_info), compare_func);

    for (int i = 0; i < count; i++) {
        printf("%-60s ", files[i].name);
        print_size(files[i].size);
        printf("\n");
    }
}

int main() {
    file_info *files = malloc(sizeof(file_info));
    int count = 0;

    read_directory(".", &files, &count);

    print_usage(files, count);

    free(files);

    return 0;
}