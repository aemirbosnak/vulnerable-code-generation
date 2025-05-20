//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

// Function to copy a file
void copyFile(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (src == NULL) {
        perror("Source file opening failed");
        return;
    }

    FILE *dest = fopen(destination, "wb");
    if (dest == NULL) {
        perror("Destination file opening failed");
        fclose(src);
        return;
    }

    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    fclose(src);
    fclose(dest);
}

// Function to create a backup of a directory
void backupDirectory(const char *sourceDir, const char *destinationDir) {
    struct stat st;
    if (stat(sourceDir, &st) == -1) {
        perror("Source directory check failed");
        return;
    }

    DIR *dir = opendir(sourceDir);
    if (dir == NULL) {
        perror("Directory opening failed");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip the special entries
        }

        // Construct full path for source and destination
        char sourcePath[512], destPath[512];
        snprintf(sourcePath, sizeof(sourcePath), "%s/%s", sourceDir, entry->d_name);
        snprintf(destPath, sizeof(destPath), "%s/%s", destinationDir, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // Recursively process directories
            mkdir(destPath, 0755);
            backupDirectory(sourcePath, destPath);
        } else if (entry->d_type == DT_REG) {
            // Copy files
            copyFile(sourcePath, destPath);
        }
    }
    closedir(dir);
}

// The main function, where the magic happens
int main(int argc, char *argv[]) {
    // A warm welcome to our artistic file backup system
    printf("Welcome to the Artistic File Backup System 🎨📂\n");
    
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source = argv[1];
    const char *destination = argv[2];

    // Check if source exists
    struct stat st;
    if (stat(source, &st) == -1) {
        perror("Source path invalid");
        return EXIT_FAILURE;
    }

    // Create the destination directory if it doesn't exist
    if (S_ISDIR(st.st_mode)) {
        mkdir(destination, 0755);
        printf("Backing up directory: %s to %s\n", source, destination);
        backupDirectory(source, destination);
    } else if (S_ISREG(st.st_mode)) {
        // For single files
        printf("Backing up file: %s to %s\n", source, destination);
        copyFile(source, destination);
    } else {
        fprintf(stderr, "Unsupported type for source: %s\n", source);
        return EXIT_FAILURE;
    }

    printf("Backup completed successfully! 🥳✨\n");
    return EXIT_SUCCESS;
}