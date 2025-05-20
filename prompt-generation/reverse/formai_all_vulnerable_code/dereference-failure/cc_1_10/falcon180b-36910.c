//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LEN 100

typedef struct {
    char name[MAX_PROCESS_NAME_LEN];
    int pid;
    int ram_usage;
} process_t;

int main() {
    int num_processes = 0;
    process_t processes[MAX_PROCESSES];

    while (1) {
        printf("Enter process name (or 'exit' to quit): ");
        char input[MAX_PROCESS_NAME_LEN];
        fgets(input, MAX_PROCESS_NAME_LEN, stdin);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        int pid = atoi(strtok(input, " "));
        strcpy(processes[num_processes].name, input);
        processes[num_processes].pid = pid;
        num_processes++;
    }

    while (1) {
        printf("\n");
        for (int i = 0; i < num_processes; i++) {
            printf("%d. %s (PID: %d)\n", i+1, processes[i].name, processes[i].pid);
        }

        printf("\nEnter process number to view RAM usage: ");
        int process_num;
        scanf("%d", &process_num);

        if (process_num < 1 || process_num > num_processes) {
            printf("Invalid process number.\n");
        } else {
            printf("\nRAM usage for %s (PID: %d): %d bytes\n", processes[process_num-1].name, processes[process_num-1].pid, processes[process_num-1].ram_usage);
        }
    }

    return 0;
}