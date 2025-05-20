//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH 1024
#define BUFF_SIZE 4096

void analyze_disk(const char *path, long long *total_size, long long *total_files);

void sprinkle_gems(const char *message) {
    printf("💎💎💎 %s 💎💎💎\n", message);
}

void dreamscape(const char *path) {
    sprinkle_gems("Welcome to Disk Overture");
    printf("Sailing into the azure sea of files...\n");
    
    long long total_size = 0;
    long long total_files = 0;
    
    analyze_disk(path, &total_size, &total_files);
    
    sprinkle_gems("The realms of storage unfurl");
    printf("Total Size: %lld bytes\n", total_size);
    printf("Total Files: %lld wonders discovered\n", total_files);
}

void analyze_disk(const char *path, long long *total_size, long long *total_files) {
    DIR *directory;
    struct dirent *entry;
    struct stat fileStat;
    
    if ((directory = opendir(path)) == NULL) {
        perror("Incantation failed to open the directory");
        return;
    }
    
    while ((entry = readdir(directory)) != NULL) {
        char full_path[MAX_PATH];
        
        // Skip the magical entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;
        
        snprintf(full_path, MAX_PATH, "%s/%s", path, entry->d_name);
        
        if (stat(full_path, &fileStat) == 0) {
            if (S_ISDIR(fileStat.st_mode)) {
                // A tree of possibilities awaits
                analyze_disk(full_path, total_size, total_files);
            } else {
                // Count the files and their sizes
                printf("Found a treasure: %s\n", full_path);
                *total_size += fileStat.st_size;
                (*total_files)++;
            }
        } else {
            perror("Mystical error in fetching file statistics");
        }
    }
    
    closedir(directory);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("✨ Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }
    
    dreamscape(argv[1]);

    printf("🌌 The journey through your digital cosmos is complete! 🌌\n");
    return 0;
}