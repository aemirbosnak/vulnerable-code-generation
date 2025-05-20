//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Ada Lovelace
/* 
    C File Synchronizer 
    by Ada Lovelace

    This program synchronizes two directories,
    copying files from the source directory to
    the destination directory if they are not
    already present.

    To use this program, run it with the paths of 
    the source and destination directories as arguments.

    Example usage: ./sync /path/to/source /path/to/destination
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void copy_file(char *src_path, char *dest_path);
int is_file(char *path);
int is_dir(char *path);

int main(int argc, char **argv) {
    // Check for correct number of arguments
    if(argc != 3) {
        printf("Usage: %s [source_directory] [destination_directory]\n", argv[0]);
        exit(1);
    }

    // Open source directory
    DIR *src = opendir(argv[1]);
    if(src == NULL) {
        printf("Error: could not open source directory %s\n", argv[1]);
        exit(1);
    }

    // Open destination directory
    DIR *dest = opendir(argv[2]);
    if(dest == NULL) {
        printf("Error: could not open destination directory %s\n", argv[2]);
        exit(1);
    }

    // Iterate through files in source directory
    struct dirent *entry;
    while((entry = readdir(src)) != NULL) {
        // Ignore current and parent directory entries
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct paths to source and destination files
        char src_path[1024];
        char dest_path[1024];
        sprintf(src_path, "%s/%s", argv[1], entry->d_name);
        sprintf(dest_path, "%s/%s", argv[2], entry->d_name);

        // Check if file already exists in destination
        if(is_file(dest_path)) {
            continue;
        }

        // Copy file to destination
        copy_file(src_path, dest_path);
    }

    // Close directories
    closedir(src);
    closedir(dest);

    printf("Synchronization complete.\n");

    return 0;
}

// Copy file from source to destination path
void copy_file(char *src_path, char *dest_path) {
    // Open source file
    FILE *src_file = fopen(src_path, "rb");
    if(src_file == NULL) {
        printf("Error opening source file %s\n", src_path);
        exit(1);
    }

    // Create destination directory if it does not exist
    char *dir_path = strdup(dest_path);
    char *dir = dirname(dir_path);
    mkdir(dir, 0755);

    // Open destination file
    FILE *dest_file = fopen(dest_path, "wb");
    if(dest_file == NULL) {
        printf("Error creating destination file %s\n", dest_path);
        exit(1);
    }

    // Copy file contents
    char buf[BUFSIZ];
    size_t size;
    while((size = fread(buf, 1, sizeof(buf), src_file)) > 0) {
        fwrite(buf, 1, size, dest_file);
    }

    // Close files
    fclose(src_file);
    fclose(dest_file);

    printf("Copied %s to %s\n", src_path, dest_path);
}

// Check if path is a file
int is_file(char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

// Check if path is a directory
int is_dir(char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}