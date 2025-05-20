//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>

#define MAX_PATH 260
#define MAX_USERS 100
#define MAX_LOG_SIZE 1024

void print_usage() {
    printf("Usage: sysadmin_tool [command]\n");
    printf("Commands:\n");
    printf("1. list_users - List all users in the system\n");
    printf("2. disk_usage - Display disk usage with formatted output\n");
    printf("3. file_stats <filename> - Shows stats of specified file\n");
    printf("4. sys_info - Display system information\n");
    printf("5. monitor_dir <directory> - Monitor a directory for changes\n");
}

void list_users() {
    struct passwd *pw;
    setpwent(); // Start from the beginning of the passwd database
    printf("\nList of Users:\n");
    while ((pw = getpwent()) != NULL) {
        printf("Username: %s, UID: %d, GID: %d\n", pw->pw_name, pw->pw_uid, pw->pw_gid);
    }
    endpwent();
}

void disk_usage() {
    printf("\nDisk Usage:\n");
    char command[50];
    snprintf(command, sizeof(command), "df -h");
    system(command);
}

void file_stats(char *filename) {
    struct stat statbuf;
    if (stat(filename, &statbuf) == -1) {
        perror("stat");
        return;
    }

    printf("\nFile: %s\n", filename);
    printf("Size: %lld bytes\n", (long long)statbuf.st_size);
    printf("Permissions: %o\n", statbuf.st_mode & 0777);
    printf("Last modified: %s", ctime(&statbuf.st_mtime));
}

void sys_info() {
    printf("\nSystem Information:\n");
    char command[50];
    snprintf(command, sizeof(command), "uname -a");
    system(command);
}

void monitor_dir(char *dir_path) {
    DIR *dir;
    struct dirent *entry;
    char log[MAX_LOG_SIZE];
    time_t last_mod_time = 0;

    if (!(dir = opendir(dir_path))) {
        perror("opendir");
        return;
    }

    printf("\nMonitoring Directory: %s\n", dir_path);

    while (1) {
        struct stat dir_stat;
        if (stat(dir_path, &dir_stat) == -1) {
            perror("stat");
            closedir(dir);
            return;
        }

        // Check for changes by comparing modification time
        if (dir_stat.st_mtime != last_mod_time) {
            last_mod_time = dir_stat.st_mtime;
            snprintf(log, sizeof(log), "Directory %s was modified.", dir_path);
            printf("%s\n", log);
        }

        // Check for changes in the files in the directory
        while ((entry = readdir(dir)) != NULL) {
            char file_path[MAX_PATH];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);
            struct stat file_stat;
            if (stat(file_path, &file_stat) == -1) {
                perror("stat");
                continue;
            }

            if (file_stat.st_mtime > last_mod_time) {
                snprintf(log, sizeof(log), "File %s was modified.", file_path);
                printf("%s\n", log);
            }
        }

        rewinddir(dir); // Reset the directory stream
        sleep(5); // Wait before the next check
    }
    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "list_users") == 0) {
        list_users();
    } else if (strcmp(argv[1], "disk_usage") == 0) {
        disk_usage();
    } else if (strcmp(argv[1], "file_stats") == 0 && argc == 3) {
        file_stats(argv[2]);
    } else if (strcmp(argv[1], "sys_info") == 0) {
        sys_info();
    } else if (strcmp(argv[1], "monitor_dir") == 0 && argc == 3) {
        monitor_dir(argv[2]);
    } else {
        print_usage();
    }

    return EXIT_SUCCESS;
}