//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_FILES 1000

void create_backup_directory(const char *backup_dir);
void copy_file(const char *source, const char *destination);
void backup_files(const char *source_dir, const char *backup_dir);
void get_current_time(char *buffer);
void list_files(const char *directory, const char *backup_dir);
void prompt_user(const char *backup_dir);

int main() {
    char source_dir[MAX_PATH];
    char backup_dir[MAX_PATH];

    printf("Welcome to the Imaginative C File Backup System!\n");
    printf("Enter the source directory you want to backup: ");
    fgets(source_dir, MAX_PATH, stdin);
    source_dir[strcspn(source_dir, "\n")] = 0; // Remove newline

    printf("Now, enter the name for your backup directory: ");
    fgets(backup_dir, MAX_PATH, stdin);
    backup_dir[strcspn(backup_dir, "\n")] = 0; // Remove newline

    create_backup_directory(backup_dir);
    backup_files(source_dir, backup_dir);
    prompt_user(backup_dir);

    return 0;
}

void create_backup_directory(const char *backup_dir) {
    if (mkdir(backup_dir, 0755) == -1) {
        perror("Error creating backup directory");
        exit(EXIT_FAILURE);
    }
    printf("Backup directory '%s' created successfully!\n", backup_dir);
}

void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (!src) {
        perror("Error opening source file");
        return;
    }
    FILE *dst = fopen(destination, "wb");
    if (!dst) {
        perror("Error creating destination file");
        fclose(src);
        return;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dst);
    }

    fclose(src);
    fclose(dst);
    printf("Copied file from '%s' to '%s'\n", source, destination);
}

void backup_files(const char *source_dir, const char *backup_dir) {
    DIR *dir;
    struct dirent *entry;
    char source_path[MAX_PATH], backup_path[MAX_PATH];

    dir = opendir(source_dir);
    if (!dir) {
        perror("Error opening source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
            snprintf(backup_path, sizeof(backup_path), "%s/%s", backup_dir, entry->d_name);
            copy_file(source_path, backup_path);
        }
    }
    closedir(dir);
}

void get_current_time(char *buffer) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, 100, "Backup_%Y%m%d_%H%M%S", t);
}

void list_files(const char *directory, const char *backup_dir) {
    DIR *dir;
    struct dirent *entry;
    char file_path[MAX_PATH];

    dir = opendir(directory);
    if (!dir) {
        perror("Error opening directory");
        return;
    }

    printf("Files in '%s':\n", directory);
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            printf(" - %s\n", entry->d_name);
        }
    }
    closedir(dir);
}

void prompt_user(const char *backup_dir) {
    char choice[10];
    printf("\nWould you like to see the backed up files? (yes/no): ");
    fgets(choice, sizeof(choice), stdin);
    choice[strcspn(choice, "\n")] = 0; // Remove newline

    if (strcasecmp(choice, "yes") == 0) {
        list_files(backup_dir, backup_dir);
    } else {
        printf("Thank you for using the Imaginative C File Backup System!\n");
    }
}