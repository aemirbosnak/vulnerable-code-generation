//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>

#define MAX_PATH 1024
#define MAX_FILE_NAME 256

void display_menu() {
    printf("\n*** Mind-Bending File Management System ***\n");
    printf("1. Create a new directory\n");
    printf("2. List all files in a directory\n");
    printf("3. Delete a file\n");
    printf("4. Copy a file\n");
    printf("5. Move a file\n");
    printf("6. Display file information\n");
    printf("7. Exit\n");
    printf("Choose an option: ");
}

void create_directory() {
    char dir_name[MAX_FILE_NAME];
    printf("Enter the name of the directory to create: ");
    scanf("%s", dir_name);
    if (mkdir(dir_name, 0755) == 0) {
        printf("Directory '%s' created successfully!\n", dir_name);
    } else {
        perror("Error creating directory");
    }
}

void list_files() {
    char path[MAX_PATH];
    printf("Enter the directory path to list files: ");
    scanf("%s", path);
    DIR *dir = opendir(path);
    struct dirent *entry;
    
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }
    
    printf("Files in directory '%s':\n", path);
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') // Skipping hidden files
            printf("%s\n", entry->d_name);
    }
    closedir(dir);
}

void delete_file() {
    char file_name[MAX_PATH];
    printf("Enter the file name to delete: ");
    scanf("%s", file_name);
    if (remove(file_name) == 0) {
        printf("File '%s' deleted successfully!\n", file_name);
    } else {
        perror("Error deleting file");
    }
}

void copy_file() {
    char source[MAX_PATH];
    char destination[MAX_PATH];
    printf("Enter the source file name: ");
    scanf("%s", source);
    printf("Enter the destination file name: ");
    scanf("%s", destination);

    FILE *src = fopen(source, "rb");
    if (src == NULL) {
        perror("Error opening source file");
        return;
    }

    FILE *dest = fopen(destination, "wb");
    if (dest == NULL) {
        fclose(src);
        perror("Error opening destination file");
        return;
    }

    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    fclose(src);
    fclose(dest);
    printf("File '%s' copied to '%s' successfully!\n", source, destination);
}

void move_file() {
    char source[MAX_PATH];
    char destination[MAX_PATH];
    printf("Enter the source file name: ");
    scanf("%s", source);
    printf("Enter the destination file name: ");
    scanf("%s", destination);

    if (rename(source, destination) == 0) {
        printf("File '%s' moved to '%s' successfully!\n", source, destination);
    } else {
        perror("Error moving file");
    }
}

void display_file_info() {
    char file_name[MAX_PATH];
    printf("Enter the file name to display information: ");
    scanf("%s", file_name);
    struct stat file_stat;

    if (stat(file_name, &file_stat) == 0) {
        printf("File: %s\n", file_name);
        printf("Size: %lld bytes\n", (long long)file_stat.st_size);
        printf("Permissions: %o\n", file_stat.st_mode & 0777);
        printf("Last modified: %s", ctime(&file_stat.st_mtime));
    } else {
        perror("Error retrieving file information");
    }
}

int main() {
    int choice;
    
    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                create_directory();
                break;
            case 2:
                list_files();
                break;
            case 3:
                delete_file();
                break;
            case 4:
                copy_file();
                break;
            case 5:
                move_file();
                break;
            case 6:
                display_file_info();
                break;
            case 7:
                printf("Exiting Mind-Bending File Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}