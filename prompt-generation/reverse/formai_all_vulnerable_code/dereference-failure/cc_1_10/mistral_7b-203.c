//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_FILENAME_LENGTH 256
#define BUFFER_SIZE 4096

void generateBackupFileName(char* baseFileName, char* backupSuffix, char backupFileName[MAX_FILENAME_LENGTH]);
void copyFile(char* sourceFileName, char* destinationFileName);
int main(int argc, char* argv[]) {
    if (argc < 2) { // Check if the correct number of arguments are provided
        printf("Usage: %s <file_to_be_backed_up>\n", argv[0]);
        return 1;
    }

    char baseFileName[MAX_FILENAME_LENGTH];
    strcpy(baseFileName, argv[1]); // Copy the base file name to a local variable

    char backupSuffix[8] = "_backup"; // Define the backup suffix
    char backupFileName[MAX_FILENAME_LENGTH];

    generateBackupFileName(baseFileName, backupSuffix, backupFileName); // Generate the backup file name

    printf("Generating backup of %s to %s...\n", baseFileName, backupFileName);
    copyFile(argv[1], backupFileName); // Call the copyFile function to copy the original file to the backup file

    return 0;
}

void generateBackupFileName(char* baseFileName, char* backupSuffix, char backupFileName[MAX_FILENAME_LENGTH]) {
    int baseFileNameLength = strlen(baseFileName);
    int backupFileNameLength = strlen(backupSuffix);

    strncpy(backupFileName, baseFileName, baseFileNameLength); // Copy the base file name to the backup file name
    strncat(backupFileName, backupSuffix, backupFileNameLength); // Append the backup suffix to the backup file name
}

void copyFile(char* sourceFileName, char* destinationFileName) {
    int sourceFileFD = open(sourceFileName, O_RDONLY); // Open the source file in read-only mode

    if (sourceFileFD < 0) {
        perror("Error opening source file");
        return;
    }

    int destinationFileFD = open(destinationFileName, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); // Open the destination file in write-only mode, creating it if it doesn't exist and truncating it if it does

    if (destinationFileFD < 0) {
        perror("Error opening destination file");
        close(sourceFileFD);
        return;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    while ((bytesRead = read(sourceFileFD, buffer, BUFFER_SIZE)) > 0) {
        write(destinationFileFD, buffer, bytesRead); // Write the data from the source file to the destination file
    }

    close(sourceFileFD);
    close(destinationFileFD);
}