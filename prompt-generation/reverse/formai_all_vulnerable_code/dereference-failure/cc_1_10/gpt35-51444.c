//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: satisfied
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

struct Folder {
    char name[200];
    long long int size;
};

void analyzeFolder(char *folderPath, int indentationLevel, struct Folder *folders, int *folderCount) {
    DIR *d;
    struct dirent *dir;
    d = opendir(folderPath);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
                continue;
            }
            struct stat st;
            char filePath[300];
            sprintf(filePath, "%s/%s", folderPath, dir->d_name);
            stat(filePath, &st);
            if (S_ISDIR(st.st_mode)) {
                int folderIndex = *folderCount;
                (*folderCount)++;
                strcpy(folders[folderIndex].name, dir->d_name);
                folders[folderIndex].size = 0;
                for (int i = 0; i < indentationLevel * 2; i++) {
                    printf(" ");
                }
                printf("%s/\n", dir->d_name);
                analyzeFolder(filePath, indentationLevel + 1, folders, folderCount);
                for (int i = 0; i < indentationLevel * 2; i++) {
                    printf(" ");
                }
                printf("Size: %lld bytes\n", folders[folderIndex].size);
            } else {
                for (int i = 0; i < indentationLevel * 2; i++) {
                    printf(" ");
                }
                printf("%s: %lld bytes\n", dir->d_name, st.st_size);
                for (int i = 0; i < *folderCount; i++) {
                    if (strcmp(folders[i].name, folderPath) == 0) {
                        folders[i].size += st.st_size;
                    }
                }
            }
        }
        closedir(d);
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <folder>\n", argv[0]);
        return 1;
    }

    char* folder = argv[1];
    struct Folder folders[1000];
    int folderCount = 0;
    analyzeFolder(folder, 0, folders, &folderCount);

    return 0;
}