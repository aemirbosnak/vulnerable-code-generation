//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256

void get_cpu_usage(int pid, float *cpu_usage) {
    char path[BUFFER_SIZE];
    FILE *file;
    int utime, stime, cutime, cstime;
    
    snprintf(path, sizeof(path), "/proc/%d/stat", pid);
    file = fopen(path, "r");
    
    if (file) {
        fscanf(file, "%*d %*s %*s %*s %*s %*s %*s %*s %*s %*s "
                     "%d %d %d %d", &utime, &stime, &cutime, &cstime);
        fclose(file);
        
        *cpu_usage = (utime + stime + cutime + cstime) / (float)sysconf(_SC_CLK_TCK);
    } else {
        *cpu_usage = 0.0f; // Unable to get CPU usage for this PID
    }
}

void list_processes() {
    DIR *dir;
    struct dirent *ent;
    char path[BUFFER_SIZE];
    char cmdline[BUFFER_SIZE];
    FILE *file;
    float cpu_usage;

    if ((dir = opendir("/proc")) != NULL) {
        printf("%-10s %-25s %-10s\n", "PID", "COMMAND", "CPU(%)");
        printf("----------------------------------------------------------\n");

        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_DIR) {
                int pid = atoi(ent->d_name);
                if (pid > 0) {
                    // Get command name
                    snprintf(path, sizeof(path), "/proc/%s/cmdline", ent->d_name);
                    file = fopen(path, "r");
                    if (file) {
                        fgets(cmdline, sizeof(cmdline), file);
                        fclose(file);
                    } else {
                        strcpy(cmdline, "N/A");
                    }

                    // Get CPU usage
                    get_cpu_usage(pid, &cpu_usage);

                    // Print process information
                    printf("%-10d %-25s %-10.2f\n", pid, cmdline, cpu_usage);
                }
            }
        }
        closedir(dir);
    } else {
        perror("Could not open /proc directory");
    }
}

int main() {
    printf("Process Viewer\n");
    printf("==============\n");
    list_processes();
    return 0;
}