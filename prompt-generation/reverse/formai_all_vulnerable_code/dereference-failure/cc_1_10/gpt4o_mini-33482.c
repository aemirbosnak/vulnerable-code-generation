//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define MAX_LINE_LENGTH 256

void print_file_stats(const char *file_path) {
    struct stat file_info;
    
    if (stat(file_path, &file_info) == -1) {
        perror("stat");
        return;
    }

    struct passwd *pw = getpwuid(file_info.st_uid);
    struct group *gr = getgrgid(file_info.st_gid);
    char time_buf[26];
    struct tm *tm_info;

    tm_info = localtime(&file_info.st_mtime);
    strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", tm_info);

    printf("File: %s\n", file_path);
    printf("Size: %lld bytes\n", (long long)file_info.st_size);
    printf("Owner: %s (UID: %d)\n", pw->pw_name, file_info.st_uid);
    printf("Group: %s (GID: %d)\n", gr->gr_name, file_info.st_gid);
    printf("Last modified: %s\n\n", time_buf);
}

void list_directory(const char *dir_path) {
    FILE *fp;
    char command[MAX_LINE_LENGTH];

    snprintf(command, sizeof(command), "ls -1 %s", dir_path); // List files in the specified directory
    fp = popen(command, "r");
    
    if (fp == NULL) {
        perror("popen");
        return;
    }

    char file_name[MAX_LINE_LENGTH];
    while (fgets(file_name, sizeof(file_name), fp) != NULL) {
        file_name[strcspn(file_name, "\n")] = 0; // Remove trailing newline
        print_file_stats(file_name);
    }

    pclose(fp);
}

void create_file(const char *file_name) {
    FILE *fp = fopen(file_name, "w");
    if (fp == NULL) {
        perror("fopen");
        return;
    }
    fprintf(fp, "This file was created by the C System Administration Example Program.\n");
    fclose(fp);
    printf("File '%s' created successfully.\n", file_name);
}

void delete_file(const char *file_name) {
    if (remove(file_name) == 0) {
        printf("File '%s' deleted successfully.\n", file_name);
    } else {
        perror("remove");
    }
}

void display_menu() {
    printf("\nSimple C System Administration Tool\n");
    printf("1. List Files in a Directory\n");
    printf("2. Create a File\n");
    printf("3. Delete a File\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    char input_buffer[MAX_LINE_LENGTH];
    
    while (1) {
        display_menu();
        printf("Select an option: ");
        fgets(input_buffer, sizeof(input_buffer), stdin);
        choice = atoi(input_buffer);

        switch (choice) {
            case 1:
                printf("Enter directory path: ");
                fgets(input_buffer, sizeof(input_buffer), stdin);
                input_buffer[strcspn(input_buffer, "\n")] = 0; // Remove trailing newline
                list_directory(input_buffer);
                break;
            case 2:
                printf("Enter file name to create: ");
                fgets(input_buffer, sizeof(input_buffer), stdin);
                input_buffer[strcspn(input_buffer, "\n")] = 0; // Remove trailing newline
                create_file(input_buffer);
                break;
            case 3:
                printf("Enter file name to delete: ");
                fgets(input_buffer, sizeof(input_buffer), stdin);
                input_buffer[strcspn(input_buffer, "\n")] = 0; // Remove trailing newline
                delete_file(input_buffer);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}