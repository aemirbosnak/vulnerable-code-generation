//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <wait.h>

#define MAX_PROC_NUM 1024

typedef struct process_info {
    char name[256];
    int pid;
    struct process_info* next;
} process_info;

process_info* head = NULL;

void display_processes() {
    process_info* current = head;
    printf("Processes:\n");
    while (current) {
        printf("%s (PID: %d)\n", current->name, current->pid);
        current = current->next;
    }
}

void add_process(char* name) {
    process_info* new_process = malloc(sizeof(process_info));
    new_process->name[0] = '\0';
    strcpy(new_process->name, name);
    new_process->pid = getpid();
    new_process->next = NULL;

    if (head == NULL) {
        head = new_process;
    } else {
        process_info* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_process;
    }
}

int main() {
    add_process("firefox");
    add_process("chrome");
    add_process("gnome-shell");
    add_process("system-monitor");

    display_processes();

    wait(NULL);

    return 0;
}