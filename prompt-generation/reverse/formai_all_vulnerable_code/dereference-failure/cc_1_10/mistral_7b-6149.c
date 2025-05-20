//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <math.h>

struct file_info {
    char fileName[256];
    off_t fileSize;
};

double totalSize = 0.0;
int numFiles = 0, numDirs = 0;
struct file_info files[1024];

void processDirectory(char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;

    if (!(dir = opendir(path))) {
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char fullPath[512];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            numDirs++;
            processDirectory(fullPath);
        } else {
            if (stat(fullPath, &fileStat) == -1) {
                continue;
            }
            numFiles++;
            strcpy(files[numFiles].fileName, entry->d_name);
            files[numFiles].fileSize = fileStat.st_size;
            totalSize += fileStat.st_size;
        }
    }

    closedir(dir);
}

int main() {
    processDirectory(".");

    printf("\nTotal space used: %.2f bytes\n", totalSize);
    printf("Number of files: %d\n", numFiles);
    printf("Number of directories: %d\n", numDirs);

    printf("\nFile size distribution:\n");

    int sizeBins[10] = {0};

    for (int i = 0; i < numFiles; i++) {
        int sizeIndex = (int)(log10(files[i].fileSize / 1024.0)) >= 0 ? (int)(log10(files[i].fileSize / 1024.0)) : 9;
        sizeBins[sizeIndex]++;
    }

    for (int i = 0; i < 10; i++) {
        printf("Size bin %d (KB): %d files, %.1f%% of total size\n", i * 10 + 1, sizeBins[i], (sizeBins[i] / (double)numFiles) * 100.0);
    }

    return 0;
}