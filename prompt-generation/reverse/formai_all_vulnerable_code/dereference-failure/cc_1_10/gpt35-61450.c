//FormAI DATASET v1.0 Category: System process viewer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

// define constants for max sizes
#define MAX_PID_LENGTH 256
#define MAX_PATH_LENGTH 1024

// define the proc file path
#define PROC_FILE_PATH "/proc/"

// define the command names
#define CMD_NAME_LENGTH 256
const char *COMMAND_NAMES[] = {"ps", "top", "htop", "pgrep", "kill"};

// define struct to hold process information
typedef struct {
    char pid[MAX_PID_LENGTH];
    char cmd[CMD_NAME_LENGTH];
    char cmd_path[MAX_PATH_LENGTH];
    char user[256];
    char cpu[16];
    char mem[16];
    char uptime[16];
} process_info;

// function to extract process information from /proc/<pid>/stat
void get_process_info(char pid[], process_info *info) {
    char stat_path[MAX_PATH_LENGTH], stat_buf[1024], *tok;
    FILE *fp;

    // create the /proc/<pid>/stat path
    snprintf(stat_path, MAX_PATH_LENGTH, "%s%s/stat", PROC_FILE_PATH, pid);

    // open the file at the stat path
    fp = fopen(stat_path, "r");
    if (fp == NULL) {
        return;
    }

    // read the contents of the file
    fgets(stat_buf, 1024, fp);

    // close the file
    fclose(fp);

    // extract the process information from the stat string
    tok = strtok(stat_buf, " "); // pid
    strncpy(info->pid, tok, MAX_PID_LENGTH - 1);
    info->pid[MAX_PID_LENGTH - 1] = '\0';

    tok = strtok(NULL, " "); // comm (process command name)
    strncpy(info->cmd, tok, CMD_NAME_LENGTH - 1);
    info->cmd[CMD_NAME_LENGTH - 1] = '\0';

    tok = strtok(NULL, "\n"); // state (process state)
}

// function to check if the command exists in the system
int cmd_exists(char cmd_name[]) {
    int i;
    char cmd_path[MAX_PATH_LENGTH];
    FILE *fp;

    // loop through the command names array
    for (i = 0; i < 5; i++) {
        // create the command path
        snprintf(cmd_path, MAX_PATH_LENGTH, "/usr/bin/%s", COMMAND_NAMES[i]);

        // open the command file
        fp = fopen(cmd_path, "r");
        if (fp == NULL) {
            continue;
        }

        // close the command file
        fclose(fp);

        // check if the command names match
        if (strcmp(cmd_name, COMMAND_NAMES[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

// main function
int main() {
    DIR *dir;
    struct dirent *ent;
    process_info info;
    char pid[MAX_PID_LENGTH], cmd_buf[CMD_NAME_LENGTH], cmd_path[MAX_PATH_LENGTH];
    FILE *fp;
    int i, len, cmd_found;

    // print header
    printf("PID\tCOMMAND\tUSER\tCPU\tMEM\tUPTIME\n");

    // open the /proc directory
    dir = opendir(PROC_FILE_PATH);
    if (dir != NULL) {
        // loop through all the entries in the directory
        while ((ent = readdir(dir)) != NULL) {
            // check if the entry is a directory and its name is a number (i.e. a process ID)
            len = strlen(ent->d_name);
            if (ent->d_type == DT_DIR && len > 0 && isdigit(ent->d_name[0])) {
                // copy the pid string
                strncpy(pid, ent->d_name, MAX_PID_LENGTH - 1);
                pid[MAX_PID_LENGTH - 1] = '\0';

                // get the process info from /proc/<pid>/stat
                get_process_info(pid, &info);

                // check if the process command is valid
                if (strlen(info.cmd) > 0) {
                    // copy the process command and check if it exists
                    strncpy(cmd_buf, info.cmd, CMD_NAME_LENGTH - 1);
                    cmd_buf[CMD_NAME_LENGTH - 1] = '\0';
                    cmd_found = cmd_exists(cmd_buf);

                    // if the command exists, get its full path
                    if (cmd_found) {
                        snprintf(cmd_path, MAX_PATH_LENGTH, "/usr/bin/%s", cmd_buf);
                    } else {
                        cmd_path[0] = '\0';
                    }

                    // print the process info
                    printf("%s\t%s\t%s\t%s\t%s\t%s\n",
                           info.pid,
                           cmd_found ? cmd_path : info.cmd,
                           info.user,
                           info.cpu,
                           info.mem,
                           info.uptime);
                }
            }
        }

        // close the /proc directory
        closedir(dir);
    }

    return 0;
}