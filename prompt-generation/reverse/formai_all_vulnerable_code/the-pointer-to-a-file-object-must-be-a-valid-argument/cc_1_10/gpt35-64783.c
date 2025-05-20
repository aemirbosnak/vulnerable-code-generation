//FormAI DATASET v1.0 Category: System process viewer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <unistd.h>

#define BUFF_SIZE 1024

// Function to check if the string is numeric
int is_numeric(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (!isdigit(*(str + i))) {
            return 0;
        }
    }
    return 1;
}

int main() {

    char buff[BUFF_SIZE], path[BUFF_SIZE], cmd[BUFF_SIZE], state[BUFF_SIZE];
    char name[BUFF_SIZE], status[BUFF_SIZE];
    DIR *dir = NULL;
    struct dirent *entry = NULL;
    FILE *fp = NULL;

    //get the directory in which processes are stored in linux system
    sprintf(path, "/proc/");
    dir = opendir(path);

    if (dir == NULL) {
        printf("Cannot open /proc/ directory \n");
        exit(0);
    }

    printf("\n%-6s %-20s %-10s %-10s %-22s %-20s\n", "PID", "Name", "State", "Status", "Memory", "Command");

    while ((entry = readdir(dir)) != NULL) {

        //check if directory name is numeric
        if (is_numeric(entry->d_name)) {

            sprintf(buff, "%s/%s", path, entry->d_name);

            //open the cmdline file inside the process directory
            sprintf(cmd, "%s/cmdline", buff);
            fp = fopen(cmd, "r");

            if (fp != NULL) {

                fgets(name, BUFF_SIZE, fp);

                //remove trailing newline character from name
                if (strlen(name) > 0 && name[strlen(name)-1] == '\n') {
                    name[strlen(name)-1] = '\0';
                }

                fclose(fp);

                //open the stat file inside the process directory
                sprintf(cmd, "%s/stat", buff);
                fp = fopen(cmd, "r");

                if (fp != NULL) {

                    fscanf(fp, "%s %s %s", buff, buff, state);

                    //get the status of the process from /proc/<PID>/status file
                    sprintf(cmd, "%s/status", buff);
                    FILE *fp_status = fopen(cmd, "r");

                    if (fp_status != NULL) {
                        char buff_status[BUFF_SIZE];
                        while (fgets(buff_status, BUFF_SIZE, fp_status) != NULL) {
                            if (strstr(buff_status, "State:")) {
                                sscanf(buff_status, "%s %s", buff, status);
                            }
                        }
                        fclose(fp_status);
                    }

                    //calculate the memory usage of the process
                    unsigned long long int memory;
                    fscanf(fp, "%llu", &memory);
                    memory = memory/1024; //converting from bytes to kilobytes

                    //get the command line of the process
                    sprintf(cmd, "%s/cmdline", buff);
                    fp = fopen(cmd, "r");
                    char command[BUFF_SIZE] = "";
                    while (fgets(buff, BUFF_SIZE, fp) != NULL) {
                        strcat(command, buff);
                    }
                    fclose(fp);

                    printf("%-6s %-20s %-10s %-10s %-22llu %-20s\n", entry->d_name, name, state, status, memory, command);
                }
            }
        }
    }

    closedir(dir);
    return 0;
}