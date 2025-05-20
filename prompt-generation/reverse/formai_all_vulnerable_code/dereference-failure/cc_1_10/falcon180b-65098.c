//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int pid;
    char name[20];
    int ram_usage;
} Process;

Process *processes[MAX_PROCESSES];
int num_processes = 0;

void add_process(int pid, char *name, int ram_usage) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    Process *new_process = malloc(sizeof(Process));
    new_process->pid = pid;
    strcpy(new_process->name, name);
    new_process->ram_usage = ram_usage;
    processes[num_processes++] = new_process;
}

void remove_process(int pid) {
    for (int i = 0; i < num_processes; i++) {
        if (processes[i]->pid == pid) {
            free(processes[i]);
            processes[i] = processes[--num_processes];
            return;
        }
    }
}

void update_ram_usage(int pid, int new_ram_usage) {
    for (int i = 0; i < num_processes; i++) {
        if (processes[i]->pid == pid) {
            processes[i]->ram_usage = new_ram_usage;
            return;
        }
    }
}

void print_processes() {
    printf("PID\tName\tRAM Usage\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i]->pid, processes[i]->name, processes[i]->ram_usage);
    }
}

int main() {
    add_process(1, "Init", 1000);
    add_process(2, "Kernel", 2000);
    add_process(3, "Shell", 3000);

    print_processes();

    update_ram_usage(2, 2500);

    print_processes();

    remove_process(3);

    print_processes();

    return 0;
}