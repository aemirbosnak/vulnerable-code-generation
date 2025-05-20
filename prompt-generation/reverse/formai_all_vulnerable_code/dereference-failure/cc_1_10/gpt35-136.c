//FormAI DATASET v1.0 Category: File Backup System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to backup a file
void backupFile(char* file) {
    // Open the original file for reading
    FILE* originalFile = fopen(file, "r");
    if (originalFile == NULL) {
        printf("Error: could not open file %s\n", file);
        return;
    }

    // Create a backup file with the same name but with a ".bak" extension
    char* backupFilename = malloc(strlen(file) + 4);
    strcpy(backupFilename, file);
    strcat(backupFilename, ".bak");
    FILE* backupFile = fopen(backupFilename, "w");
    if (backupFile == NULL) {
        printf("Error: could not create backup file %s\n", backupFilename);
        fclose(originalFile);
        free(backupFilename);
        return;
    }

    // Copy the contents of the original file to the backup file
    int c;
    while ((c = fgetc(originalFile)) != EOF) {
        fputc(c, backupFile);
    }

    // Close the files and free memory
    fclose(originalFile);
    fclose(backupFile);
    free(backupFilename);

    printf("Successfully backed up file %s\n", file);
}

int main(int argc, char** argv) {
    // Make sure a filename is given as argument
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Backup the file
    backupFile(argv[1]);

    return 0;
}