//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_FILENAME 256
#define MAX_PATH 512

void create_directory(const char *path) {
    if (mkdir(path, 0755) == -1) {
        perror("Error creating backup directory");
        exit(EXIT_FAILURE);
    }
    printf("🎉 Backup directory '%s' created! 🎉\n", path);
}

void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    FILE *dest = fopen(destination, "wb");

    if (!src || !dest) {
        perror("Error opening files for copy");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    fclose(src);
    fclose(dest);
    printf("✅ Successfully backed up '%s' to '%s'!\n", source, destination);
}

void backup_file(const char *file, const char *backup_dir) {
    char backup_path[MAX_PATH];
    snprintf(backup_path, sizeof(backup_path), "%s/%s.bak", backup_dir, file);

    copy_file(file, backup_path);
}

void get_files_in_directory(const char *directory, char files[][MAX_FILENAME], int *count) {
    DIR *dir = opendir(directory);
    struct dirent *entry;

    if (!dir) {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {  // Regular file
            strncpy(files[*count], entry->d_name, MAX_FILENAME);
            (*count)++;
        }
    }

    closedir(dir);
}

void display_files(char files[][MAX_FILENAME], int count) {
    printf("📁 Files in current directory:\n");
    for (int i = 0; i < count; i++) {
        printf("    %s\n", files[i]);
    }
}

int main() {
    char current_directory[MAX_PATH];
    char backup_directory[MAX_PATH];
    char files[100][MAX_FILENAME]; 
    int file_count = 0;

    printf("✨ Welcome to the C File Backup System! ✨\n");

    // Get current directory
    if (getcwd(current_directory, sizeof(current_directory)) == NULL) {
        perror("Error getting current directory");
        exit(EXIT_FAILURE);
    }

    printf("🔍 Current Directory: %s\n", current_directory);

    // Prompt user for backup directory
    printf("📂 Enter the backup directory name: ");
    scanf("%s", backup_directory);
    
    create_directory(backup_directory);

    // Get all files in the current directory
    get_files_in_directory(current_directory, files, &file_count);

    // Display files to the user
    display_files(files, file_count);

    // Backup each file
    for (int i = 0; i < file_count; i++) {
        backup_file(files[i], backup_directory);
    }

    printf("🎊 All files have been backed up successfully to '%s'! 🎊\n", backup_directory);
    return 0;
}