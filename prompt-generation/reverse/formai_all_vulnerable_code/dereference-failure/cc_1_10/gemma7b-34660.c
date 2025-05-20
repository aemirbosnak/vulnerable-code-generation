//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PROC 10

typedef struct process_info {
    char name[256];
    int pid;
    long uptime;
    struct process_info* next;
} process_info;

process_info* head = NULL;

void add_process(char* name, int pid, long uptime) {
    process_info* new_process = malloc(sizeof(process_info));
    strcpy(new_process->name, name);
    new_process->pid = pid;
    new_process->uptime = uptime;
    new_process->next = head;
    head = new_process;
}

long get_process_uptime(int pid) {
    process_info* current_process = head;
    while (current_process) {
        if (current_process->pid == pid) {
            return current_process->uptime;
        }
        current_process = current_process->next;
    }
    return -1;
}

int main() {
    char buffer[256];
    long uptime;
    int i, j, k, pid;

    for (i = 0; i < MAX_PROC; i++) {
        add_process("Process", i, 0);
    }

    while (1) {
        printf("Enter command: ");
        scanf("%s", buffer);

        if (strcmp(buffer, "quit") == 0) {
            break;
        } else if (strcmp(buffer, "uptime") == 0) {
            printf("Enter process ID: ");
            scanf("%d", &pid);

            uptime = get_process_uptime(pid);

            if (uptime != -1) {
                printf("Process uptime: %ld seconds\n", uptime);
            } else {
                printf("Process not found.\n");
            }
        }
    }

    return 0;
}