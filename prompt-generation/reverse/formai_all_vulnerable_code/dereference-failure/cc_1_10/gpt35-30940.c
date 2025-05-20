//FormAI DATASET v1.0 Category: System process viewer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

struct Process {
    int pid;
    char name[255];
    char status;
};

void print_header() {
    printf("%-10s %-15s %-10s\n", "PID", "NAME", "STATUS");
}

void print_process(struct Process p) {
    printf("%-10d %-15s %-10c\n", p.pid, p.name, p.status);
}

int is_numeric(const char *str) {
    while (*str) {
        if (*str < '0' || *str > '9') {
            return 0;
        }
        str++;
    }

    return 1;
}

int main() {
    DIR *proc_dir = opendir("/proc");

    if (proc_dir == NULL) {
        fprintf(stderr, "Error opening /proc directory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    print_header();

    struct dirent *ent;
    while ((ent = readdir(proc_dir)) != NULL) {
        if (!is_numeric(ent->d_name)) {
            continue;
        }

        char path[255];
        sprintf(path, "/proc/%s/status", ent->d_name);

        FILE *status_file = fopen(path, "r");
        if (status_file == NULL) {
            continue;
        }

        struct Process p;
        p.pid = atoi(ent->d_name);
        p.status = 'U'; // assume status is unknown until found in status file

        char line[255];
        while (fgets(line, sizeof(line), status_file)) {
            if (strncmp(line, "Name:", 5) == 0) {
                sscanf(line + 5, "%s", p.name);
            } else if (strncmp(line, "State:", 6) == 0) {
                char state;
                sscanf(line + 6, "%c", &state);
                p.status = state;
            }
        }

        fclose(status_file);

        print_process(p);
    }

    closedir(proc_dir);

    return 0;
}