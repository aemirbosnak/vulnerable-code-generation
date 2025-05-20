//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 1024
#define MAX_PROCESS_NAME_LEN 16

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME_LEN];
    int ram_usage;
} Process;

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;
    char command[64] = "ps -eo pid,comm --no-headers";
    FILE *fp;
    char line[1024];
    int pid, i;
    char name[MAX_PROCESS_NAME_LEN];
    int ram_usage;

    // Get the list of processes
    fp = popen(command, "r");
    while (fgets(line, sizeof(line), fp)!= NULL) {
        sscanf(line, "%d %s", &pid, name);
        ram_usage = get_ram_usage(pid);
        for (i = 0; i < num_processes; i++) {
            if (processes[i].pid == pid) {
                processes[i].ram_usage = ram_usage;
                break;
            }
        }
        if (i == num_processes) {
            processes[num_processes].pid = pid;
            strncpy(processes[num_processes].name, name, MAX_PROCESS_NAME_LEN - 1);
            processes[num_processes].name[MAX_PROCESS_NAME_LEN - 1] = '\0';
            processes[num_processes].ram_usage = ram_usage;
            num_processes++;
        }
    }
    pclose(fp);

    // Print the list of processes
    printf("PID\tName\tRAM Usage (KB)\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].ram_usage);
    }

    return 0;
}

int get_ram_usage(int pid) {
    char path[64];
    sprintf(path, "/proc/%d/statm", pid);
    FILE *fp = fopen(path, "r");
    int ram_usage;
    if (fp!= NULL) {
        fscanf(fp, "%*d %*d %*d %*d %d", &ram_usage);
        fclose(fp);
    } else {
        ram_usage = -1;
    }
    return ram_usage;
}