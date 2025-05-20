//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: backup <source file> <destination file>\n");
        return 1;
    }
    
    char *sourceFile = argv[1];
    char *destinationFile = argv[2];
    
    FILE *sourceFilePtr = fopen(sourceFile, "rb");
    FILE *destinationFilePtr = fopen(destinationFile, "wb");
    
    if (sourceFilePtr == NULL || destinationFilePtr == NULL) {
        printf("Error opening files for reading or writing.\n");
        return 1;
    }
    
    fseek(sourceFilePtr, 0, SEEK_END);
    long fileSize = ftell(sourceFilePtr);
    rewind(sourceFilePtr);
    
    char *buffer = malloc(fileSize + 1);
    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    long bytesRead = fread(buffer, 1, fileSize, sourceFilePtr);
    if (bytesRead!= fileSize) {
        printf("Error reading file.\n");
        fclose(sourceFilePtr);
        free(buffer);
        return 1;
    }
    
    fclose(sourceFilePtr);
    
    fwrite(buffer, 1, fileSize, destinationFilePtr);
    fclose(destinationFilePtr);
    
    free(buffer);
    
    printf("Backup complete.\n");
    return 0;
}