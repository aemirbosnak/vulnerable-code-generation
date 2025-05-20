//FormAI DATASET v1.0 Category: System process viewer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define PROC_PATH "/proc"  // Path to the proc file system
#define MAX_PID_DIGITS 5    // Maximum number of digits allowed for a PID

int is_num(const char *s) {
    // Returns true if a string contains only numeric characters
    for (const char *c = s; *c; ++c) {
        if (!isdigit(*c)) {
            return 0;
        }
    }
    return 1;
}

void print_process_info(const char *pid) {
    // Print the memory and status information for the given PID
    char proc_path[256];
    snprintf(proc_path, sizeof(proc_path), "%s/%s", PROC_PATH, pid);

    FILE *status_file = fopen(strcat(proc_path, "/status"), "r");
    if (status_file == NULL) {
        return;
    }

    char buffer[512];
    char name[50];
    int ppid, vmsize, state;

    while (fgets(buffer, sizeof(buffer), status_file)) {
        if (sscanf(buffer, "Name:\t%s", name)) {
            printf("Name:\t%s\n", name);
        }
        if (sscanf(buffer, "State:\t%c", &state)) {
            printf("State:\t%c\n", state);
        }
        if (sscanf(buffer, "PPid:\t%d", &ppid)) {
            printf("PPid:\t%d\n", ppid);
        }
        if (sscanf(buffer, "VmSize:\t%d kB", &vmsize)) {
            printf("VmSize:\t%d kB\n", vmsize);
        }
    }
    fclose(status_file);
}

int main(void) {
    DIR *d;
    struct dirent *dir;
    char pid[MAX_PID_DIGITS + 1];
    int pid_len = strlen(pid);

    printf(" PID   Name                             State   PPID    Memory\n");

    d = opendir(PROC_PATH);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            strncpy(pid, dir->d_name, sizeof(pid));
            pid[MAX_PID_DIGITS] = '\0';

            if (is_num(pid)) {
                printf("%5s  ", pid);
                print_process_info(pid);
            }
        }
        closedir(d);
    }
    return 0;
}