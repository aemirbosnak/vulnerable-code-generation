//FormAI DATASET v1.0 Category: System process viewer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PATH_SIZE 512
#define BUF_SIZE 1024

// Define colors
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"
#define RESET_COLOR "\033[0m"

// Function to check if a string is a number
bool is_number(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

// Function to get the process executable path
void get_executable_path(char *pid, char *path) {
    char file[MAX_PATH_SIZE];
    sprintf(file, "/proc/%s/exe", pid);
    memset(path, 0, MAX_PATH_SIZE);
    readlink(file, path, MAX_PATH_SIZE);
}

// Function to get the process state
char get_process_state(char *pid) {
    char path[MAX_PATH_SIZE];
    char state;

    // Open the /proc/[pid]/status file
    char file[MAX_PATH_SIZE];
    sprintf(file, "/proc/%s/status", pid);
    int fd = open(file, O_RDONLY);
    if (fd < 0) {
        return '?';
    }

    // Read the file line by line and look for the "State:" line
    char buf[BUF_SIZE];
    while (read(fd, buf, BUF_SIZE) > 0) {
        if (strncmp(buf, "State:", strlen("State:")) == 0) {
            state = buf[strlen("State:") + 1];
            break;
        }
    }

    close(fd);
    return state;
}

// Function to get the process memory usage
void get_memory_usage(char *pid, char *resident_set_size, char *virtual_memory_size) {
    // Open the /proc/[pid]/status file
    char file[MAX_PATH_SIZE];
    sprintf(file, "/proc/%s/status", pid);
    int fd = open(file, O_RDONLY);
    if (fd < 0) {
        return;
    }

    // Read the file line by line and look for the "VmRSS:" and "VmSize:" lines
    char buf[BUF_SIZE];
    while (read(fd, buf, BUF_SIZE) > 0) {
        if (strncmp(buf, "VmRSS:", strlen("VmRSS:")) == 0) {
            sscanf(buf, "%*s %s", resident_set_size);
        }
        if (strncmp(buf, "VmSize:", strlen("VmSize:")) == 0) {
            sscanf(buf, "%*s %s", virtual_memory_size);
        }
    }

    close(fd);
}

// Function to print the process table header
void print_table_header() {
    printf("+-------+----------------------+-------+---------+---------------+---------------+\n");
    printf("| %-5s | %-20s | %-5s | %-7s | %-13s | %-13s |\n", "PID", "NAME", "STATE", "USER", "RSS", "VSZ");
    printf("+-------+----------------------+-------+---------+---------------+---------------+\n");
}

// Function to print a process information
void print_process_info(char *pid, char *process_name, char *process_state, char *user, char *resident_set_size, char *virtual_memory_size) {
    printf("| %-5s | %-20s | ", pid, process_name);
    if (*process_state == 'T') {
        printf(RED "%-5c" RESET_COLOR " | ", *process_state);
    } else if (*process_state == 'D') {
        printf(YELLOW "%-5c" RESET_COLOR " | ", *process_state);
    } else if (*process_state == 'R') {
        printf(GREEN "%-5c" RESET_COLOR " | ", *process_state);
    } else {
        printf("%-5c | ", *process_state);
    }
    printf("%-7s | %-13s | %-13s |\n", user, resident_set_size, virtual_memory_size);
}

int main() {
    DIR *proc_dir;
    struct dirent *entry;

    printf("System Process Viewer\n\n");

    // Open the /proc directory
    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        printf("Failed to open /proc directory\n");
        return -1;
    }

    // Print the process table header
    print_table_header();

    // Read the /proc directory and look for directories that are decimal numbers (PIDs)
    while ((entry = readdir(proc_dir)) != NULL) {
        if (is_number(entry->d_name)) {
            char pid[MAX_PATH_SIZE];
            strcpy(pid, entry->d_name);

            // Get the process name
            char process_name[MAX_PATH_SIZE];
            get_executable_path(pid, process_name);
            char *process_name_only = strrchr(process_name, '/');
            if (process_name_only != NULL) {
                process_name_only++;
            } else {
                process_name_only = process_name;
            }

            // Get the process state
            char process_state = get_process_state(pid);

            // Get the process memory usage
            char resident_set_size[MAX_PATH_SIZE];
            char virtual_memory_size[MAX_PATH_SIZE];
            get_memory_usage(pid, resident_set_size, virtual_memory_size);

            // Get the process user
            char process_user[MAX_PATH_SIZE];
            char file[MAX_PATH_SIZE];
            sprintf(file, "/proc/%s/status", pid);
            int fd = open(file, O_RDONLY);
            if (fd < 0) {
                continue;
            }
            char buf[BUF_SIZE];
            while (read(fd, buf, BUF_SIZE) > 0) {
                if (strncmp(buf, "Uid:", strlen("Uid:")) == 0) {
                    char *uid_str = buf + strlen("Uid:");
                    char *endptr;
                    long uid_long = strtol(uid_str, &endptr, 10);
                    sprintf(file, "/etc/passwd");
                    FILE *fp = fopen(file, "r");
                    if (fp == NULL) {
                        sprintf(process_user, "%ld", uid_long);
                        break;
                    }
                    char passwd_buf[BUF_SIZE];
                    while (fgets(passwd_buf, BUF_SIZE, fp) != NULL) {
                        char *s = passwd_buf;
                        char *p;
                        for (p = s; *p != ':'; p++);
                        *p = '\0';
                        for (p = s; *p != '\0'; p++) {
                            *p = tolower(*p);
                        }
                        if (atoi(s) == uid_long) {
                            strcpy(process_user, passwd_buf);
                            break;
                        }
                    }
                    fclose(fp);
                    break;
                }
            }
            close(fd);

            // Print the process information
            print_process_info(pid, process_name_only, &process_state, process_user, resident_set_size, virtual_memory_size);
        }
    }

    closedir(proc_dir);

    return 0;
}