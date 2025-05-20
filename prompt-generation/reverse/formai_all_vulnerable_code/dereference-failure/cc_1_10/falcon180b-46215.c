//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_PROCESS_NAME_LENGTH 16

typedef struct {
    int pid;
    char process_name[MAX_PROCESS_NAME_LENGTH];
    float cpu_usage;
} process_info;

void get_process_info(process_info *process_list, int num_processes) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token;
    int i = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error: Could not open /proc/stat\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (i >= num_processes) {
            break;
        }

        token = strtok(line, " ");
        if (token == NULL) {
            continue;
        }

        if (strcmp(token, "cpu") == 0) {
            token = strtok(NULL, " ");
            if (token == NULL) {
                continue;
            }

            for (int j = 0; j < num_processes; j++) {
                if (process_list[j].pid == atoi(token)) {
                    process_list[j].cpu_usage = atof(strtok(NULL, " "));
                    break;
                }
            }
        }
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [process_name]\n", argv[0]);
        exit(1);
    }

    int num_processes = 1;
    process_info process_list[MAX_PROCESS_NAME_LENGTH];

    strncpy(process_list[0].process_name, argv[1], MAX_PROCESS_NAME_LENGTH - 1);
    process_list[0].process_name[MAX_PROCESS_NAME_LENGTH - 1] = '\0';
    process_list[0].pid = getpid();

    get_process_info(process_list, num_processes);

    printf("Process Name: %s\n", process_list[0].process_name);
    printf("PID: %d\n", process_list[0].pid);
    printf("CPU Usage: %.2f%%\n", process_list[0].cpu_usage);

    return 0;
}