//FormAI DATASET v1.0 Category: System process viewer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define MAX_PID_LENGTH 6

int main(void) {
    DIR *proc_dir;
    struct dirent *dir_entry;
    char proc_pid_path[20], status_path[30], line[100], *c;
    FILE *status_file;
    int pid, ppid, state, vm_size;

    printf("%-6s %-6s %-20s %-10s\n", "PID", "PPID", "COMMAND", "STATE");
    proc_dir = opendir("/proc");
    if (proc_dir) {
        while ((dir_entry = readdir(proc_dir)) != NULL) {
            // check if the entry is a directory and its name only contains digits
            if (dir_entry->d_type == DT_DIR && atoi(dir_entry->d_name) != 0) {
                // get the path to the process's status file
                sprintf(proc_pid_path, "/proc/%s", dir_entry->d_name);
                sprintf(status_path, "%s/status", proc_pid_path);
                status_file = fopen(status_path, "r");
                if (status_file) {
                    // initialize variables
                    pid = atoi(dir_entry->d_name);
                    ppid = -1;
                    state = -1;
                    vm_size = -1;
                    // read each line of the status file
                    while (fgets(line, sizeof(line), status_file)) {
                        // check if line is the PPid
                        if (strncmp(line, "PPid:", 5) == 0) {
                            c = line + 5;
                            while (isspace(*c)) c++;
                            ppid = atoi(c);
                        }
                        // check if line is the State
                        else if (strncmp(line, "State:", 6) == 0) {
                            c = line + 6;
                            while (isspace(*c)) c++;
                            switch (*c) {
                                case 'R':
                                    state = 1;
                                    break;
                                case 'S':
                                    state = 2;
                                    break;
                                case 'D':
                                    state = 3;
                                    break;
                                case 'Z':
                                    state = 4;
                                    break;
                                case 'T':
                                    state = 5;
                                    break;
                                case 't':
                                    state = 6;
                                    break;
                                case 'X':
                                    state = 7;
                                    break;
                                default:
                                    state = -1;
                                    break;
                            }
                        }
                        // check if line is the VmSize
                        else if (strncmp(line, "VmSize:", 7) == 0) {
                            c = line + 7;
                            while (isspace(*c)) c++;
                            vm_size = atoi(c);
                            break; // we have all the info we need in this file
                        }
                    }
                    // print the info for the process
                    if (ppid != -1 && state != -1 && vm_size != -1) {
                        printf("%-6d %-6d %-20s %-10d\n", pid, ppid, dir_entry->d_name, state);
                    }
                    fclose(status_file);
                }
            }
        }
        closedir(proc_dir);
    }
    return 0;
}