//FormAI DATASET v1.0 Category: System process viewer ; Style: accurate
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_PID 32768
#define BUFFER_SIZE 512

// function to check if given directory name is a directory or not
int is_directory(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) != 0) {
        return 0;
    }
    return S_ISDIR(statbuf.st_mode);
}

// function to read command line arguments and return PID
int get_pid_from_args(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <PID>\n", argv[0]);
        exit(1);
    }
    int pid = atoi(argv[1]);
    if (pid < 1 || pid >= MAX_PID) {
        printf("Invalid PID: %d.\n", pid);
        exit(2);
    }
    return pid;
}

// function to get process information from /proc/<PID>/stat file
void get_proc_info(int pid, char *state, char *name, int *parent_pid, int *pgid, int *sid, int *tty_nr) {
    char buffer[BUFFER_SIZE], path[BUFFER_SIZE];
    sprintf(path, "/proc/%d/stat", pid);
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s.\n", path);
        exit(3);
    }
    fgets(buffer, BUFFER_SIZE, fp);
    fclose(fp);
    // parse the contents of stat file
    char *pos1 = strchr(buffer, '('), *pos2 = strrchr(buffer, ')');
    strncpy(name, pos1 + 1, pos2 - pos1 - 1);
    name[pos2 - pos1 - 1] = '\0';
    sscanf(pos2, ") %c %d %d %d %d %d %d %d %d", state, parent_pid, pgid, sid, tty_nr, tty_nr + 1, tty_nr + 2, tty_nr + 3, tty_nr + 4);
}

// function to get process command from /proc/<PID>/cmdline file
void get_proc_cmd(int pid, char *cmdline) {
    char path[BUFFER_SIZE];
    sprintf(path, "/proc/%d/cmdline", pid);
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s.\n", path);
        exit(3);
    }
    fgets(cmdline, BUFFER_SIZE, fp);
    fclose(fp);
    // replace null bytes with spaces
    for (char *p = cmdline; *p != '\0'; ++p) {
        if (*p == '\0') {
            *p = ' ';
        }
    }
}

// function to get process state name from state character code
void get_state_name(char state, char *name) {
    switch (state) {
        case 'R':
            strcpy(name, "Running");
            break;
        case 'S':
            strcpy(name, "Sleeping");
            break;
        case 'D':
            strcpy(name, "Waiting");
            break;
        case 'Z':
            strcpy(name, "Zombie");
            break;
        case 'T':
            strcpy(name, "Stopped");
            break;
        case 't':
            strcpy(name, "Tracing stop");
            break;
        case 'X':
            strcpy(name, "Dead");
            break;
        case 'x':
            strcpy(name, "Dead");
            break;
        case 'K':
            strcpy(name, "Wakekill");
            break;
        case 'W':
            strcpy(name, "Waking");
            break;
        case 'P':
            strcpy(name, "Parked");
            break;
        default:
            strcpy(name, "Unknown");
            break;
    }
}

// function to print process information
void print_proc_info(int pid, char *name, char *cmdline, char state, int parent_pid, int pgid, int sid, int tty_nr) {
    char state_name[16];
    get_state_name(state, state_name);
    printf("%6d %20s %6d %6d %6d %16s %5s\n", pid, name, parent_pid, pgid, sid, state_name, cmdline);
}

// function to print header row
void print_header() {
    printf("%6s %20s %6s %6s %6s %16s %5s\n", "PID", "NAME", "PPID", "PGID", "SID", "STATE", "TTY");
}

// function to display process information of all running processes
void display_proc_info(int *pid_list, int pid_count) {
    print_header();
    for (int i = 0; i < pid_count; ++i) {
        int pid = pid_list[i];
        char state, name[BUFFER_SIZE], cmdline[BUFFER_SIZE];
        int parent_pid, pgid, sid, tty_nr[5];
        get_proc_info(pid, &state, name, &parent_pid, &pgid, &sid, tty_nr);
        get_proc_cmd(pid, cmdline);
        print_proc_info(pid, name, cmdline, state, parent_pid, pgid, sid, tty_nr[0]);
    }
}

// function to read /proc directory and get list of all running process PIDs
void get_running_pids(int *pid_list, int *pid_count) {
    DIR *dir;
    struct dirent *ent;
    dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error: Cannot open directory /proc.\n");
        exit(4);
    }
    *pid_count = 0;
    while ((ent = readdir(dir)) != NULL) {
        // check if the directory name is a number
        if (isdigit(*ent->d_name)) {
            int pid = atoi(ent->d_name);
            // check if the process directory is accessible
            if (is_directory(ent->d_name)) {
                char path[BUFFER_SIZE];
                sprintf(path, "/proc/%d/status", pid);
                FILE *fp = fopen(path, "r");
                if (fp != NULL) {
                    char buffer[4096], *pos;
                    while ((pos = fgets(buffer, sizeof(buffer), fp)) != NULL) {
                        if (strncmp(pos, "State:", 6) == 0) {
                            // check if the process is running or not
                            if (pos[7] == 'R') {
                                pid_list[*pid_count] = pid;
                                ++*pid_count;
                            }
                            break;
                        }
                    }
                    fclose(fp);
                }
            }
        }
    }
    closedir(dir);
}

// main function
int main(int argc, char *argv[]) {
    int pid_list[MAX_PID], pid_count;
    get_running_pids(pid_list, &pid_count);
    if (argc > 1) {
        int pid = get_pid_from_args(argc, argv);
        if (pid_count > 0) {
            char path[BUFFER_SIZE];
            sprintf(path, "/proc/%d/status", pid);
            if (access(path, F_OK) != -1) {
                char state, name[BUFFER_SIZE], cmdline[BUFFER_SIZE];
                int parent_pid, pgid, sid, tty_nr[5];
                get_proc_info(pid, &state, name, &parent_pid, &pgid, &sid, tty_nr);
                get_proc_cmd(pid, cmdline);
                print_header();
                print_proc_info(pid, name, cmdline, state, parent_pid, pgid, sid, tty_nr[0]);
            } else {
                printf("Error: Process with PID %d does not exist.\n", pid);
            }
        } else {
            printf("No running processes found.\n");
        }
    } else {
        if (pid_count > 0) {
            display_proc_info(pid_list, pid_count);
        } else {
            printf("No running processes found.\n");
        }
    }
    return 0;
}