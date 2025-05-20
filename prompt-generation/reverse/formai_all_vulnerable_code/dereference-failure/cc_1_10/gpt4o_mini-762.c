//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_FILES 100
#define FILENAME_SIZE 256
#define FILE_SIGNATURE ".txt"

typedef struct {
    char name[FILENAME_SIZE];
    long size;
    char* data;
} File;

typedef struct {
    File files[MAX_FILES];
    int count;
} VirtualDisk;

// Function to initialize the virtual disk with test files
void initializeDisk(VirtualDisk* disk) {
    disk->count = 0;
    for (int i = 0; i < 10; i++) {
        snprintf(disk->files[i].name, FILENAME_SIZE, "file%d.txt", i);
        disk->files[i].size = 1024 + (i * 100); // Increase size
        disk->files[i].data = malloc(disk->files[i].size);
        
        // Simulating file content
        for (long j = 0; j < disk->files[i].size; j++) {
            disk->files[i].data[j] = 'A' + (j % 26);
        }
        disk->count++;
    }
}

// Function to simulate recovery
void recoverFiles(VirtualDisk* disk) {
    printf("Attempting to recover files from the disk:\n");
    for (int i = 0; i < disk->count; i++) {
        if (strstr(disk->files[i].name, FILE_SIGNATURE)) {
            printf("Recovering %s (Size: %ld bytes)\n", disk->files[i].name, disk->files[i].size);
            printf("Contents: %.10s...\n", disk->files[i].data); // Print only the first 10 characters
        }
    }
}

// Clean up the allocated memory
void freeDisk(VirtualDisk* disk) {
    for (int i = 0; i < disk->count; i++) {
        free(disk->files[i].data);
    }
}

int main() {
    VirtualDisk disk;

    // Initialize virtual disk with files
    initializeDisk(&disk);
    
    // Recovering files
    recoverFiles(&disk);
    
    // Free the disk resources
    freeDisk(&disk);

    return 0;
}