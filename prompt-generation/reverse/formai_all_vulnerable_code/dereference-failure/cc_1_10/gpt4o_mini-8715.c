//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>

#define MAX_PATH_LENGTH 256
#define MAX_COMMAND_LENGTH 512

void display_menu();
void list_files(const char *path);
void create_directory(const char *path);
void delete_file(const char *filename);
void search_file(const char *filename, const char *path);
void print_error(const char *message);

int main() {
    char command[MAX_COMMAND_LENGTH];
    char path[MAX_PATH_LENGTH];
    char filename[MAX_PATH_LENGTH];

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;  // Remove newline

        if (strcmp(command, "1") == 0) {
            printf("Enter directory path to list files: ");
            fgets(path, sizeof(path), stdin);
            path[strcspn(path, "\n")] = 0;  // Remove newline
            list_files(path);
        } else if (strcmp(command, "2") == 0) {
            printf("Enter directory name to create: ");
            fgets(path, sizeof(path), stdin);
            path[strcspn(path, "\n")] = 0;  // Remove newline
            create_directory(path);
        } else if (strcmp(command, "3") == 0) {
            printf("Enter filename to delete: ");
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = 0;  // Remove newline
            delete_file(filename);
        } else if (strcmp(command, "4") == 0) {
            printf("Enter filename to search for: ");
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = 0;  // Remove newline
            printf("Enter directory to search in: ");
            fgets(path, sizeof(path), stdin);
            path[strcspn(path, "\n")] = 0;  // Remove newline
            search_file(filename, path);
        } else if (strcmp(command, "5") == 0) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void display_menu() {
    printf("\n--- System Admin Menu ---\n");
    printf("1. List files in a directory\n");
    printf("2. Create a new directory\n");
    printf("3. Delete a file\n");
    printf("4. Search for a file\n");
    printf("5. Exit\n");
}

void list_files(const char *path) {
    DIR *dir = opendir(path);
    struct dirent *entry;

    if (dir == NULL) {
        print_error("Failed to open directory");
        return;
    }

    printf("Files in %s:\n", path);
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {  // Exclude hidden files
            printf(" - %s\n", entry->d_name);
        }
    }

    closedir(dir);
}

void create_directory(const char *path) {
    if (mkdir(path, 0755) == -1) {
        print_error("Failed to create directory");
    } else {
        printf("Directory '%s' created successfully!\n", path);
    }
}

void delete_file(const char *filename) {
    if (remove(filename) == -1) {
        print_error("Failed to delete file");
    } else {
        printf("File '%s' deleted successfully!\n", filename);
    }
}

void search_file(const char *filename, const char *path) {
    struct stat st;
    char filepath[MAX_PATH_LENGTH];
    snprintf(filepath, sizeof(filepath), "%s/%s", path, filename);

    if (stat(filepath, &st) == 0) {
        printf("File '%s' found at: %s\n", filename, filepath);
        printf("Size: %lld bytes\n", (long long)st.st_size);
        printf("Last modified: %s", ctime(&st.st_mtime));
    } else {
        printf("File '%s' not found in %s\n", filename, path);
    }
}

void print_error(const char *message) {
    perror(message);
}