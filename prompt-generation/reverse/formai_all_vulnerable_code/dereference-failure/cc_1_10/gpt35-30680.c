//FormAI DATASET v1.0 Category: System process viewer ; Style: irregular
/* C System Process Viewer */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define CMDLINE_LEN 1024
#define MAX_LINE_LEN 1024

/* Define a process structure */
struct proc {
    char pid[20];
    char name[50];
    char state[5];
    char mem[10];
};

/* Function to read process status */
int read_proc_stat(char *pid, char *name, char *state, char *mem) {
    char stat_file[CMDLINE_LEN], line[MAX_LINE_LEN];
    FILE *fp;

    /* Open the /proc/[pid]/stat file */
    sprintf(stat_file, "/proc/%s/stat", pid);
    fp = fopen(stat_file, "r");
    if (fp == NULL) {
        return 0;
    }

    /* Read the first line of the file */
    if (fgets(line, MAX_LINE_LEN, fp) == NULL) {
        fclose(fp);
        return 0;
    }

    /* Parse the line to get the process name, state and memory */
    sscanf(line, "%*s %s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s",
           name, state, mem);

    /* Close the file and return success */
    fclose(fp);
    return 1;
}

/* Function to get the list of running processes */
int get_proc_list(struct proc *plist, int max_procs) {
    DIR *dirp;
    struct dirent *dir_entry;
    int num_procs = 0;

    /* Open the /proc directory */
    dirp = opendir("/proc");
    if (dirp == NULL) {
        return 0;
    }

    /* Read each entry in the /proc directory */
    while ((dir_entry = readdir(dirp)) != NULL) {
        char *pid_str = dir_entry->d_name;
        char cmdline_file[CMDLINE_LEN], cmdline[MAX_LINE_LEN];

        /* Check if the entry is a process directory (has a numeric name) */
        if (!isdigit(pid_str[0])) {
            continue;
        }

        /* Read the process command line */
        sprintf(cmdline_file, "/proc/%s/cmdline", pid_str);
        FILE *fp = fopen(cmdline_file, "r");
        if (fp == NULL) {
            continue;
        }
        if (fgets(cmdline, MAX_LINE_LEN, fp) == NULL) {
            strcpy(cmdline, "unknown");
        }
        fclose(fp);

        /* Get the process status */
        if (!read_proc_stat(pid_str, plist[num_procs].name,
                            plist[num_procs].state, plist[num_procs].mem)) {
            continue;
        }

        /* Copy the process ID */
        strcpy(plist[num_procs].pid, pid_str);

        /* Increment the number of processes */
        num_procs++;

        /* Break if we have reached the maximum number of processes */
        if (num_procs >= max_procs) {
            break;
        }
    }

    /* Close the directory and return the number of processes */
    closedir(dirp);
    return num_procs;
}

/* Function to print process list */
void print_proc_list(struct proc *plist, int num_procs) {
    int i;
    printf("   PID  STATE     MEMORY  NAME\n");
    for (i = 0; i < num_procs; i++) {
        printf("%6s  %-5s  %8s  %s\n",
               plist[i].pid, plist[i].state, plist[i].mem, plist[i].name);
    }
}

/* Main function */
int main() {
    struct proc plist[1024];
    int num_procs;

    /* Get the list of running processes */
    num_procs = get_proc_list(plist, 1024);

    /* Print the process list */
    print_proc_list(plist, num_procs);

    return 0;
}