//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <time.h>
#include <dirent.h>

#define MAX_PATH 1024
#define MAX_COMMAND 256

void print_usage() {
    printf("Usage: sysadmin_tool [list|backup|restore|info]\n");
    printf("Commands:\n");
    printf("  list       - List files in the current directory\n");
    printf("  backup     - Create a backup of the current directory\n");
    printf("  restore    - Restore files from a backup\n");
    printf("  info       - Show system information\n");
}

void list_files() {
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d) {
        printf("Files in the current directory:\n");
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_name[0] != '.') { // ignore hidden files
                printf("%s\n", dir->d_name);
            }
        }
        closedir(d);
    } else {
        perror("opendir");
    }
}

void backup_files() {
    char command[MAX_COMMAND];
    snprintf(command, sizeof(command), "tar -czf backup_$(date +%%Y%%m%%d).tar.gz .");
    int result = system(command);
    if (result == -1) {
        perror("Backup failed");
    } else {
        printf("Backup created successfully.\n");
    }
}

void restore_files() {
    struct dirent *dir;
    DIR *d = opendir(".");
    if (!d) {
        perror("Failed to open directory");
        return;
    }

    printf("Available backups:\n");
    while ((dir = readdir(d)) != NULL) {
        if (strstr(dir->d_name, "backup_") != NULL) {
            printf("%s\n", dir->d_name);
        }
    }
    closedir(d);

    char backup_name[MAX_PATH];
    printf("Enter the name of the backup file to restore (or 'exit' to cancel): ");
    scanf("%s", backup_name);

    if (strcmp(backup_name, "exit") == 0) {
        printf("Restore canceled.\n");
        return;
    }

    char command[MAX_COMMAND];
    snprintf(command, sizeof(command), "tar -xzf %s", backup_name);
    int result = system(command);
    if (result == -1) {
        perror("Restore failed");
    } else {
        printf("Restore completed successfully.\n");
    }
}

void show_system_info() {
    struct passwd *pw = getpwuid(getuid());
    char host[MAX_PATH];
    gethostname(host, sizeof(host));

    printf("User Information:\n");
    printf("  Username: %s\n", pw->pw_name);
    printf("  Home Directory: %s\n", pw->pw_dir);
    printf("System Information:\n");
    printf("  Hostname: %s\n", host);
    printf("  Current Time: %s", ctime(&(time_t){time(NULL)}));
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "list") == 0) {
        list_files();
    } else if (strcmp(argv[1], "backup") == 0) {
        backup_files();
    } else if (strcmp(argv[1], "restore") == 0) {
        restore_files();
    } else if (strcmp(argv[1], "info") == 0) {
        show_system_info();
    } else {
        print_usage();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}