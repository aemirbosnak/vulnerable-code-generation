//FormAI DATASET v1.0 Category: System process viewer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>


struct Process {
    char* pid;
    char* name;
    char* status;
    char* user;
};


void format_string(char* str) {
    /*
        Function to format the given string by
        removing trailing whitespaces and newlines.
    */
    int i = strlen(str) - 1;

    while (isspace(str[i])) {
        str[i] = '\0';
        i--;
    }
}


struct Process* parse_status(const char* pid, const char* filename) {
    /*
        Parse the /proc/[pid]/status file and extract
        relevant data to create a Process struct.
    */
    struct Process* proc = malloc(sizeof(struct Process));
    proc->pid = malloc(10);
    proc->status = malloc(100);
    proc->user = malloc(100);

    sprintf(proc->pid, "%s", pid);

    FILE* fp = fopen(filename, "r");
    char line[200];

    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "Name:", 5) == 0) {
            char* ptr = strrchr(line, '\t') + 1;
            format_string(ptr);
            proc->name = malloc(strlen(ptr) + 1);
            sprintf(proc->name, "%s", ptr);
        }

        if (strncmp(line, "State:", 6) == 0) {
            char* ptr = strchr(line, '\t') + 1;
            format_string(ptr);
            sprintf(proc->status, "%s", ptr);
        }

        if (strncmp(line, "Uid:", 4) == 0) {
            char* ptr = strrchr(line, '\t') + 1;
            format_string(ptr);
            sprintf(proc->user, "%s", ptr);
        }
    }

    fclose(fp);
    return proc;
}


void print_processes() {
    /*
        Traverse all subdirectories of /proc and parse
        relevant files to extract process information.
    */
    DIR* dir = opendir("/proc");

    if (!dir) {
        perror("opendir");
        exit(1);
    }

    printf("%-10s %-25s %-10s %s\n", "PID", "Name", "User", "Status");

    struct dirent* entry;

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            char filename[256];
            sprintf(filename, "/proc/%s/status", entry->d_name);

            struct Process* proc = parse_status(entry->d_name, filename);
            printf("%-10s %-25s %-10s %s\n",
                   proc->pid, proc->name, proc->user, proc->status);

            free(proc->pid);
            free(proc->name);
            free(proc->status);
            free(proc->user);
            free(proc);
        }
    }

    closedir(dir);
}


int main() {
    print_processes();
    return 0;
}