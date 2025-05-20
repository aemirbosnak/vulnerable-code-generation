//FormAI DATASET v1.0 Category: System process viewer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>

#define STRLEN 128

/*
 * This program is a simple system process viewer that displays
 * the process ID, memory usage, and process name for each running
 * program on the system. 
 */

void printHeader() {
    printf("%-10s%-20s%-10s\n", "PID", "Process Name", "Memory");
}

void printProcessInfo(char *pid, char *procName) {
    char memUsage[STRLEN] = "";
    FILE *fp;
    
    // read memory usage
    char cmd[STRLEN] = "pmap ";
    strcat(cmd, pid);
    fp = popen(cmd, "r");
    fgets(memUsage, STRLEN, fp);
    pclose(fp);
    
    // get rid of non-numeric characters
    int i = 0;
    while (memUsage[i]) {
        if (!isdigit(memUsage[i]))
            memUsage[i] = ' ';
        i++;
    }
    
    // trim whitespace
    char *endptr = memUsage + STRLEN;
    while (isspace(*--endptr));
    *(endptr+1) = '\0';
    char *startptr = memUsage;
    while (isspace(*startptr)) startptr++;
    printf("%-10s%-20s%-10s\n", pid, procName, startptr);
}

int main() {
    DIR *dir;
    struct dirent *entry;
    char pid[STRLEN], procName[STRLEN], path[STRLEN];
    
    printf("System Process Viewer\n\n");
    
    // print header
    printHeader();
    
    // read /proc directory
    if (!(dir = opendir("/proc"))) {
        perror("Could not read directory");
        exit(EXIT_FAILURE);
    }
    
    // loop through directory entries
    while ((entry = readdir(dir)) != NULL) {
        if (!(isdigit(*entry->d_name)))
            continue;
        strcpy(pid, entry->d_name);
        
        // read name of process from /proc/pid/comm
        sprintf(path, "/proc/%s/comm", pid);
        FILE *fp = fopen(path, "r");
        fgets(procName, STRLEN, fp);
        fclose(fp);
        procName[strcspn(procName, "\n")] = 0; // remove newline
        
        // print process info
        printProcessInfo(pid, procName);
    }
    
    closedir(dir);
    return 0;
}