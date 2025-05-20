//FormAI DATASET v1.0 Category: System process viewer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PID_LEN 16

int main() {
    DIR *d;
    struct dirent *dir;
    char dirname[] = "/proc";
    char pid[MAX_PID_LEN];

    d = opendir(dirname);
    if (d == NULL) {
        fprintf(stderr, "Cannot open directory %s\n", dirname);
        exit(1);
    }
    printf("Surreal System Process Viewer:\n\n");
    printf("PID\t\tPPID\t\tSTATUS\t\tCOMMAND\n");

    while ((dir = readdir(d)) != NULL) {
        if (isdigit(dir->d_name[0])) {
            strcpy(pid,dir->d_name);
            strcat(dirname,"/");
            strcat(dirname, pid);
            strcat(dirname, "/status");
            
            FILE *fp = fopen(dirname, "r");
            char *line = NULL;
            size_t len = 0;
            ssize_t read;

            if (fp == NULL) {
                fprintf(stderr, "Cannot open file for reading %s\n", dirname);
                exit(1);
            }

            char ppid[MAX_PID_LEN], status[16], command[255];
            int i = 0;
            while ((read = getline(&line, &len, fp)) != -1) {
                if (strncmp(line, "PPid:", 5) == 0) {
                    strtok(line, " \t\n");
                    strcpy(ppid, strtok(NULL, " \t\n"));
                }
                if (strncmp(line, "State:", 6) == 0) {
                    strtok(line, " \t\n");
                    strcpy(status, strtok(NULL, " \t\n"));
                }
                if (strncmp(line, "Name:", 5) == 0) {
                    strtok(line, " \t\n");
                    strcpy(command, strtok(NULL, " \t\n"));
                }
                i++;
            }
            fclose(fp);
            
            printf("%s\t\t%s\t\t%s\t\t%s\n", pid, ppid, status, command);
        }
    }
    closedir(d);

    return 0;
}