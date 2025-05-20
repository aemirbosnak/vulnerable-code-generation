//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to copy a file
int copy_file(const char *src, const char *dest) {
    FILE *source, *destination;
    char buffer[1024];
    size_t bytes;

    source = fopen(src, "rb");
    if (!source) {
        perror("Source file opening error");
        return -1;
    }

    destination = fopen(dest, "wb");
    if (!destination) {
        fclose(source);
        perror("Destination file opening error");
        return -1;
    }

    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);
    
    return 0;
}

// Function to return the size of a file
long get_file_size(const char *filename) {
    struct stat st;
    if (stat(filename, &st) == -1)
        return -1;
    return st.st_size;
}

// Function to check if a file needs to be synchronized
int needs_sync(const char *src, const char *dest) {
    long src_size = get_file_size(src);
    long dest_size = get_file_size(dest);
    return (src_size != dest_size);
}

// Function to synchronize two files
void sync_file(const char *src, const char *dest) {
    if (needs_sync(src, dest)) {
        printf("Syncing %s to %s\n", src, dest);
        if (copy_file(src, dest) == 0) {
            printf("Synchronization complete: %s -> %s\n", src, dest);
        } else {
            fprintf(stderr, "Error occurred while syncing %s to %s\n", src, dest);
        }
    } else {
        printf("%s is up to date. No action needed.\n", dest);
    }
}

// Function to synchronize an entire directory
void sync_directory(const char *src_dir, const char *dest_dir) {
    struct dirent *entry;
    DIR *dp = opendir(src_dir);

    if (dp == NULL) {
        perror("Directory opening error");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Only synchronize regular files
            char src_file[1024];
            char dest_file[1024];

            snprintf(src_file, sizeof(src_file), "%s/%s", src_dir, entry->d_name);
            snprintf(dest_file, sizeof(dest_file), "%s/%s", dest_dir, entry->d_name);
            
            sync_file(src_file, dest_file);
        }
    }

    closedir(dp);
}

// Main function to execute the synchronizer
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *src_dir = argv[1];
    const char *dest_dir = argv[2];

    // Create destination directory if it does not exist
    struct stat st;
    if (stat(dest_dir, &st) == -1) {
        if (mkdir(dest_dir, 0777) != 0) {
            perror("Error creating destination directory");
            return EXIT_FAILURE;
        }
    }

    printf("Starting synchronization from %s to %s...\n", src_dir, dest_dir);
    sync_directory(src_dir, dest_dir);
    printf("Synchronization finished successfully.\n");

    return EXIT_SUCCESS;
}