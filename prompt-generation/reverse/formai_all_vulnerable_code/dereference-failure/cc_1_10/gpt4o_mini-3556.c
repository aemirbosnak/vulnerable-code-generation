//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define MAX_LOG_LINE 256
#define MAX_COMMAND_LENGTH 512

void log_event(const char *log_message) {
    FILE *log_file = fopen("sys_admin.log", "a");
    if (log_file == NULL) {
        perror("Failed to open log file");
        return;
    }
    
    time_t current_time = time(NULL);
    char *time_str = ctime(&current_time);
    time_str[strlen(time_str) - 1] = '\0'; // Remove newline character
    
    fprintf(log_file, "[%s] %s\n", time_str, log_message);
    fclose(log_file);
    printf("Log event: %s\n", log_message);
}

void display_welcome_message() {
    printf("Welcome to the Enthusiastic System Administration Tool!\n");
    printf("-----------------------------------------------------\n");
    printf("This tool allows you to perform various system tasks and logs each action taken.\n");
    printf("Let's make system administration fun and exciting!\n\n");
}

void execute_command(const char *command) {
    printf("Executing: %s\n", command);
    system(command);
    log_event(command);
}

void display_help() {
    printf("Available commands:\n");
    printf("1. View system uptime\n");
    printf("2. List the contents of the current directory\n");
    printf("3. Check disk usage\n");
    printf("4. Show current logged-in users\n");
    printf("5. Exit the program\n");
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    display_welcome_message();

    int choice;
    while (1) {
        printf("\nChoose an option (1-5) or type 5 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                strcpy(command, "uptime");
                execute_command(command);
                break;
            case 2:
                strcpy(command, "ls -l");
                execute_command(command);
                break;
            case 3:
                strcpy(command, "df -h");
                execute_command(command);
                break;
            case 4:
                strcpy(command, "who");
                execute_command(command);
                break;
            case 5:
                printf("Exiting the program. Have a great day!\n");
                log_event("Exited the program");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
                log_event("Invalid choice selected");
                display_help();
        }
    }
    
    return 0;
}