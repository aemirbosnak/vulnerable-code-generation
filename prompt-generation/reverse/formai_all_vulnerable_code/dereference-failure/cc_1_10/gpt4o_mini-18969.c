//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 1024
#define BUFFER_SIZE 8192

void display_menu();
void backup_file(const char *source, const char *destination);
void backup_directory(const char *source, const char *destination);
void create_backup(const char *source, const char *destination);
void copy_file(const char *src, const char *dest);
void copy_directory(const char *src, const char *dest);

int main() {
    char source[MAX_PATH_LENGTH];
    char destination[MAX_PATH_LENGTH];

    while (1) {
        display_menu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 3) {
            printf("Exiting the program.\n");
            break;
        }
        
        printf("Enter the source path: ");
        scanf("%s", source);
        printf("Enter the destination path: ");
        scanf("%s", destination);
        
        create_backup(source, destination);
    }
    
    return 0;
}

void display_menu() {
    printf("\n---- File Backup System ----\n");
    printf("1. Backup a file\n");
    printf("2. Backup a directory\n");
    printf("3. Exit\n");
}

void create_backup(const char *source, const char *destination) {
    struct stat statbuf;
    
    if (stat(source, &statbuf) == -1) {
        perror("Stat error");
        return;
    }
    
    if (S_ISDIR(statbuf.st_mode)) {
        backup_directory(source, destination);
    } else if (S_ISREG(statbuf.st_mode)) {
        backup_file(source, destination);
    } else {
        printf("Unsupported file type.\n");
    }
}

void backup_file(const char *source, const char *destination) {
    char dest_file[MAX_PATH_LENGTH];
    snprintf(dest_file, sizeof(dest_file), "%s/%s.bak", destination, strrchr(source, '/') ? strrchr(source, '/') + 1 : source);
    copy_file(source, dest_file);
    printf("Backup of file '%s' created as '%s'.\n", source, dest_file);
}

void backup_directory(const char *source, const char *destination) {
    DIR *dir = opendir(source);
    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip the special entries "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char source_path[MAX_PATH_LENGTH];
        char dest_path[MAX_PATH_LENGTH];

        snprintf(source_path, sizeof(source_path), "%s/%s", source, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", destination, entry->d_name);

        if (entry->d_type == DT_DIR) {
            mkdir(dest_path, 0755);
            backup_directory(source_path, dest_path);
        } else if (entry->d_type == DT_REG) {
            copy_file(source_path, dest_path);
            printf("Backup of file '%s' created as '%s'.\n", source_path, dest_path);
        }
    }
    
    closedir(dir);
}

void copy_file(const char *src, const char *dest) {
    FILE *sourceFile = fopen(src, "rb");
    FILE *destinationFile = fopen(dest, "wb");
    
    if (!sourceFile || !destinationFile) {
        perror("File error");
        if (sourceFile) fclose(sourceFile);
        return;
    }
    
    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destinationFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);
}