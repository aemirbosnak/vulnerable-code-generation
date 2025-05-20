//FormAI DATASET v1.0 Category: System process viewer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PATH_LENGTH 1024
#define MAX_PID_LENGTH 16

char *get_process_name(char *pid) {
    char *name = NULL;
    char path[MAX_PATH_LENGTH];
    sprintf(path, "/proc/%s/cmdline", pid);
    FILE *cmd_file = fopen(path, "r");
    if (cmd_file != NULL) {
        if (fscanf(cmd_file, "%ms", &name) == 1) {
            char *ptr = strchr(name, '\0');
            while (ptr > name && !isalnum(*(ptr - 1))) {
                *--ptr = '\0';
            }
        }
        fclose(cmd_file);
    }
    return name;
}


int main() {
    DIR *proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        fprintf(stderr, "Failed to open /proc directory\n");
        return EXIT_FAILURE;
    }

    struct dirent *dir_entry;
    printf("%-10s %-20s %-5s %s\n", "PID", "NAME", "STATE", "COMMAND");
    printf("%-10s %-20s %-5s %s\n", "---", "----", "-----", "-------");
    while ((dir_entry = readdir(proc_dir)) != NULL) {
        char *name = dir_entry->d_name;
        if (isdigit(name[0])) {
            char pid[MAX_PID_LENGTH];
            strcpy(pid, name);

            char path[MAX_PATH_LENGTH];
            sprintf(path, "/proc/%s/stat", pid);

            FILE *stat_file = fopen(path, "r");
            if (stat_file != NULL) {
                int status;
                fscanf(stat_file, "%*d %*s %c %d", &status, &status);
                fclose(stat_file);

                char *state;
                switch (status) {
                    case 'R': state = "Running"; break;
                    case 'S': state = "Sleeping"; break;
                    case 'D': state = "Waiting"; break;
                    case 'Z': state = "Zombie"; break;
                    case 'T': state = "Stopped"; break;
                    default: state = "Unknown"; break;
                }

                char *process_name = get_process_name(pid);
                if (process_name != NULL) {
                    printf("%-10s %-20s %-5s %s\n", pid, process_name, state, process_name);
                    free(process_name);
                }
            }
        }
    }

    closedir(proc_dir);
    return 0;
}