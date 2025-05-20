//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define CMD_MAX_LEN 512
#define FILE_PATH "/var/log/sysadmin_log.txt"

void log_message(const char *message) {
    int fd = open(FILE_PATH, O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (fd < 0) {
        perror("Unable to open log file");
        return;
    }
    write(fd, message, strlen(message));
    write(fd, "\n", 1);
    close(fd);
}

void execute_command(const char *command) {
    log_message(command);
    int status = system(command);
    if (status == -1) {
        perror("Command execution failed");
    } else if (WIFEXITED(status)) {
        printf("Command exit status: %d\n", WEXITSTATUS(status));
    }
}

void check_and_create_directory(const char *path) {
    struct stat st;
    if (stat(path, &st) == -1) {
        if (errno == ENOENT) {
            log_message("Directory does not exist. Creating now.");
            if (mkdir(path, 0755) == -1) {
                perror("Failed to create directory");
                return;
            }
            char msg[CMD_MAX_LEN];
            snprintf(msg, sizeof(msg), "Directory created: %s", path);
            log_message(msg);
        }
    } else {
        log_message("Directory already exists.");
    }
}

void display_system_info() {
    log_message("Displaying system info.");
    execute_command("uname -a");
    execute_command("uptime");
    execute_command("df -h");
}

void create_backup(const char *source, const char *destination) {
    char command[CMD_MAX_LEN];
    snprintf(command, sizeof(command), "cp -r %s %s", source, destination);
    log_message("Creating backup.");
    execute_command(command);
}

void show_menu() {
    printf("\n=== System Administration Menu ===\n");
    printf("1. Display System Info\n");
    printf("2. Check and Create Directory\n");
    printf("3. Create Backup\n");
    printf("4. Exit\n");
    printf("===================================\n");
}

int main() {
    char choice;
    char path[CMD_MAX_LEN];
    char source[CMD_MAX_LEN];
    char dest[CMD_MAX_LEN];

    // Initial log message
    log_message("System administration tool started.");

    while (1) {
        show_menu();
        printf("Select an option: ");
        choice = getchar();
        while (getchar() != '\n'); // Clear the input buffer

        switch (choice) {
            case '1':
                display_system_info();
                break;
            case '2':
                printf("Enter directory path: ");
                fgets(path, sizeof(path), stdin);
                path[strcspn(path, "\n")] = 0; // Remove newline character
                check_and_create_directory(path);
                break;
            case '3':
                printf("Enter source directory: ");
                fgets(source, sizeof(source), stdin);
                source[strcspn(source, "\n")] = 0; // Remove newline character
                printf("Enter destination directory: ");
                fgets(dest, sizeof(dest), stdin);
                dest[strcspn(dest, "\n")] = 0; // Remove newline character
                create_backup(source, dest);
                break;
            case '4':
                log_message("Exiting the system administration tool.");
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }

    return 0;
}