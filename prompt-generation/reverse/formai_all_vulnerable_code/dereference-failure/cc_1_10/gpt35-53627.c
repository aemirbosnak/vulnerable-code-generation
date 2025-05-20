//FormAI DATASET v1.0 Category: File Synchronizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

char *destination_directory = "/home/user/destination"; // Replace with the destination directory path

void synchronize_files(char *source_path, char *destination_path);

void synchronize_directories(char *source_path, char *destination_path);

void copy_file(char *source_path, char *destination_path);

void create_directory(char *directory_path);

void synchronize_files(char *source_path, char *destination_path) {
    struct stat source_stat, destination_stat;
    if (stat(source_path, &source_stat) < 0) {
        printf("Failed to get file stat: %s - Skipping file...\n", source_path);
        return;
    }
    if (stat(destination_path, &destination_stat) < 0) {
        printf("File does not exist: %s - Copying file...\n", destination_path);
        copy_file(source_path, destination_path);
    } else if (source_stat.st_mtime > destination_stat.st_mtime) {
        printf("File has been modified: %s - Copying file...\n", source_path);
        copy_file(source_path, destination_path);
    }
}

void synchronize_directories(char *source_path, char *destination_path) {
    DIR *dir;
    struct dirent *entry;
    char *source_file_path, *destination_file_path;
    if ((dir = opendir(source_path)) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            if ((strcmp(entry->d_name, ".") == 0) || (strcmp(entry->d_name, "..") == 0)) {
                continue;
            }
            source_file_path = (char *) malloc(sizeof(char) * (strlen(source_path) + strlen(entry->d_name) + 2));
            snprintf(source_file_path, strlen(source_path) + strlen(entry->d_name) + 2, "%s/%s", source_path, entry->d_name);
            destination_file_path = (char *) malloc(sizeof(char) * (strlen(destination_path) + strlen(entry->d_name) + 2));
            snprintf(destination_file_path, strlen(destination_path) + strlen(entry->d_name) + 2, "%s/%s", destination_path, entry->d_name);
            if (entry->d_type == DT_DIR) {
                printf("Syncing directory: %s\n", source_file_path);
                synchronize_directories(source_file_path, destination_file_path);
            } else {
                printf("Syncing file: %s\n", source_file_path);
                synchronize_files(source_file_path, destination_file_path);
            }
            free(source_file_path);
            free(destination_file_path);
        }
        closedir(dir);
    }
}

void copy_file(char *source_path, char *destination_path) {
    FILE *source_file, *destination_file;
    char buffer[1024];
    size_t bytes_read;
    source_file = fopen(source_path, "rb");
    if (source_file == NULL) {
        printf("Failed to open source file: %s\n", source_path);
        return;
    }
    create_directory(destination_path);
    destination_file = fopen(destination_path, "wb");
    if (destination_file == NULL) {
        printf("Failed to open destination file: %s\n", destination_path);
        return;
    }
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        fwrite(buffer, 1, bytes_read, destination_file);
    }
    printf("File copied: %s\n", destination_path);
    fclose(source_file);
    fclose(destination_file);
}

void create_directory(char *directory_path) {
    char *parent_directory_path;
    struct stat directory_stat;
    if (stat(directory_path, &directory_stat) == 0) {
        return;
    }
    parent_directory_path = dirname(directory_path);
    create_directory(parent_directory_path);
    mkdir(directory_path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    printf("Directory created: %s\n", directory_path);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Source directory not provided!\n");
        return -1;
    }
    char *source_directory_path = argv[1];
    synchronize_directories(source_directory_path, destination_directory);
    printf("Synchronization complete!\n");
    return 0;
}