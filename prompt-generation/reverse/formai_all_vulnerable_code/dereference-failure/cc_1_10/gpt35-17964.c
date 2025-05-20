//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

void analyzeDir(char* path, float totalSize, float* folderSizes, int *i, int* numFolders) {
    DIR* dir = opendir(path);
    if (!dir) {
        printf("Unable to open directory %s\n", path);
        return;
    }
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        char* name = entry->d_name;
        if ((strcmp(name, ".")==0) || (strcmp(name,"..")==0)) {
            continue;
        }
        if (entry->d_type == DT_DIR) {
            char* newPath = malloc(strlen(path)+strlen(name)+2);
            snprintf(newPath, strlen(path)+strlen(name)+2, "%s/%s", path, name);
            analyzeDir(newPath, totalSize, folderSizes, i, numFolders);
            free(newPath);
        }
        else {
            char* filePath = malloc(strlen(path)+strlen(name)+2);
            snprintf(filePath, strlen(path)+strlen(name)+2, "%s/%s", path, name);
            struct stat st;
            if (stat(filePath, &st) == 0) {
                totalSize += st.st_size;
                // Add the size to the current folder
                folderSizes[*i] += st.st_size;
                if (totalSize/1000000000 > 1) {
                    printf("Current folder: %s\nSize: %.2f GB\n\n", path, folderSizes[*i]/1000000000.0);
                    (*i)++;
                    (*numFolders)++;
                    folderSizes = realloc(folderSizes, (*numFolders+1)*sizeof(float));
                    folderSizes[*numFolders] = 0.0;
                    totalSize = 0;
                }
            }
            free(filePath);
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Please specify a directory to analyze.\n");
        return 0;
    }
    // Create an array to keep track of sizes for each folder
    float* folderSizes = malloc(sizeof(float));
    folderSizes[0] = 0.0;
    int numFolders = 1;
    int i = 0;
    char* path = argv[1];
    float totalSize = 0;
    analyzeDir(path, totalSize, folderSizes, &i, &numFolders);
    if (totalSize > 0) {
        printf("Current folder: %s\nSize: %.2f GB\n\n", path, totalSize/1000000000.0);
    }
    for (int j = 0; j < numFolders; j++) {
        printf("Folder %d size: %.2f GB\n", j+1, folderSizes[j]/1000000000.0);
    }
    free(folderSizes);
    return 0;
}