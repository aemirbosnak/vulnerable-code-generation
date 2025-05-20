//FormAI DATASET v1.0 Category: File system simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Defining the maximum number of files that can be stored and the maximum
 * file name length */
#define MAX_FILES 100
#define MAX_NAME_LENGTH 100

/* Struct to represent a file */
typedef struct File {
    char* name;
    int size;
    char* content;
} File;

/* Global array to hold all files */
File files[MAX_FILES];
int num_files = 0;

/* Function to create a new file */
void createFile(char* name, int size, char* content) {
    if (num_files >= MAX_FILES) {
        printf("Maximum number of files reached. Could not create new file.\n");
        return;
    }
    
    /* Allocate space for the new file's name and content */
    char* new_name = (char*) malloc(MAX_NAME_LENGTH * sizeof(char));
    char* new_content = (char*) malloc(size * sizeof(char));
    
    /* Copy the name and content into the newly allocated space */
    strcpy(new_name, name);
    strcpy(new_content, content);
    
    /* Create the new file and add it to the array */
    File new_file = { .name = new_name, .size = size, .content = new_content };
    files[num_files] = new_file;
    num_files++;
}

/* Function to delete a file */
void deleteFile(char* name) {
    int index = -1;
    
    /* Find the index of the file with the given name */
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    
    /* If the file was found, delete it */
    if (index != -1) {
        free(files[index].name);
        free(files[index].content);
        for (int i = index; i < num_files - 1; i++) {
            files[i] = files[i+1];
        }
        num_files--;
        printf("File %s deleted.\n", name);
    } else {
        printf("File %s not found.\n", name);
    }
}

/* Function to list all files */
void listFiles() {
    printf("Files:\n");
    for (int i = 0; i < num_files; i++) {
        printf("  %s (%d bytes)\n", files[i].name, files[i].size);
    }
}

/* Main function */
int main() {
    /* Example usage */
    createFile("file1.txt", 10, "Hello, world!");
    createFile("file2.txt", 5, "12345");
    listFiles();
    deleteFile("file1.txt");
    listFiles();
    
    return 0;
}