//FormAI DATASET v1.0 Category: System boot optimizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 255

/* Define a struct to store boot process information */
typedef struct {
    char name[MAX_LINE_LENGTH];
    int priority;
    bool isEnabled;
} BootProcess;

/* Define a helper function to read a line from a file */
char* readLine(FILE* file) {
    char* line = malloc(MAX_LINE_LENGTH);
    fgets(line, MAX_LINE_LENGTH, file);
    return line;
}

/* Define a helper function to parse a line into a BootProcess struct */
BootProcess parseLine(char* line) {
    BootProcess process;
    char* token = strtok(line, ",");
    strcpy(process.name, token);
    token = strtok(NULL, ",");
    process.priority = atoi(token);
    token = strtok(NULL, ",");
    process.isEnabled = (strcmp(token, "true\n") == 0);
    return process;
}

int main() {
    /* Open the boot process file for reading */
    FILE* file = fopen("boot_process.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open boot process file\n");
        return 1;
    }

    /* Read each line of the file and parse it into a BootProcess struct */
    BootProcess processes[10];
    int numProcesses = 0;
    char* line;
    while ((line = readLine(file)) != NULL) {
        processes[numProcesses] = parseLine(line);
        numProcesses++;
        free(line);
    }

    /* Close the file */
    fclose(file);

    /* Sort the boot processes by priority */
    for (int i = 0; i < numProcesses - 1; i++) {
        for (int j = i + 1; j < numProcesses; j++) {
            if (processes[j].priority > processes[i].priority) {
                BootProcess temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    /* Disable all low priority boot processes */
    for (int i = numProcesses - 1; i >= 0; i--) {
        if (processes[i].priority < 5) {
            processes[i].isEnabled = false;
        }
    }

    /* Open the boot process file for writing */
    file = fopen("boot_process.txt", "w");
    if (file == NULL) {
        printf("Error: Could not open boot process file for writing\n");
        return 1;
    }

    /* Write the updated boot process information back to the file */
    for (int i = 0; i < numProcesses; i++) {
        fprintf(file, "%s,%d,%s\n", processes[i].name, processes[i].priority, processes[i].isEnabled ? "true" : "false");
    }

    /* Close the file */
    fclose(file);

    printf("Boot process optimization complete!\n");

    return 0;
}