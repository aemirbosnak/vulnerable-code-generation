//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PATH 256
#define BUFFER_SIZE 256

void print_usage() {
    printf("Usage: process_viewer [OPTION]\n");
    printf("Options:\n");
    printf("  -h, --help       Show this help message\n");
    printf("  -p, --pid        Show process details by PID\n");
    printf("  -u, --user       Show processes by user\n");
}

int is_digit_string(const char *str) {
    while (*str) {
        if (!isdigit(*(str++)))
            return 0;
    }
    return 1;
}

void print_process_info(int pid) {
    char path[MAX_PATH];
    char buffer[BUFFER_SIZE];
    FILE *stat_file;

    snprintf(path, sizeof(path), "/proc/%d/stat", pid);
    stat_file = fopen(path, "r");
    if (stat_file == NULL) {
        perror("fopen");
        return;
    }

    // Read process information from stat file
    fgets(buffer, sizeof(buffer), stat_file);
    fclose(stat_file);

    // Tokenize the stat file data (fields)
    char *token = strtok(buffer, " ");
    int field_index = 0;

    printf("PID: %d\n", pid);

    while (token != NULL) {
        switch (field_index) {
            case 1: // Command
                printf("Command: %s\n", token);
                break;
            case 2: // State
                printf("State: %s\n", token);
                break;
            case 3: // PPID
                printf("Parent PID: %s\n", token);
                break;
            case 4: // UID
                printf("User ID: %s\n", token);
                break;
            // Add more fields as necessary
            default:
                break;
        }
        token = strtok(NULL, " ");
        field_index++;
    }
    printf("\n");
}

void list_processes() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    printf("Listing all processes:\n");

    while ((entry = readdir(dir)) != NULL) {
        if (is_digit_string(entry->d_name)) {
            int pid = atoi(entry->d_name);
            print_process_info(pid);
        }
    }
    closedir(dir);
}

void list_user_processes(const char *desired_user) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    printf("Listing processes for user: %s\n", desired_user);

    while ((entry = readdir(dir)) != NULL) {
        if (is_digit_string(entry->d_name)) {
            int pid = atoi(entry->d_name);
            char uid[10], username[BUFFER_SIZE];

            snprintf(uid, sizeof(uid), "/proc/%d/uid_map", pid);
            FILE *f_uid = fopen(uid, "r");
            if (f_uid != NULL) {
                fscanf(f_uid, "%s", username);
                fclose(f_uid);

                if (strcmp(username, desired_user) == 0) {
                    print_process_info(pid);
                }
            }
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        list_processes();
        return 0;
    }

    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        print_usage();
        return 0;
    } else if (strcmp(argv[1], "-p") == 0 || strcmp(argv[1], "--pid") == 0) {
        if (argc >= 3 && is_digit_string(argv[2])) {
            int pid = atoi(argv[2]);
            print_process_info(pid);
            return 0;
        } else {
            fprintf(stderr, "Invalid PID provided.\n");
            return 1;
        }
    } else if (strcmp(argv[1], "-u") == 0 || strcmp(argv[1], "--user") == 0) {
        if (argc >= 3) {
            list_user_processes(argv[2]);
            return 0;
        } else {
            fprintf(stderr, "User not specified.\n");
            return 1;
        }
    } else {
        fprintf(stderr, "Unknown option: %s\n", argv[1]);
        print_usage();
        return 1;
    }

    return 0;
}