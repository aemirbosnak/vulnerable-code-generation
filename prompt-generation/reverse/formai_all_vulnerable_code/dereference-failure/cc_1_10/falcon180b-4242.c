//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/sysinfo.h>

#define BUFFER_SIZE 1024

typedef struct {
    char name[32];
    int pid;
    float cpu_usage;
} process_info_t;

void get_process_info(process_info_t *process_info, int num_processes) {
    FILE *fp;
    char line[BUFFER_SIZE];
    char *token;
    int i = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error: could not open /proc/stat\n");
        exit(1);
    }

    while (fgets(line, BUFFER_SIZE, fp)!= NULL) {
        token = strtok(line, " ");
        if (token!= NULL) {
            if (strcmp(token, "cpu") == 0) {
                token = strtok(NULL, " ");
                sscanf(token, "%d", &process_info[i].pid);
                process_info[i].cpu_usage = 0.0;
                i++;
            }
        }
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    int num_processes = 0;
    process_info_t *process_info = NULL;

    if (argc!= 2) {
        printf("Usage: %s <number_of_processes>\n", argv[0]);
        return 1;
    }

    num_processes = atoi(argv[1]);
    process_info = (process_info_t *)malloc(num_processes * sizeof(process_info_t));

    get_process_info(process_info, num_processes);

    while (1) {
        sleep(1);
        get_process_info(process_info, num_processes);

        printf("\n");
        for (int i = 0; i < num_processes; i++) {
            if (process_info[i].pid > 0) {
                printf("%-32s %-10d %-10.2f%%\n", process_info[i].name, process_info[i].pid, process_info[i].cpu_usage);
            }
        }
    }

    return 0;
}