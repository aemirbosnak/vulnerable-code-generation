//FormAI DATASET v1.0 Category: System process viewer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_LINE_LEN 1024
#define MAX_PID_LEN  32

// Global variables
char *program_name;

// Function declarations
void print_help();
int is_valid_pid(const char *pid);
void list_processes();
int get_process_info(const char *pid, char *name, char *status);
int get_process_owner(const char *pid, char *owner);

int main(int argc, char **argv)
{
    program_name = argv[0];

    if (argc == 1) {
        list_processes();
        return 0;
    }

    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        print_help();
        return 0;
    }

    if (!is_valid_pid(argv[1])) {
        fprintf(stderr, "%s: invalid PID: %s\n", program_name, argv[1]);
        return 1;
    }

    char name[MAX_LINE_LEN] = {0};
    char status[MAX_LINE_LEN] = {0};
    char owner[MAX_LINE_LEN] = {0};

    if (get_process_info(argv[1], name, status)) {
        fprintf(stderr, "%s: cannot get process info for PID %s\n", program_name, argv[1]);
        return 1;
    }

    if (get_process_owner(argv[1], owner)) {
        fprintf(stderr, "%s: cannot get process owner for PID %s\n", program_name, argv[1]);
        return 1;
    }

    printf("PID: %s\nName: %s\nStatus: %s\nOwner: %s\n", argv[1], name, status, owner);

    return 0;
}

void print_help()
{
    printf("Usage: %s [<pid>]\n", program_name);
    printf("  <pid> - optional PID of the process to get info for\n");
    printf("  If no PID is provided, a list of running processes with their PIDs is shown.\n");
}

int is_valid_pid(const char *pid)
{
    for (int i = 0; pid[i] != '\0'; i++) {
        if (!isdigit(pid[i]))
            return 0;
    }

    struct stat st;

    char proc_file_path[MAX_LINE_LEN] = {0};
    snprintf(proc_file_path, MAX_LINE_LEN, "/proc/%s", pid);

    if (stat(proc_file_path, &st) == -1)
        return 0;

    if (!S_ISDIR(st.st_mode))
        return 0;

    return 1;
}

void list_processes()
{
    DIR *dir = opendir("/proc");

    if (!dir) {
        fprintf(stderr, "%s: cannot open /proc directory\n", program_name);
        exit(1);
    }

    printf("PID\tName\n");

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        if (!isdigit(entry->d_name[0]))
            continue;

        char name[MAX_LINE_LEN] = {0};
        char status[MAX_LINE_LEN] = {0};

        int err = get_process_info(entry->d_name, name, status);

        if (err == -1) {
            fprintf(stderr, "%s: cannot get name/status for PID %s\n", program_name, entry->d_name);
            continue;
        }

        printf("%s\t%s\n", entry->d_name, name);
    }

    closedir(dir);
}

int get_process_info(const char *pid, char *name, char *status)
{
    char proc_file_path[MAX_LINE_LEN] = {0};
    snprintf(proc_file_path, MAX_LINE_LEN, "/proc/%s/status", pid);

    FILE *file = fopen(proc_file_path, "r");

    if (!file)
        return -1;

    while (!feof(file)) {
        char line[MAX_LINE_LEN] = {0};
        fgets(line, MAX_LINE_LEN, file);

        if (sscanf(line, "Name: %s", name) == 1)
            continue;

        if (sscanf(line, "State: %s", status) == 1)
            continue;
    }

    fclose(file);

    return 0;
}

int get_process_owner(const char *pid, char *owner)
{
    char proc_file_path[MAX_LINE_LEN] = {0};
    snprintf(proc_file_path, MAX_LINE_LEN, "/proc/%s/status", pid);

    FILE *file = fopen(proc_file_path, "r");

    if (!file)
        return -1;

    while (!feof(file)) {
        char line[MAX_LINE_LEN] = {0};
        fgets(line, MAX_LINE_LEN, file);

        if (sscanf(line, "Uid: %*d %*d %*d %s", owner) == 1)
            break;
    }

    fclose(file);

    char passwd_file_path[MAX_LINE_LEN] = {0};
    snprintf(passwd_file_path, MAX_LINE_LEN, "/etc/passwd");

    file = fopen(passwd_file_path, "r");

    if (!file)
        return -1;

    while (!feof(file)) {
        char line[MAX_LINE_LEN] = {0};
        fgets(line, MAX_LINE_LEN, file);

        char *token = strtok(line, ":");

        if (strcmp(token, owner) == 0) {
            strcpy(owner, token);

            break;
        }
    }

    fclose(file);

    return 0;
}