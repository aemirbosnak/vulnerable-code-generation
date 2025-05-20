//FormAI DATASET v1.0 Category: System process viewer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define PROC_PATH "/proc"

// structure to hold process information
typedef struct {
    int pid;
    char command[256];
    char state;
    char user[256];
} process_info;

// function to get process information from /proc/<pid>/stat file
process_info get_process_info_from_stat_file(char *pid_str) {
    char stat_file_path[256];
    sprintf(stat_file_path, "%s/%s/stat", PROC_PATH, pid_str);
    FILE *stat_file = fopen(stat_file_path, "r");
    if (stat_file == NULL) {
        printf("Error: Could not open %s\n", stat_file_path);
        exit(1);
    }

    process_info process;
    char buffer[1024];
    fgets(buffer, 1024, stat_file);
    fclose(stat_file);

    char *token = strtok(buffer, " ");
    process.pid = atoi(token);

    token = strtok(NULL, " ");
    token++;     // remove leading '('
    strncpy(process.command, token, 256);
    process.command[strlen(process.command) - 1] = '\0'; // remove trailing ')'

    token = strtok(NULL, " ");
    process.state = token[0];

    // ignore some token until we get to the username (it is the second to last token)
    for (int i = 0; i < 5; i++) {
        token = strtok(NULL, " ");
    }

    strncpy(process.user, token, 256);
    process.user[strlen(process.user) - 1] = '\0';    // remove trailing '\r'

    return process;
}

// main function
int main() {
    DIR *proc_dir = opendir(PROC_PATH);
    if (proc_dir == NULL) {
        printf("Error: Could not open %s\n", PROC_PATH);
        exit(1);
    }

    // print out header
    printf("PID\tCOMMAND\t\t\t\tSTATE\tUSER\n");
    printf("------------------------------------------------------------\n");

    struct dirent *entry;
    while ((entry = readdir(proc_dir))) {    // loop over all files and directories in /proc
        if (entry->d_type != DT_DIR) {
            continue;
        }

        int pid = atoi(entry->d_name);
        if (pid == 0) {     // ignore the "0" directory
            continue;
        }

        process_info process = get_process_info_from_stat_file(entry->d_name);

        // if this is an interesting process (change this to customize to your needs)
        if (strncmp(process.command, "python", 6) == 0 || process.pid == 1) {
            printf("%d\t%-24s\t%c\t%s\n", process.pid, process.command, process.state, process.user);
        }
    }

    closedir(proc_dir);

    return 0;
}