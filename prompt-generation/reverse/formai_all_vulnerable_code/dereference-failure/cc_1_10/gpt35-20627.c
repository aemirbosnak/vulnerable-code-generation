//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <math.h>

// function to convert file size from bytes to a human-readable format
void formatSize(double size, char* buf) {
    const char* units[] = {"B", "KB", "MB", "GB", "TB"};
    int i = 0;
    while (size > 1024 && i < 4) {
        size /= 1024;
        i++;
    }
    sprintf(buf, "%.1f %s", size, units[i]);
}

// function to obtain the disk usage of a directory
double getDirectorySize(char* path) {
    DIR* dir;
    struct dirent* entry;
    char filepath[256];
    double totalSize = 0;

    dir = opendir(path);
    if (dir == NULL) {
        printf("Could not open directory: %s\n", path);
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        // skip the current and parent directories to avoid infinite recursion
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name);
            if (entry->d_type == DT_DIR) {
                totalSize += getDirectorySize(filepath);
            }
            else if (entry->d_type == DT_REG) {
                FILE* fp = fopen(filepath, "rb");
                if (fp != NULL) {
                    fseek(fp, 0L, SEEK_END);
                    double size = ftell(fp);
                    totalSize += size;
                    fclose(fp);
                }
            }
        }
    }

    closedir(dir);

    return totalSize;
}

int main(int argc, char** argv) {
    char* path;
    if (argc > 1) {
        path = argv[1];
    }
    else {
        path = ".";
    }

    double totalSize = getDirectorySize(path);
    if (totalSize < 0) {
        return 1;
    }

    // calculate and display the total disk usage
    char sizeBuf[16];
    formatSize(totalSize, sizeBuf);
    printf("Total disk usage: %s\n", sizeBuf);

    // calculate and display the disk usage breakdown by file type
    DIR* dir;
    struct dirent* entry;
    char filepath[256];
    double totalTypes[5] = {0, 0, 0, 0, 0};

    dir = opendir(path);
    if (dir == NULL) {
        printf("Could not open directory: %s\n", path);
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name);
            if (entry->d_type == DT_DIR) {
                continue;
            }
            else if (entry->d_type == DT_REG) {
                // determine the file type based on the file extension
                char* ext = strrchr(entry->d_name, '.');
                if (ext == NULL) {
                    totalTypes[0] += getDirectorySize(filepath);
                }
                else if (strcmp(ext, ".txt") == 0) {
                    totalTypes[1] += getDirectorySize(filepath);
                }
                else if (strcmp(ext, ".jpg") == 0 || strcmp(ext, ".png") == 0) {
                    totalTypes[2] += getDirectorySize(filepath);
                }
                else if (strcmp(ext, ".mp3") == 0 || strcmp(ext, ".wav") == 0) {
                    totalTypes[3] += getDirectorySize(filepath);
                }
                else {
                    totalTypes[4] += getDirectorySize(filepath);
                }
            }
        }
    }

    closedir(dir);

    // display the disk usage breakdown
    printf("Disk usage breakdown:\n");
    formatSize(totalTypes[0], sizeBuf);
    printf("\tOther files: %s\n", sizeBuf);
    formatSize(totalTypes[1], sizeBuf);
    printf("\tText files: %s\n", sizeBuf);
    formatSize(totalTypes[2], sizeBuf);
    printf("\tImage files: %s\n", sizeBuf);
    formatSize(totalTypes[3], sizeBuf);
    printf("\tAudio files: %s\n", sizeBuf);
    formatSize(totalTypes[4], sizeBuf);
    printf("\tOther media files: %s\n", sizeBuf);

    return 0;
}