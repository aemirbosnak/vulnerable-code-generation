//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program will analyze the disk space utilization of a given directory or disk

struct directory {
    char name[50];
    int sizeInKB;
    struct directory *subDirectories;
    int numSubDirectories;
};

void getDirectorySize(struct directory *dir) {
    // Recursively get the size of each directory and sub-directory
    int totalSize = 0;
    
    for (int i = 0; i < dir->numSubDirectories; i++) {
        getDirectorySize(&(dir->subDirectories[i]));
        totalSize += dir->subDirectories[i].sizeInKB;
    }
    
    dir->sizeInKB = totalSize;
}

void printDirectorySizes(struct directory *dir) {
    // Print the size of each directory and sub-directory
    
    printf("%s: %d KB\n", dir->name, dir->sizeInKB);
    
    for (int i = 0; i < dir->numSubDirectories; i++) {
        printf("  ");
        printDirectorySizes(&(dir->subDirectories[i]));
    }
}

int main(int argc, char *argv[]) {
    // Initialize the root directory
    struct directory root = {"C:\\", 0, NULL, 0};
    
    // Add sub-directories
    struct directory windows = {"Windows", 0, NULL, 0};
    struct directory programFiles = {"Program Files", 0, NULL, 0};
    struct directory users = {"Users", 0, NULL, 0};
    root.subDirectories = (struct directory *) malloc(3 * sizeof(struct directory));
    root.subDirectories[0] = windows;
    root.subDirectories[1] = programFiles;
    root.subDirectories[2] = users;
    root.numSubDirectories = 3;
    
    // Add sub-directories to Windows directory
    struct directory system32 = {"System32", 0, NULL, 0};
    struct directory drivers = {"Drivers", 0, NULL, 0};
    windows.subDirectories = (struct directory *) malloc(2 * sizeof(struct directory));
    windows.subDirectories[0] = system32;
    windows.subDirectories[1] = drivers;
    windows.numSubDirectories = 2;
    
    // Add sub-directories to Users directory
    struct directory bob = {"Bob", 0, NULL, 0};
    struct directory alice = {"Alice", 0, NULL, 0};
    users.subDirectories = (struct directory *) malloc(2 * sizeof(struct directory));
    users.subDirectories[0] = bob;
    users.subDirectories[1] = alice;
    users.numSubDirectories = 2;
    
    // Add sub-directories to Bob directory
    struct directory myDocuments = {"My Documents", 0, NULL, 0};
    bob.subDirectories = (struct directory *) malloc(sizeof(struct directory));
    bob.subDirectories[0] = myDocuments;
    bob.numSubDirectories = 1;
    
    // Add sub-directories to Alice directory
    struct directory pictures = {"Pictures", 0, NULL, 0};
    alice.subDirectories = (struct directory *) malloc(sizeof(struct directory));
    alice.subDirectories[0] = pictures;
    alice.numSubDirectories = 1;
    
    // Get the size of each directory
    getDirectorySize(&root);
    
    // Print the size of each directory
    printDirectorySizes(&root);
    
    return 0;
}