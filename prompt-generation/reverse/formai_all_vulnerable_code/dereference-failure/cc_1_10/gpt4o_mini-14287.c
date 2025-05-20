//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Let's bring some color to our terminal output
#define COLOR_GREEN "\033[0;32m"
#define COLOR_RED "\033[0;31m"
#define COLOR_RESET "\033[0m"

// Function to check if a file exists in the destination
int file_exists(const char *path) {
    struct stat buffer;   
    return (stat(path, &buffer) == 0); 
}

// Function to synchronize files
void sync_files(const char *source_dir, const char *dest_dir) {
    struct dirent *entry;
    DIR *dp = opendir(source_dir);
    
    if (dp == NULL) {
        printf(COLOR_RED "Oops! Can't open the source directory: %s\n" COLOR_RESET, source_dir);
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_name[0] == '.') {
            // Skip hidden files and current directory references
            continue;
        }

        char source_path[1024];
        char dest_path[1024];
        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);
        
        if (file_exists(dest_path)) {
            printf(COLOR_GREEN "File already exists: %s\n" COLOR_RESET, entry->d_name);
        } else {
            FILE *src_file = fopen(source_path, "rb");
            FILE *dst_file = fopen(dest_path, "wb");
            
            if (src_file == NULL || dst_file == NULL) {
                printf(COLOR_RED "Oh no! Unable to open files for copying: %s\n" COLOR_RESET, entry->d_name);
                if (src_file) fclose(src_file);
                continue;
            }

            char buffer[1024];
            size_t bytes_read;
            while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                fwrite(buffer, 1, bytes_read, dst_file);
            }

            printf(COLOR_GREEN "Successfully synced: %s to %s\n" COLOR_RESET, source_path, dest_path);

            fclose(src_file);
            fclose(dst_file);
        }
    }
    
    closedir(dp);
}

// Main function to start our syncing journey
int main(int argc, char **argv) {
    if (argc != 3) {
        printf(COLOR_RED "Usage: %s <source_directory> <destination_directory>\n" COLOR_RESET, argv[0]);
        return EXIT_FAILURE;
    }

    const char *source = argv[1];
    const char *destination = argv[2];

    printf(COLOR_GREEN "🎉 Syncing files from '%s' to '%s' 🎉\n" COLOR_RESET, source, destination);
    sync_files(source, destination);
    printf(COLOR_GREEN "🎈 All done with the syncing! Have a great day! 🎈\n" COLOR_RESET);

    return EXIT_SUCCESS;
}