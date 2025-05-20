//FormAI DATASET v1.0 Category: File system simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_SIZE 1024

// File Control Block (FCB) structure
typedef struct {
    char* filename;
    char* content;
    int size;
} FCB;

// File Allocation Table (FAT) structure
typedef struct {
    int size;
    int* blocks;
} FAT;

// File System structure
typedef struct {
    FCB* FCBs[MAX_FILES];
    FAT* FAT;
} FileSystem;

// Function prototypes
FileSystem* initFileSystem();
FCB* createFile(FileSystem* fs, char* filename);
void writeFile(FCB* fcb, char* content);
void readFile(FCB* fcb);
void deleteFile(FileSystem* fs, FCB* fcb);
void displayFileSystem(FileSystem* fs);

int main() {
    printf("Welcome to File System Simulation program!\n");

    FileSystem* fs = initFileSystem();
    displayFileSystem(fs);

    FCB* file1 = createFile(fs, "file1.txt");
    writeFile(file1, "This is the content of file1.");
    readFile(file1);
    displayFileSystem(fs);

    FCB* file2 = createFile(fs, "file2.txt");
    writeFile(file2, "This is the content of file2.");
    readFile(file2);
    displayFileSystem(fs);

    deleteFile(fs, file1);
    displayFileSystem(fs);

    deleteFile(fs, file2);
    displayFileSystem(fs);

    return 0;
}

// Initialize an empty file system
FileSystem* initFileSystem() {
    FileSystem* fs = malloc(sizeof(FileSystem));
    fs->FAT = malloc(sizeof(FAT));
    fs->FAT->size = MAX_FILES * MAX_FILE_SIZE;
    fs->FAT->blocks = malloc(sizeof(int) * fs->FAT->size);
    memset(fs->FAT->blocks, 0, sizeof(int) * fs->FAT->size);
    for (int i = 0; i < MAX_FILES; i++) {
        fs->FCBs[i] = NULL;
    }
    return fs;
}

// Create a new file with the specified filename
FCB* createFile(FileSystem* fs, char* filename) {
    // Find a free slot in the FCB array
    int free_slot = -1;
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->FCBs[i] == NULL) {
            free_slot = i;
            break;
        }
    }
    if (free_slot == -1) {
        printf("Cannot create file, maximum number of files reached.\n");
        return NULL;
    }

    // Allocate a new FCB for the file
    FCB* fcb = malloc(sizeof(FCB));
    fcb->filename = strdup(filename);
    fcb->size = 0;
    fcb->content = malloc(sizeof(char) * MAX_FILE_SIZE);

    // Increment the FAT blocks used by the file
    int blocks_needed = (MAX_FILE_SIZE + sizeof(int) - 1) / sizeof(int);
    int blocks_allocated = 0;
    for (int i = 0; i < fs->FAT->size; i++) {
        if (fs->FAT->blocks[i] == 0) {
            fs->FAT->blocks[i] = 1;
            blocks_allocated++;
            if (blocks_allocated == blocks_needed) {
                break;
            }
        }
    }
    if (blocks_allocated < blocks_needed) {
        printf("Cannot create file, not enough disk space.\n");
        free(fcb->filename);
        free(fcb->content);
        free(fcb);
        return NULL;    
    }

    // Add the FCB to the filesystem
    fs->FCBs[free_slot] = fcb;

    printf("File %s created.\n", filename);

    return fcb;
}

// Write the specified content to the file
void writeFile(FCB* fcb, char* content) {
    int content_size = strlen(content);
    if (content_size > MAX_FILE_SIZE) {
        printf("Cannot write to file, file size too large.\n");
        return;
    }
    fcb->size = content_size;
    strncpy(fcb->content, content, MAX_FILE_SIZE);
    printf("File %s written.\n", fcb->filename);
}

// Read and display the content of the file
void readFile(FCB* fcb) {
    printf("Content of file %s:\n%s\n", fcb->filename, fcb->content);
}

// Delete the specified file
void deleteFile(FileSystem* fs, FCB* fcb) {
    // Free the FCB memory
    free(fcb->filename);
    free(fcb->content);
    free(fcb);

    // Decrement the FAT blocks used by the file
    int blocks_needed = (MAX_FILE_SIZE + sizeof(int) - 1) / sizeof(int);
    int blocks_deallocated = 0;
    for (int i = 0; i < fs->FAT->size; i++) {
        if (fs->FAT->blocks[i] == 1) {
            fs->FAT->blocks[i] = 0;
            blocks_deallocated++;
            if (blocks_deallocated == blocks_needed) {
                break;
            }
        }
    }

    // Remove the FCB from the filesystem
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->FCBs[i] == fcb) {
            fs->FCBs[i] = NULL;
            break;
        }
    }

    printf("File %s deleted.\n", fcb->filename);
}

// Display the current file system status
void displayFileSystem(FileSystem* fs) {
    printf("\nCurrent File System Status:\n");
    printf("----------------------------\n");

    printf("FCB Table:\n");
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->FCBs[i] == NULL) {
            printf("Slot %d: Free\n", i);
        } else {
            printf("Slot %d: %s %d bytes\n", i, fs->FCBs[i]->filename, fs->FCBs[i]->size);
        }
    }

    printf("\nFAT Table:\n");
    int free_blocks = 0;
    for (int i = 0; i < fs->FAT->size; i++) {
        if (fs->FAT->blocks[i] == 0) {
            free_blocks++;
        }
    }
    printf("Free Blocks: %d / %d\n", free_blocks, fs->FAT->size);
}