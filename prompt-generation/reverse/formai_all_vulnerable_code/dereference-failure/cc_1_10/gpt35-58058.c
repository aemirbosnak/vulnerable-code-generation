//FormAI DATASET v1.0 Category: File system simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 100
#define MAX_FILES 100
#define MAX_DIRS 100
#define MAX_FILE_SIZE 100

// A struct to represent files
typedef struct File
{
    char name[MAX_FILENAME];
    char data[MAX_FILE_SIZE];
    int size;
} file_t;

// A struct to represent directories
typedef struct Dir
{
    char name[MAX_FILENAME];
    int num_files;
    file_t files[MAX_FILES];
    int num_dirs;
    struct Dir* dirs[MAX_DIRS];
    struct Dir* parent_dir;
} dir_t;

// Function prototypes
dir_t* create_dir(char* name, dir_t* parent_dir);
void delete_dir(dir_t* dir_to_delete);
file_t* add_file(char* name, char* data, int size, dir_t* dest_dir);
void delete_file(file_t* file_to_delete, dir_t* parent_dir);
void print_all_files(dir_t* dir_to_print);
void print_dirs(dir_t* dir_to_print);

// Global variables
dir_t* root_dir;

int main()
{
    // Create the root directory
    root_dir = create_dir("root", NULL);

    // Add some directories and files to the root directory
    dir_t* sub_dir_1 = create_dir("sub_dir_1", root_dir);
    dir_t* sub_dir_2 = create_dir("sub_dir_2", root_dir);
    add_file("file_1.txt", "Hello, world!", 13, root_dir);
    add_file("file_2.txt", "This is a test file.", 22, sub_dir_1);
    add_file("file_3.txt", "Another test file.", 19, sub_dir_2);

    // Print out the entire directory structure
    printf("Root directory:\n");
    print_all_files(root_dir);

    // Delete a file and a directory
    delete_file(&(sub_dir_1->files[0]), sub_dir_1);
    delete_dir(sub_dir_2);

    // Print out the updated directory structure
    printf("\nAfter deleting a file and a directory:\n");
    print_all_files(root_dir);

    return 0;
}

// Creates a new directory with the given name and parent directory
dir_t* create_dir(char* name, dir_t* parent_dir)
{
    dir_t* new_dir = malloc(sizeof(dir_t));
    strcpy(new_dir->name, name);
    new_dir->num_files = 0;
    new_dir->num_dirs = 0;
    new_dir->parent_dir = parent_dir;

    // Add the new directory to the parent directory's list of subdirectories
    if (parent_dir != NULL)
    {
        parent_dir->dirs[parent_dir->num_dirs] = new_dir;
        parent_dir->num_dirs++;
    }

    return new_dir;
}

// Deletes a directory and all its contents
void delete_dir(dir_t* dir_to_delete)
{
    // Delete all files in the directory
    for (int i = 0; i < dir_to_delete->num_files; i++)
    {
        delete_file(&(dir_to_delete->files[i]), dir_to_delete);
    }

    // Delete all subdirectories
    while (dir_to_delete->num_dirs > 0)
    {
        delete_dir(dir_to_delete->dirs[dir_to_delete->num_dirs - 1]);
    }

    // Remove the directory from its parent directory's list of subdirectories
    if (dir_to_delete->parent_dir != NULL)
    {
        for (int i = 0; i < dir_to_delete->parent_dir->num_dirs; i++)
        {
            if (dir_to_delete->parent_dir->dirs[i] == dir_to_delete)
            {
                // Shift all the directories after the deleted one over by one
                for (int j = i; j < dir_to_delete->parent_dir->num_dirs - 1; j++)
                {
                    dir_to_delete->parent_dir->dirs[j] = dir_to_delete->parent_dir->dirs[j + 1];
                }

                dir_to_delete->parent_dir->num_dirs--;
                break;
            }
        }
    }

    free(dir_to_delete);
}

// Adds a new file with the given name, data, and size to the given directory
file_t* add_file(char* name, char* data, int size, dir_t* dest_dir)
{
    file_t* new_file = malloc(sizeof(file_t));
    strcpy(new_file->name, name);
    strcpy(new_file->data, data);
    new_file->size = size;

    // Add the new file to the directory's list of files
    dest_dir->files[dest_dir->num_files] = *new_file;
    dest_dir->num_files++;

    return new_file;
}

// Deletes a file from the given directory
void delete_file(file_t* file_to_delete, dir_t* parent_dir)
{
    // Remove the file from the directory's list of files
    for (int i = 0; i < parent_dir->num_files; i++)
    {
        if (&(parent_dir->files[i]) == file_to_delete)
        {
            // Shift all the files after the deleted one over by one
            for (int j = i; j < parent_dir->num_files - 1; j++)
            {
                parent_dir->files[j] = parent_dir->files[j + 1];
            }

            parent_dir->num_files--;
            break;
        }
    }

    free(file_to_delete);
}

// Prints out all files and subdirectories in the given directory recursively
void print_all_files(dir_t* dir_to_print)
{
    printf("Directory: %s\n", dir_to_print->name);

    // Print out files in the directory
    for (int i = 0; i < dir_to_print->num_files; i++)
    {
        printf("  File: %s (%d bytes)\n", dir_to_print->files[i].name, dir_to_print->files[i].size);
    }

    // Print out subdirectories in the directory
    for (int i = 0; i < dir_to_print->num_dirs; i++)
    {
        print_all_files(dir_to_print->dirs[i]);
    }
}

// Prints out all subdirectories in the given directory
void print_dirs(dir_t* dir_to_print)
{
    for (int i = 0; i < dir_to_print->num_dirs; i++)
    {
        printf("%s\n", dir_to_print->dirs[i]->name);
    }
}