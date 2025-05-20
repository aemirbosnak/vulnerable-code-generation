//FormAI DATASET v1.0 Category: System process viewer ; Style: Ken Thompson
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define PROC_DIRECTORY "/proc"

/* Struct to hold process information */
struct Process {
    char name[256];
    int pid;
    int ppid;
    char state;
};

/* Function to get all process information from /proc directory */
int get_processes(struct Process *processes) {
    DIR *dir;
    struct dirent *ent;
    int id;
    char path[128], buffer[256], *name_ptr;
    FILE *file;

    dir = opendir(PROC_DIRECTORY);
    if (dir == NULL) {
        printf("Error: Could not open /proc directory\n");
        return 0;
    }

    id = 0;
    while ((ent = readdir(dir)) != NULL) {
        /* Check if directory name is a number (i.e., a process ID) */
        if (isdigit(ent->d_name[0])) {
            /* Create path to process information file */
            sprintf(path, "%s/%s/stat", PROC_DIRECTORY, ent->d_name);

            /* Open file */
            file = fopen(path, "r");
            if (file == NULL) {
                printf("Error: Could not open %s\n", path);
                continue;
            }

            /* Read process information from file */
            fscanf(file, "%d %s %c %d", &processes[id].pid, buffer, &processes[id].state, &processes[id].ppid);
            fclose(file);

            /* Extract process name */
            name_ptr = strrchr(buffer, '(') + 1;
            strncpy(processes[id].name, name_ptr, strlen(name_ptr)-1);

            /* Move to next index in processes array */
            id++;
        }
    }

    closedir(dir);
    return id;
}

/* Function to print all process information */
void print_processes(struct Process *processes, int num_processes) {
    printf("PID\tPPID\tSTATE\tPROCESS NAME\n");
    for (int i=0; i<num_processes; i++) {
        printf("%d\t%d\t%c\t%s\n", processes[i].pid, processes[i].ppid, processes[i].state, processes[i].name);
    }
}

/* Main function */
int main() {
    struct Process processes[1024];
    int num_processes;

    /* Get process information */
    num_processes = get_processes(processes);

    /* Print process information */
    print_processes(processes, num_processes);

    return 0;
}