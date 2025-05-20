//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KB 1024
#define MB (KB * 1024)
#define GB (MB * 1024)

typedef struct {
    char name[256];
    long size;
} FileData;

void diskSpaceAnalyzer(char *path) {
    printf("Analyzing disk space...\n");
    printf("Path: %s\n", path);

    FILE *fp = popen("du -h -d 1", "r");
    if (fp == NULL) {
        printf("Error: unable to execute command.\n");
        return;
    }

    int fileCount = 0;
    long totalSize = 0;
    FileData *fileData = malloc(sizeof(FileData) * 256);
    char buf[256], file[256];
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        if (sscanf(buf, "%ld\t%s", &fileData[fileCount].size, fileData[fileCount].name) == 2) {
            strcat(fileData[fileCount].name, "/");
            fileCount++;
            totalSize += fileData[fileCount-1].size;
        }
    }

    printf("\n--------------------------------------\n");
    printf("%-50s %13s\n", "FILE/FOLDER NAME", "SIZE");

    for (int i = 0; i < fileCount; i++) {
        char size[16];
        if (fileData[i].size < KB) {
            sprintf(size, "%ld B", fileData[i].size);
        } else if (fileData[i].size < MB) {
            sprintf(size, "%.1f KB", (double)fileData[i].size/KB);
        } else if (fileData[i].size < GB) {
            sprintf(size, "%.1f MB", (double)fileData[i].size/MB);
        } else {
            sprintf(size, "%.1f GB", (double)fileData[i].size/GB);
        }
        printf("%-50s %13s\n", fileData[i].name, size);
    }

    char totalSizeStr[16];
    if (totalSize < KB) {
        sprintf(totalSizeStr, "%ld B", totalSize);
    } else if (totalSize < MB) {
        sprintf(totalSizeStr, "%.1f KB", (double)totalSize/KB);
    } else if (totalSize < GB) {
        sprintf(totalSizeStr, "%.1f MB", (double)totalSize/MB);
    } else {
        sprintf(totalSizeStr, "%.1f GB", (double)totalSize/GB);
    }

    printf("\n--------------------------------------\n");
    printf("%-50s %13s\n", "TOTAL", totalSizeStr);

    pclose(fp);
    free(fileData);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s [directory path]\n", argv[0]);
        return 1;
    }

    diskSpaceAnalyzer(argv[1]);
    return 0;
}