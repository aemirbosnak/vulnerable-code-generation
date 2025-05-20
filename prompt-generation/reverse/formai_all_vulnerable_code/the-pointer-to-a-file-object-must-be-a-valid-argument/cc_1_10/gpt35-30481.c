//FormAI DATASET v1.0 Category: System process viewer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PID_LEN 6
#define MAX_CMDLINE_LEN 512

struct Process {
    char pid[MAX_PID_LEN];
    char cmdline[MAX_CMDLINE_LEN];
};

void display_processes(struct Process* p, int len) {
    printf("PID\tCMDLINE\n");
    printf("---\t-------\n");
    for (int i = 0; i < len; i++) {
        printf("%s\t%s\n", p[i].pid, p[i].cmdline);
    }
}

int main() {
    struct Process process_list[1024];
    char cmd[MAX_CMDLINE_LEN];
    FILE* fp;
    char temp_pid[MAX_PID_LEN];
    int index = 0;
    char* start_ptr, *end_ptr;

    // Read /proc directory to get all running processes
    fp = fopen("/proc", "r");
    while (fgets(cmd, MAX_CMDLINE_LEN, fp) != NULL) {
        // Check if directory name is numeric (i.e., process id)
        if (cmd[0] >= '0' && cmd[0] <= '9') {
            // Get PID from directory name
            strncpy(temp_pid, cmd, MAX_PID_LEN);
            // Open cmdline file for process and read command line
            snprintf(cmd, MAX_CMDLINE_LEN, "/proc/%s/cmdline", temp_pid);
            FILE* cmdfp = fopen(cmd, "r");
            if (cmdfp != NULL) {
                fgets(cmd, MAX_CMDLINE_LEN, cmdfp);
                fclose(cmdfp);
                // Replace null bytes in command line with spaces
                for (int i = 0; i < strlen(cmd); i++) {
                    if (cmd[i] == '\0') {
                        cmd[i] = ' ';
                    }
                }
                // Store process pid and command line
                strncpy(process_list[index].pid, temp_pid, MAX_PID_LEN);
                strcpy(process_list[index].cmdline, cmd);
                index++;
            }
        }
    }
    fclose(fp);

    // Display all running processes
    display_processes(process_list, index);

    return 0;
}