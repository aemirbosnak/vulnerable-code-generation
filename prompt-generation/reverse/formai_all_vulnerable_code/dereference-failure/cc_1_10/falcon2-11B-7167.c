//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Define the path to the directory to be backed up
    char* directory = "/path/to/directory";
    
    // Define the path to the backup directory
    char* backupDirectory = "/path/to/backup/directory";
    
    // Define the name of the backup file
    char* backupFileName = "backup.tar.gz";
    
    // Create the backup directory if it doesn't exist
    if (mkdir(backupDirectory, 0777) == -1) {
        perror("mkdir");
        exit(EXIT_FAILURE);
    }
    
    // Create the backup file
    FILE* backupFile = fopen(backupFileName, "wb");
    if (backupFile == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    
    // Backup the files
    char* files[] = {"file1.txt", "file2.txt", "file3.txt"};
    for (int i = 0; i < 3; i++) {
        char filePath[100];
        sprintf(filePath, "%s/%s", directory, files[i]);
        FILE* file = fopen(filePath, "rb");
        if (file == NULL) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }
        fseek(file, 0, SEEK_END);
        int fileSize = ftell(file);
        rewind(file);
        fwrite(file, 1, fileSize, backupFile);
        fclose(file);
    }
    
    // Close the backup file
    fclose(backupFile);
    
    // Delete the original files
    for (int i = 0; i < 3; i++) {
        char filePath[100];
        sprintf(filePath, "%s/%s", directory, files[i]);
        remove(filePath);
    }
    
    // Clean up the backup directory
    if (rmdir(backupDirectory) == -1) {
        perror("rmdir");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}