//FormAI DATASET v1.0 Category: System process viewer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_PID_LENGTH 6
#define MAX_CMDLINE_LENGTH 256

struct Process {
    int pid;
    char cmdline[MAX_CMDLINE_LENGTH];
    unsigned long rss_size;
    unsigned long vms_size;
    char status;
    time_t start_time;
};

struct Process * get_process_list(int *num_procs) {
    DIR *proc_directory = opendir("/proc");
    if (proc_directory == NULL) {
        printf("Error: Failed to open /proc directory\n");
        exit(1);
    }

    struct dirent *entry;
    int num_entries = 0;
    while ((entry = readdir(proc_directory)) != NULL) {
        if (entry->d_type != DT_DIR) {
            continue;
        }
        char *endptr;
        int pid = strtol(entry->d_name, &endptr, 10);
        if (*endptr != '\0') {
            continue;
        }
        char cmdline_filepath[256];
        snprintf(cmdline_filepath, sizeof(cmdline_filepath), "/proc/%d/cmdline", pid);
        FILE *cmdline_file = fopen(cmdline_filepath, "r");
        if (cmdline_file == NULL) {
            continue;
        }
        char cmdline[MAX_CMDLINE_LENGTH];
        int cmdline_length = fread(cmdline, 1, sizeof(cmdline) - 1, cmdline_file);
        fclose(cmdline_file);
        if (cmdline_length == 0) {
            continue;
        }
        cmdline[cmdline_length] = '\0';

        char status_filepath[256];
        snprintf(status_filepath, sizeof(status_filepath), "/proc/%d/status", pid);
        FILE *status_file = fopen(status_filepath, "r");
        if (status_file == NULL) {
            continue;
        }
        char status_line[256];
        while (fgets(status_line, sizeof(status_line), status_file)) {
            if (strncmp(status_line, "VmSize:", strlen("VmSize:")) == 0) {
                char *endptr;
                unsigned long size = strtoul(status_line + strlen("VmSize:"), &endptr, 10);
                if (*endptr == 'k') {
                    size *= 1024;
                } else if (*endptr == 'm') {
                    size *= 1024 * 1024;
                }
                struct Process proc = { .pid = pid };
                strncpy(proc.cmdline, cmdline, sizeof(proc.cmdline));
                proc.rss_size = 0;
                proc.vms_size = size;
                if (strncmp(status_line + strlen("VmSize:")+5, "kB", strlen("kB"))==0){
                    proc.status = 'kB';
                }else if(strncmp(status_line + strlen("VmSize:")+5, "MB", strlen("MB"))==0){
                    proc.status = 'MB'; 
                }
                char stathelp[256];
                time_t start_time = 0;
                while (fgets(stathelp, sizeof(stathelp), status_file)) {
                    if (strncmp(stathelp, "State:", strlen("State:")) == 0) {
                        proc.status = stathelp[strlen(stathelp)-2];
                    } else if (strncmp(stathelp, "se.sum_exec_runtime", strlen("se.sum_exec_runtime")) == 0) {
                        char *endptr;
                        unsigned long cpu_time = strtoul(stathelp + strlen("se.sum_exec_runtime:"), &endptr, 10);
                        if (*endptr == '.') {
                            int i;
                            for (i = 0; i < 8 && endptr[i] != '\n'; i++) {
                                if (endptr[i] == '\0') {
                                    break;
                                }
                            }
                            endptr += i;
                        }
                        long clock_tick_per_sec = sysconf(_SC_CLK_TCK);
                        proc.start_time = time(NULL) - cpu_time / clock_tick_per_sec;
                    }
                }
                fclose(status_file);
                (*num_procs)++;
            }
        }
    }
    closedir(proc_directory);

    return NULL;
}

void print_process(struct Process proc) {
    char proc_status_name;
    switch (proc.status) {
        case 'R':
            proc_status_name = 'Running';
            break;
        case 'S':
            proc_status_name = 'Sleeping';
            break;
        case 'D':
            proc_status_name = 'Disk Sleep';
            break;
        case 'Z':
            proc_status_name = 'Zombie';
            break;
        default:
            proc_status_name = 'Unknown';
    }
    printf("%d\t%s\t%lu %c\t%lu %c\t%s\t%s\n", proc.pid, proc.cmdline, proc.vms_size, proc.status, proc.rss_size, proc.status, asctime(localtime(&proc.start_time)), proc_status_name);
}

int main() {
    int num_procs = 0;
    struct Process *procs = get_process_list(&num_procs);

    printf("PID\tCmdline\tVMS Size\tRSS Size\tStart Time\tStatus Name\n");
    for (int i = 0; i < num_procs; i++) {
        print_process(procs[i]);
    }

    if (procs != NULL) {
        free(procs);
    }

    return 0;
}