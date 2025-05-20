//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define MAX_PROCESS_NAME_LENGTH 16

typedef struct process_info {
    pid_t pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    unsigned long long mem_usage;
} process_info_t;

void get_process_info(process_info_t *process_info, int num_processes) {
    FILE *file;
    char line[1024];
    char *token;
    int i = 0;

    file = fopen("/proc/self/status", "r");
    if (file == NULL) {
        printf("Error opening /proc/self/status\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        token = strtok(line, ":");
        if (token!= NULL) {
            if (strcmp(token, "VmSize") == 0) {
                process_info[i].mem_usage = atoll(strtok(NULL, " "));
            } else if (strcmp(token, "Name") == 0) {
                strncpy(process_info[i].name, strtok(NULL, " "), MAX_PROCESS_NAME_LENGTH - 1);
            }
        }
        i++;
    }

    fclose(file);
}

void print_process_info(process_info_t *process_info, int num_processes) {
    int i;

    for (i = 0; i < num_processes; i++) {
        printf("%-10d %-16s %10llu\n", process_info[i].pid, process_info[i].name, process_info[i].mem_usage);
    }
}

int main(int argc, char *argv[]) {
    process_info_t process_info[MAX_PROCESSES];
    int num_processes = 0;

    if (argc!= 2) {
        printf("Usage: %s <process_name>\n", argv[0]);
        exit(1);
    }

    strncpy(process_info[num_processes].name, argv[1], MAX_PROCESS_NAME_LENGTH - 1);
    process_info[num_processes].mem_usage = 0;
    num_processes++;

    get_process_info(process_info, num_processes);
    print_process_info(process_info, num_processes);

    return 0;
}