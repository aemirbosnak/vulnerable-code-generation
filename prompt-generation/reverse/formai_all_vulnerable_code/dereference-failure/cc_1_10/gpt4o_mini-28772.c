//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

#define BUFFER_SIZE 256

typedef struct {
    char pid[10];
    char cmd[BUFFER_SIZE];
    char state[5];
    char user[BUFFER_SIZE];
} ProcessInfo;

void get_user_by_pid(char *pid, char *user) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), "/proc/%s/status", pid);
    FILE *file = fopen(path, "r");
    
    if (file) {
        char line[BUFFER_SIZE];
        while (fgets(line, sizeof(line), file)) {
            if (strncmp(line, "Uid:", 4) == 0) {
                char uid[10];
                sscanf(line, "Uid:\t%s", uid);
                FILE *passwd = fopen("/etc/passwd", "r");
                if (passwd) {
                    char passwd_line[BUFFER_SIZE];
                    while (fgets(passwd_line, sizeof(passwd_line), passwd)) {
                        char *token = strtok(passwd_line, ":");
                        if (token) {
                            int real_uid;
                            sscanf(&passwd_line[strlen(token) + 1], "%*s %*s %d", &real_uid);
                            if (atoi(uid) == real_uid) {
                                strcpy(user, token);
                                break;
                            }
                        }
                    }
                    fclose(passwd);
                }
                break;
            }
        }
        fclose(file);
    }
}

int get_process_info(const char *pid_dir, ProcessInfo *process_info) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), "%s/status", pid_dir);
    
    FILE *file = fopen(path, "r");
    if (!file) {
        return 0;
    }

    strcpy(process_info->pid, basename(pid_dir));

    char line[BUFFER_SIZE];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "State:", 6) == 0) {
            sscanf(line, "State:\t%s", process_info->state);
        } else if (strncmp(line, "Name:", 5) == 0) {
            sscanf(line, "Name:\t%s", process_info->cmd);
        }
    }
    
    get_user_by_pid(process_info->pid, process_info->user);
    
    fclose(file);
    return 1;
}

void list_processes() {
    struct dirent *entry;
    DIR *proc_dir = opendir("/proc");

    if (!proc_dir) {
        perror("Could not open /proc directory");
        return;
    }

    ProcessInfo process_info;
    printf("%-10s %-20s %-10s %s\n", "PID", "Command", "State", "User");
    printf("%-10s %-20s %-10s %s\n", "---", "---------------", "------", "----");

    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            char pid_dir[BUFFER_SIZE];
            snprintf(pid_dir, sizeof(pid_dir), "/proc/%s", entry->d_name);
            if (get_process_info(pid_dir, &process_info)) {
                printf("%-10s %-20s %-10s %s\n", process_info.pid, process_info.cmd, process_info.state, process_info.user);
            }
        }
    }
    
    closedir(proc_dir);
}

int main() {
    while (1) {
        printf("\033[H\033[J"); // Clear the terminal
        printf("Process Viewer\n");
        printf("Press Ctrl+C to exit\n\n");
        list_processes();
        sleep(2); // Refresh every 2 seconds
    }
    return 0;
}