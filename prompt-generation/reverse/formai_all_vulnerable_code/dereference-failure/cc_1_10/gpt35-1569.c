//FormAI DATASET v1.0 Category: File Synchronizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PATH_LENGTH 256
#define MAX_BUFFER_SIZE 1024

// Function prototypes
bool sync_file(char *file_path);
bool compare_files(FILE* file1, FILE* file2);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./sync <file_path>\n");
        return 1;
    }

    char file_path[MAX_PATH_LENGTH];
    strncpy(file_path, argv[1], MAX_PATH_LENGTH);

    if (sync_file(file_path)) {
        printf("File synchronization successful!\n");
    } else {
        printf("File synchronization failed!\n");
    }

    return 0;
}

bool sync_file(char *file_path) {
    FILE *original_file = fopen(file_path, "r");
    if (original_file == NULL) {
        printf("ERROR: Could not open file at path %s\n", file_path);
        return false;
    }

    char synced_file_path[MAX_PATH_LENGTH];
    strncpy(synced_file_path, file_path, MAX_PATH_LENGTH);
    strcat(synced_file_path, ".sync");

    FILE *synced_file = fopen(synced_file_path, "w");
    if (synced_file == NULL) {
        printf("ERROR: Could not create synced file at path %s\n", synced_file_path);
        fclose(original_file);
        return false;
    }

    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, MAX_BUFFER_SIZE, original_file)) {
        fputs(buffer, synced_file);
    }

    fclose(original_file);
    fclose(synced_file);

    // Check if files are identical
    FILE *file1 = fopen(file_path, "r");
    FILE *file2 = fopen(synced_file_path, "r");

    if (compare_files(file1, file2)) {
        printf("Files are identical!\n");
        return true;
    } else {
        printf("Files are different!\n");
        return false;
    }
}

bool compare_files(FILE* file1, FILE* file2) {
    int char1, char2;
    do {
        char1 = fgetc(file1);
        char2 = fgetc(file2);
        if (char1 != char2) {
            return false;
        }
    } while (char1 != EOF && char2 != EOF);

    return true;
}