//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>

#define MAX_PATH_LENGTH 1024
#define SPACE_FACTOR 1024

void display_humorous_message(size_t total, size_t used, size_t free) {
    printf("\nHere's a ridiculous breakdown of your disk space:\n");
    printf("Total Space: %zu GB\n", total / SPACE_FACTOR / SPACE_FACTOR);
    printf("Used Space: %zu GB\n", used / SPACE_FACTOR / SPACE_FACTOR);
    printf("Free Space: %zu GB\n", free / SPACE_FACTOR / SPACE_FACTOR);
    
    if (free < SPACE_FACTOR * SPACE_FACTOR * 5) {
        printf("Warning: You're running out of space! It’s like a cat with too many toys...\n");
        printf("Your disk is cluttered with stuff. Consider cleaning it or adopting more virtual kittens!\n");
    } else {
        printf("You're brimming with space! Like a hoarder but in a good way.\n");
    }
}

void silly_disk_space_analyzer(const char *path) {
    struct statvfs stat;
    
    if (statvfs(path, &stat) != 0) {
        // Error occurred: possibly the directory does not exist
        perror("Oops, I couldn't find the path! Did you lose it, like your car keys?");
        return;
    }

    size_t total = stat.f_frsize * stat.f_blocks; // Total space in bytes
    size_t free = stat.f_frsize * stat.f_bfree;   // Free space in bytes
    size_t used = total - free;                     // Used space in bytes

    display_humorous_message(total, used, free);
}

int main(int argc, char* argv[]) {
    printf("Welcome to the Silly Disk Space Analyzer!\n");
    printf("We'll unearth where your disk space has gone faster than a magician!\n");

    char path[MAX_PATH_LENGTH];

    if (argc != 2) {
        printf("No directory path provided, so I shall assume you're asking about the current abyss...\n");
        snprintf(path, MAX_PATH_LENGTH, ".");
    } else {
        strncpy(path, argv[1], MAX_PATH_LENGTH);
        path[MAX_PATH_LENGTH - 1] = '\0';  // Ensure null termination
    }

    silly_disk_space_analyzer(path);
    
    printf("\nThanks for using the Silly Disk Space Analyzer!\n");
    printf("Remember: A clean disk is a happy disk. Happy cleaning, you digital hero!\n");
    
    return 0;
}