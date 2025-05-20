//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_BUFFER 1024
#define IMAGE_EXTENSIONS ".jpg,.jpeg,.png,.gif"
#define AUDIO_EXTENSIONS ".mp3,.wav,.flac"
#define VIDEO_EXTENSIONS ".mp4,.avi,.mkv,.mov"

void extract_file_metadata(const char *file_path) {
    struct stat file_stat;
    if(stat(file_path, &file_stat) == -1) {
        perror("stat() error");
        return;
    }

    char *file_type = "unknown";
    if(S_ISREG(file_stat.st_mode)) {
        if (strstr(file_path, ".jpg") || strstr(file_path, ".jpeg")) {
            file_type = "Image (JPEG)";
        } else if (strstr(file_path, ".png")) {
            file_type = "Image (PNG)";
        } else if (strstr(file_path, ".gif")) {
            file_type = "Image (GIF)";
        } else if (strstr(file_path, ".mp3") || strstr(file_path, ".wav") || strstr(file_path, ".flac")) {
            file_type = "Audio";
        } else if (strstr(file_path, ".mp4") || strstr(file_path, ".avi") || strstr(file_path, ".mkv") || strstr(file_path, ".mov")) {
            file_type = "Video";
        }
    }

    printf("File: %s\n", file_path);
    printf("Type: %s\n", file_type);
    printf("Size: %ld bytes\n", file_stat.st_size);
    printf("Last Modified: %ld\n\n", file_stat.st_mtime);
}

void list_files_in_directory(const char *directory_path) {
    struct dirent *entry;
    DIR *dp = opendir(directory_path);

    if (dp == NULL) {
        perror("opendir() error");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Only regular files
            char file_path[MAX_BUFFER];
            snprintf(file_path, sizeof(file_path), "%s/%s", directory_path, entry->d_name);
            extract_file_metadata(file_path);
        }
    }

    closedir(dp);
}

void validate_directory(const char *path) {
    struct stat path_stat;
    if (stat(path, &path_stat) == -1) {
        perror("stat() error");
        exit(EXIT_FAILURE);
    }

    if (!S_ISDIR(path_stat.st_mode)) {
        fprintf(stderr, "Error: %s is not a directory\n", path);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory_path = argv[1];
    validate_directory(directory_path);
    list_files_in_directory(directory_path);

    return EXIT_SUCCESS;
}