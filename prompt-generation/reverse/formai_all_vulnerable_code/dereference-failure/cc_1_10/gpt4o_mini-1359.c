//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function prototype
void scan_file(const char *file_name);
int is_virus(const char *file_content);
void scan_directory(const char *dir_name);

// Main function
int main(int argc, char *argv[]) {
    // Prank alert!
    printf("Welcome to the ViralScan3000! The only antivirus that guarantees laughs...\n");

    if (argc != 2) {
        printf("Usage: %s <directory_to_scan>\n", argv[0]);
        return 1;
    }
    
    printf("Scanning directory: %s...\n", argv[1]);
    scan_directory(argv[1]);
    printf("Scanned everything! No viruses found... or were there?! Muahahaha!\n");

    return 0;
}

// Scan a given directory for files
void scan_directory(const char *dir_name) {
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(dir_name))) {
        perror("Couldn't open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip hidden files and special directories
        if (entry->d_name[0] == '.' || entry->d_type != DT_REG) continue;

        char file_path[BUFFER_SIZE];
        snprintf(file_path, sizeof(file_path), "%s/%s", dir_name, entry->d_name);
        scan_file(file_path);
    }
    
    closedir(dir);
}

// Function to scan a single file
void scan_file(const char *file_name) {
    printf("Scanning file: %s\n", file_name);
    
    FILE *file = fopen(file_name, "r");
    if (!file) {
        printf("Oops! Can't open %s. Is it a secret?\n", file_name);
        return;
    }

    char *content = (char *)malloc(BUFFER_SIZE);
    fread(content, sizeof(char), BUFFER_SIZE, file);
    fclose(file);

    if (is_virus(content)) {
        printf("ALERT: Virus detected in %s! Quick, run away!\n", file_name);
    } else {
        printf("All clear at %s! Nothing to see here, folks!\n", file_name);
    }

    free(content);
}

// A simple simulated virus detection function
int is_virus(const char *file_content) {
    // Look for the most suspicious phrase...
    if (strstr(file_content, "I AM A VIRUS!") != NULL) {
        return 1; // Virus detected!
    }

    // Well, maybe all that "LOL" in the file is suspicious too!
    if (strstr(file_content, "LOL") != NULL) {
        printf("Warning: File potentially harboring too much laughter!\n");
    }

    return 0; // No virus found
}