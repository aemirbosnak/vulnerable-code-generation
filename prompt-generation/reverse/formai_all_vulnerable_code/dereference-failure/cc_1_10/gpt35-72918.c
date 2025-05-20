//FormAI DATASET v1.0 Category: System process viewer ; Style: Claude Shannon
// Our program will show the currently running processes in a unique style
// inspired by Claude Shannon's mathematical theorem.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

// function to calculate entropy based on Shannon's theorem
double entropy(int *freq, int size) {
    double H = 0;
    for (int i = 0; i < size; i++) {
        double p = (double)freq[i] / size;
        if (p != 0) {
            H -= p * log2(p);
        }
    }
    return H;
}

int main() {
    DIR *dir;
    struct dirent *ent;
    int pid;
    char path[128];
    char line[128];
    char *attr;
    int freq[256] = {0}; // frequency of first byte of each process name
    int total_procs = 0;

    printf("\n************ Running processes ************\n\n");
    printf("    PID    |    NAME\n");
    printf("===========================================\n");

    if ((dir = opendir("/proc")) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            pid = atoi(ent->d_name); // convert directory name to PID
            if (pid == 0) {
                continue; // skip non-process directories
            }
            sprintf(path, "/proc/%d/cmdline", pid);
            FILE *f = fopen(path, "r");
            if (f != NULL) {
                fgets(line, sizeof(line), f);
                attr = strtok(line, " "); // get first argument (process name)
                freq[(int)attr[0]]++; // update frequency of first byte
                printf("%9d    |    %s\n", pid, attr);
                fclose(f);
                total_procs++;
            }
        }
        closedir(dir);
    } else {
        printf("Error: Could not open directory.\n");
        return 1;
    }

    double total_entropy = entropy(freq, 256); // calculate entropy of first byte frequencies
    double avg_entropy = total_entropy / total_procs;
    
    printf("\n===========================================\n");
    printf("Total processes: %d\n", total_procs);
    printf("Average entropy: %f\n", avg_entropy);

    return 0;
}