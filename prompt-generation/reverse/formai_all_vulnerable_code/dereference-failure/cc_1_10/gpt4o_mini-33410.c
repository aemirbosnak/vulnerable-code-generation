//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#define SPACE_CUTOFF 10 // in percentage
#define BUFFER_SIZE 256

typedef struct {
    char name[BUFFER_SIZE];
    unsigned long total;
    unsigned long free;
    unsigned long used;
    unsigned long percent_used;
} DiskSpace;

void analyzeDiskSpace(const char *path, DiskSpace *disk) {
    struct statvfs stat;

    if (statvfs(path, &stat) != 0) {
        perror("Failed to get disk space");
        return;
    }

    disk->total = stat.f_blocks * stat.f_frsize;
    disk->free = stat.f_bfree * stat.f_frsize;
    disk->used = disk->total - disk->free;
    disk->percent_used = (disk->used * 100) / disk->total;

    strncpy(disk->name, path, BUFFER_SIZE - 1);
}

// Displays a single DiskSpace info
void displayDiskSpace(DiskSpace *disk) {
    printf("\nDisk Space Analysis for: %s\n", disk->name);
    printf("Total Space: %lu bytes\n", disk->total);
    printf("Free Space: %lu bytes\n", disk->free);
    printf("Used Space: %lu bytes\n", disk->used);
    printf("Percentage Used: %lu%%\n", disk->percent_used);
}

// Check high usage warning
void checkUsageWarning(DiskSpace *disk) {
    if (disk->percent_used > SPACE_CUTOFF) {
        printf("Warning: Disk usage exceeded %d%%!\n", SPACE_CUTOFF);
    }
}

// Recursive function to analyze the disk space of all directories
void analyzeDirectory(const char *directory) {
    DIR *dir;
    struct dirent *entry;

    DiskSpace disk;

    // Try accessing the directory
    if ((dir = opendir(directory)) == NULL) {
        perror("Unable to open directory");
        return;
    }

    // Analyze the current directory 
    analyzeDiskSpace(directory, &disk);
    displayDiskSpace(&disk);
    checkUsageWarning(&disk);

    // Loop through directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Skip the "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        // Create path for the next recursive call
        char path[BUFFER_SIZE];
        snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);

        // If it's a directory, analyze it recursively
        if (entry->d_type == DT_DIR) {
            analyzeDirectory(path);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    // Start analyzing from the given directory or root if not specified
    const char *start_directory = argv[1];
    printf("\n🛸 Beginning Disk Space Analysis in: %s 🛸\n", start_directory);
    analyzeDirectory(start_directory);
    printf("\n🛸 Analysis Complete! 🛸\n");

    return 0;
}