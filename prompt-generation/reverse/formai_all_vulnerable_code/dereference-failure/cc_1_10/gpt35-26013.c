//FormAI DATASET v1.0 Category: File system simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCKSIZE 1024
#define MAXFILENAME 256
#define MAXDATASIZE 512

typedef struct file {
    char name[MAXFILENAME];
    int size;
    char data[MAXDATASIZE];
    struct file *next;
} file_t;

file_t *fs; // file system root

/* Function prototypes */
void create(char *name, char *data);
void read(char *name);
void write(char *name, char *data);
void delete(char *name);
void display();

/* Main function */
int main(){
    fs = NULL; // Initialize file system root to NULL

    create("file1", "Hello World!");
    create("file2", "This is a sample");
    write("file2", "data block");
    read("file1");
    read("file2");
    display();
    delete("file1");
    display();

    return 0;
}

/* Create a new file */
void create(char *name, char *data){
    file_t *new_file = (file_t*)malloc(sizeof(file_t)); // Allocate memory for new file

    // Copy file's name and data
    strcpy(new_file->name, name);
    strcpy(new_file->data, data);

    // Set file's size
    new_file->size = strlen(new_file->data);

    // Add file to file system
    new_file->next = fs;
    fs = new_file;

    printf("File '%s' created successfully.\n", name);
}

/* Read an existing file */
void read(char *name){
    file_t *current_file = fs; // Start at the beginning of the file system

    while(current_file != NULL){ // Traverse the file system
        if(strcmp(current_file->name, name) == 0){ // Check if current file is the one we're looking for
            printf("%s\n", current_file->data);
            return;
        }
        current_file = current_file->next;
    }

    printf("File '%s' not found.\n", name);
}

/* Write to an existing file */
void write(char *name, char *data){
    file_t *current_file = fs; // Start at the beginning of the file system

    while(current_file != NULL){ // Traverse the file system
        if(strcmp(current_file->name, name) == 0){ // Check if current file is the one we're looking for
            // Copy new data to file
            strcpy(current_file->data, data);

            // Update file's size
            current_file->size = strlen(current_file->data);

            printf("Data written to file '%s' successfully.\n", name);
            return;
        }
        current_file = current_file->next;
    }

    printf("File '%s' not found.\n", name);
}

/* Delete an existing file */
void delete(char *name){
    file_t *current_file = fs; // Start at the beginning of the file system
    file_t *prev_file = NULL; // Keep track of previous file node

    while(current_file != NULL){ // Traverse the file system
        if(strcmp(current_file->name, name) == 0){ // Check if current file is the one we're looking for
            if(prev_file == NULL){ // File is at the beginning of the linked list
                fs = current_file->next;
            }
            else { // File is in the middle or end of the linked list
                prev_file->next = current_file->next;
            }

            free(current_file);
            printf("File '%s' deleted successfully.\n", name);
            return;
        }

        prev_file = current_file;
        current_file = current_file->next;
    }

    printf("File '%s' not found.\n", name);
}

/* Display all files in the file system */
void display(){
    file_t *current_file = fs; // Start at the beginning of the file system

    printf("File system contents:\n");

    while(current_file != NULL){ // Traverse the file system
        printf("%s (%d bytes)\n", current_file->name, current_file->size);
        current_file = current_file->next;
    }
}