//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_NAME_LENGTH 100

void createBackup(char *fileName) {
    int sourceFileFD, targetFileFD;
    char targetFileName[MAX_FILE_NAME_LENGTH];
    struct stat fileStat;

    // Open the source file for reading
    sourceFileFD = open(fileName, O_RDONLY);
    if (sourceFileFD < 0) {
        perror("Error opening source file.");
        return;
    }

    // Create the target file name with the '.bkp' extension
    strcpy(targetFileName, fileName);
    strcat(targetFileName, ".bkp");

    // Open the target file for writing
    targetFileFD = open(targetFileName, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (targetFileFD < 0) {
        perror("Error opening target file.");
        close(sourceFileFD);
        return;
    }

    // Read the source file and write to the target file
    ssize_t bytesRead;
    char buffer[1024];
    while ((bytesRead = read(sourceFileFD, buffer, sizeof(buffer))) > 0) {
        write(targetFileFD, buffer, bytesRead);
    }

    // Close both files
    close(sourceFileFD);
    close(targetFileFD);

    printf("Created backup file: %s\n", targetFileName);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    // Call the createBackup function with the given file name
    createBackup(argv[1]);

    return 0;
}