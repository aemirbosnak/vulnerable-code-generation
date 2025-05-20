//FormAI DATASET v1.0 Category: File Synchronizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to recursively copy files and directories 
void copy(char *src_path, char *dest_path) {
    
    struct stat stat_buffer; 
    
    // Get file status
    stat(src_path, &stat_buffer);

    // Check if given file is directory or not
    if(S_ISDIR(stat_buffer.st_mode)) {

        // Create same directory in destination
        mkdir(dest_path, stat_buffer.st_mode);

        // Open the directory to read its contents
        DIR *dir = opendir(src_path);
        if (dir == NULL) return;

        // Read all entries from the directory
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) {

            // Ignore hidden directories or files
            if (entry->d_name[0] == '.') continue;

            // Construct new file paths
            char src_path_new[1024];
            char dest_path_new[1024];
            sprintf(src_path_new, "%s/%s", src_path, entry->d_name);
            sprintf(dest_path_new, "%s/%s", dest_path, entry->d_name);

            // Recursively copy subdirectories and files
            copy(src_path_new, dest_path_new);
        }

        closedir(dir);

    } else if(S_ISREG(stat_buffer.st_mode)) {

        // Create new file in destination path
        FILE *src_file, *dest_file;
        char ch;
        src_file = fopen(src_path, "r");
        dest_file = fopen(dest_path, "w");

        // If any of the files failed to open
        if (src_file == NULL || dest_file == NULL) return;

        // Copy contents of source file into destination file
        while ((ch = fgetc(src_file)) != EOF) {
            fputc(ch, dest_file);
        }

        fclose(src_file);
        fclose(dest_file);

    }
}

int main(int argc, char **argv) {

    char *src_path, *dest_path;

    // If source and destination paths are not provided
    if(argc <= 1) {
        printf("Please provide source and destination paths as arguments.\n");
        printf("Usage: ./sync [source_path] [destination_path]\n");
        return 0;
    } else {
        src_path = argv[1];
        dest_path = argv[2];
    }

    // Call the copy function to synchronize files and directories
    copy(src_path, dest_path);

    printf("Files and directories synchronized successfully!\n");

    return 0;
}