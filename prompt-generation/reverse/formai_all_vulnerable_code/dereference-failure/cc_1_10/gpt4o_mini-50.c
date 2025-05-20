//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define HASH_SIZE 256

typedef struct {
    char *path;
    unsigned long hash;
} FileRecord;

unsigned long hash_file(const char *path) {
    FILE *file;
    unsigned long hash = 5381; // Start with a magic number
    int c;

    file = fopen(path, "rb");
    if (!file) {
        return 0;
    }
    
    while ((c = fgetc(file)) != EOF) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    
    fclose(file);
    return hash;
}

void sync_files(const char *source_dir, const char *dest_dir) {
    DIR *source, *dest;
    struct dirent *entry;

    source = opendir(source_dir);
    dest = opendir(dest_dir);

    if (!source || !dest) {
        perror("Error opening directories");
        exit(EXIT_FAILURE);
    }

    FileRecord *source_records = malloc(sizeof(FileRecord) * HASH_SIZE);
    FileRecord *dest_records = malloc(sizeof(FileRecord) * HASH_SIZE);
    
    size_t src_count = 0, dest_count = 0;

    // Read source directory
    while ((entry = readdir(source)) != NULL) {
        if (entry->d_type == DT_REG) {
            char full_path[MAX_PATH];
            snprintf(full_path, MAX_PATH, "%s/%s", source_dir, entry->d_name);
            unsigned long hash = hash_file(full_path);
            if (hash != 0) {
                source_records[src_count].path = strdup(full_path);
                source_records[src_count].hash = hash;
                src_count++;
            }
        }
    }

    // Read destination directory
    while ((entry = readdir(dest)) != NULL) {
        if (entry->d_type == DT_REG) {
            char full_path[MAX_PATH];
            snprintf(full_path, MAX_PATH, "%s/%s", dest_dir, entry->d_name);
            unsigned long hash = hash_file(full_path);
            if (hash != 0) {
                dest_records[dest_count].path = strdup(full_path);
                dest_records[dest_count].hash = hash;
                dest_count++;
            }
        }
    }

    // Synchronize files based on hash values
    for (size_t i = 0; i < src_count; i++) {
        int found = 0;
        for (size_t j = 0; j < dest_count; j++) {
            if (source_records[i].hash == dest_records[j].hash) {
                found = 1;
                break;
            }
        }
        if (!found) {
            // Copy file to destination
            char command[MAX_PATH * 2];
            snprintf(command, sizeof(command), "cp %s %s", source_records[i].path, dest_dir);
            system(command);
            printf("Copied: %s to %s\n", source_records[i].path, dest_dir);
        }
    }

    // Free allocated memory
    for (size_t i = 0; i < src_count; i++) {
        free(source_records[i].path);
    }
    for (size_t j = 0; j < dest_count; j++) {
        free(dest_records[j].path);
    }
    free(source_records);
    free(dest_records);

    closedir(source);
    closedir(dest);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *source_dir = argv[1];
    const char *dest_dir = argv[2];

    sync_files(source_dir, dest_dir);
    
    return EXIT_SUCCESS;
}