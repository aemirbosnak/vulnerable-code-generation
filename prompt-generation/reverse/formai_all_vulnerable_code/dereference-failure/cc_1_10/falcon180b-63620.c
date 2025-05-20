//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    char target[MAX_PATH];
} file_t;

void sync_files(char* source, char* target) {
    DIR* dir = opendir(source);
    if (dir == NULL) {
        fprintf(stderr, "Error: Could not open source directory '%s'\n", source);
        exit(1);
    }

    file_t files[1000];
    int count = 0;

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_REG || entry->d_type == DT_LNK) {
            snprintf(files[count].path, MAX_PATH, "%s/%s", source, entry->d_name);
            snprintf(files[count].target, MAX_PATH, "%s/%s", target, entry->d_name);
            count++;
        }
    }

    closedir(dir);

    for (int i = 0; i < count; i++) {
        sync_files(files[i].path, files[i].target);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s source_directory target_directory\n", argv[0]);
        exit(1);
    }

    char source[MAX_PATH];
    char target[MAX_PATH];

    snprintf(source, MAX_PATH, "%s", argv[1]);
    snprintf(target, MAX_PATH, "%s", argv[2]);

    sync_files(source, target);

    return 0;
}