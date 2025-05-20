//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_PATH 1024

// Function to compare names (for use with qsort)
int compare_names(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

// Function to compare sizes (for use with qsort)
int compare_sizes(const void *a, const void *b) {
    struct statvfs stat1, stat2;
    statvfs(*(char **)a, &stat1);
    statvfs(*(char **)b, &stat2);
    return difftime(stat1.f_blocks, stat2.f_blocks);
}

void print_dir(char* path, int sort_by_size) {
    DIR *d;
    struct dirent *dir;
    d = opendir(path);

    if (d) {
        char **files = NULL;
        int count = 0;

        while ((dir = readdir(d))!= NULL) {
            files = realloc(files, sizeof(char *) * ++count);
            files[count-1] = strdup(dir->d_name);
        }

        // Sort files by name or size
        if (sort_by_size) {
            qsort(files, count, sizeof(char *), compare_sizes);
        } else {
            qsort(files, count, sizeof(char *), compare_names);
        }

        // Print sorted file list
        for (int i = 0; i < count; i++) {
            printf("%s\n", files[i]);
            free(files[i]);
        }
        free(files);

        closedir(d);
    }
}

void analyze_disk_space(char* path, int sort_by_size) {
    char cwd[MAX_PATH];
    getcwd(cwd, MAX_PATH);
    chdir(path);

    struct statvfs buf;
    if (statvfs(".", &buf) == 0) {
        printf("Total space: %ld bytes\n", buf.f_blocks * buf.f_frsize);
        printf("Used space: %ld bytes\n", (buf.f_blocks - buf.f_bavail) * buf.f_frsize);
        printf("Free space: %ld bytes\n", buf.f_bavail * buf.f_frsize);
    } else {
        perror("");
        exit(EXIT_FAILURE);
    }

    print_dir(".", sort_by_size);

    chdir(cwd);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s [path] [sort_by_size]\n", argv[0]);
        return 1;
    }

    char* path = argv[1];
    int sort_by_size = (argc > 2)? atoi(argv[2]) : 0;

    analyze_disk_space(path, sort_by_size);

    return 0;
}