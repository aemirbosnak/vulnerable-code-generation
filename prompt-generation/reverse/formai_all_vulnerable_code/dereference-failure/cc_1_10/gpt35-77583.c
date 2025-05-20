//FormAI DATASET v1.0 Category: File Synchronizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define CHUNK_SIZE 1024

/* Function to check if path is a directory */
bool is_directory(char* path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

/* Function to recursively copy files from source to destination */
void copy_files(char* source, char* destination) {
    DIR *dir = opendir(source);
    struct dirent *entry;
    char source_path[1000], dest_path[1000];
    while ((entry = readdir(dir)) != NULL) {
        sprintf(source_path, "%s/%s", source, entry->d_name);
        sprintf(dest_path, "%s/%s", destination, entry->d_name);
        if (entry->d_type == DT_DIR) {
            // If the entry is a directory, recursively copy the directory
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                mkdir(dest_path, 0777); // Create the directory in the destination path
                copy_files(source_path, dest_path); // Recursively copy files from the source directory to the new destination directory
            }
        } else if (entry->d_type == DT_REG) {
            // If the entry is a regular file, copy the file
            FILE* source_file = fopen(source_path, "rb"); // Open the source file in binary mode
            FILE* dest_file = fopen(dest_path, "wb"); // Open the destination file in binary mode
            char buf[CHUNK_SIZE];
            size_t bytes;
            while ((bytes = fread(buf, 1, CHUNK_SIZE, source_file)) > 0) { // Read the source file in chunks and write to the destination file
                fwrite(buf, 1, bytes, dest_file);
            }
            fclose(source_file); // Close the source file
            fclose(dest_file); // Close the destination file
        }
    }
    closedir(dir); // Close the source directory
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s source_directory destination_directory\n", argv[0]);
        return EXIT_FAILURE;
    }
    if (!is_directory(argv[1])) {
        printf("%s is not a directory.\n", argv[1]);
        return EXIT_FAILURE;
    }
    if (!is_directory(argv[2])) {
        printf("%s is not a directory.\n", argv[2]);
        return EXIT_FAILURE;
    }
    copy_files(argv[1], argv[2]); // Copy files from source directory to destination directory
    printf("Files synchronized successfully.\n");
    return EXIT_SUCCESS;
}