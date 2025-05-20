//FormAI DATASET v1.0 Category: File Backup System ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void backupFile(char* fileName);

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Error: Invalid number of arguments!\n");
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    backupFile(argv[1]);
    return 0;
}

void backupFile(char* fileName) {
    // Open the original file for reading
    FILE* originalFile = fopen(fileName, "r");
    if (originalFile == NULL) {
        printf("Error: Could not open file %s!\n", fileName);
        return;
    }

    // Construct the backup file name
    char* backupFileName = malloc(strlen(fileName) + 5);
    strcpy(backupFileName, fileName);
    strcat(backupFileName, ".bak");

    // Open the backup file for writing
    FILE* backupFile = fopen(backupFileName, "w");
    if (backupFile == NULL) {
        printf("Error: Could not create backup file %s!\n", backupFileName);
        fclose(originalFile);
        free(backupFileName);
        return;
    }

    // Copy the contents of the original file to the backup file
    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), originalFile)) > 0) {
        fwrite(buffer, 1, bytesRead, backupFile);
    }

    // Close the files and free the memory
    fclose(originalFile);
    fclose(backupFile);
    free(backupFileName);

    printf("Backup successfully created for file: %s\n", fileName);
}