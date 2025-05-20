//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold file information
struct FileInfo {
    char* fileName;
    int fileSize;
};

// Function to compare two file info structures based on file size
int compareFileInfo(const void* a, const void* b) {
    const struct FileInfo* info1 = (const struct FileInfo*)a;
    const struct FileInfo* info2 = (const struct FileInfo*)b;
    return info1->fileSize - info2->fileSize;
}

// Function to check if two files are identical
int isFileIdentical(const char* file1, const char* file2) {
    // Open both files for reading
    FILE* fp1 = fopen(file1, "rb");
    FILE* fp2 = fopen(file2, "rb");
    if (fp1 == NULL || fp2 == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", file1);
        fprintf(stderr, "Failed to open file: %s\n", file2);
        return -1;
    }
    
    // Read the file size of both files
    fseek(fp1, 0, SEEK_END);
    int fileSize1 = ftell(fp1);
    rewind(fp1);
    fseek(fp2, 0, SEEK_END);
    int fileSize2 = ftell(fp2);
    rewind(fp2);
    
    // Compare file sizes
    if (fileSize1!= fileSize2) {
        fclose(fp1);
        fclose(fp2);
        return 0; // Files are not identical
    }
    
    // Read the entire contents of both files into memory
    char buffer[10000];
    int bytesRead1 = fread(buffer, 1, sizeof(buffer), fp1);
    int bytesRead2 = fread(buffer, 1, sizeof(buffer), fp2);
    
    // Compare the contents of both files
    for (int i = 0; i < bytesRead1; i++) {
        if (buffer[i]!= buffer[bytesRead1 - i - 1]) {
            fclose(fp1);
            fclose(fp2);
            return 0; // Files are not identical
        }
    }
    
    // Close the files
    fclose(fp1);
    fclose(fp2);
    return 1; // Files are identical
}

int main() {
    // Prompt the user for the source and destination file names
    printf("Enter the source file name: ");
    char sourceFile[100];
    scanf("%s", sourceFile);
    printf("Enter the destination file name: ");
    char destinationFile[100];
    scanf("%s", destinationFile);
    
    // Check if the files exist
    FILE* fp1 = fopen(sourceFile, "rb");
    FILE* fp2 = fopen(destinationFile, "rb");
    if (fp1 == NULL || fp2 == NULL) {
        fprintf(stderr, "Source file: %s\n", sourceFile);
        fprintf(stderr, "Destination file: %s\n", destinationFile);
        return -1;
    }
    
    // Create a structure to hold file information
    struct FileInfo fileInfo1 = {sourceFile, ftell(fp1)};
    struct FileInfo fileInfo2 = {destinationFile, ftell(fp2)};
    
    // Sort the file info structures based on file size
    qsort(&fileInfo1, 1, sizeof(struct FileInfo), compareFileInfo);
    qsort(&fileInfo2, 1, sizeof(struct FileInfo), compareFileInfo);
    
    // Compare the files
    int identical = isFileIdentical(sourceFile, destinationFile);
    
    // Print the result
    if (identical == 1) {
        printf("Files are identical.\n");
    } else if (identical == 0) {
        printf("Files are not identical.\n");
    } else {
        printf("An error occurred while comparing the files.\n");
    }
    
    // Close the files
    fclose(fp1);
    fclose(fp2);
    
    return 0;
}