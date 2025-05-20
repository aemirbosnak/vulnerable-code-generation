//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH 1024
#define MAX_COMMAND 256

void list_directory(const char *path);
void check_disk_usage(const char *path);
void show_system_info();
void interactive_shell();
void invalid_command();

int main() {
    char command[MAX_COMMAND];
    while (1) {
        printf("sysadmin> ");
        fgets(command, MAX_COMMAND, stdin);
        
        // Remove newline character
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "list") == 0) {
            list_directory(".");
        } else if (strncmp(command, "usage", 5) == 0) {
            char path[MAX_PATH];
            if (sscanf(command, "usage %s", path) == 1) {
                check_disk_usage(path);
            } else {
                fprintf(stderr, "Usage: usage <directory>\n");
            }
        } else if (strcmp(command, "info") == 0) {
            show_system_info();
        } else if (strcmp(command, "shell") == 0) {
            interactive_shell();
        } else {
            invalid_command();
        }
    }
    return 0;
}

void list_directory(const char *path) {
    DIR *d;
    struct dirent *dir;
    d = opendir(path);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_name[0] != '.') {  // Skip hidden files
                printf("%s\n", dir->d_name);
            }
        }
        closedir(d);
    } else {
        perror("Could not open directory");
    }
}

void check_disk_usage(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == 0) {
        printf("Disk usage for %s:\n", path);
        printf("Total Size: %ld bytes\n", statbuf.st_size);
        printf("Blocks: %ld\n", statbuf.st_blocks);
        printf("Inode: %ld\n", statbuf.st_ino);
    } else {
        perror("Could not retrieve disk usage");
    }
}

void show_system_info() {
    struct passwd *pw = getpwuid(getuid());
    if (pw) {
        printf("User: %s\n", pw->pw_name);
    }

    char hostname[MAX_PATH];
    gethostname(hostname, sizeof(hostname));
    printf("Hostname: %s\n", hostname);

    printf("Current Directory: ");
    char cwd[MAX_PATH];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s\n", cwd);
    } else {
        perror("getcwd() error");
    }
}

void interactive_shell() {
    char shell_command[MAX_COMMAND];
    printf("Entering interactive shell. Type 'exit' to return.\n");
    while (1) {
        printf("shell> ");
        fgets(shell_command, MAX_COMMAND, stdin);
        shell_command[strcspn(shell_command, "\n")] = 0;

        if (strcmp(shell_command, "exit") == 0) {
            break;
        }

        int result = system(shell_command);
        if (result == -1) {
            perror("System command failed");
        }
    }
}

void invalid_command() {
    printf("Invalid command! Try 'list', 'usage <directory>', 'info', or 'shell'.\n");
}