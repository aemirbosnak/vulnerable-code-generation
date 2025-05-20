//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define BUFFER_SIZE 256

void get_process_info(pid_t pid) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), "/proc/%d/stat", pid);
    
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        perror("fopen");
        return;
    }

    char comm[BUFFER_SIZE];
    char state;
    unsigned long utime, stime, cutime, cstime;

    fscanf(fp, "%d %s %c %*d %*d %*d %*d %*d %*u %*u %lu %lu %lu %lu",
           &pid, comm, &state, &utime, &stime, &cutime, &cstime);

    // Remove parentheses from `comm`
    char *pos = strchr(comm, '(');
    if (pos) {
        *pos = '\0';  // truncate at '('
        pos++;
    }
    snprintf(comm, sizeof(comm), "%s", pos ? pos : comm);  // get the part after '('
    pos = strchr(comm, ')');
    if (pos) *pos = '\0';  // truncate at ')'

    fclose(fp);

    printf("%-6d %-20s %-6c %-10lu %-10lu\n", pid, comm, state, utime + stime, cutime + cstime);
}

void list_processes() {
    struct dirent *entry;
    DIR *dp = opendir("/proc");

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printf("%-6s %-20s %-6s %-10s %-10s\n", "PID", "COMMAND", "STATE", "USER_TIME", "SYSTEM_TIME");
    printf("-------------------------------------------------------------\n");

    while ((entry = readdir(dp)) != NULL) {
        if (isdigit(*entry->d_name)) {
            pid_t pid = atoi(entry->d_name);
            get_process_info(pid);
        }
    }
    closedir(dp);
}

int main() {
    printf("Simple Linux Process Viewer\n");
    printf("===================================\n");
    
    while (1) {
        list_processes();
        printf("\nPress Ctrl+C to exit.\n");
        sleep(5); // Refresh every 5 seconds
    }

    return 0;
}