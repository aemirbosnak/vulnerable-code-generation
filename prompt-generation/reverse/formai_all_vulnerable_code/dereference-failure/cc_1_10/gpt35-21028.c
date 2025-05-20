//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

struct DirEntry {
    char* name;
    long size;
};

int compareEntriesByName(const void *a, const void *b) {
    const struct DirEntry* entryA = *(const struct DirEntry**)a;
    const struct DirEntry* entryB = *(const struct DirEntry**)b;
    return strcmp(entryA->name, entryB->name);
}

int compareEntriesBySize(const void *a, const void *b) {
    const struct DirEntry* entryA = *(const struct DirEntry**)a;
    const struct DirEntry* entryB = *(const struct DirEntry**)b;
    return entryB->size - entryA->size;
}

void printSize(long size) {
    if (size < 1024) {
        printf("%ld B", size);
    } else if (size < 1024 * 1024) {
        printf("%.2f KB", size / 1024.0);
    } else if (size < 1024 * 1024 * 1024) {
        printf("%.2f MB", size / (1024.0 * 1024.0));
    } else {
        printf("%.2f GB", size / (1024.0 * 1024.0 * 1024.0));
    }
}

void analyzeDirectory(const char* path, int sortBySize) {
    DIR* dir = opendir(path);
    if (!dir) {
        printf("Error: Can't read directory %s\n", path);
        return;
    }
    
    // Read directory entries into an array
    struct DirEntry** entries = NULL;
    int numEntries = 0;
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // skip hidden files/dirs
        // Allocate space for new entry
        struct DirEntry* newEntry = malloc(sizeof(*newEntry));
        newEntry->name = malloc(strlen(entry->d_name) + 1);
        strcpy(newEntry->name, entry->d_name);
        newEntry->size = 0;
        // Compute size of entry if it's a file
        if (entry->d_type == DT_REG) {
            struct stat st;
            char pathBuf[1024];
            snprintf(pathBuf, sizeof(pathBuf), "%s/%s", path, entry->d_name);
            if (stat(pathBuf, &st) == 0) {
                newEntry->size = st.st_size;
            }
        }
        // Add entry to array
        numEntries++;
        entries = realloc(entries, numEntries * sizeof(*entries));
        entries[numEntries - 1] = newEntry;
    }
    closedir(dir);
    
    // Sort entries by name or size
    qsort(entries, numEntries, sizeof(*entries), sortBySize ? compareEntriesBySize : compareEntriesByName);
    
    // Print info for each entry
    long totalSize = 0;
    for (int i = 0; i < numEntries; i++) {
        printf("%s\t", entries[i]->name);
        printSize(entries[i]->size);
        printf("\n");
        totalSize += entries[i]->size;
    }
    printf("Total Size: ");
    printSize(totalSize);
    printf("\n");
    
    // Clean up
    for (int i = 0; i < numEntries; i++) {
        free(entries[i]->name);
        free(entries[i]);
    }
    free(entries);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: disk-analyzer [directory] [--size]\n");
        return 1;
    }
    const char* path = argv[1];
    int sortBySize = argc > 2 && strcmp(argv[2], "--size") == 0;
    analyzeDirectory(path, sortBySize);
    return 0;
}