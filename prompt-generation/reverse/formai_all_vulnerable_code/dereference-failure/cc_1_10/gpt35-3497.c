//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

long long int calculateFileSize(char *path);
void displayFolders(char *path);
void displayFiles(char *path);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        exit(1);
    }
    char *path = argv[1];
    displayFolders(path);
    displayFiles(path);
    return 0;
}

void displayFolders(char *path) {
    printf("\nFolders:\n");
    DIR *directory = opendir(path);
    if (directory == NULL) {
        printf("Unable to open directory %s\n", path);
        exit(1);
    }
    struct dirent *entry;
    while ((entry = readdir(directory)) != NULL) {
        if ((entry->d_type == DT_DIR) && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char *subdirectory = malloc(strlen(path) + strlen(entry->d_name) + 2);
            sprintf(subdirectory, "%s/%s", path, entry->d_name);
            long long int size = calculateFileSize(subdirectory);
            printf("%s - %lld bytes\n", subdirectory, size);
            displayFolders(subdirectory);
            free(subdirectory);
        }
    }
    closedir(directory);
}

void displayFiles(char *path) {
    printf("\nFiles:\n");
    DIR *directory = opendir(path);
    if (directory == NULL) {
        printf("Unable to open directory %s\n", path);
        exit(1);
    }
    struct dirent *entry;
    while ((entry = readdir(directory)) != NULL) {
        if ((entry->d_type == DT_REG)) {
            char *filename = malloc(strlen(path) + strlen(entry->d_name) + 2);
            sprintf(filename, "%s/%s", path, entry->d_name);
            long long int size = calculateFileSize(filename);
            printf("%s - %lld bytes\n", filename, size);
            free(filename);
        }
    }
    closedir(directory);
}

long long int calculateFileSize(char *path) {
    struct stat fileStat;
    if (stat(path, &fileStat) < 0) {
        printf("Unable to stat file %s\n", path);
        exit(1);
    }
    return (long long int)fileStat.st_size;
}