//FormAI DATASET v1.0 Category: System process viewer ; Style: unmistakable
/* A unique C system process viewer example program */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

/* struct to hold data for each process */
typedef struct _ProcessData {
    int pid;
    char name[256];
    char state;
    int memory;
} ProcessData;

/* function to get process data */
void getProcessData(ProcessData *data, int pid) {
    char filename[256];
    FILE *fp;
    sprintf(filename, "/proc/%d/stat", pid);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: failed to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%d %s %c %*d %*d %*d %*d %*d %*u %*u %*u %*u %*u %*u %*u %*u %*d %*d %*d %*d %*d %*u %d",
           &(data->pid), data->name, &(data->state), &(data->memory));
    fclose(fp);
}

/* function to print process data */
void printProcessData(ProcessData data) {
    printf("%d\t%s\t%c\t%d\n", data.pid, data.name, data.state, data.memory);
}

/* main function */
int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *dir_entry;
    int pid;
    ProcessData data;

    /* print header */
    printf("PID\tNAME\tSTATE\tMEMORY\n");

    /* open process directory */
    dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error: failed to open directory /proc\n");
        exit(EXIT_FAILURE);
    }

    /* loop through process directories */
    while ((dir_entry = readdir(dir)) != NULL) {
        pid = atoi(dir_entry->d_name);
        if (pid != 0) {
            getProcessData(&data, pid);
            if (strlen(data.name) > 0) {
                printProcessData(data);
            }
        }
    }

    /* cleanup */
    closedir(dir);

    return 0;
}