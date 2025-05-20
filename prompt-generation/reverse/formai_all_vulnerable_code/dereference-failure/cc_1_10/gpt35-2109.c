//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: future-proof
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

long long int totalSize = 0;

void printSize(long long int size) {
    if(size < 1024) {
        printf("%lld B", size);
    } else if(size < 1048576) {
        printf("%lld KB", size/1024);
    } else if(size < 1073741824) {
        printf("%lld MB", size/1048576);
    } else {
        printf("%lld GB", size/1073741824);
    }
}

void analyzeDirectory(char* path) {
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;

    if(!(dir = opendir(path))) {
        perror("opendir");
        return;
    }

    while((entry = readdir(dir)) != NULL) {
        char entryPath[1024];
        sprintf(entryPath, "%s/%s", path, entry->d_name);
        stat(entryPath, &fileStat);

        if(entry->d_type == DT_DIR) {
            if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            analyzeDirectory(entryPath);
        } else {
            totalSize += (long long int)fileStat.st_size;
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if(argc != 2) {
        printf("Usage: c-disk-analyzer <path>\n");
        return 0;
    }

    char *path = argv[1];

    if(path[0] != '/') {
        printf("Please provide an absolute path\n");
        return 0;
    }

    analyzeDirectory(path);

    printf("Total disk space used by %s: ", path);
    printSize(totalSize);
    printf("\n");

    return 0;
}