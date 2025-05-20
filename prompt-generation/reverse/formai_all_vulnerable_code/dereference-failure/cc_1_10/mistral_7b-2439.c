//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

struct FileInfo {
    char fileName[256];
    off_t fileSize;
};

int main() {
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    struct FileInfo files[1024];
    int numFiles = 0;
    long long totalSize = 0;

    dir = opendir(".");

    if (!dir) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            sprintf(files[numFiles].fileName, "%s", entry->d_name);
            stat(entry->d_name, &fileStat);
            files[numFiles].fileSize = fileStat.st_size;
            numFiles++;
            totalSize += files[numFiles - 1].fileSize;
        }

        if (numFiles >= 1024) {
            break;
        }
    }

    closedir(dir);

    printf("\n%s\n", "A fair report, to comfort and reassure:\n");
    printf("%s\n", "Your disk space usage in the beloved city of Romeo:\n");
    printf("%s\n", "---------------------------------------------------");

    for (int i = 0; i < numFiles; i++) {
        printf("%s: %lld bytes\n", files[i].fileName, files[i].fileSize);
        totalSize -= files[i].fileSize;
    }

    printf("\n%s\n", "-----------------------------------------------");
    printf("\n%s\n", "Total disk space used: %lld bytes\n", totalSize);

    return 0;
}