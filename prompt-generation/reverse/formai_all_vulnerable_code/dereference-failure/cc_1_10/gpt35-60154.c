//FormAI DATASET v1.0 Category: File Backup System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare file structures
typedef struct {
    char fileName[50];
    char fileLocation[100];
} File;

typedef struct {
    File* files;
    int numFiles;
} Backup;

// Declare functions
void initializeBackup(Backup*);
void addFile(Backup*, char*, char*);
void removeFile(Backup*, char*);
void displayFiles(Backup*);
void saveBackup(Backup*);
void loadBackup(Backup*);

// Main function
int main() {
    // Introduction
    printf("Welcome to Sherlock Holmes' File Backup System!\n\n");
    
    // Initialize a new backup
    Backup backup;
    initializeBackup(&backup);
    
    // Display the current files in the backup
    printf("Here are the current files in the backup:\n");
    displayFiles(&backup);
    printf("\n");
    
    // Add a new file to the backup
    printf("Let's add a new file to the backup.\n");
    char fileName[50];
    char fileLocation[100];
    printf("Enter the filename: ");
    scanf("%s", fileName);
    printf("Enter the file location: ");
    scanf("%s", fileLocation);
    addFile(&backup, fileName, fileLocation);
    printf("The file has been added to the backup.\n\n");
    
    // Display the updated files in the backup
    printf("Here are the updated files in the backup:\n");
    displayFiles(&backup);
    printf("\n");
    
    // Remove a file from the backup
    printf("Now let's remove a file from the backup.\n");
    printf("Enter the filename: ");
    scanf("%s", fileName);
    removeFile(&backup, fileName);
    printf("The file has been removed from the backup.\n\n");
    
    // Display the updated files in the backup
    printf("Here are the updated files in the backup:\n");
    displayFiles(&backup);
    printf("\n");
    
    // Save the backup to a file
    saveBackup(&backup);
    
    // Load a backup from a file
    Backup newBackup;
    printf("Let's load a new backup from a file.\n");
    loadBackup(&newBackup);
    printf("Here are the files in the new backup:\n");
    displayFiles(&newBackup);
    printf("\n");
    
    // Goodbye message
    printf("Thank you for using Sherlock Holmes' File Backup System!\n");
    
    return 0;
}

// Initialize a new backup
void initializeBackup(Backup* backup) {
    backup->files = NULL;
    backup->numFiles = 0;
}

// Add a file to the backup
void addFile(Backup* backup, char* fileName, char* fileLocation) {
    // Create a new file structure
    File* newFile = (File*) malloc(sizeof(File));
    strcpy(newFile->fileName, fileName);
    strcpy(newFile->fileLocation, fileLocation);
    
    // Allocate memory for the new file in the backup
    if (backup->files == NULL) {
        backup->files = (File*) malloc(sizeof(File));
    }
    else {
        backup->files = (File*) realloc(backup->files, (backup->numFiles + 1) * sizeof(File));
    }
    
    // Add the new file to the backup
    backup->files[backup->numFiles] = *newFile;
    backup->numFiles++;
}

// Remove a file from the backup
void removeFile(Backup* backup, char* fileName) {
    int index = -1;
    // Find the index of the file to remove
    for (int i = 0; i < backup->numFiles; i++) {
        if (strcmp(backup->files[i].fileName, fileName) == 0) {
            index = i;
            break;
        }
    }
    // If the file is found, remove it from the backup
    if (index != -1) {
        for (int i = index; i < backup->numFiles - 1; i++) {
            backup->files[i] = backup->files[i+1];
        }
        backup->numFiles--;
        backup->files = (File*) realloc(backup->files, backup->numFiles * sizeof(File));
        printf("The file has been successfully removed from the backup.\n");
    }
    // If the file is not found, display an error message
    else {
        printf("The file \"%s\" is not in the backup.\n", fileName);
    }
}

// Display the files in the backup
void displayFiles(Backup* backup) {
    if (backup->numFiles == 0) {
        printf("The backup is empty.\n");
    }
    else {
        for (int i = 0; i < backup->numFiles; i++) {
            printf("File %d:\n", i+1);
            printf("Filename: %s\n", backup->files[i].fileName);
            printf("Location: %s\n", backup->files[i].fileLocation);
        }
    }
}

// Save the backup to a file
void saveBackup(Backup* backup) {
    FILE* file = fopen("backup.dat", "wb");
    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
    }
    else {
        fwrite(&(backup->numFiles), sizeof(int), 1, file);
        for (int i = 0; i < backup->numFiles; i++) {
            fwrite(&(backup->files[i]), sizeof(File), 1, file);
        }
        fclose(file);
        printf("The backup has been successfully saved to file.\n");
    }
}

// Load a backup from a file
void loadBackup(Backup* backup) {
    FILE* file = fopen("backup.dat", "rb");
    if (file == NULL) {
        printf("Error: Unable to open file for reading.\n");
    }
    else {
        fread(&(backup->numFiles), sizeof(int), 1, file);
        backup->files = (File*) malloc(backup->numFiles * sizeof(File));
        for (int i = 0; i < backup->numFiles; i++) {
            fread(&(backup->files[i]), sizeof(File), 1, file);
        }
        fclose(file);
        printf("The backup has been successfully loaded from file.\n");
    }
}