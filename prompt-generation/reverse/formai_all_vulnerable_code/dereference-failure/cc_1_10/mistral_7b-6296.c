//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct {
    char name[256];
    off_t size;
} FileInfo;

void PrintDir(DIR *dir, char *path) {
    struct stat st;
    struct dirent *entry;
    FileInfo file;
    char fullPath[512];

    while ((entry = readdir(dir))) {
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            if (chdir(fullPath) == 0) {
                PrintDir(opendir("."), fullPath);
                chdir("..");
            }
            continue;
        }

        if (stat(fullPath, &st) < 0) {
            perror("Error reading file");
            continue;
        }

        memset(&file, 0, sizeof(FileInfo));
        strncpy(file.name, entry->d_name, sizeof(file.name) - 1);
        file.size = st.st_size;

        printf("\033[31m%-50s\033[1;33m--> %lld bytes\033[0m\n", file.name, file.size);
    }
}

int main(int argc, char *argv[]) {
    DIR *dir;
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    if ((dir = opendir(argv[1])) == NULL) {
        perror("Error opening directory");
        return 1;
    }

    printf("\033[1;32m-----------------------------------------------------------------------------------\033[0m\n");
    printf("\033[1;32m|                                 Disk Space Analyzer (DiskSage)                      |\033[0m\n");
    printf("\033[1;32m-----------------------------------------------------------------------------------\033[0m\n");

    PrintDir(dir, argv[1]);

    closedir(dir);
    return 0;
}