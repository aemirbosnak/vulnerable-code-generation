//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define BUFFER_SIZE 1024

void scanFile(char* filename);
int isExecutable(char* filename);
int scanDir(char* dirName);
void cleanUp(char* message);

int main(int argc, char *argv[]) {
    if (argv[1] == NULL) {
        printf("Please specify a directory to scan.\n");
        return 1;
    }
    printf("Starting C Antivirus Scanner...\n");
    printf("Scanning directory: %s\n\n", argv[1]);

    int numFiles = scanDir(argv[1]);

    printf("\nScan complete. %d files scanned.\n", numFiles);

    return 0;
}

void scanFile(char* filename) {
    printf("Scanning file: %s\n", filename);
    FILE* file = fopen(filename, "r");
    char buffer[BUFFER_SIZE];
    while(fgets(buffer, BUFFER_SIZE, file)) {
        if (strstr(buffer, "virus")) {
            printf("Found virus in file %s!\n", filename);
            cleanUp("Infected file found. Exiting...\n");
        }
    }
    fclose(file);
}

int isExecutable(char* filename) {
    char* extension = strrchr(filename, '.');
    return (strcmp(extension, ".exe") == 0) || 
           (strcmp(extension, ".dll") == 0) ||
           (strcmp(extension, ".so") == 0);
}

int scanDir(char* dirName) {
    DIR *dir;
    struct dirent *entry;
    dir = opendir(dirName);
    if (dir == NULL) {
        printf("Error opening directory %s\n", dirName);
        exit(1);
    }
    int numFiles = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char* filename = malloc((strlen(dirName) + strlen(entry->d_name) + 2) * sizeof(char));
        strcpy(filename, dirName);
        strcat(filename, "/");
        strcat(filename, entry->d_name);
        if (entry->d_type == DT_DIR) {
            numFiles += scanDir(filename);
            free(filename);
        } else if (entry->d_type == DT_REG) {
            if (isExecutable(filename)) {
                scanFile(filename);
                numFiles++;
            }
            free(filename);
        }
    }
    closedir(dir);
    return numFiles;
}

void cleanUp(char* message) {
    printf("%s", message);
    exit(1);
}