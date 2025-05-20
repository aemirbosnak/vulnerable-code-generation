//FormAI DATASET v1.0 Category: File Synchronizer ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/time.h>
#include <utime.h>

// Function to recursively copy files from one directory to another
void copyDir(char *dir_source, char *dir_dest) {
    DIR *source = opendir(dir_source); // Open source directory
    struct dirent *entry; // Create dirent struct to hold directory entry information
    char source_path[1024], dest_path[1024]; // Create two char arrays to hold the source and destination file paths
    
    // Check if source directory exists
    if (source == NULL) {
        return;
    }

    // Loop through each directory entry in the source directory
    while ((entry = readdir(source)) != NULL) {
        // If directory entry is a directory, ignore it if it is "." or "..", otherwise recursively copy the contents of the directory
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            // Create the new directory in the destination directory
            sprintf(source_path, "%s/%s", dir_source, entry->d_name);
            sprintf(dest_path, "%s/%s", dir_dest, entry->d_name);
            mkdir(dest_path, 0777);

            // Recursively copy the contents of the directory
            copyDir(source_path, dest_path);
        }
        // If directory entry is a file, copy it to the destination directory
        else if (entry->d_type == DT_REG) {
            // Set the source and destination file paths
            sprintf(source_path, "%s/%s", dir_source, entry->d_name);
            sprintf(dest_path, "%s/%s", dir_dest, entry->d_name);

            // Open read and write file descriptors for source and destination paths
            int fd_src = open(source_path, O_RDONLY);
            int fd_dest = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);

            // Test if read and write file descriptors opened successfully
            if (fd_src < 0 || fd_dest < 0) {
                perror("Error opening file");
                continue;
            }

            // Create a buffer to hold file contents
            char buffer[4096];
            ssize_t bytes;

            // Write contents of source file to destination file
            while ((bytes = read(fd_src, buffer, sizeof(buffer))) > 0) {
                write(fd_dest, buffer, bytes);
            }

            // Set ownership, mode, and modification time of destination file to match source file
            struct stat st;
            stat(source_path, &st);
            fchown(fd_dest, st.st_uid, st.st_gid);
            fchmod(fd_dest, st.st_mode);
            struct utimbuf ut;
            ut.actime = st.st_atime;
            ut.modtime = st.st_mtime;
            utime(dest_path, &ut);

            // Close file descriptors
            close(fd_src);
            close(fd_dest);
        }
    }

    // Close source directory
    closedir(source);
}

int main(int argc, char *argv[]) {
    // Check if there are at least two arguments (source and destination directories)
    if (argc < 3) {
        printf("Usage: %s [source_directory] [destination_directory]\n", argv[0]);
        exit(1);
    }

    // Check if source directory exists
    if (opendir(argv[1]) == NULL) {
        printf("Error: Source directory does not exist\n");
        exit(1);
    }

    // Check if destination directory exists
    if (opendir(argv[2]) == NULL) {
        printf("Error: Destination directory does not exist\n");
        exit(1);
    }

    // Copy source directory contents to destination directory
    copyDir(argv[1], argv[2]);

    printf("File sync complete!\n");

    return 0;
}