//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: enthusiastic
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

void analyzeDiskSpace(const char* path, const int tabCount);

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Usage: ./diskanalyzer <path>\n");
        return -1;
    }

    analyzeDiskSpace(argv[1], 0);

    return 0;
}

void analyzeDiskSpace(const char* path, const int tabCount)
{
    DIR* directory = opendir(path);
    if (directory == NULL) {
        printf("Could not open directory: %s\n", path);
        return;
    }

    struct dirent* dir;
    while ((dir = readdir(directory)) != NULL) {
        if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
            continue;
        }

        char filePath[512];
        sprintf(filePath, "%s/%s", path, dir->d_name);

        struct stat fileStat;
        if (stat(filePath, &fileStat) < 0) {
            continue;
        }

        if (S_ISDIR(fileStat.st_mode)) {
            for (int i = 0; i < tabCount; i++) {
                printf("\t");
            }
            printf("[%s]\n", dir->d_name);
            analyzeDiskSpace(filePath, tabCount + 1);
        } else {
            for (int i = 0; i < tabCount; i++) {
                printf("\t");
            }
            printf("%s\n", dir->d_name);
        }
    }

    closedir(directory);
}