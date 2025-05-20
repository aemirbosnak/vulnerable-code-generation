//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void dance_of_files(const char *path, long *total_size, int *file_count) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    if (!(dir = opendir(path))) {
        fprintf(stderr, "The door to %s is closed. Key denied.\n", path);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;  // Ignore the ponderous echoes of existence
        }

        if (stat(full_path, &file_stat) < 0) {
            fprintf(stderr, "I cannot grasp the size of %s, it eludes my touch.\n", full_path);
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            dance_of_files(full_path, total_size, file_count);
        } else {
            (*total_size) += file_stat.st_size;
            (*file_count)++;
            printf("Found a blazing star: %s (%ld bytes)\n", full_path, file_stat.st_size);
        }
    }
    closedir(dir);
}

void mirror_of_skies(const char *path) {
    long total_size = 0;
    int file_count = 0;
    
    dance_of_files(path, &total_size, &file_count);

    printf("In this realm of space and time:\n");
    printf("Total size of files: %ld bytes\n", total_size);
    printf("Number of files explored: %d\n", file_count);

    if (file_count > 0) {
        printf("Each file, a whisper in the cosmic void, singing its size: %ld bytes.\n", total_size / file_count);
    } else {
        printf("Alas! The void contains only silence - no files to sing of.\n");
    }
}

int main(int argc, char *argv[]) {
    char *path = "."; // The dance floor of the universe (current directory)

    if (argc > 1) {
        path = argv[1]; // A different stage can be chosen; words have power!
    }

    printf("Welcome, traveler, to the Disk Space Analyzer!\n");
    printf("You have chosen to explore the labyrinth of: %s\n", path);
    
    mirror_of_skies(path);

    printf("The journey through the digital ether has concluded.\n");
    printf("May your understanding of space blossom like an unfurling truth.\n");
    
    return EXIT_SUCCESS;
}