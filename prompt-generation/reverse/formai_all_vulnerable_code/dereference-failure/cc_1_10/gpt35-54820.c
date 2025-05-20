//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define PATH_MAX 4096 // maximum length for file path

typedef struct file {
    char name[100];
    long size;
} File;

int compare_file_size(const void *p, const void *q) {
    long x = ((File *) p)->size;
    long y = ((File *) q)->size;
    return (x < y) ? 1 : -1;
}

long get_file_size(char *filepath) {
    struct stat st;
    if (stat(filepath, &st) == 0) {
        return st.st_size;
    }
    return -1;
}

void print_formatted_size(long size) {
    float kb = (float) size / 1024;
    float mb = kb / 1024;
    float gb = mb / 1024;
    if (gb > 1) {
        printf("%.2f GB", gb);
    } else if (mb > 1) {
        printf("%.2f MB", mb);
    } else if (kb > 1) {
        printf("%.2f KB", kb);
    } else {
        printf("%ld Byte", size);
    }
}

int main(int argc, char **argv) {
    char target_path[PATH_MAX];
    if (argc < 2) {
        printf("Enter the path to analyze: ");
        fgets(target_path, sizeof(target_path), stdin);
        target_path[strcspn(target_path, "\n")] = 0; // remove the trailing newline character
    } else {
        strcpy(target_path, argv[1]);
    }

    DIR *dir;
    struct dirent *entry;
    File files[1000]; // maximum files to analyze
    int file_count = 0;

    // open directory
    if ((dir = opendir(target_path)) != NULL) {
        // iterate through all entries in the directory
        while ((entry = readdir(dir)) != NULL) {
            if (entry->d_type == DT_REG) {
                char filepath[PATH_MAX];
                snprintf(filepath, PATH_MAX, "%s/%s", target_path, entry->d_name);
                long size = get_file_size(filepath);
                if (size > 0) {
                    File f = { .size = size };
                    strcpy(f.name, entry->d_name);
                    files[file_count++] = f;
                }
            }
        }
        closedir(dir);
    } else {
        printf("Cannot open directory %s\n", target_path);
        return 1;
    }

    if (file_count == 0) {
        printf("No files found in %s\n", target_path);
        return 0;
    }

    qsort(files, file_count, sizeof(File), compare_file_size);

    printf("\nTop 10 Largest Files in %s:\n", target_path);
    printf("------------------------------------------------\n");
    printf("%-40s  %s\n", "Filename", "Size");
    printf("------------------------------------------------\n");
    for (int i = 0; i < 10 && i < file_count; i++) {
        File f = files[i];
        printf("%-40s  ", f.name);
        print_formatted_size(f.size);
        printf("\n");
    }

    printf("------------------------------------------------\n");
    printf("Total number of files: %d\n", file_count);

    return 0;
}