//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 1024

typedef struct {
    char name[16];
    int pid;
    int mem_usage;
} process;

void init_table() {
    FILE *fp = fopen("/proc/self/status", "r");
    char line[BUF_SIZE];
    process *table = (process*) malloc(sizeof(process) * 10);
    int count = 0;

    while (fgets(line, BUF_SIZE, fp)!= NULL) {
        if (strncmp(line, "VmSize:", 8) == 0) {
            table[count].mem_usage = atoi(line + 8) / 1024;
            strncpy(table[count].name, line, 15);
            table[count].name[15] = '\0';
            table[count].pid = getpid();
            count++;
        }
    }

    fclose(fp);

    if (count == 0) {
        printf("No processes found\n");
        exit(1);
    }

    printf("Process\t\tPID\t\tMemory Usage (KB)\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%d\t\t%d\n", table[i].name, table[i].pid, table[i].mem_usage);
    }
}

void update_table() {
    FILE *fp = fopen("/proc/self/status", "r");
    char line[BUF_SIZE];
    process *table = (process*) malloc(sizeof(process) * 10);
    int count = 0;

    while (fgets(line, BUF_SIZE, fp)!= NULL) {
        if (strncmp(line, "VmSize:", 8) == 0) {
            for (int i = 0; i < count; i++) {
                if (strcmp(table[i].name, line) == 0) {
                    table[i].mem_usage = atoi(line + 8) / 1024;
                    break;
                }
            }
            count++;
        }
    }

    fclose(fp);

    if (count == 0) {
        printf("No processes found\n");
        exit(1);
    }

    printf("\nProcess\t\tPID\t\tMemory Usage (KB)\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%d\t\t%d\n", table[i].name, table[i].pid, table[i].mem_usage);
    }
}

void monitor_ram() {
    init_table();
    while (1) {
        sleep(5);
        update_table();
    }
}

int main() {
    monitor_ram();
    return 0;
}