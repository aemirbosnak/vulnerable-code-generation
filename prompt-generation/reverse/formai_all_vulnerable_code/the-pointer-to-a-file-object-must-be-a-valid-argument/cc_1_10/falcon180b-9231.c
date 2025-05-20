//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 50

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    int pid;
    int memory_usage;
} Process;

int main() {
    char *process_names[MAX_PROCESSES];
    int num_processes = 0;
    int i;

    // Get the list of running processes
    FILE *fp;
    char filename[100];
    sprintf(filename, "/proc/self/status");
    fp = fopen(filename, "r");
    char line[100];
    while (fgets(line, 100, fp)) {
        if (strstr(line, "VmSize")!= NULL) {
            char *token = strtok(line, " ");
            int pid = atoi(token);
            char *name = (char*)malloc(MAX_PROCESS_NAME_LENGTH);
            sprintf(name, "/proc/%d/stat", pid);
            FILE *fp_name;
            fp_name = fopen(name, "r");
            char *comm;
            fscanf(fp_name, "%s", comm);
            fclose(fp_name);
            free(name);
            if (num_processes < MAX_PROCESSES) {
                process_names[num_processes] = (char*)malloc(strlen(comm) + 1);
                strcpy(process_names[num_processes], comm);
                num_processes++;
            }
        }
    }
    fclose(fp);

    // Sort the list of processes by memory usage
    for (i = 0; i < num_processes - 1; i++) {
        int j;
        for (j = i + 1; j < num_processes; j++) {
            if (atoi(process_names[j]) < atoi(process_names[i])) {
                char *temp = process_names[i];
                process_names[i] = process_names[j];
                process_names[j] = temp;
            }
        }
    }

    // Print the list of processes
    printf("Process\tMemory Usage\n");
    for (i = 0; i < num_processes; i++) {
        printf("%s\t%d\n", process_names[i], atoi(process_names[i]));
    }

    return 0;
}