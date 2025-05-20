//FormAI DATASET v1.0 Category: System process viewer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PID_LENGTH 10
#define MAX_COMMAND_LENGTH 255

char *get_cmd_name(char *cmd_line);
char *get_pid_name(int pid);
void print_process_info(int pid);

int main() {
    DIR *dir;
    struct dirent *dp;

    printf("=======================================\n");
    printf("     Shape Shifting Process Viewer     \n");
    printf("=======================================\n\n");

    dir = opendir("/proc/");
    if (!dir) {
        printf("Failed to open /proc/ directory\n");
        return 1;
    }

    while ((dp = readdir(dir)) != NULL) {
        if (!isdigit(dp->d_name[0])) {
            continue;
        }

        int pid = atoi(dp->d_name);
        print_process_info(pid);
    }

    closedir(dir);
    return 0;
}

char *get_cmd_name(char *cmd_line) {
    char *token = strtok(cmd_line, " ");
    if (token == NULL) {
        return NULL;
    }

    token = strtok(NULL, " ");
    if (token == NULL) {
        return NULL;
    }

    return token;
}

char *get_pid_name(int pid) {
    char *filename = malloc(sizeof(char) * MAX_PID_LENGTH + 7);
    sprintf(filename, "/proc/%d/cmdline", pid);

    FILE *file = fopen(filename, "r");
    if (file) {
        char *content = malloc(sizeof(char) * MAX_COMMAND_LENGTH);
        fgets(content, MAX_COMMAND_LENGTH, file);
        fclose(file);

        return get_cmd_name(content);
    }

    return NULL;
}

void print_process_info(int pid) {
    char *pid_name = get_pid_name(pid);
    if (pid_name == NULL) {
        return;
    }

    char *filename = malloc(sizeof(char) * MAX_PID_LENGTH + 11);
    sprintf(filename, "/proc/%d/status", pid);

    FILE *file = fopen(filename, "r");
    if (!file) {
        free(pid_name);
        free(filename);
        return;
    }

    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, file) != -1) {
        if (strstr(line, "State:") != NULL) {
            printf("%s - %s\n", pid_name, line + 7);
            break;
        }
    }

    fclose(file);
    free(line);
    free(filename);
    free(pid_name);
}