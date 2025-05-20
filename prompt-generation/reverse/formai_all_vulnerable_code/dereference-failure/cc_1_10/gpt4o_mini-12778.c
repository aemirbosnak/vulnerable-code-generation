//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define MAX_LINE_LENGTH 256
#define MAX_FILE_COUNT 100

void check_file_existence(const char *filename) {
    struct stat buffer;
    if (stat(filename, &buffer) == 0) {
        printf("File '%s' exists.\n", filename);
    } else {
        printf("File '%s' does not exist.\n", filename);
    }
}

void list_files(const char *directory) {
    printf("\nListing files in directory: %s\n", directory);
    FILE *fp;
    char command[MAX_LINE_LENGTH];
    snprintf(command, sizeof(command), "ls -l %s", directory);
    
    // Execute the command using popen
    fp = popen(command, "r");
    if (fp == NULL) {
        perror("popen failed");
        return;
    }

    char output[MAX_LINE_LENGTH];
    while (fgets(output, sizeof(output)-1, fp) != NULL) {
        printf("%s", output);
    }
    pclose(fp);
}

void create_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file) {
        fprintf(file, "This is a sample file: %s\n", filename);
        fclose(file);
        printf("File '%s' created successfully.\n", filename);
    } else {
        perror("Error creating file");
    }
}

void remove_file(const char *filename) {
    if (remove(filename) == 0) {
        printf("File '%s' removed successfully.\n", filename);
    } else {
        perror("Error deleting file");
    }
}

void check_file_permissions(const char *filename) {
    struct stat file_stat;
    if (stat(filename, &file_stat) == 0) {
        printf("Permissions for file '%s':\n", filename);
        printf("User: %o\n", file_stat.st_mode & (S_IRWXU));
        printf("Group: %o\n", file_stat.st_mode & (S_IRWXG));
        printf("Others: %o\n", file_stat.st_mode & (S_IRWXO));
    } else {
        perror("Error retrieving file permissions");
    }
}

void display_file_last_access_time(const char *filename) {
    struct stat file_stat;
    if (stat(filename, &file_stat) == 0) {
        char buffer[30];
        struct tm *tm_info;
        tm_info = localtime(&file_stat.st_atime);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
        printf("Last accessed time for '%s': %s\n", filename, buffer);
    } else {
        perror("Error retrieving last access time");
    }
}

void display_system_info() {
    struct passwd *pw = getpwuid(getuid());
    struct group  *gr = getgrgid(pw->pw_gid);
    
    printf("\nSystem Information:\n");
    printf("User: %s (UID: %d)\n", pw->pw_name, pw->pw_uid);
    printf("Group: %s (GID: %d)\n", gr->gr_name, gr->gr_gid);
}

void show_automated_management_menu() {
    printf("\nAutomated System Management\n");
    printf("1. Check file existence\n");
    printf("2. List files in directory\n");
    printf("3. Create a new file\n");
    printf("4. Remove a file\n");
    printf("5. Check file permissions\n");
    printf("6. Display file last access time\n");
    printf("7. Display system information\n");
    printf("0. Exit\n");
}

int main() {
    int choice;
    char filename[MAX_LINE_LENGTH];
    char directory[MAX_LINE_LENGTH];

    while (1) {
        show_automated_management_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter filename to check: ");
                scanf("%s", filename);
                check_file_existence(filename);
                break;
            case 2:
                printf("Enter directory to list files: ");
                scanf("%s", directory);
                list_files(directory);
                break;
            case 3:
                printf("Enter filename to create: ");
                scanf("%s", filename);
                create_file(filename);
                break;
            case 4:
                printf("Enter filename to remove: ");
                scanf("%s", filename);
                remove_file(filename);
                break;
            case 5:
                printf("Enter filename to check permissions: ");
                scanf("%s", filename);
                check_file_permissions(filename);
                break;
            case 6:
                printf("Enter filename to display last access time: ");
                scanf("%s", filename);
                display_file_last_access_time(filename);
                break;
            case 7:
                display_system_info();
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    }
    return 0;
}