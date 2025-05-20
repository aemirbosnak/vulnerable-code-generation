//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROC 10 // Maximum number of processes
#define MAX_NAME 20 // Maximum length of process name

typedef struct {
    char name[MAX_NAME];
    int ram;
} process;

int main() {
    int i, total_ram = 0, used_ram = 0;
    process *procs[MAX_PROC];

    // Initialize processes
    for (i = 0; i < MAX_PROC; i++) {
        procs[i] = (process*) malloc(sizeof(process));
        memset(procs[i], 0, sizeof(process));
    }

    // Assign process names and RAM usage
    strcpy(procs[0]->name, "chrome.exe");
    procs[0]->ram = 300;
    strcpy(procs[1]->name, "outlook.exe");
    procs[1]->ram = 150;
    strcpy(procs[2]->name, "notepad.exe");
    procs[2]->ram = 50;

    // Print header
    printf("Process\t\tRAM Usage\n");

    // Print process names and RAM usage
    for (i = 0; i < MAX_PROC; i++) {
        if (strcmp(procs[i]->name, "") != 0) {
            total_ram += procs[i]->ram;
            printf("%s\t\t%d\n", procs[i]->name, procs[i]->ram);
        }
    }
    used_ram = total_ram;

    // Print footer
    printf("------------------------------\n");
    printf("Total RAM Usage:\t%d\n", total_ram);
    printf("Used RAM:\t\t%d\n", used_ram);

    // Free processes
    for (i = 0; i < MAX_PROC; i++) {
        if (procs[i] != NULL) {
            free(procs[i]);
            procs[i] = NULL;
        }
    }

    return 0;
}