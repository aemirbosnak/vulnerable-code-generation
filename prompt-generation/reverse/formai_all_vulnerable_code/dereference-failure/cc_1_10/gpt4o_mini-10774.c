//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_METADATA_LENGTH 1024
#define MAX_FILES 100
#define METADATA_FILE "metadata.txt"

typedef struct {
    char filename[256];
    char filetype[32];
    size_t size;
    time_t last_modified;
} FileMetadata;

void extract_metadata(const char *directory, FileMetadata *files, int *count) {
    struct dirent *entry;
    struct stat file_info;
    DIR *dir = opendir(directory);

    if (dir == NULL) {
        perror("Unable to open directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files

        char filepath[512];
        snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);

        if (stat(filepath, &file_info) == -1) {
            perror("stat error");
            continue;
        }

        if (S_ISREG(file_info.st_mode)) {
            strcpy(files[*count].filename, entry->d_name);
            strcpy(files[*count].filetype, strrchr(entry->d_name, '.') + 1);
            files[*count].size = file_info.st_size;
            files[*count].last_modified = file_info.st_mtime;
            (*count)++;
        }
    }

    closedir(dir);
}

void write_metadata_to_file(FileMetadata *files, int count) {
    FILE *fp = fopen(METADATA_FILE, "w");
    if (fp == NULL) {
        perror("Unable to open metadata file");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "Filename\tFiletype\tSize (bytes)\tLast Modified\n");
    fprintf(fp, "--------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s\t%s\t%zu\t%s", 
                files[i].filename,
                files[i].filetype,
                files[i].size,
                ctime(&files[i].last_modified)); // Print formatted date
    }

    fclose(fp);
    printf("Metadata successfully written to %s\n", METADATA_FILE);
}

void display_metadata(FileMetadata *files, int count) {
    printf("Filename\tFiletype\tSize (bytes)\tLast Modified\n");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t%zu\t%s", 
               files[i].filename,
               files[i].filetype,
               files[i].size,
               ctime(&files[i].last_modified));
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FileMetadata files[MAX_FILES];
    int count = 0;

    extract_metadata(argv[1], files, &count);

    if (count > 0) {
        display_metadata(files, count);
        write_metadata_to_file(files, count);
    } else {
        printf("No files found in the specified directory.\n");
    }

    return EXIT_SUCCESS;
}