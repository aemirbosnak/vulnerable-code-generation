//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to recursively backup a file
void backupFile(const char* filePath, const char* backupPath) {
    // Open the source file for reading
    FILE* srcFile = fopen(filePath, "r");
    
    // Check if the source file exists
    if (srcFile == NULL) {
        printf("Source file does not exist!\n");
        return;
    }
    
    // Open the destination file for writing
    FILE* dstFile = fopen(backupPath, "w");
    
    // Check if the destination file already exists
    if (dstFile!= NULL) {
        printf("Destination file already exists!\n");
        return;
    }
    
    // Recursively copy the file
    char buffer[BUFSIZ];
    while (fgets(buffer, sizeof(buffer), srcFile)) {
        fputs(buffer, dstFile);
    }
    
    // Close the files
    fclose(srcFile);
    fclose(dstFile);
    
    // Call the function recursively on all subdirectories
    if (strcmp(filePath, ".")!= 0 && strcmp(filePath, "..")!= 0) {
        char* dirPath = strdup(filePath);
        char* currDir = dirPath;
        while (currDir!= NULL) {
            backupFile(currDir, backupPath);
            char* nextDir = strtok(NULL, "/");
            free(currDir);
            currDir = nextDir;
        }
        free(dirPath);
    }
}

// Main function
int main() {
    const char* filePath = "C:\\Users\\User\\Desktop\\TestFile.txt";
    const char* backupPath = "C:\\Users\\User\\Desktop\\Backup\\TestFile.txt";
    
    // Call the backup function
    backupFile(filePath, backupPath);
    
    return 0;
}