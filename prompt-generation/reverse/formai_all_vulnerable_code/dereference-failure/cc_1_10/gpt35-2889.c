//FormAI DATASET v1.0 Category: System process viewer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

/* Structure to hold process information */
typedef struct {
    char name[50];
    int pid;
    char status[20];
} process;

/* Function to get process information */
void get_process_info(process *p, char *pid) {
    char path[50];
    FILE *fp;
    sprintf(path, "/proc/%s/status", pid);

    fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Process with PID %s does not exist.\n", pid);
        exit(1);
    }

    char line[100];
    while (fgets(line, 100, fp)) {
        if (strncmp(line, "Name:", 5) == 0) {
            sscanf(line, "Name:\t%s", p->name);
        }
        if (strncmp(line, "Pid:", 4) == 0) {
            sscanf(line, "Pid:\t%d", &p->pid);
        }
        if (strncmp(line, "State:", 6) == 0) {
            sscanf(line, "State:\t%s", p->status);
        }
    }
    fclose(fp);
}

/* Function to print process information */
void print_process_info(process p) {
    printf("%-20s%-10d%-10s\n", p.name, p.pid, p.status);
}

int main() {
    DIR *dir;
    struct dirent *dir_entry;
    
    printf("%-20s%-10s%-10s\n", "Name", "PID", "Status");

    dir = opendir("/proc");
    if (dir) {
        while ((dir_entry = readdir(dir)) != NULL) {
            if (isdigit(dir_entry->d_name[0])) { // check if directory name is a PID
                process p;
                get_process_info(&p, dir_entry->d_name);
                print_process_info(p);
            }
        }
        closedir(dir);
    } else {
        printf("Error: Could not open /proc directory.\n");
        exit(1);
    }

    return 0;
}