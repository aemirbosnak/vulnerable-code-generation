//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

// Function prototypes
void displayMenu();
void listFiles(const char *path);
void createDirectory(const char *name);
void deleteDirectory(const char *name);
void viewFile(const char *filename);
void getFileInfo(const char *filename);

int main() {
    int choice;
    char input[256];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        fgets(input, sizeof(input), stdin);
        choice = atoi(input);

        switch (choice) {
            case 1: 
                printf("Enter the directory path to list files: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline character
                listFiles(input);
                break;

            case 2: 
                printf("Enter the name of the directory to create: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                createDirectory(input);
                break;

            case 3:
                printf("Enter the name of the directory to delete: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                deleteDirectory(input);
                break;

            case 4:
                printf("Enter the filename to view: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                viewFile(input);
                break;

            case 5:
                printf("Enter the filename to get info: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                getFileInfo(input);
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);
            
            default:
                printf("Invalid choice, please select again.\n");
                break;
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Simple File Management System ---\n");
    printf("1. List files in a directory\n");
    printf("2. Create a new directory\n");
    printf("3. Delete a directory\n");
    printf("4. View file content\n");
    printf("5. Get file information\n");
    printf("6. Exit\n");
}

void listFiles(const char *path) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(path)) == NULL) {
        perror("opendir error");
        return;
    }

    printf("Files in directory '%s':\n", path);
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') { // Ignoring hidden files
            printf("- %s\n", entry->d_name);
        }
    }
    closedir(dir);
}

void createDirectory(const char *name) {
    if (mkdir(name, 0755) == 0) {
        printf("Directory '%s' created successfully.\n", name);
    } else {
        perror("mkdir error");
    }
}

void deleteDirectory(const char *name) {
    if (rmdir(name) == 0) {
        printf("Directory '%s' deleted successfully.\n", name);
    } else {
        perror("rmdir error");
    }
}

void viewFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen error");
        return;
    }

    char buffer[256];
    printf("Contents of '%s':\n", filename);
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}

void getFileInfo(const char *filename) {
    struct stat fileStat;
    if (stat(filename, &fileStat) < 0) {
        perror("stat error");
        return;
    }

    printf("File: %s\n", filename);
    printf("Size: %lld bytes\n", (long long)fileStat.st_size);
    printf("Permissions: %o\n", fileStat.st_mode & 0777);
    printf("Last modified: %s", ctime(&fileStat.st_mtime));
}