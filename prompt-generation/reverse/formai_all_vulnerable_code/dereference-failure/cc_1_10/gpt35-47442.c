//FormAI DATASET v1.0 Category: File system simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold file information
typedef struct file {
    char* name; // Name of the file
    int size; // Size of the file in bytes
    char* content; // Content of the file
} File;

// Structure to hold directory information
typedef struct directory {
    char* name; // Name of the directory
    int numFiles; // Number of files in the directory
    File* files; // Array of files in the directory
    int numDirectories; // Number of sub-directories in the directory
    struct directory* directories; // Array of sub-directories in the directory
} Directory;

// Function to create a file with the given name and content
File* createFile(char* name, char* content) {
    File* file = (File*)malloc(sizeof(File));
    file->name = strdup(name);
    file->size = strlen(content) + 1;
    file->content = strdup(content);
    return file;
}

// Function to create a directory with the given name
Directory* createDirectory(char* name) {
    Directory* directory = (Directory*)malloc(sizeof(Directory));
    directory->name = strdup(name);
    directory->numFiles = 0;
    directory->files = NULL;
    directory->numDirectories = 0;
    directory->directories = NULL;
    return directory;
}

// Function to add a file to the directory
void addFileToDirectory(Directory* directory, File* file) {
    directory->numFiles++;
    directory->files = (File*)realloc(directory->files, directory->numFiles * sizeof(File));
    directory->files[directory->numFiles - 1] = *file;
}

// Function to add a sub-directory to the directory
void addDirectoryToDirectory(Directory* directory, Directory* subDirectory) {
    directory->numDirectories++;
    directory->directories = (Directory*)realloc(directory->directories, directory->numDirectories * sizeof(Directory));
    directory->directories[directory->numDirectories - 1] = *subDirectory;
}

int main() {
    // Create root directory
    Directory* root = createDirectory("root");
    
    // Create sub-directories
    Directory* castle1 = createDirectory("castle1");
    Directory* castle2 = createDirectory("castle2");
    Directory* village1 = createDirectory("village1");
    
    // Create files for castle1
    File* knight = createFile("knight.txt", "A brave knight");
    addFileToDirectory(castle1, knight);
    
    File* dragon = createFile("dragon.txt", "A fierce dragon");
    addFileToDirectory(castle1, dragon);
    
    File* princess = createFile("princess.txt", "A beautiful princess");
    addFileToDirectory(castle1, princess);
    
    // Create files for castle2
    File* king = createFile("king.txt", "A wise king");
    addFileToDirectory(castle2, king);
    
    File* queen = createFile("queen.txt", "A kind queen");
    addFileToDirectory(castle2, queen);
    
    // Create files for village1
    File* peasant = createFile("peasant.txt", "A hardworking peasant");
    addFileToDirectory(village1, peasant);
    
    File* merchant = createFile("merchant.txt", "A wealthy merchant");
    addFileToDirectory(village1, merchant);
    
    // Add sub-directories to root directory
    addDirectoryToDirectory(root, castle1);
    addDirectoryToDirectory(root, castle2);
    addDirectoryToDirectory(root, village1);
    
    // Output directory structure
    printf("%s\n", root->name);
    for(int i = 0; i < root->numDirectories; i++) {
        printf("\t%s\n", root->directories[i].name);
        for(int j = 0; j < root->directories[i].numFiles; j++) {
            printf("\t\t%s - %d bytes - \"%s\"\n", root->directories[i].files[j].name, root->directories[i].files[j].size, root->directories[i].files[j].content);
        }
    }
    
    return 0;
}