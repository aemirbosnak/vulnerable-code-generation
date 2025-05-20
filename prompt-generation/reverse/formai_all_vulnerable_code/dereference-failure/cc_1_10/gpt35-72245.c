//FormAI DATASET v1.0 Category: System process viewer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

void printProcessInfo(char *pid, char *pname, char *ppid, char *status, char *path){
    printf("PID: %s\n", pid);
    printf("Name: %s\n", pname);
    printf("PPID: %s\n", ppid);
    printf("Status: %s\n", status);
    printf("Path: %s\n", path);
    printf("\n");
}

void removeNewLine(char *line){
    int len = strlen(line);
    if (line[len-1] == '\n'){
        line[len-1] = '\0';
    }
}

void getProcessInfo(){
    DIR *dir;
    struct dirent *entry;
    char pid[10];
    char pname[50];
    char ppid[10];
    char status[10];
    char path[100];
    FILE *fp;
    char line[1024];
    char *token;

    printf("Listing all active processes:\n\n");
    dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error: Unable to open /proc.\n");
        exit(1);
    }
    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            memset(path, 0, sizeof(path));
            sprintf(path, "/proc/%s/status", entry->d_name);
            fp = fopen(path, "r");
            if (fp != NULL) {
                while (fgets(line, 1024, fp) != NULL) {
                    if (strstr(line, "Pid:") != NULL) {
                        token = strtok(line, " \t");
                        token = strtok(NULL, " \t");
                        strcpy(pid, token);
                    } else if (strstr(line, "Name:") != NULL) {
                        token = strtok(line, " \t");
                        token = strtok(NULL, " \t");
                        strcpy(pname, token);
                    } else if (strstr(line, "PPid:") != NULL) {
                        token = strtok(line, " \t");
                        token = strtok(NULL, " \t");
                        strcpy(ppid, token);
                    } else if (strstr(line, "State:") != NULL) {
                        token = strtok(line, " \t");
                        token = strtok(NULL, " \t");
                        strcpy(status, token);
                    }
                }
                fclose(fp);
            }

            removeNewLine(pid);
            removeNewLine(pname);
            removeNewLine(ppid);
            removeNewLine(status);

            printProcessInfo(pid, pname, ppid, status, path);
        }
    }
    closedir(dir);
}

int main(){
    getProcessInfo();
    return 0;
}