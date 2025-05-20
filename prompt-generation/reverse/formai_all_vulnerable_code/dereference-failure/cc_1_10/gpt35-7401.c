//FormAI DATASET v1.0 Category: File Synchronizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void synchronize(char* source_dir, char* dest_dir);
void copy_file(char* source_file, char* dest_file);
void create_directory(char* dir);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s source_dir dest_dir\n", argv[0]);
        exit(1);
    }

    char* source_dir = argv[1];
    char* dest_dir = argv[2];

    synchronize(source_dir, dest_dir);

    return 0;
}

void synchronize(char* source_dir, char* dest_dir) {
    DIR* dir;
    struct dirent* entry;

    // Open the source directory
    dir = opendir(source_dir);

    if (!dir) {
        printf("Error opening source directory.\n");
        exit(-1);
    }

    // Read each file in the directory
    while ((entry = readdir(dir)) != NULL) {
        // Ignore the current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the full path of the source file
        char source_file_path[1024];
        sprintf(source_file_path, "%s/%s", source_dir, entry->d_name);

        // Construct the full path of the destination file
        char dest_file_path[1024];
        sprintf(dest_file_path, "%s/%s", dest_dir, entry->d_name);

        struct stat stat_source_buf;
        if (stat(source_file_path, &stat_source_buf) == -1) {
            printf("Error file status.\n");
            continue;
        }

        // If the entry is a directory, call synchronize recursively
        if (S_ISDIR(stat_source_buf.st_mode)) {
            create_directory(dest_file_path);
            synchronize(source_file_path, dest_file_path);
        }
        // If the entry is a file, copy it to the destination directory
        else if (S_ISREG(stat_source_buf.st_mode)) {
            copy_file(source_file_path, dest_file_path);
        }
    }

    closedir(dir);
}

void copy_file(char* source_file, char* dest_file) {
    FILE *source, *dest;
    size_t bytes_read;
    char buffer[4096];

    source = fopen(source_file, "rb");

    if (!source) {
        printf("Error opening source file.\n");
        return;
    }

    dest = fopen(dest_file, "wb");

    if (!dest) {
        printf("Error opening destination file.\n");
        fclose(source);
        return;
    }

    // Copy the contents of the file to the destination
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes_read, dest);
    }

    fclose(source);
    fclose(dest);
}

void create_directory(char* dir) {
    // Check if the directory exists
    struct stat st;
    if (stat(dir, &st) == 0) {
        return;
    }

    // Create the directory
    if (mkdir(dir, 0700) == -1) {
        printf("Error creating directory.\n");
        exit(-1);
    }
}