//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_SIZE 1024

// Function to display usage
void usage() {
    printf("Usage: disk-analyzer <directory-path>\n");
}

// Function to calculate total file size in bytes
long int calculateFileSize(const char *filename) {
    FILE *fp = fopen(filename, "rb");

    fseek(fp, 0, SEEK_END);
    long int file_size = ftell(fp);

    fclose(fp);

    return file_size;
}

// Function to format file size in KB/MB/GB etc.
void formatFileSize(long int fileSize, char *formattedSize) {
    int count = 0;
    while (fileSize >= 1024 && count < 5) {
        fileSize /= 1024;
        count++;
    }

    switch (count) {
        case 0:
            sprintf(formattedSize, "%ld B", fileSize);
            break;
        case 1:
            sprintf(formattedSize, "%ld KB", fileSize);
            break;
        case 2:
            sprintf(formattedSize, "%ld MB", fileSize);
            break;
        case 3:
            sprintf(formattedSize, "%ld GB", fileSize);
            break;
        case 4:
            sprintf(formattedSize, "%ld TB", fileSize);
            break;
        default:
            sprintf(formattedSize, "%ld B", fileSize);
            break;
    }
}

// Function to calculate total disk space used by a directory and its sub-directories
long int calculateDiskSpace(const char *path) {
    DIR *dir;
    struct dirent *ent;
    long int totalSize = 0;

    if ((dir = opendir(path)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            char childPath[MAX_SIZE];
            sprintf(childPath, "%s/%s", path, ent->d_name);

            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
                continue;
            }

            if (ent->d_type == DT_DIR) {
                totalSize += calculateDiskSpace(childPath);
            } else {
                totalSize += calculateFileSize(childPath);
            }
        }

        closedir(dir);
    } else {
        printf("Unable to open directory %s\n", path);
        exit(EXIT_FAILURE);
    }

    return totalSize;
}

// Main function
int main(int argc, char *argv[]) {

    if (argc != 2) {
        usage();
        exit(EXIT_FAILURE);
    }

    char path[MAX_SIZE];
    strcpy(path, argv[1]);

    long int totalSize = calculateDiskSpace(path);

    char formattedSize[MAX_SIZE];
    formatFileSize(totalSize, formattedSize);

    printf("Total Disk Space Used by %s: %s\n", path, formattedSize);

    return 0;
}