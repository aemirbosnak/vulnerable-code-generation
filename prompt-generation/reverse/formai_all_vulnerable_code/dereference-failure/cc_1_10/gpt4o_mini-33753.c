//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <dirent.h>

#define MAX_PATH 4096
#define MAX_CMD_LENGTH 256

void display_file_info(const char *filepath) {
    struct stat fileStat;
    if (stat(filepath, &fileStat) < 0) {
        perror("stat");
        return;
    }

    printf("File: %s\n", filepath);
    printf("Size: %lld bytes\n", (long long)fileStat.st_size);
    printf("Owner: %s\n", getpwuid(fileStat.st_uid)->pw_name);
    printf("Group: %s\n", getgrgid(fileStat.st_gid)->gr_name);
    printf("Last Modified: %s", ctime(&fileStat.st_mtime));
    printf("Permissions: \n");
    printf("  Owner: %c%c%c\n", (fileStat.st_mode & S_IRUSR) ? 'r' : '-',
                                 (fileStat.st_mode & S_IWUSR) ? 'w' : '-',
                                 (fileStat.st_mode & S_IXUSR) ? 'x' : '-');
    printf("  Group: %c%c%c\n", (fileStat.st_mode & S_IRGRP) ? 'r' : '-',
                                 (fileStat.st_mode & S_IWGRP) ? 'w' : '-',
                                 (fileStat.st_mode & S_IXGRP) ? 'x' : '-');
    printf("  Others: %c%c%c\n", (fileStat.st_mode & S_IROTH) ? 'r' : '-',
                                 (fileStat.st_mode & S_IWOTH) ? 'w' : '-',
                                 (fileStat.st_mode & S_IXOTH) ? 'x' : '-');
    printf("\n");
}

void list_directory(const char *dirpath) {
    struct dirent *entry;
    DIR *dp = opendir(dirpath);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printf("Listing files in directory: %s\n", dirpath);
    while ((entry = readdir(dp))) {
        printf(" - %s\n", entry->d_name);
    }
    closedir(dp);
    printf("\n");
}

void clear_screen() {
    printf("\033[H\033[J");
}

void run_command(const char *command) {
    int status = system(command);
    if (status == -1) {
        perror("system");
    }
}

void print_help() {
    printf("Simple System Admin Tool\n");
    printf("Usage:\n");
    printf("  1. info <filepath>    - Displays information about a file\n");
    printf("  2. list <dirpath>     - Lists files in a directory\n");
    printf("  3. clear               - Clears the screen\n");
    printf("  4. exec <command>      - Executes a shell command\n");
    printf("  5. exit                - Exits the program\n");
}

int main() {
    char command[MAX_CMD_LENGTH];

    clear_screen();
    printf("Welcome to the Simple System Administration Tool\n");
    print_help();

    while (1) {
        printf("\nEnter command: ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;
        }

        // Remove newline character
        command[strcspn(command, "\n")] = 0;

        if (strncmp(command, "info ", 5) == 0) {
            display_file_info(command + 5);
        } else if (strncmp(command, "list ", 5) == 0) {
            list_directory(command + 5);
        } else if (strcmp(command, "clear") == 0) {
            clear_screen();
        } else if (strncmp(command, "exec ", 5) == 0) {
            run_command(command + 5);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Unknown command: %s\n", command);
            print_help();
        }
    }

    return 0;
}