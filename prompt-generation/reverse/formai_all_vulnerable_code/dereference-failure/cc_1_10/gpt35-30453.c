//FormAI DATASET v1.0 Category: File Synchronizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int sync_files(char* source, char* destination) {
    DIR *dir;
    struct dirent *entry;

    // Open the source directory
    if ((dir = opendir(source)) == NULL) {
        printf("Unable to open directory: %s\n", source);
        return -1;
    }

    // Create the destination directory
    if (mkdir(destination, 0777) != 0) {
        printf("Unable to create directory: %s\n", destination);
        return -1;
    }

    // Loop through all files and subdirectories in the source directory
    while ((entry = readdir(dir)) != NULL) {
        // Skip over "." and ".." as well as any hidden files/folders that may exist
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0 || entry->d_name[0] == '.') {
            continue;
        }

        // Construct the full path for both the source and destination files
        char source_path[1024], dest_path[1024];
        snprintf(source_path, sizeof(source_path), "%s/%s", source, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", destination, entry->d_name);

        // Check the type of file
        struct stat sb;
        if (stat(source_path, &sb) == -1) {
            printf("Unable to get file info for: %s\n", source_path);
            return -1;
        }

        if (S_ISREG(sb.st_mode)) { // Regular file
            int source_fd, dest_fd;
            ssize_t bytes_read, bytes_written, total_bytes_written = 0;
            char buffer[4096];

            // Open both the source and destination files
            if ((source_fd = open(source_path, O_RDONLY)) == -1) {
                printf("Unable to open file: %s\n", source_path);
                return -1;
            }

            if ((dest_fd = open(dest_path, O_WRONLY | O_CREAT, sb.st_mode)) == -1) {
                printf("Unable to create file: %s\n", dest_path);
                return -1;
            }

            // Copy the file from source to destination
            while ((bytes_read = read(source_fd, buffer, sizeof(buffer))) > 0) {
                bytes_written = write(dest_fd, buffer, bytes_read);
                if (bytes_written == -1) {
                    printf("Unable to write to file: %s\n", dest_path);
                    return -1;
                }
                total_bytes_written += bytes_written;
            }

            // Close the files
            close(source_fd);
            close(dest_fd);

            // Verify that the file copy was successful
            if (total_bytes_written != sb.st_size) {
                printf("Unable to copy file: %s\n", source_path);
                return -1;
            }
            
            printf("Successfully synced file: %s\n", source_path);
        } else if (S_ISDIR(sb.st_mode)) { // Directory
            sync_files(source_path, dest_path); // Recursively sync subdirectories
        }
    }

    // Close the directory
    closedir(dir);

    return 0;
}

int main() {
    char source[1024], destination[1024];

    // Prompt the user for the source and destination directories
    printf("Enter the source directory: ");
    scanf("%s", source);

    printf("Enter the destination directory: ");
    scanf("%s", destination);

    // Sync the files
    if (sync_files(source, destination) == 0) {
        printf("Successfully synced all files!\n");
    } else {
        printf("Error syncing files.\n");
    }

    return 0;
}