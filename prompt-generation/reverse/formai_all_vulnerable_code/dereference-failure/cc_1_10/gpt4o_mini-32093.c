//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 256
#define BUFFER_SIZE 1024

void list_files(const char *dir_path) {
    struct dirent *de;
    DIR *dr = opendir(dir_path);
    
    if (dr == NULL) {
        printf("Could not open directory: %s\n", dir_path);
        return;
    }
    
    printf("Files in \"%s\":\n", dir_path);
    while ((de = readdir(dr)) != NULL) {
        if (strcmp(de->d_name, ".") != 0 && strcmp(de->d_name, "..") != 0) {
            printf(" - %s\n", de->d_name);
        }
    }
    closedir(dr);
}

int backup_file(const char *source_file, const char *dest_file) {
    FILE *source = fopen(source_file, "rb");
    FILE *destination = fopen(dest_file, "wb");
    char buffer[BUFFER_SIZE];
    size_t bytes;

    if (source == NULL) {
        printf("Could not open source file: %s\n", source_file);
        return 1;
    }
    if (destination == NULL) {
        printf("Could not open destination file: %s\n", dest_file);
        fclose(source);
        return 1;
    }

    // Copy the file data
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, source)) != 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);
    printf("Backed up: %s to %s\n", source_file, dest_file);
    return 0;
}

int file_exists(const char *file_path) {
    struct stat buffer;
    return (stat(file_path, &buffer) == 0);
}

void get_absolute_path(const char *base_path, const char *relative_path, char *absolute_path) {
    snprintf(absolute_path, MAX_PATH, "%s/%s", base_path, relative_path);
}

int main() {
    char source_dir[MAX_PATH], dest_dir[MAX_PATH];
    char source_file[MAX_PATH], dest_file[MAX_PATH];
    
    printf("Welcome to the Relaxed File Backup System!\n");
    
    printf("Enter the source directory: ");
    scanf("%s", source_dir);
    printf("Enter the destination directory: ");
    scanf("%s", dest_dir);

    while (1) {
        list_files(source_dir);

        printf("Enter the file you want to back up (or 'exit' to quit): ");
        scanf("%s", source_file);
        
        if (strcmp(source_file, "exit") == 0) {
            printf("Exiting backup system... Bye!\n");
            break;
        }

        get_absolute_path(source_dir, source_file, source_file);
        get_absolute_path(dest_dir, source_file, dest_file);
        
        if (file_exists(dest_file)) {
            char response;
            printf("File %s already exists in the destination. Overwrite? (y/n): ", dest_file);
            scanf(" %c", &response);
            if (response != 'y' && response != 'Y') {
                printf("Skipping backup of %s...\n", source_file);
                continue;
            }
        }

        if (backup_file(source_file, dest_file) != 0) {
            printf("Failed to back up %s\n", source_file);
        }
    }

    return 0;
}