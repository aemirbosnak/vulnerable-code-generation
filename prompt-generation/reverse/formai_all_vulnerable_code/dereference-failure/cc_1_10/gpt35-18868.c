//FormAI DATASET v1.0 Category: System process viewer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define BUF_SIZE 1024

int is_all_digit(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

void print_process_info(const char *pid_str, const char *pname) {
    char stat_file_path[BUF_SIZE];
    sprintf(stat_file_path, "/proc/%s/stat", pid_str);

    FILE *stat_file = fopen(stat_file_path, "r");
    if (!stat_file) {
        return;
    }

    int pid;
    char comm[BUF_SIZE];
    char state;
    fscanf(stat_file, "%d %s %c", &pid, comm, &state);
    fclose(stat_file);

    printf("%-10s %-20s %-10c\n", pid_str, pname, state);
}

void list_processes() {
    DIR *proc_dir = opendir("/proc");
    struct dirent *entry;
    while ((entry = readdir(proc_dir))) {
        char *entry_name = entry->d_name;
        if (!is_all_digit(entry_name)) {
            continue;
        }

        char cmdline_file_path[BUF_SIZE];
        sprintf(cmdline_file_path, "/proc/%s/cmdline", entry_name);

        FILE *cmdline_file = fopen(cmdline_file_path, "r");
        if (!cmdline_file) {
            continue;
        }

        char process_name[BUF_SIZE] = "";
        fgets(process_name, BUF_SIZE, cmdline_file);
        fclose(cmdline_file);

        if (strlen(process_name) == 0) {
            strncpy(process_name, "<unknown>", BUF_SIZE - 1);
        }

        print_process_info(entry_name, process_name);
    }

    closedir(proc_dir);
}

int main() {
    printf("%-10s %-20s %-10s\n", "PID", "NAME", "STATE");
    list_processes();

    return 0;
}