//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_TYPE_NAME_LEN 20
#define MAX_FILE_NAME_LEN 100

typedef struct {
    char fileName[MAX_FILE_NAME_LEN];
    char fileType[MAX_TYPE_NAME_LEN];
    off_t fileSize;
} FileInfo;

void getFileType(char *fileName, char *fileType) {
    int lastDot = -1;
    int len = strlen(fileName);

    for (int i = len - 1; i >= 0; i--) {
        if (fileName[i] == '.') {
            lastDot = i;
            break;
        }
    }

    if (lastDot == -1) {
        strcpy(fileType, "Unknown");
    } else {
        strncpy(fileType, fileName + lastDot, MAX_TYPE_NAME_LEN);
        fileType[MAX_TYPE_NAME_LEN - 1] = '\0';
    }
}

void printFileInfo(FileInfo fileInfo) {
    printf("%-20s %-10ld bytes (%-.2f%%)\n", fileInfo.fileType, fileInfo.fileSize,
           (100.0 * fileInfo.fileSize / (1024 * 1024)) / 100.0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    FileInfo fileInfo;
    char fileType[MAX_TYPE_NAME_LEN];

    dir = opendir(argv[1]);
    if (!dir) {
        perror("opendir");
        return 1;
    }

    printf("Directory: %s\n", argv[1]);
    printf("------------------------------------------\n");
    printf("| File Type       | Size (MB) | Percentage |\n");
    printf("------------------------------------------\n");

    off_t totalSize = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            continue;
        }

        strcpy(fileInfo.fileName, argv[1]);
        strcat(fileInfo.fileName, "/");
        strcat(fileInfo.fileName, entry->d_name);

        if (stat(fileInfo.fileName, &fileStat) == -1) {
            perror("stat");
            continue;
        }

        fileInfo.fileSize = fileStat.st_size;
        getFileType(entry->d_name, fileType);
        printFileInfo((FileInfo) { .fileType = fileType, .fileSize = fileInfo.fileSize });

        totalSize += fileInfo.fileSize;
    }

    closedir(dir);

    printf("------------------------------------------\n");
    printf("| Total             | %.2f MB |\n", totalSize / (1024 * 1024));

    return 0;
}