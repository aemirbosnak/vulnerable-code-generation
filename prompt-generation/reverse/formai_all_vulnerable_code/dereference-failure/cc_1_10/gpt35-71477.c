//FormAI DATASET v1.0 Category: File Backup System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BUFFER_SIZE 1024

void printSuccessMessage(char* fileName){
    printf("File %s has been successfully backed up!\n", fileName);
}

void printErrorMessage(char* fileName){
    printf("Error: Could not backup file %s.\n", fileName);
}

int main(){

    // Get current time
    time_t currentTime;
    time(&currentTime);

    // Initialize random seed
    srand((unsigned) time(&currentTime));

    // Generate random backup ID
    int backupID = rand() % 10000;

    // Build backup filename
    char* fileName = "main.c";
    char* backupFolder = "backup";
    char* backupFileExtension = ".bak";
    char backupFileName[BUFFER_SIZE];
    sprintf(backupFileName, "%s/%s-%d-%ld%s", backupFolder, fileName, backupID, currentTime, backupFileExtension);

    // Attempt to open file for reading
    FILE* originalFile = fopen(fileName, "r");
    if(originalFile == NULL){
        printErrorMessage(fileName);
        return -1;
    }

    // Attempt to create and open backup file for writing
    FILE* backupFile = fopen(backupFileName, "w");
    if(backupFile == NULL){
        printErrorMessage(backupFileName);
        return -1;
    }

    // Copy contents of original file to backup file
    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    while((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, originalFile)) > 0){
        fwrite(buffer, sizeof(char), bytesRead, backupFile);
    }

    // Close files
    fclose(originalFile);
    fclose(backupFile);

    // Print success message
    printSuccessMessage(fileName);

    return 0;
}