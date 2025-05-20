//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PROC_NUM 1024

typedef struct proc_info_t {
    char name[256];
    pid_t pid;
    int ppid;
    struct proc_info_t *next;
} proc_info_t;

proc_info_t *proc_info_head = NULL;

void display_processes() {
    proc_info_t *curr = proc_info_head;
    printf("---------------------------------------------\n");
    printf("Process Information:\n");
    printf("---------------------------------------------\n");
    while (curr) {
        printf("Name: %s, PID: %d, PPID: %d\n", curr->name, curr->pid, curr->ppid);
        curr = curr->next;
    }
    printf("---------------------------------------------\n");
}

int main() {
    char proc_name[256];
    int pid, ppid;

    // Allocate and initialize process information structure
    proc_info_head = malloc(sizeof(proc_info_t));
    proc_info_head->next = NULL;

    // Get the process name from the user
    printf("Enter the name of the process: ");
    scanf("%s", proc_name);

    // Get the PID and PPID of the process
    pid = getpid();
    ppid = getppid();

    // Create a new process information structure node
    proc_info_t *new_node = malloc(sizeof(proc_info_t));
    new_node->next = NULL;

    // Fill the node with process information
    strcpy(new_node->name, proc_name);
    new_node->pid = pid;
    new_node->ppid = ppid;

    // Add the node to the process information structure
    if (proc_info_head->next) {
        proc_info_head->next = new_node;
    } else {
        proc_info_head = new_node;
    }

    // Display the processes
    display_processes();

    return 0;
}