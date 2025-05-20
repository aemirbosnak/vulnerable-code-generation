//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Decree of Synchronization
#define TOWNSPEAKER "Hark! Thy files dost require synchronization!"

// Function Declarations
void announce(const char *message);
void check_files(const char *directory1, const char *directory2);
void copy_file(const char *source_path, const char *dest_path);
void create_directory(const char *dir_path);
int file_exists(const char *path);
void synchronize_copies(const char *directory1, const char *directory2);

// The Grand Entry Point
int main(int argc, char *argv[]) {
    if(argc != 3) {
        announce("Alas, thou hast not provided the correct number of directories!");
        return EXIT_FAILURE;
    }
    
    // Announce the commencement of the synchronization
    announce(TOWNSPEAKER);
    synchronize_copies(argv[1], argv[2]);

    return EXIT_SUCCESS;
}

// Proclaim the message to the townsfolk
void announce(const char *message) {
    printf("%s\n", message);
}

// The line that synchronizes the files betwixt two directories
void synchronize_copies(const char *directory1, const char *directory2) {
    check_files(directory1, directory2);
}

// Check the sacred scrolls of files in both directories
void check_files(const char *directory1, const char *directory2) {
    struct dirent *entry;
    DIR *dir = opendir(directory1);
    
    if(dir == NULL) {
        announce("Alas! The first directory could not be opened!");
        return;
    }

    // Traverse the files in the first folder
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') { // Ignore hidden files
            char source_path[256];
            char dest_path[256];

            snprintf(source_path, sizeof(source_path), "%s/%s", directory1, entry->d_name);
            snprintf(dest_path, sizeof(dest_path), "%s/%s", directory2, entry->d_name);
            
            // Copy if it doesn't exist in the second directory
            if (!file_exists(dest_path)) {
                announce("A file is missing in the second directory, copying...");
                copy_file(source_path, dest_path);
            }
        }
    }
    closedir(dir);
    announce("Aye! The synchronization hath concluded!");
}

// To copy the parchment (file) from one's directory to another
void copy_file(const char *source_path, const char *dest_path) {
    FILE *src = fopen(source_path, "rb");
    FILE *dest = fopen(dest_path, "wb");

    if (src == NULL || dest == NULL) {
        announce("Prithee! An error occurred whilst attempting to copy the parchment.");
        return;
    }

    char buffer[1024];
    size_t n;

    while ((n = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, n, dest);
    }

    fclose(src);
    fclose(dest);
}

// To check if the parchment exists within the royal archives (directory)
int file_exists(const char *path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0);
}

// A mighty function that ensures the directory exists (creates if not)
void create_directory(const char *dir_path) {
    mkdir(dir_path, 0700);
}