//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <time.h>

#define MAX_FILES 100
#define FILE_NAME_LENGTH 255
#define BUFFER_SIZE 1024

void list_files();
void upload_file(const char *file_name);
void download_file(const char *file_name);

int main() {
    int choice;
    char file_name[FILE_NAME_LENGTH];
    
    printf("Welcome to the Decentralized File Sharing System!\n");
    
    while (1) {
        printf("\n1. List Files\n");
        printf("2. Upload File\n");
        printf("3. Download File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                list_files();
                break;
            case 2:
                printf("Enter the file name to upload: ");
                scanf("%s", file_name);
                upload_file(file_name);
                break;
            case 3:
                printf("Enter the file name to download: ");
                scanf("%s", file_name);
                download_file(file_name);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

void list_files() {
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir("shared")) != NULL) {
        printf("Available files:\n");
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG) {
                printf("- %s\n", ent->d_name);
            }
        }
        closedir(dir);
    } else {
        perror("Could not open directory");
    }
}

void upload_file(const char *file_name) {
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        return;
    }
    
    if (pid == 0) { // Child process for uploading
        char command[BUFFER_SIZE];
        snprintf(command, sizeof(command), "cp %s shared/", file_name);
        if (system(command) == -1) {
            perror("Failed to upload file");
        } else {
            printf("File uploaded successfully: %s\n", file_name);
        }
        exit(0);
    } else {
        wait(NULL); // Parent process waits for child
    }
}

void download_file(const char *file_name) {
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        return;
    }

    if (pid == 0) { // Child process for downloading
        char command[BUFFER_SIZE];
        snprintf(command, sizeof(command), "cp shared/%s .", file_name);
        if (system(command) == -1) {
            perror("Failed to download file");
        } else {
            printf("File downloaded successfully: %s\n", file_name);
        }
        exit(0);
    } else {
        wait(NULL); // Parent process waits for child
    }
}