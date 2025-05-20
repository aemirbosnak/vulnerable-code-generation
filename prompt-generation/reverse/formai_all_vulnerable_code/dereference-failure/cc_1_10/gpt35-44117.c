//FormAI DATASET v1.0 Category: System process viewer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PROC 65535 // maximum number of processes
#define MAX_PATH 256 //maximum path length

/* helper function to check whether a string is a number */
int is_number(const char *str) {
    int i;
    for (i=0; str[i]; i++) {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

/* helper function to read integer values from a file */
int read_int_from_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp)
        return -1;
    char buf[32];
    fgets(buf, 32, fp);
    fclose(fp);
    return atoi(buf);
}

/* helper function to read string values from a file */
char *read_string_from_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp)
        return NULL;
    char *buf = (char *)malloc(MAX_PATH * sizeof(char));
    fgets(buf, MAX_PATH, fp);
    fclose(fp);
    buf[strlen(buf)-1] = '\0';
    return buf;
}

int main() {
    DIR *d;
    struct dirent *dir;
    char proc_path[MAX_PATH];
    char cmd_path[MAX_PATH];
    int pid[MAX_PROC]; //array to hold pid of each process
    int num_procs = 0; //number of running processes
    int i;

    d = opendir("/proc");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (is_number(dir->d_name)) {
                pid[num_procs++] = atoi(dir->d_name);
            }
        }
        closedir(d);
    }
    printf("Number of running processes: %d\n\n", num_procs);

    printf("%-6s %-10s %s\n", "PID", "PPID", "CMD");
    printf("--------------------------------------------------\n");
    for (i=0; i<num_procs; i++) {
        snprintf(proc_path, MAX_PATH, "/proc/%d", pid[i]);

        /* get parent pid */
        snprintf(cmd_path, MAX_PATH, "%s/stat", proc_path);
        int ppid = read_int_from_file(cmd_path);
        if (ppid == -1)
            continue;

        /* get command name */
        snprintf(cmd_path, MAX_PATH, "%s/cmdline", proc_path);
        char *cmdline = read_string_from_file(cmd_path);
        if (!cmdline)
            continue;

        printf("%-6d %-10d %s\n", pid[i], ppid, cmdline);

        free(cmdline);
    }

    return 0;
}