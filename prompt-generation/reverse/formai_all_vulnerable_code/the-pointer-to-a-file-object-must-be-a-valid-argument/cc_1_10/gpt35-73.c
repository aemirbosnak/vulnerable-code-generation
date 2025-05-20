//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

struct FileInfo {
    char* name;
    unsigned long size;
};

void sortFileInfo(struct FileInfo* fileInfo, int count) {
    struct FileInfo temp;
    int i, j;

    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (fileInfo[i].size < fileInfo[j].size) {
                temp = fileInfo[i];
                fileInfo[i] = fileInfo[j];
                fileInfo[j] = temp;
            }
        }
    }
}

char* formatSize(unsigned long size) {
    char* units[] = { "B", "KB", "MB", "GB", "TB" };
    int unitIndex = 0;
    double newSize = (double)size;

    while (newSize >= 1024 && unitIndex < 4) {
        newSize /= 1024;
        unitIndex++;
    }

    char* formattedSize = (char*)malloc(sizeof(char) * 10);
    sprintf(formattedSize, "%.1f %s", newSize, units[unitIndex]);

    return formattedSize;
}

void analyzeDiskSpace(char* root, int depth) {
    char command[MAX_FILENAME_LENGTH * 2];

    sprintf(command, "du -hd%d %s", depth, root);

    FILE* output = popen(command, "r");

    char line[MAX_FILENAME_LENGTH * 3];
    int count = 0;

    struct FileInfo fileInfos[MAX_FILENAME_LENGTH];

    while (fgets(line, MAX_FILENAME_LENGTH * 3, output)) {
        char* sizeString = strtok(line, "\t");
        char* fileName = strtok(NULL, "\n");

        if (sizeString != NULL && fileName != NULL) {
            unsigned long size = strtoul(sizeString, NULL, 10);
            fileInfos[count].name = fileName;
            fileInfos[count].size = size;
            count++;
        }
    }

    pclose(output);

    sortFileInfo(fileInfos, count);

    int i;
    for (i = 0; i < count; i++) {
        printf("%*s%s\n", i * 2, "", fileInfos[i].name);
        printf("%*s%s\n", i * 2, "", formatSize(fileInfos[i].size));
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("ERROR: Must provide a root directory\n");
        return 1;
    }

    char* root = argv[1];
    int depth = 1;

    if (argc == 3) {
        depth = atoi(argv[2]);
    }

    analyzeDiskSpace(root, depth);

    return 0;
}