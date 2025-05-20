//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_PATTERN_LENGTH 256

typedef struct {
    char name[256];
    char virusPattern[MAX_PATTERN_LENGTH];
} VirusDef;

VirusDef virusDefinitions[] = {
    {"VirusA", "maliciouscode1"},
    {"VirusB", "maliciouscode2"},
    {"VirusC", "maliciouscode3"},
    {"VirusD", "maliciouscode4"},
    {"VirusE", "maliciouscode5"},
};

int numVirusDefs = sizeof(virusDefinitions) / sizeof(VirusDef);

void scanFile(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s for reading.\n", filePath);
        return;
    }

    char *buffer = NULL;
    size_t size = 0;
    ssize_t read;

    while ((read = getline(&buffer, &size, file)) != -1) {
        for (int i = 0; i < numVirusDefs; i++) {
            if (strstr(buffer, virusDefinitions[i].virusPattern) != NULL) {
                printf("Virus found in file: %s -> %s detected!\n", filePath, virusDefinitions[i].name);
                break;
            }
        }
    }

    free(buffer);
    fclose(file);
}

void scanDirectory(const char *dirPath) {
    struct dirent *entry;
    struct stat fileInfo;
    DIR *directory = opendir(dirPath);

    if (directory == NULL) {
        fprintf(stderr, "Could not open directory %s.\n", dirPath);
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        char fullPath[MAX_PATH];
        snprintf(fullPath, MAX_PATH, "%s/%s", dirPath, entry->d_name);

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                scanDirectory(fullPath);
            }
        } else {
            scanFile(fullPath);
        }
    }

    closedir(directory);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Starting antivirus scan on directory: %s\n", argv[1]);
    scanDirectory(argv[1]);
    printf("Scan complete.\n");

    return 0;
}