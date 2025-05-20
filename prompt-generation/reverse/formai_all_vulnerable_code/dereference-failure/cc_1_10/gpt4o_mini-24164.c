//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_PATH 1024
#define MAX_METADATA_SIZE 256
#define EXTENSION_SIZE 5

typedef struct {
    char name[MAX_PATH];
    char type[EXTENSION_SIZE];
    long size;
    time_t creation_time;
    char owner[MAX_METADATA_SIZE];
} FileMetadata;

void get_file_owner(const char *filename, char *owner) {
    struct stat fileStat;
    if(stat(filename, &fileStat) >= 0) {
        sprintf(owner, "%d", fileStat.st_uid); // Just using UID for simplicity
    } else {
        strcpy(owner, "Unknown");
    }
}

void get_file_metadata(const char *filename, FileMetadata *metadata) {
    struct stat fileStat;
    if(stat(filename, &fileStat) < 0) {
        perror("Failed to get file stats");
        return;
    }

    strncpy(metadata->name, filename, MAX_PATH);
    metadata->size = fileStat.st_size;
    metadata->creation_time = fileStat.st_ctime; // Using creation time
    strcpy(metadata->owner, "UID: ");
    get_file_owner(filename, metadata->owner);

    const char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) {
        strcpy(metadata->type, "N/A");
    } else {
        strncpy(metadata->type, dot + 1, EXTENSION_SIZE - 1);
        metadata->type[EXTENSION_SIZE - 1] = '\0'; // Null-terminate
    }
}

void display_metadata(FileMetadata *metadata) {
    printf("File Name: %s\n", metadata->name);
    printf("File Type: %s\n", metadata->type);
    printf("File Size: %ld bytes\n", metadata->size);
    printf("Creation Time: %s", ctime(&metadata->creation_time));
    printf("Owner UID: %s\n", metadata->owner);
}

void extract_metadata_from_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);
    if (dp == NULL) {
        perror("Unable to open directory");
        return;
    }

    FileMetadata metadata;
    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Only regular files
            char file_path[MAX_PATH];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);
            get_file_metadata(file_path, &metadata);
            display_metadata(&metadata);
            printf("--------------------------\n");
        }
    }
    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    extract_metadata_from_directory(argv[1]);

    return EXIT_SUCCESS;
}