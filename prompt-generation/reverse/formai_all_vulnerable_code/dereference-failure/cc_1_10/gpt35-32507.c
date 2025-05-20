//FormAI DATASET v1.0 Category: File system simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define FILENAME_LENGTH 50
#define MAX_FILES 1000
#define FILE_SIZE 1024

typedef struct File {
    char* filename;
    char data[FILE_SIZE];
    int size;
} File;

int fileCount = 0;
File files[MAX_FILES];

// Function prototypes
void listFiles();
bool createFile(char* filename);
bool deleteFile(char* filename);
bool writeFile(char* filename, char* data, int size);
bool readFile(char* filename);

int main() {
    printf("Welcome to the C File System!\n");

    bool running = true;
    char choice;

    while (running) {
        printf("\nPress L to list files, C to create a new file, D to delete a file, W to write to a file, R to read a file, or Q to quit.\n");
        scanf(" %c", &choice);

        switch (choice) {
            case 'L':
            case 'l':
                listFiles();
                break;
            case 'C':
            case 'c': {
                char filename[FILENAME_LENGTH];
                printf("Enter a filename: ");
                scanf("%s", filename);
                if (createFile(filename)) {
                    printf("File %s created successfully.\n", filename);
                } else {
                    printf("Could not create file %s.\n", filename);
                }
                break;
            }
            case 'D':
            case 'd': {
                char filename[FILENAME_LENGTH];
                printf("Enter the name of the file you want to delete: ");
                scanf("%s", filename);
                if (deleteFile(filename)) {
                    printf("File %s deleted successfully.\n", filename);
                } else {
                    printf("Could not delete file %s.\n", filename);
                }
                break;
            }
            case 'W':
            case 'w': {
                char filename[FILENAME_LENGTH];
                printf("Enter the name of the file you want to write to: ");
                scanf("%s", filename);
                char data[FILE_SIZE];
                printf("Enter the data you want to write to the file: ");
                scanf(" %[^\n]s", data);
                int size = strlen(data);
                if (writeFile(filename, data, size)) {
                    printf("Data written to file %s successfully.\n", filename);
                } else {
                    printf("Could not write to file %s.\n", filename);
                }
                break;
            }
            case 'R':
            case 'r': {
                char filename[FILENAME_LENGTH];
                printf("Enter the name of the file you want to read: ");
                scanf("%s", filename);
                if (readFile(filename)) {
                    printf("\n");
                } else {
                    printf("Could not read file %s.\n", filename);
                }
                break;
            }
            case 'Q':
            case 'q':
                running = false;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    printf("Goodbye!\n");

    return 0;
}

void listFiles() {
    printf("\n*** Listing Files ***\n");
    if (fileCount == 0) {
        printf("There are no files.\n");
    } else {
        for (int i = 0; i < fileCount; i++) {
            printf("%d. %s (%d bytes)\n", i + 1, files[i].filename, files[i].size);
        }
    }
}

bool createFile(char* filename) {
    if (fileCount >= MAX_FILES) {
        return false;
    }
    for (int i = 0; i < fileCount; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            return false;
        }
    }
    files[fileCount].filename = malloc(strlen(filename) + 1);
    strcpy(files[fileCount].filename, filename);
    files[fileCount].size = 0;
    fileCount++;
    return true;
}

bool deleteFile(char* filename) {
    for (int i = 0; i < fileCount; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            free(files[i].filename);
            for (int j = i + 1; j < fileCount; j++) {
                files[j - 1] = files[j];
            }
            fileCount--;
            return true;
        }
    }
    return false;
}

bool writeFile(char* filename, char* data, int size) {
    for (int i = 0; i < fileCount; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            if (size > FILE_SIZE) {
                return false;
            }
            strncpy(files[i].data, data, size);
            files[i].size = size;
            return true;
        }
    }
    return false;
}

bool readFile(char* filename) {
    for (int i = 0; i < fileCount; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            printf("%s\n", files[i].data);
            return true;
        }
    }
    return false;
}