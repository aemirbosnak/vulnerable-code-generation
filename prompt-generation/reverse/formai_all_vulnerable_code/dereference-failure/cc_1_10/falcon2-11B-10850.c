//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for representing a file
typedef struct {
    char name[100];
    int size;
    char* data;
} File;

// Function to create a new file
File* createFile(char* name, int size) {
    File* newFile = malloc(sizeof(File));
    strcpy(newFile->name, name);
    newFile->size = size;
    newFile->data = NULL;
    return newFile;
}

// Function to open an existing file
File* openFile(char* name) {
    File* file = malloc(sizeof(File));
    strcpy(file->name, name);
    file->size = 0;
    file->data = NULL;
    return file;
}

// Function to close a file
void closeFile(File* file) {
    free(file->data);
    free(file);
}

// Function to write to a file
void writeToFile(File* file, char* data, int size) {
    if (file->size + size > 0) {
        char* newData = realloc(file->data, file->size + size);
        if (newData!= NULL) {
            memcpy(newData + file->size, data, size);
            file->data = newData;
            file->size += size;
        } else {
            printf("Error: Unable to allocate memory for file data.\n");
            closeFile(file);
        }
    } else {
        file->data = malloc(size);
        memcpy(file->data, data, size);
        file->size = size;
    }
}

// Function to read from a file
char* readFromFile(File* file, int size) {
    char* data = malloc(size);
    if (file->size > 0 && file->size >= size) {
        memcpy(data, file->data, size);
        return data;
    } else {
        printf("Error: Unable to read from file.\n");
        closeFile(file);
        return NULL;
    }
}

// Function to delete a file
void deleteFile(File* file) {
    free(file->data);
    free(file);
}

int main() {
    // Create a new file
    File* file1 = createFile("file1.txt", 100);
    
    // Open an existing file
    File* file2 = openFile("file2.txt");
    
    // Write to file1
    writeToFile(file1, "Hello, world!", 13);
    
    // Read from file2
    char* data = readFromFile(file2, 20);
    if (data!= NULL) {
        printf("Data from file2: %s\n", data);
        free(data);
    }
    
    // Close both files
    closeFile(file1);
    closeFile(file2);
    
    // Delete file1
    deleteFile(file1);
    
    return 0;
}