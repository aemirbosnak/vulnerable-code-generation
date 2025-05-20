//FormAI DATASET v1.0 Category: System process viewer ; Style: lively
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

// structure to store process information
struct ProcessInfo {
    char pid[10];
    char name[50];
    char state[10];
    char memory[20];
};

/**
 * Function to get the process information from the /proc directory
 * @param procDir the /proc directory path
 * @param procInfos pointer to the process information array
 * @param nprocs the number of processes
 */
void getProcessInfo(const char *procDir, struct ProcessInfo *procInfos, int nprocs) {
    DIR *dir;
    struct dirent *ent;
    char path[100], line[200];

    // open the /proc directory
    dir = opendir(procDir);
    if (dir != NULL) {
        // for each entry in the /proc directory
        while ((ent = readdir(dir)) != NULL) {
            // if the entry is a directory and the name is a number (a process id)
            if (ent->d_type == DT_DIR && atoi(ent->d_name) != 0) {
                // get the process information from the status file
                sprintf(path, "%s/%s/status", procDir, ent->d_name);
                FILE *fp = fopen(path, "r");
                if (fp != NULL) {
                    int i = 0;
                    while (fgets(line, sizeof(line), fp) != NULL && i < 4) {
                        // get the process name
                        if (strstr(line, "Name") != NULL) {
                            char *s = strchr(line, ':');
                            strncpy(procInfos->name, s+2, sizeof(procInfos->name));
                            procInfos->name[strlen(procInfos->name)-1] = '\0';  // remove the newline character
                            i++;
                        }
                        // get the process state
                        else if (strstr(line, "State") != NULL) {
                            char *s = strchr(line, ':');
                            strncpy(procInfos->state, s+2, sizeof(procInfos->state));
                            procInfos->state[strlen(procInfos->state)-1] = '\0';  // remove the newline character
                            i++;
                        }
                        // get the process memory usage
                        else if (strstr(line, "VmSize") != NULL) {
                            char *s = strchr(line, ':');
                            strncpy(procInfos->memory, s+2, sizeof(procInfos->memory));
                            procInfos->memory[strlen(procInfos->memory)-3] = '\0';  // remove the " kB" suffix
                            i++;
                        }
                    }
                    fclose(fp);

                    // save the process id
                    sprintf(procInfos->pid, "%s", ent->d_name);

                    // move to the next process
                    procInfos++;
                }
            }
        }

        closedir(dir);
    }
}

int main() {
    // get the number of processes
    DIR *dir = opendir("/proc");
    int nprocs = -2;  // exclude the . and .. directories
    struct dirent *ent;
    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_DIR && atoi(ent->d_name) != 0) {
            nprocs++;
        }
    }
    closedir(dir);

    // allocate the process information array
    struct ProcessInfo *procInfos = (struct ProcessInfo*) malloc(nprocs * sizeof(struct ProcessInfo));

    // get the process information
    getProcessInfo("/proc", procInfos, nprocs);

    // print the process information
    printf("%-10s %-50s %-10s %-20s\n", "PID", "Name", "State", "Memory");
    for (int i = 0; i < nprocs; i++) {
        printf("%-10s %-50s %-10s %-20s\n", procInfos[i].pid, procInfos[i].name, procInfos[i].state, procInfos[i].memory);
    }

    // free the process information array
    free(procInfos);

    return 0;
}