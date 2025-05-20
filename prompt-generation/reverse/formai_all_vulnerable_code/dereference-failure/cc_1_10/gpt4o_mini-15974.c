//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 4096

void introspect(const char *message) {
    printf("[INFO]: %s\n", message);
}

int is_file_exist(const char *filename) {
    struct stat buffer;   
    return (stat(filename, &buffer) == 0);
}

void sync_file(const char *src, const char *dest) {
    FILE *source, *destination;
    char buffer[BUFFER_SIZE];
    size_t bytes;

    source = fopen(src, "rb");
    if (!source) {
        introspect("Could not open source file.");
        return;
    }

    destination = fopen(dest, "wb");
    if (!destination) {
        introspect("Could not open destination file.");
        fclose(source);
        return;
    }

    while ((bytes = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);
}

void sync_directory(const char *src_dir, const char *dest_dir) {
    struct dirent *de;
    DIR *src = opendir(src_dir);
    
    if (!src) {
        introspect("Could not open source directory.");
        return;
    }

    while ((de = readdir(src)) != NULL) {
        if (strcmp(de->d_name, ".") != 0 && strcmp(de->d_name, "..") != 0) {
            char src_path[MAX_PATH];
            char dest_path[MAX_PATH];

            snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, de->d_name);
            snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, de->d_name);

            if (is_file_exist(dest_path)) {
                introspect("File exists, skipping synchronization.");
            } else {
                introspect("Synchronizing file...");
                sync_file(src_path, dest_path);
                introspect("File synchronized.");
            }
        }
    }

    closedir(src);
}

int main(int argc, char *argv[]) {
    introspect("C File Synchronizer: An introspective journey.");

    if (argc != 3) {
        introspect("Usage: ./sync_program <source_directory> <destination_directory>");
        return 1;
    }

    const char *source_directory = argv[1];
    const char *destination_directory = argv[2];

    introspect("Starting synchronization process...");
    sync_directory(source_directory, destination_directory);

    introspect("Synchronization process completed.");
    return 0;
}