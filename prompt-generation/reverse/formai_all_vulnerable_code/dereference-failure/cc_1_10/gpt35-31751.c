//FormAI DATASET v1.0 Category: System process viewer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

/* Define process info struct */
struct proc_info {
    int pid;
    char pname[256];
    char state;
};

/* Define comparator function */
int cmp_proc_info(const void *p1, const void *p2) {
    const struct proc_info *proc1 = (const struct proc_info *) p1;
    const struct proc_info *proc2 = (const struct proc_info *) p2;
    return proc1->pid - proc2->pid;
}

/* Define function to get process info */
void get_process_info(struct proc_info *proc, char *pid) {
    char filename[256];
    char line[256];
    FILE *fptr;
    
    /* Create filename for process info */
    sprintf(filename, "/proc/%s/status", pid);
    
    /* Open process info file */
    if ((fptr = fopen(filename, "r"))) {
        /* Read lines until we find the name and state */
        while (fgets(line, sizeof(line), fptr)) {
            /* Check if it's the name line */
            if (strncmp(line, "Name:", 5) == 0) {
                strcpy(proc->pname, line + 6);
                proc->pname[strlen(proc->pname) - 1] = '\0'; /* Remove newline */
            }
            /* Check if it's the state line */
            else if (strncmp(line, "State:", 6) == 0) {
                proc->state = line[7];
            }
        }
        /* Get process ID */
        proc->pid = atoi(pid);
        /* Close process info file */
        fclose(fptr);
    }
}

/* Define function to display the process list */
void display_process_list() {
    DIR *dir;
    struct dirent *ent;
    struct proc_info procs[256]; /* max 256 processes */
    int num_procs = 0;
    
    /* Open the directory */
    if ((dir = opendir("/proc"))) {
        /* Loop through all items in the directory */
        while ((ent = readdir(dir))) {
            /* Check if this is a directory representing a process */
            if (isdigit(ent->d_name[0])) {
                /* Get process info and add it to the list */
                get_process_info(&procs[num_procs], ent->d_name);
                num_procs++;
            }
        }
        /* Close the directory */
        closedir(dir);
    }
    
    /* Sort the processes by ID */
    qsort(procs, num_procs, sizeof(struct proc_info), cmp_proc_info);
    
    /* Print the process list */
    printf("%-5s %-30s %s\n", "PID", "NAME", "STATE");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < num_procs; i++) {
        printf("%-5d %-30s %c\n", procs[i].pid, procs[i].pname, procs[i].state);
    }
}

/* Define main function */
int main(int argc, char *argv[]) {
    /* Display process list */
    display_process_list();
    return 0;
}