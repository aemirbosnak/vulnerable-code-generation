//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of files that can be stored in the file system
#define MAX_FILES 10

// Define the structure of a file
typedef struct file
{
    char name[256];
    int size;
    struct file* next;
} file;

// Define the root node of the file system
file* root = NULL;

// Function to create a new file
file* create_file(char* name, int size)
{
    // Allocate memory for the new file
    file* new_file = (file*)malloc(sizeof(file));

    // Copy the file name and size
    strcpy(new_file->name, name);
    new_file->size = size;

    // Set the next pointer to NULL
    new_file->next = NULL;

    // Return the new file
    return new_file;
}

// Function to add a new file to the file system
void add_file(char* name, int size)
{
    // Create a new file
    file* new_file = create_file(name, size);

    // If the file system is empty, make the new file the root node
    if (root == NULL)
    {
        root = new_file;
    }
    else
    {
        // Traverse the file system to find the last file
        file* last_file = root;
        while (last_file->next)
        {
            last_file = last_file->next;
        }

        // Add the new file to the last file's next pointer
        last_file->next = new_file;
    }
}

// Function to list all files in the file system
void list_files()
{
    // Traverse the file system and print each file's name
    file* current_file = root;
    while (current_file)
    {
        printf("%s\n", current_file->name);
        current_file = current_file->next;
    }
}

int main()
{
    // Add some files to the file system
    add_file("test.txt", 10);
    add_file("my.doc", 20);
    add_file("image.jpg", 50);

    // List all files in the file system
    list_files();

    return 0;
}