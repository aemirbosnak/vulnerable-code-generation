//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_FILE_NAME 1024

// Function to compare names (for use with qsort)
int compare_names(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

// Function to compare sizes (for use with qsort)
int compare_sizes(const void *a, const void *b) {
    struct statvfs stat1, stat2;
    statvfs(*(char **)a, &stat1);
    statvfs(*(char **)b, &stat2);
    if (stat1.f_blocks > stat2.f_blocks) {
        return -1;
    } else if (stat1.f_blocks < stat2.f_blocks) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print directory contents
void print_dir(char* path, int sort_by_size) {
    DIR* dir;
    struct dirent* ent;
    dir = opendir(path);

    if (dir!= NULL) {
        char** files = NULL;
        int count = 0;

        while ((ent = readdir(dir))!= NULL) {
            files = realloc(files, sizeof(char*) * ++count);
            files[count-1] = malloc(MAX_FILE_NAME);
            strcpy(files[count-1], ent->d_name);
        }

        // Sort files by name or size
        if (sort_by_size) {
            qsort(files, count, sizeof(char*), compare_sizes);
        } else {
            qsort(files, count, sizeof(char*), compare_names);
        }

        // Print sorted file list
        for (int i = 0; i < count; i++) {
            printf("%s\n", files[i]);
            free(files[i]);
        }
        free(files);

        closedir(dir);
    }
}

// Function to get disk space usage
void get_disk_space(char* path, struct statvfs* stat) {
    statvfs(path, stat);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s [directory] [sort_by_size]\n", argv[0]);
        return 1;
    }

    char* path = argv[1];
    int sort_by_size = (argc > 2)? atoi(argv[2]) : 0;

    print_dir(path, sort_by_size);

    return 0;
}