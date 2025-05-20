//FormAI DATASET v1.0 Category: Data recovery tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold file information
typedef struct {
    char name[100];
    int size;
} File;

// Define a function to read the file information from a binary file
void readFile(char* filename, File* files, int* count) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    
    int numFiles;
    fread(&numFiles, sizeof(int), 1, fp); // Read number of files
    
    *count = numFiles;
    files = (File*)malloc(sizeof(File) * numFiles); // Allocate memory for file information
    
    fread(files, sizeof(File), numFiles, fp); // Read file information
    
    fclose(fp);
}

// Define a function to print the file information
void printFiles(File* files, int count) {
    printf("Number of files: %d\n", count);
    for (int i = 0; i < count; i++) {
        printf("File %d\n", i+1);
        printf("Name: %s\n", files[i].name);
        printf("Size: %d\n", files[i].size);
    }
}

int main() {
    // Read the file information from the binary file
    char* filename = "files.dat";
    File* files;
    int count;
    readFile(filename, files, &count);
    
    // Print the file information
    printFiles(files, count);
    
    // Free the memory allocated for the file information
    free(files);
    
    return 0;
}