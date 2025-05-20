//FormAI DATASET v1.0 Category: System process viewer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#define PROC "/proc"

/* Definition of the proc struct */
typedef struct {
    char *pid;
    char *ppid;
    char *state;
    char *tty;
    char *command;
} proc;

/* Function to read /proc file system */
void read_proc(proc *p, char *dir) {
    /* Open the /proc directory */
    DIR *dp = opendir(dir);
    if (dp == NULL) {
        return;
    }
    /* Loop through each entry in the /proc directory */
    struct dirent *ep;
    while ((ep = readdir(dp))) {
        char fname[512] = "";
        /* Skip any entry that is not a directory */
        if (!isdigit(ep->d_name[0])) {
            continue;
        }
        /* Open the process status file for this process */
        snprintf(fname, sizeof(fname), "%s/%s/status", dir, ep->d_name);
        FILE *fp = fopen(fname, "r");
        if (fp == NULL) {
            continue;
        }
        /* Read the process data from the status file */
        char line[512] = "";
        while (fgets(line, sizeof(line), fp)) {
            char *pos = strchr(line, ':');
            if (pos == NULL) {
                continue;
            }
            *pos = '\0';
            pos++;
            if (strcmp(line, "Pid") == 0) {
                p->pid = strdup(pos);
            } else if (strcmp(line, "PPid") == 0) {
                p->ppid = strdup(pos);
            } else if (strcmp(line, "State") == 0) {
                p->state = strdup(pos);
            } else if (strcmp(line, "Tty") == 0) {
                p->tty = strdup(pos);
            } else if (strcmp(line, "Cmd") == 0) {
                p->command = strdup(pos);
            }
        }
        fclose(fp);
        /* Print the process data */
        if (p->pid != NULL) {
            printf("%5s %5s %5s %10s %s", p->pid, p->ppid, p->state, p->tty,
                   p->command);
            free(p->pid);
            free(p->ppid);
            free(p->state);
            free(p->tty);
            free(p->command);
        }
    }
    closedir(dp);
}

/* Main function */
int main(void) {
    /* Print the header */
    printf("%5s %5s %5s %10s %s", "PID", "PPID", "STAT", "TTY", "COMMAND");
    /* Loop through each process in the system */
    read_proc((proc *) calloc(1, sizeof(proc)), PROC);
    return 0;
}