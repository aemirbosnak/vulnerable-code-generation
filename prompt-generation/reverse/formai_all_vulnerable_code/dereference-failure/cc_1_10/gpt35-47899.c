//FormAI DATASET v1.0 Category: System process viewer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

struct process_info {
    int pid;
    char name[50];
    char status;
};

int is_numeric(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i]))
            return 0; // not numeric
    }
    return 1; // numeric
}

int get_process_info(struct process_info *arr, int len) {
    DIR *proc_dir = opendir("/proc"); // open /proc directory
    struct dirent *dp;
    char filename[50];
    int count = 0;

    if (proc_dir == NULL) {
        return -1; // failed to open proc directory
    }

    while ((dp = readdir(proc_dir)) != NULL && count < len) {
        if (is_numeric(dp->d_name)) { // check if the directory name is a number (i.e., process ID)
            strcpy(filename, "/proc/");
            strcat(filename, dp->d_name);
            strcat(filename, "/stat");
            FILE *fs = fopen(filename, "r"); // open the stat file of the process

            if (fs == NULL) {
                continue; // failed to open stat file, move on to the next process
            }

            int pid;
            char name[50];
            char status;
            fscanf(fs, "%d %s %c", &pid, name, &status); // read process info from stat file

            struct process_info p = {
                .pid = pid,
                .status = status
            };
            strcpy(p.name, name+1); // remove the first '(' character from process name

            arr[count++] = p; // add process info to the array
            fclose(fs);
        }
    }

    closedir(proc_dir);
    return count; // return the number of processes read
}

int main() {
    struct process_info processes[100];
    int count = get_process_info(processes, 100);

    printf("PID NAME                 STATUS\n");
    printf("--------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-4d%-20s%c\n", processes[i].pid, processes[i].name, processes[i].status);
    }

    return 0;
}