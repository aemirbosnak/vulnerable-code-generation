//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 1024

struct file_metadata {
    char name[MAX_PATH_LENGTH];
    off_t size;
};

void analyze_directory(char *path, struct file_metadata *data, int *count, int depth) {
    DIR *dir = opendir(path);
    if(!dir) {
        printf("Could not open directory %s\n", path);
        return;
    }

    struct dirent *entry;
    while((entry = readdir(dir)) != NULL) {
        char entry_path[MAX_PATH_LENGTH];
        sprintf(entry_path, "%s/%s", path, entry->d_name);

        struct stat metadata;
        if(lstat(entry_path, &metadata) == -1) {
            printf("Could not get metadata for %s\n", entry_path);
            continue;
        }

        if(S_ISREG(metadata.st_mode)) {
            // entry is a regular file
            struct file_metadata fdata;
            strncpy(fdata.name, entry->d_name, MAX_PATH_LENGTH);
            fdata.size = metadata.st_size;

            data[*count] = fdata;
            (*count)++;
        } else if(S_ISDIR(metadata.st_mode)) {
            // entry is a directory
            if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            if(depth > 0) {
                analyze_directory(entry_path, data, count, depth - 1);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Usage: %s <directory_path> [depth]\n", argv[0]);
        return 1;
    }

    char *path = argv[1];
    int depth = 1;

    if(argc > 2) {
        depth = atoi(argv[2]);
    }

    struct file_metadata *data = malloc(sizeof(struct file_metadata) * 1000);
    int count = 0;

    analyze_directory(path, data, &count, depth);

    off_t total_size = 0;
    for(int i = 0; i < count; i++) {
        printf("%s: %lu bytes\n", data[i].name, data[i].size);
        total_size += data[i].size;
    }

    printf("Total size of directory %s: %lu bytes\n", path, total_size);

    return 0;
}