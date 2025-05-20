//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void print_welcome_message() {
    printf("***************************************\n");
    printf("*                                     *\n");
    printf("*       C File Backup System          *\n");
    printf("*                                     *\n");
    printf("***************************************\n\n");
}

void display_instructions() {
    printf("This program will help you back up your files.\n");
    printf("You need to provide a source directory and a target directory.\n");
    printf("All files from the source directory will be copied to the target directory.\n");
    printf("Let's get started!\n\n");
}

int create_directory(const char *path) {
    return mkdir(path, 0777);
}

void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (!src) {
        perror("Failed to open source file");
        return;
    }

    FILE *dest = fopen(destination, "wb");
    if (!dest) {
        perror("Failed to create destination file");
        fclose(src);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    fclose(src);
    fclose(dest);
    printf("Copied: %s to %s\n", source, destination);
}

void backup_files(const char *source_dir, const char *target_dir) {
    DIR *dir = opendir(source_dir);
    if (!dir) {
        perror("Failed to open source directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // Ignore hidden files and directories
        }

        char source_path[512];
        char target_path[512];

        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        snprintf(target_path, sizeof(target_path), "%s/%s", target_dir, entry->d_name);

        if (entry->d_type == DT_REG) { // If it's a regular file
            copy_file(source_path, target_path);
        } else if (entry->d_type == DT_DIR) { // If it's a directory
            create_directory(target_path);
            backup_files(source_path, target_path); // Recursive backup
        }
    }

    closedir(dir);
}

int main() {
    print_welcome_message();
    display_instructions();

    char source_dir[256];
    char target_dir[256];

    printf("Enter source directory path: ");
    scanf("%s", source_dir);
    
    printf("Enter target directory path: ");
    scanf("%s", target_dir);

    if (create_directory(target_dir) != 0) {
        perror("Failed to create target directory");
        return EXIT_FAILURE;
    }

    backup_files(source_dir, target_dir);
    printf("\nBackup completed successfully!\n");
    return EXIT_SUCCESS;
}