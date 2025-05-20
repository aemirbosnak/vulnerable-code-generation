//FormAI DATASET v1.0 Category: System process viewer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define CMDLINE_PATH "proc/%d/cmdline"
#define STAT_PATH "proc/%d/stat"
#define PROCESS_NAME_MAX_LENGTH 4096
#define PROCESS_INFO_MAX_LENGTH 1000

int is_number(const char* s) {
    for(int i=0; s[i]!='\0'; i++) {
        if(!isdigit(s[i]))
            return 0;
    }

    return 1;
}

int main() {
    DIR* dir;
    struct dirent* entry;
    char process_name[PROCESS_NAME_MAX_LENGTH];
    char process_info[PROCESS_INFO_MAX_LENGTH];
    FILE* fd;
    int pid, ppid, status, num_threads;
    long int utime, stime;

    printf("PID\tPPID\tName\t\t\tStatus\t\tNum Threads\tUser Time\tSystem Time\n");

    dir = opendir("proc");

    if(dir == NULL) {
        printf("Error opening proc directory.\n");
        return 1;
    }

    while((entry = readdir(dir)) != NULL) {
        if(is_number(entry->d_name)) {
            pid = atoi(entry->d_name);

            // Get process name
            sprintf(process_name, CMDLINE_PATH, pid);
            fd = fopen(process_name, "r");

            if(fd != NULL) {
                fgets(process_name, PROCESS_NAME_MAX_LENGTH, fd);

                if (strlen(process_name) > 0 && process_name[strlen(process_name)-1] == '\n') {
                    process_name[strlen(process_name)-1] = '\0';
                }

                fclose(fd);
            } else {
                strcpy(process_name, "N/A");
            }

            // Get process status and parent PID
            sprintf(process_info, STAT_PATH, pid);
            fd = fopen(process_info, "r");

            if(fd != NULL) {
                fscanf(fd, "%*d %*s %c %d ", &status, &ppid);
                fclose(fd);
            } else {
                status = 'N';
                ppid = -1;
            }

            // Get number of threads
            sprintf(process_info, "proc/%d/task", pid);
            num_threads = 0;

            DIR* task_dir = opendir(process_info); 
            if(task_dir != NULL) { 
                while((entry = readdir(task_dir)) != NULL) {
                    if(is_number(entry->d_name)) {
                        num_threads++;
                    }
                }

                closedir(task_dir);
            }

            // Get user and system time
            sprintf(process_info, "proc/%d/stat", pid);

            fd = fopen(process_info, "r");

            if(fd != NULL) {
                fscanf(fd, "%*d %*s %*c %*d %*d %*d %*d %*d %*u %*u %*u %*u %ld %ld", &utime, &stime);
                fclose(fd);
            } else { 
                utime = -1;
                stime = -1;
            }

            printf("%d\t%d\t%-24s\t%c\t\t%d\t\t%ld\t%ld\n", pid, ppid, process_name, status, num_threads, utime, stime);
        }
    }

    closedir(dir);
    return 0;
}