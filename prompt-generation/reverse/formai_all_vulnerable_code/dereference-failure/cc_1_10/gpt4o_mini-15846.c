//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH 1024
#define SPACE_UNIT 1024

typedef struct {
    long total_bytes;
    long used_bytes;
    long free_bytes;
} DiskSpace;

void analyze_directory(const char *path, DiskSpace *diskSpace);
void print_space(DiskSpace diskSpace);

int main(int argc, char *argv[]) {
    DiskSpace diskSpace = {0, 0, 0};
    char path[MAX_PATH];

    if (argc < 2) {
        printf("Please provide a directory path to analyze.\n");
        return 1;
    }

    strcpy(path, argv[1]);

    analyze_directory(path, &diskSpace);
    print_space(diskSpace);

    return 0;
}

void analyze_directory(const char *path, DiskSpace *diskSpace) {
    struct dirent *entry;
    struct stat statbuf;
    DIR *dir = opendir(path);

    if (dir == NULL) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char full_path[MAX_PATH];
            snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

            if (stat(full_path, &statbuf) == 0) {
                if (S_ISDIR(statbuf.st_mode)) {
                    analyze_directory(full_path, diskSpace);
                }
                diskSpace->used_bytes += statbuf.st_size;
            }
        }
    }

    closedir(dir);
    diskSpace->total_bytes += diskSpace->used_bytes;  // Accumulate for the root path
    diskSpace->free_bytes = diskSpace->total_bytes - diskSpace->used_bytes;  // Calculate free space dynamically
}

void print_space(DiskSpace diskSpace) {
    printf("\n--- Disk Space Analysis ---\n");
    printf("Total Space: %.2f MB\n", diskSpace.total_bytes / (float)SPACE_UNIT / SPACE_UNIT);
    printf("Used Space:  %.2f MB\n", diskSpace.used_bytes / (float)SPACE_UNIT / SPACE_UNIT);
    printf("Free Space:  %.2f MB\n", diskSpace.free_bytes / (float)SPACE_UNIT / SPACE_UNIT);

    // Visual representation using ASCII art
    printf("\nDisk Usage Visualization:\n");
    long total_space = diskSpace.total_bytes / SPACE_UNIT;  // Convert to KB for display
    long used_space = diskSpace.used_bytes / SPACE_UNIT;
    long free_space = diskSpace.free_bytes / SPACE_UNIT;

    printf("Used Space: ");
    for (long i = 0; i < used_space; i += 10) {
        printf("█");
    }
    printf(" (%ld KB)\n", used_space);

    printf("Free Space: ");
    for (long j = 0; j < free_space; j += 10) {
        printf("░");
    }
    printf(" (%ld KB)\n", free_space);

    printf("\nEnd of Disk Space Analysis.\n");
}