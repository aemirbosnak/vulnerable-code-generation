//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_PATH 1024

void listFiles(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);
    
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printf("Listing files in directory: %s\n", path);
    while ((entry = readdir(dp))) {
        // Exclude the special directories "." and ".."
        if (entry->d_name[0] == '.') {
            continue;
        }
        printf(" - %s\n", entry->d_name);
    }
    closedir(dp);
}

void createDirectory(const char *path) {
    if (mkdir(path, 0755) == -1) {
        perror("mkdir");
    } else {
        printf("Successfully created directory: %s\n", path);
    }
}

void deleteDirectory(const char *path) {
    if (rmdir(path) == -1) {
        perror("rmdir");
    } else {
        printf("Successfully deleted directory: %s\n", path);
    }
}

void writeToFile(const char *filePath, const char *content) {
    FILE *file = fopen(filePath, "w");
    if (file == NULL) {
        perror("fopen");
        return;
    }
    fprintf(file, "%s", content);
    fclose(file);
    printf("Successfully wrote to file: %s\n", filePath);
}

void readFromFile(const char *filePath) {
    char buffer[256];
    FILE *file = fopen(filePath, "r");
    
    if (file == NULL) {
        perror("fopen");
        return;
    }
    
    printf("Reading from file: %s\n", filePath);
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    
    fclose(file);
}

void showMenu() {
    printf("\nWelcome to the Simple C System Administration Tool!\n");
    printf("Choose an option:\n");
    printf("1. List files in a directory\n");
    printf("2. Create a new directory\n");
    printf("3. Delete a directory\n");
    printf("4. Write to a file\n");
    printf("5. Read from a file\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    char path[MAX_PATH];
    char filePath[MAX_PATH];
    char content[256];

    while (1) {
        showMenu();
        scanf("%d", &choice);
        getchar(); // consume newline left by scanf

        switch (choice) {
            case 1:
                printf("Enter the directory path: ");
                fgets(path, MAX_PATH, stdin);
                path[strcspn(path, "\n")] = 0; // remove newline
                listFiles(path);
                break;
            case 2:
                printf("Enter the new directory name: ");
                fgets(path, MAX_PATH, stdin);
                path[strcspn(path, "\n")] = 0; // remove newline
                createDirectory(path);
                break;
            case 3:
                printf("Enter the directory name to delete: ");
                fgets(path, MAX_PATH, stdin);
                path[strcspn(path, "\n")] = 0; // remove newline
                deleteDirectory(path);
                break;
            case 4:
                printf("Enter file path to write to: ");
                fgets(filePath, MAX_PATH, stdin);
                filePath[strcspn(filePath, "\n")] = 0; // remove newline
                printf("Enter content to write: ");
                fgets(content, sizeof(content), stdin);
                writeToFile(filePath, content);
                break;
            case 5:
                printf("Enter file path to read from: ");
                fgets(filePath, MAX_PATH, stdin);
                filePath[strcspn(filePath, "\n")] = 0; // remove newline
                readFromFile(filePath);
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}