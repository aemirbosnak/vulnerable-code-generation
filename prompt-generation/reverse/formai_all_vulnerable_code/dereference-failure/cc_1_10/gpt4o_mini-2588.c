//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <dirent.h>

#define MAX_COMMAND_LENGTH 256
#define MAX_OUTPUT_LENGTH 1024

void execute_command(const char *command) {
    char buffer[MAX_OUTPUT_LENGTH];
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("popen failed");
        return;
    }
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    pclose(fp);
}

void list_users() {
    struct passwd *pw;
    setpwent(); // Rewind the password database
    while ((pw = getpwent()) != NULL) {
        printf("User: %-15s UID: %-5d GID: %-5d Home: %-25s Shell: %s\n",
               pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_dir, pw->pw_shell);
    }
    endpwent();
}

void check_processes() {
    char command[MAX_COMMAND_LENGTH];
    snprintf(command, sizeof(command), "ps aux");
    printf("\nActive Processes:\n");
    execute_command(command);
}

void show_system_info() {
    char command[MAX_COMMAND_LENGTH];
    snprintf(command, sizeof(command), "uname -a");
    printf("\nSystem Information:\n");
    execute_command(command);
}

void check_disk_usage() {
    char command[MAX_COMMAND_LENGTH];
    snprintf(command, sizeof(command), "df -h");
    printf("\nDisk Usage:\n");
    execute_command(command);
}

void show_current_directory() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("\nCurrent Directory: %s\n", cwd);
    } else {
        perror("getcwd() error");
    }
}

void list_files() {
    struct dirent *entry;
    DIR *dp = opendir(".");
    if (dp == NULL) {
        perror("opendir");
        return;
    }
    
    printf("\nFiles in Current Directory:\n");
    while ((entry = readdir(dp)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dp);
}

void show_last_boot_time() {
    struct stat statbuf;
    if (stat("/var/run/utmp", &statbuf) == -1) {
        perror("stat");
        return;
    }
    
    printf("\nLast Boot Time: %s", ctime(&statbuf.st_mtime));
}

void display_menu() {
    printf("\n=== System Administration Tool ===\n");
    printf("1. List Users\n");
    printf("2. Check Active Processes\n");
    printf("3. Show System Info\n");
    printf("4. Check Disk Usage\n");
    printf("5. Show Current Directory\n");
    printf("6. List Files in Current Directory\n");
    printf("7. Show Last Boot Time\n");
    printf("8. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                list_users();
                break;
            case 2:
                check_processes();
                break;
            case 3:
                show_system_info();
                break;
            case 4:
                check_disk_usage();
                break;
            case 5:
                show_current_directory();
                break;
            case 6:
                list_files();
                break;
            case 7:
                show_last_boot_time();
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}