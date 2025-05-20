//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH 512
#define FILE_NAME_LENGTH 256

typedef struct {
    char name[FILE_NAME_LENGTH];
    long size;  // in bytes
} FileData;

typedef struct Node {
    FileData fileData;
    struct Node *next;
} Node;

Node *head = NULL;

void addFileToList(char *fileName, long fileSize) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->fileData.name, fileName);
    newNode->fileData.size = fileSize;
    newNode->next = head;
    head = newNode;
}

void freeFileList() {
    Node *current = head;
    Node *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

void printFileList() {
    Node *current = head;
    printf("\nList of files:\n");
    while (current != NULL) {
        printf("%s - %ld bytes\n", current->fileData.name, current->fileData.size);
        current = current->next;
    }
}

long getFileSize(const char *filePath) {
    FILE *file = fopen(filePath, "rb");  // Open file to read in binary mode
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }
    fseek(file, 0, SEEK_END);  // Move to the end of the file
    long size = ftell(file);    // Get the size of the file
    fclose(file);               // Close the file
    return size;
}

void analyzeDirectory(const char *path) {
    struct dirent *dirEntry;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((dirEntry = readdir(dir)) != NULL) {
        if (strcmp(dirEntry->d_name, ".") != 0 && strcmp(dirEntry->d_name, "..") != 0) {
            char fullPath[MAX_PATH];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", path, dirEntry->d_name);

            if (dirEntry->d_type == DT_REG) {  // If it's a regular file
                long fileSize = getFileSize(fullPath);
                if (fileSize != -1) {
                    addFileToList(fullPath, fileSize);
                }
            } else if (dirEntry->d_type == DT_DIR) {  // If it's a directory, recurse into it
                analyzeDirectory(fullPath);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    char *directoryPath = argv[1];
    printf("Analyzing directory: %s\n", directoryPath);
    analyzeDirectory(directoryPath);
    printFileList();

    // Cleanup
    freeFileList();

    return 0;
}