//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PROCESSES 10

typedef struct Process {
    char name[20];
    int cpu_usage;
    struct Process* next;
} Process;

Process* head = NULL;

void update_process_cpu_usage(char* process_name, int usage) {
    Process* current = head;
    Process* previous = NULL;

    while (current) {
        if (strcmp(current->name, process_name) == 0) {
            current->cpu_usage = usage;
            return;
        }

        previous = current;
        current = current->next;
    }

    // If the process is not found, add it to the list
    Process* new_process = malloc(sizeof(Process));
    new_process->name[0] = '\0';
    strcpy(new_process->name, process_name);
    new_process->cpu_usage = usage;
    new_process->next = NULL;

    if (previous) {
        previous->next = new_process;
    } else {
        head = new_process;
    }
}

int main() {
    update_process_cpu_usage("firefox", 80);
    update_process_cpu_usage("chrome", 60);
    update_process_cpu_usage("eclipse", 40);

    Process* current = head;
    while (current) {
        printf("%s: %d%\n", current->name, current->cpu_usage);
        current = current->next;
    }

    return 0;
}