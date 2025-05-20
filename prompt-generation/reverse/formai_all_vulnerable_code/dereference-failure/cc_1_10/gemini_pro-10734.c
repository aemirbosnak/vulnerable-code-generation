//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

// Let's get this syncing party started!
int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Hey there, syncing enthusiast! Looks like you forgot to provide source and destination paths.\n");
        printf("Make sure to include them next time, like so: %s <source path> <destination path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Prepare for the syncing extravaganza!
    char* source_path = argv[1];
    char* dest_path = argv[2];

    // Let's check if the source path exists. If not, let's give a friendly reminder.
    DIR* source_dir = opendir(source_path);
    if (source_dir == NULL) {
        printf("Hold on there, intrepid syncer! The source path you provided doesn't exist.\n");
        printf("Please double-check the path and try again.\n");
        return EXIT_FAILURE;
    }

    // Now, let's see if the destination path is ready for action. If not, let's create it.
    DIR* dest_dir = opendir(dest_path);
    if (dest_dir == NULL) {
        printf("Hang on a sec, eager synchronizer! The destination path doesn't exist yet.\n");
        printf("Let's take care of that: %s\n", mkdir(dest_path, 0755) == 0 ? "Directory created!" : "Uh-oh, couldn't create the directory.");
        dest_dir = opendir(dest_path);
    }

    // Time to dive into the syncing vortex!
    struct dirent* source_dirent;
    while ((source_dirent = readdir(source_dir)) != NULL) {
        // Skip the sneaky dots.
        if (strcmp(source_dirent->d_name, ".") == 0 || strcmp(source_dirent->d_name, "..") == 0) {
            continue;
        }

        // Construct the absolute paths for source and destination.
        char source_file_path[PATH_MAX];
        snprintf(source_file_path, PATH_MAX, "%s/%s", source_path, source_dirent->d_name);
        char dest_file_path[PATH_MAX];
        snprintf(dest_file_path, PATH_MAX, "%s/%s", dest_path, source_dirent->d_name);

        // Let's check if the file already exists in the destination.
        struct stat dest_file_stat;
        if (stat(dest_file_path, &dest_file_stat) == 0) {
            // It's already there! Let's compare the timestamps and update if necessary.
            struct stat source_file_stat;
            stat(source_file_path, &source_file_stat);
            if (source_file_stat.st_mtime > dest_file_stat.st_mtime) {
                printf("Found a newer version of %s! Updating the destination.\n", source_dirent->d_name);
                if (rename(source_file_path, dest_file_path) == 0) {
                    printf("File updated successfully!\n");
                } else {
                    printf("Oops, there was a hiccup while updating %s. Please check if you have the necessary permissions.\n", source_dirent->d_name);
                }
            } else {
                printf("Destination file is up-to-date: %s\n", source_dirent->d_name);
            }
        } else {
            // It's a new file! Let's copy it over.
            printf("Found a new file: %s. Copying it to the destination.\n", source_dirent->d_name);
            if (copy_file(source_file_path, dest_file_path) == 0) {
                printf("File copied successfully!\n");
            } else {
                printf("Oops, there was a problem copying %s. Please check if you have the necessary permissions.\n", source_dirent->d_name);
            }
        }
    }

    // And with that, our syncing marathon is complete!
    printf("Synchronization complete! Your files are now in sync.\n");
    return EXIT_SUCCESS;
}

// A helper function to copy a file from one location to another.
int copy_file(char* source_path, char* dest_path) {
    FILE* source_file = fopen(source_path, "rb");
    if (source_file == NULL) {
        printf("Couldn't open source file: %s\n", source_path);
        return -1;
    }

    FILE* dest_file = fopen(dest_path, "wb");
    if (dest_file == NULL) {
        printf("Couldn't open destination file: %s\n", dest_path);
        fclose(source_file);
        return -1;
    }

    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, 1024, source_file)) > 0) {
        if (fwrite(buffer, 1, bytes_read, dest_file) != bytes_read) {
            printf("Error writing to destination file: %s\n", dest_path);
            fclose(source_file);
            fclose(dest_file);
            return -1;
        }
    }

    fclose(source_file);
    fclose(dest_file);
    return 0;
}