//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/sysinfo.h>

#define MAX_SAMPLES 100
#define SAMPLE_INTERVAL 1

typedef struct {
    int cpu_usage;
    char *process_name;
} process_info_t;

process_info_t processes[MAX_SAMPLES];
int num_processes = 0;

void read_processes() {
    FILE *fp;
    char line[1024];
    char *token;
    int i = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error: failed to open /proc/stat\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= MAX_SAMPLES) {
            break;
        }

        token = strtok(line, " ");
        if (token == NULL) {
            continue;
        }

        if (strcmp(token, "cpu") == 0) {
            token = strtok(NULL, " ");
            processes[i].cpu_usage = atoi(token);

            token = strtok(NULL, " ");
            while (token!= NULL) {
                if (strcmp(token, "idle")!= 0 && strcmp(token, "iowait")!= 0 && strcmp(token, "irq")!= 0 && strcmp(token, "softirq")!= 0) {
                    strncpy(processes[i].process_name, token, sizeof(processes[i].process_name) - 1);
                    break;
                }

                token = strtok(NULL, " ");
            }

            i++;
        }
    }

    fclose(fp);
}

void print_processes() {
    int i;

    for (i = 0; i < num_processes; i++) {
        printf("%s: %d%%\n", processes[i].process_name, processes[i].cpu_usage);
    }
}

int main() {
    int i;
    struct sysinfo si;

    for (i = 0; i < MAX_SAMPLES; i++) {
        processes[i].cpu_usage = 0;
        strcpy(processes[i].process_name, "");
    }

    while (1) {
        sysinfo(&si);

        read_processes();

        printf("CPU Usage:\n");
        print_processes();

        sleep(SAMPLE_INTERVAL);
    }

    return 0;
}