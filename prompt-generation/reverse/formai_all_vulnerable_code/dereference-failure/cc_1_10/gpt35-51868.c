//FormAI DATASET v1.0 Category: Data recovery tool ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Declare structs to simulate the file system
typedef struct {
    int id;
    char fileName[20];
    char content[100];
} File;

typedef struct {
    int totalFiles;
    File *files;
} FileSystem;

int main() {
    printf("Welcome to the C Data Recovery tool!\n\n");

    // Simulate a corrupted file system
    FileSystem corruptedSystem = {3, malloc(sizeof(File) * 3)};
    corruptedSystem.files[0] = (File) {1, "file1.txt", "Content of file 1"};
    corruptedSystem.files[1] = (File) {2, "file2.txt", "Content of file 2"};
    corruptedSystem.files[2] = (File) {3, "file3.txt", "Content of file 3"};
    
    // Simulate data recovery
    printf("Scanning for recoverable files...\n\n");
    FileSystem recoveredSystem = {0, NULL};
    for (int i = 0; i < corruptedSystem.totalFiles; i++) {
        if (corruptedSystem.files[i].fileName[0] == '*') {
            // File is unrecoverable
            printf("File '%s' is unrecoverable. Skipping...\n", corruptedSystem.files[i].fileName);
        } else {
            // File is recoverable
            printf("Found recoverable file '%s'.\n", corruptedSystem.files[i].fileName);
            if (recoveredSystem.totalFiles == 0) {
                // Add first file to recovered system
                recoveredSystem.totalFiles++;
                recoveredSystem.files = malloc(sizeof(File));
                recoveredSystem.files[0] = corruptedSystem.files[i];
            } else {
                // Check if file with same name already exists in recovered system
                int duplicate = 0;
                for (int j = 0; j < recoveredSystem.totalFiles; j++) {
                    if (strcmp(recoveredSystem.files[j].fileName, corruptedSystem.files[i].fileName) == 0) {
                        duplicate = 1;
                        break;
                    }
                }
                if (duplicate) {
                    printf("File '%s' already exists in recovered system. Skipping...\n", corruptedSystem.files[i].fileName);
                } else {
                    // Add file to recovered system
                    recoveredSystem.totalFiles++;
                    File *newFiles = realloc(recoveredSystem.files, sizeof(File) * recoveredSystem.totalFiles);
                    if (newFiles == NULL) {
                        printf("Error allocating memory. Program terminated.");
                        exit(1);
                    }
                    recoveredSystem.files = newFiles;
                    recoveredSystem.files[recoveredSystem.totalFiles - 1] = corruptedSystem.files[i];
                }
            }
        }
    }

    // Print recovered files
    printf("\nRecoverable files found: %d\n\n", recoveredSystem.totalFiles);
    if (recoveredSystem.totalFiles == 0) {
        printf("No recoverable files found.\n");
    } else {
        printf("Recovered files:\n");
        for (int i = 0; i < recoveredSystem.totalFiles; i++) {
            printf("File %d\n", i+1);
            printf("Name: %s\n", recoveredSystem.files[i].fileName);
            printf("Content: %s\n\n", recoveredSystem.files[i].content);
        }
    }

    // Free memory
    free(corruptedSystem.files);
    free(recoveredSystem.files);

    return 0;
}