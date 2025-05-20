//FormAI DATASET v1.0 Category: File Backup System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void copyFile(FILE *sourceFile, FILE *targetFile) {
    char buffer[BUFFER_SIZE];
    size_t numRead;
    while ((numRead = fread(buffer, sizeof(char), BUFFER_SIZE, sourceFile)) > 0) {
        fwrite(buffer, sizeof(char), numRead, targetFile);
    }
}

int main() {
    char sourcePath[100];
    char targetPath[100];
    char choice;

    printf("=== C File Backup System ===\n");
    printf("Enter the path of the file to be backed up: ");
    scanf("%s", sourcePath);
    printf("Enter the path where the backup should be stored: ");
    scanf("%s", targetPath);
    
    FILE *sourceFile = fopen(sourcePath, "rb");
    FILE *targetFile = fopen(targetPath, "wb");

    if (sourceFile == NULL) {
        printf("Error: could not open file %s", sourcePath);
        exit(EXIT_FAILURE);
    }

    if (targetFile == NULL) {
        printf("Error: could not open file %s", targetPath);
        exit(EXIT_FAILURE);
    }

    copyFile(sourceFile, targetFile);

    fclose(sourceFile);
    fclose(targetFile);

    printf("Backup created successfully!\n");

    while (1) {
        printf("Do you want to view the backup contents? y/n ");
        scanf(" %c", &choice);

        if (choice == 'y') {
            /* We'll display the backup contents using cat, which may not work on all systems */
            char viewCommand[200];
            sprintf(viewCommand, "cat %s", targetPath);
            system(viewCommand);
            break;
        } else if (choice == 'n') {
            break;
        } else {
            printf("Invalid choice! Try again.");
        }
    }

    return 0;
}