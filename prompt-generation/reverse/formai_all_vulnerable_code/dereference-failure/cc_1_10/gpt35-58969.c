//FormAI DATASET v1.0 Category: System process viewer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFF_SIZE 1024

typedef struct {
    char user[BUFF_SIZE];
    char pid[BUFF_SIZE];
    char ppid[BUFF_SIZE];
    char state[BUFF_SIZE];
    char cpu_time[BUFF_SIZE];
    char priority[BUFF_SIZE];
    char memory[BUFF_SIZE];
    char command[BUFF_SIZE];
} process_info;

void parse_proc_stat(char *line, process_info *info) {
    sscanf(line, "%s %s %s %s %s %s %s", info->pid, info->command, info->state, info->ppid, info->cpu_time, info->priority, info->memory);
}

void parse_proc_status(char *line, process_info *info) {
    if (strncmp(line, "Uid:", 4) == 0) {
        char *uid = line + 4;
        while (!isdigit(*uid)) uid++;
        char *end = strchr(uid, '\t');
        if (end == NULL) end = strchr(uid, '\n');
        *end = '\0';

        char cmd[BUFF_SIZE];
        snprintf(cmd, sizeof(cmd), "/usr/bin/id -un %s", uid);
        FILE *uid_file = popen(cmd, "r");
        if (uid_file != NULL) {
            char user[BUFF_SIZE];
            if (fgets(user, sizeof(user), uid_file) != NULL) {
                char *end = strchr(user, '\n');
                if (end != NULL) *end = '\0';
                strncpy(info->user, user, sizeof(info->user));
            }
        }
    }
}

void print_process_info(process_info *info) {
    printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %s\n", "USER", "PID", "PPID", "STATE", "CPU TIME", "PRIORITY", "MEMORY", "COMMAND");
    printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %s\n", 
            info->user, info->pid, info->ppid, info->state, info->cpu_time, info->priority, info->memory, info->command);
    printf("-----------------------------------------------------------------------------------------\n");
}

int main(void) {
    printf("System process viewer\n\n");
    printf("-----------------------------------------------------------------------------------------\n");

    DIR *dirp;
    struct dirent *entry;

    if ((dirp = opendir("/proc/")) == NULL) {
        perror("Failed to open directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dirp)) != NULL) {
        if (isdigit(*entry->d_name)) {
            char path[BUFF_SIZE];
            snprintf(path, sizeof(path), "/proc/%s", entry->d_name);

            struct stat sb;
            if (stat(path, &sb) == -1) continue;
            if (!S_ISDIR(sb.st_mode)) continue;

            char proc_stat_path[BUFF_SIZE];
            snprintf(proc_stat_path, sizeof(proc_stat_path), "%s/stat", path);

            FILE *proc_stat_file = fopen(proc_stat_path, "r");
            if (proc_stat_file == NULL) continue;

            char *line = NULL;
            size_t len = 0;
            ssize_t read;
            if ((read = getline(&line, &len, proc_stat_file)) != -1) {
                process_info info;
                memset(&info, 0, sizeof(info));

                parse_proc_stat(line, &info);

                char proc_status_path[BUFF_SIZE];
                snprintf(proc_status_path, sizeof(proc_status_path), "%s/status", path);

                FILE *proc_status_file = fopen(proc_status_path, "r");
                if (proc_status_file != NULL) {
                    while ((read = getline(&line, &len, proc_status_file)) != -1) {
                        parse_proc_status(line, &info);
                    }
                    fclose(proc_status_file);
                }

                print_process_info(&info);
            }

            fclose(proc_stat_file);
        }
    }

    closedir(dirp);

    return 0;
}