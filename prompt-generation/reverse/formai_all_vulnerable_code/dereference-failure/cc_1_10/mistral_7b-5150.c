//MISTRAL-7B DATASET v1.0 Category: System process viewer ; Style: Dennis Ritchie
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PROCS 10
#define PROC_NAME_LENGTH 32

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(void) {
    DIR *proc_dir;
    struct dirent *proc_entry;
    pid_t pids[MAX_PROCS];
    int num_procs = 0;

    if ((proc_dir = opendir("/proc")) == NULL) {
        die("/proc: ");
    }

    while ((proc_entry = readdir(proc_dir)) != NULL) {
        if (isdigit(*proc_entry->d_name)) {
            errno = 0;
            pids[num_procs] = strtol(proc_entry->d_name, NULL, 10);
            if (errno != 0) {
                die("Invalid process ID: ");
            }
            num_procs++;
            if (num_procs >= MAX_PROCS) {
                break;
            }
        }
    }

    closedir(proc_dir);

    for (int i = 0; i < num_procs; ++i) {
        FILE *status_file;
        char name[PROC_NAME_LENGTH];
        int status;

        snprintf(name, PROC_NAME_LENGTH, "/proc/%d/status", pids[i]);
        if ((status_file = fopen(name, "r")) == NULL) {
            die(name);
        }

        if (fgets(name, PROC_NAME_LENGTH, status_file) == NULL ||
            sscanf(name, "%*s %d %*s", &status) != 1 ||
            WIFEXITED(status) || WIFSIGNALED(status)) {
            die("Error reading process name: ");
        }

        printf("PID: %d, Name: %s\n", pids[i], name + strlen(name) - strlen(name + strspn(name, "\n")));

        fclose(status_file);
    }

    exit(EXIT_SUCCESS);
}