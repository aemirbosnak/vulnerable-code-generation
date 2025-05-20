//FormAI DATASET v1.0 Category: File system simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10 // maximum number of files in the file system
#define MAX_FILE_NAME 20 // maximum length of file names
#define MAX_FILE_SIZE 1024 // maximum file size in bytes

// The File struct
struct File {
    char* name;
    char* contents;
    int size;
};

// The File System struct
struct FileSystem {
    struct File files[MAX_FILES];
    int numFiles;
};

// Function to create a new file
void createFile(struct FileSystem* fs, char* name, char* contents, int size) {

    // Check if file with the same name already exists
    for(int i = 0; i < fs->numFiles; i++) {
        if(strcmp(fs->files[i].name,name) == 0){
            printf("Error: File already exists.\n");
            return;
        }
    }

    // Check if maximum number of files has been reached
    if(fs->numFiles == MAX_FILES) {
        printf("Error: File System is full.\n");
        return;
    }

    // Create new File struct
    struct File f;
    f.name = (char*) malloc(MAX_FILE_NAME);
    f.contents = (char*) malloc(MAX_FILE_SIZE * sizeof(char));

    // Copy name and contents to new File struct
    strcpy(f.name,name);
    strcpy(f.contents, contents);

    // Set size of new File struct
    f.size = size;

    // Add new file to File System
    fs->files[fs->numFiles] = f;
    fs->numFiles++;

    printf("File '%s' created.\n", name);
}

// Function to read a file
void readFile(struct FileSystem* fs, char* name) {

    // Check if file exists
    int found = 0;
    for(int i = 0; i < fs->numFiles; i++) {
        if(strcmp(fs->files[i].name,name) == 0) {
            printf("File '%s' contents:\n%s\n", name, fs->files[i].contents);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Error: File '%s' not found.\n", name);
        return;
    }
}

// Function to delete a file
void deleteFile(struct FileSystem* fs, char* name) {

    // Check if file exists
    int found = 0;
    for(int i = 0; i < fs->numFiles; i++) {
        if(strcmp(fs->files[i].name,name) == 0) {
            found = 1;

            // Free memory
            free(fs->files[i].name);
            free(fs->files[i].contents);

            // Shift all files to the left to fill the gap
            for(int j = i; j < fs->numFiles - 1; j++) {
                fs->files[j] = fs->files[j+1];
            }
            fs->numFiles--;
            break;
        }
    }

    // If file not found, print error message
    if(!found) {
        printf("Error: File '%s' not found.\n", name);
    } else {
        printf("File '%s' deleted.\n", name);
    }
}

// Main function
int main() {
    struct FileSystem fs;
    fs.numFiles = 0;

    createFile(&fs, "myfile.txt", "Hello World!", 12);
    readFile(&fs, "myfile.txt");
    createFile(&fs, "myfile.txt", "New contents", 12);
    deleteFile(&fs, "myfile.txt");
    readFile(&fs, "myfile.txt");
    createFile(&fs, "myotherfile.txt", "Some more contents", 19);
    createFile(&fs, "file3.txt", "Third file", 10);
    deleteFile(&fs, "file2.txt");
    createFile(&fs, "file4.txt", "Fourth file", 11);

    return 0;
}