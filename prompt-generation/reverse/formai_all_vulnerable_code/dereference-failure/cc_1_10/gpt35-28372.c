//FormAI DATASET v1.0 Category: System process viewer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

typedef struct proc_t {
    int pid;
    char name[256];
    char state;
    char cmdline[256];
} proc_t;

int is_num(char *s) {
    while (*s) {
        if (!isdigit(*s))
            return 0;
        s++;
    }
    return 1;
}

void get_proc_info(proc_t *p, char *pid) {
    char path[256];
    char line[256];
    FILE *f;
    int len;

    sprintf(path, "/proc/%s/status", pid);
    f = fopen(path, "r");
    if (!f)
        return;

    while (fgets(line, sizeof(line), f)) {
        if (!strncmp(line, "Name:", 5)) {
            len = strlen(line) - 6;
            if (line[len] == '\n')
                line[len] = '\0';
            strncpy(p->name, line+6, sizeof(p->name) - 1);
        } else if (!strncmp(line, "State:", 6)) {
            sscanf(line+6, "%c", &p->state);
        }
    }
    fclose(f);

    sprintf(path, "/proc/%s/cmdline", pid);
    f = fopen(path, "r");
    if (!f)
        return;

    if (fgets(line, sizeof(line), f)) {
        len = strlen(line);
        if (line[len-1] == '\n')
            line[len-1] = '\0';
        strncpy(p->cmdline, line, sizeof(p->cmdline) - 1);
    }
    fclose(f);

    p->pid = atoi(pid);
}

void print_procs(proc_t *procs, int n) {
    int i;

    printf("%-10s %-20s %-10s %s\n", "PID", "Name", "State", "Command Line");
    for (i = 0; i < n; i++) {
        printf("%-10d %-20s %-10c %s\n", procs[i].pid, procs[i].name, procs[i].state, procs[i].cmdline);
    }
}

int main(int argc, char **argv) {
    DIR *dir;
    struct dirent *dent;
    proc_t *procs;
    int num_procs = 0;
    int i;

    dir = opendir("/proc");
    if (!dir) {
        fprintf(stderr, "Error opening /proc directory\n");
        exit(1);
    }

    while ((dent = readdir(dir))) {
        if (is_num(dent->d_name)) {
            num_procs++;
        }
    }
    closedir(dir);

    procs = (proc_t*)calloc(num_procs, sizeof(proc_t));

    dir = opendir("/proc");
    if (!dir) {
        fprintf(stderr, "Error opening /proc directory\n");
        exit(1);
    }

    i = 0;
    while ((dent = readdir(dir))) {
        if (is_num(dent->d_name)) {
            get_proc_info(&procs[i], dent->d_name);
            i++;
        }
    }
    closedir(dir);

    print_procs(procs, num_procs);

    free(procs);

    return 0;
}