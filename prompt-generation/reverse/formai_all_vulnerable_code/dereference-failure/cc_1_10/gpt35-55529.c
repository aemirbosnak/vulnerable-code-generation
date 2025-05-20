//FormAI DATASET v1.0 Category: System process viewer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

// function to check if a string is numeric
int isNumeric(char *str) {
    int i, len = strlen(str);
    for (i = 0; i < len; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    DIR *dir;
    struct dirent *entry;
    char procPath[50], cmdLine[100], status[100], pid[10], ppid[10], mem[15], vmsize[15], line[100], user[20];
    FILE *fp;
    long int rss, vmem, total_rss = 0, total_vmsize = 0;
    int count = 0;
    float rss_kb, vmem_kb;

    printf("%-10s %-30s %-20s %-10s %-10s %-15s %-15s %-20s\n", "PID", "CMD", "USER", "STATUS", "PPID", "MEMORY", "VMSIZE", "PATH");
    printf("-----------------------------------------------------------------------\n");

    dir = opendir("/proc");
    if (!dir) {
        printf("Error opening /proc\n");
        exit(1);
    }

    while ((entry = readdir(dir))) {
        // check if the directory entry is a process directory
        if (isNumeric(entry->d_name)) {
            strcpy(procPath, "/proc/");
            strcat(procPath, entry->d_name);
            strcat(procPath, "/");

            // get the process's command line
            strcpy(cmdLine, "");
            strcat(cmdLine, procPath);
            strcat(cmdLine, "cmdline");
            fp = fopen(cmdLine, "r");
            if (!fp) {
                printf("Error opening %s\n", cmdLine);
                continue;
            }
            fgets(line, 100, fp);
            fclose(fp);
            if (strlen(line) == 0) {
                strcpy(line, "[unknown]");
            }

            // get the process's status
            strcpy(status, "");
            strcat(status, procPath);
            strcat(status, "status");
            fp = fopen(status, "r");
            if (!fp) {
                printf("Error opening %s\n", status);
                continue;
            }
            while (fgets(line, 100, fp)) {
                if (strncmp(line, "Uid:", 4) == 0) {
                    sscanf(line, "%*s%s", user);
                }
                if (strncmp(line, "State:", 6) == 0) {
                    sscanf(line, "%*s%s", status);
                }
                if (strncmp(line, "PPid:", 5) == 0) {
                    sscanf(line, "%*s%s", ppid);
                }
                if (strncmp(line, "VmRSS:", 6) == 0) {
                    sscanf(line, "%*s%s", mem);
                }
                if (strncmp(line, "VmSize:", 7) == 0) {
                    sscanf(line, "%*s%s", vmsize);
                }
            }
            fclose(fp);

            // calculate memory usage
            rss_kb = atof(mem) / 1024;
            vmem_kb = atof(vmsize) / 1024;
            total_rss += (long int)rss_kb;
            total_vmsize += (long int)vmem_kb;

            // print process information
            printf("%-10s %-30s %-20s %-10s %-10s %-15ld KB %-15ld KB %-20s\n", entry->d_name, line, user, status, ppid, (long int)rss_kb, (long int)vmem_kb, procPath);
            count++;
        }
    }

    printf("-----------------------------------------------------------------------\n");
    printf("%-10s %-30s %-20s %-10s %-10s %-15ld KB %-15ld KB\n", "Total:", "", "", "", "", total_rss, total_vmsize);
    printf("-----------------------------------------------------------------------\n");

    printf("Total number of processes: %d\n", count);

    closedir(dir);

    return 0;
}