//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

typedef struct {
    char filename[256];
    long filesize;
    char *filetype;
} FileMetadata;

void get_file_type(const char *filename, char *filetype) {
    const char *ext = strrchr(filename, '.');
    if (ext) {
        ext++; // Move past the dot
        if (strcmp(ext, "jpg") == 0 || strcmp(ext, "jpeg") == 0) {
            strcpy(filetype, "Image");
        } else if (strcmp(ext, "png") == 0) {
            strcpy(filetype, "Image");
        } else if (strcmp(ext, "txt") == 0) {
            strcpy(filetype, "Text");
        } else if (strcmp(ext, "mp3") == 0) {
            strcpy(filetype, "Audio");
        } else if (strcmp(ext, "mp4") == 0) {
            strcpy(filetype, "Video");
        } else {
            strcpy(filetype, "Unknown");
        }
    } else {
        strcpy(filetype, "Unknown");
    }
}

FileMetadata extract_metadata(const char *filepath) {
    FileMetadata metadata;
    strcpy(metadata.filename, filepath);
    FILE *file = fopen(filepath, "rb");
    if (!file) {
        perror("File open error");
        metadata.filesize = -1; // Indicating error
        metadata.filetype = "Error";
        return metadata;
    }
    
    fseek(file, 0, SEEK_END);
    metadata.filesize = ftell(file);
    fclose(file);
    
    // File type extraction
    char *filetype = malloc(10);
    get_file_type(filepath, filetype);
    metadata.filetype = filetype;

    return metadata;
}

void display_metadata(FileMetadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("Filesize: %ld bytes\n", metadata->filesize);
    printf("File type: %s\n", metadata->filetype);
}

void free_metadata(FileMetadata *metadata) {
    free(metadata->filetype);
}

void list_directory_metadata(const char *dirpath) {
    struct dirent *entry;
    DIR *dp = opendir(dirpath);
    if (dp == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Process only regular files
            char filepath[512];
            snprintf(filepath, sizeof(filepath), "%s/%s", dirpath, entry->d_name);
            FileMetadata metadata = extract_metadata(filepath);
            display_metadata(&metadata);
            free_metadata(&metadata);
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    list_directory_metadata(argv[1]);

    return EXIT_SUCCESS;
}