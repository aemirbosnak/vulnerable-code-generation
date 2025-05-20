//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define MAX_PATH 1024
#define MAX_COMMAND 256

void getFileInfo(const char *path) {
    struct stat fileStat;
    if (stat(path, &fileStat) < 0) {
        perror("Error getting file statistics");
        return;
    }

    printf("File: %s\n", path);
    printf("Size: %lld bytes\n", (long long)fileStat.st_size);
    printf("Owner: %s\n", getpwuid(fileStat.st_uid)->pw_name);
    printf("Group: %s\n", getgrgid(fileStat.st_gid)->gr_name);
    printf("Permissions: ");
    printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");
    
    char timebuf[80];
    struct tm *tm_info;
    tm_info = localtime(&fileStat.st_mtime);
    strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Last modified: %s\n", timebuf);
}

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to create file");
        return;
    }
    fprintf(file, "This is a sample file created by the system administration program!\n");
    fclose(file);
    printf("File '%s' created successfully.\n", filename);
}

void deleteFile(const char *filename) {
    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
    } else {
        perror("Failed to delete file");
    }
}

void listFilesInDirectory(const char *directory) {
    char command[MAX_COMMAND];
    snprintf(command, sizeof(command), "ls -l %s", directory);
    system(command);
}

void printMenu() {
    printf("\nSystem Administration Menu:\n");
    printf("1. Get file information\n");
    printf("2. Create a new file\n");
    printf("3. Delete a file\n");
    printf("4. List files in a directory\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    char filePath[MAX_PATH];
    char directoryPath[MAX_PATH];
    
    while (1) {
        printMenu();
        scanf("%d", &choice);
        getchar();  // Consume newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter file path: ");
                fgets(filePath, sizeof(filePath), stdin);
                filePath[strcspn(filePath, "\n")] = 0;  // Remove newline character
                getFileInfo(filePath);
                break;
            case 2:
                printf("Enter filename to create: ");
                fgets(filePath, sizeof(filePath), stdin);
                filePath[strcspn(filePath, "\n")] = 0;  // Remove newline character
                createFile(filePath);
                break;
            case 3:
                printf("Enter filename to delete: ");
                fgets(filePath, sizeof(filePath), stdin);
                filePath[strcspn(filePath, "\n")] = 0;  // Remove newline character
                deleteFile(filePath);
                break;
            case 4:
                printf("Enter directory path: ");
                fgets(directoryPath, sizeof(directoryPath), stdin);
                directoryPath[strcspn(directoryPath, "\n")] = 0;  // Remove newline character
                listFilesInDirectory(directoryPath);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}