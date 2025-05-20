//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

typedef struct {
    char *name;
    int size;
} FileType;

int fileTypeIndex(FileType *types, char *name, int numTypes) {
    // Helper function to find index of a file type in the array of types
    for (int i = 0; i < numTypes; i++) {
        if (strcmp(types[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void addFileType(FileType **types, char *name, int size, int *numTypes, int *totalSize) {
    // Helper function to add a file type to the array of types
    int index = fileTypeIndex(*types, name, *numTypes);
    if (index == -1) {
        // File type not found in array, add it
        (*numTypes)++;
        *types = realloc(*types, *numTypes * sizeof(FileType));
        (*types)[*numTypes-1].name = strdup(name);
        (*types)[*numTypes-1].size = size;
    } else {
        // File type found in array, update its size
        (*types)[index].size += size;
    }
    *totalSize += size;
}

void analyzeDirectory(char *path, FileType **types, int *numTypes, int *totalSize) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    struct stat statbuf;
    while ((entry = readdir(dir)) != NULL) {
        char entryPath[1024];
        sprintf(entryPath, "%s/%s", path, entry->d_name);
        if (lstat(entryPath, &statbuf) == -1) {
            perror("lstat");
            continue;
        }
        if (S_ISDIR(statbuf.st_mode)) {
            // Directory found, recursively analyze it
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                analyzeDirectory(entryPath, types, numTypes, totalSize);
            }
        } else {
            // File found, add its type and size to the array of types
            char *ext = strrchr(entry->d_name, '.');
            if (ext != NULL) {
                addFileType(types, ext+1, statbuf.st_size, numTypes, totalSize);
            } else {
                addFileType(types, "no extension", statbuf.st_size, numTypes, totalSize);
            }
        }
    }
    closedir(dir);
}

int main(int argc, char **argv) {
    FileType *types = NULL;
    int numTypes = 0;
    int totalSize = 0;
    analyzeDirectory(".", &types, &numTypes, &totalSize);
    printf("Total size: %d bytes\n", totalSize);
    for (int i = 0; i < numTypes; i++) {
        printf("%s: %d bytes\n", types[i].name, types[i].size);
    }
    for (int i = 0; i < numTypes; i++) {
        free(types[i].name);
    }
    free(types);
    return 0;
}