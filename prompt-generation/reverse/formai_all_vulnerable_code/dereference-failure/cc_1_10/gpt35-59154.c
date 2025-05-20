//FormAI DATASET v1.0 Category: System process viewer ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <stdlib.h>

#define PROC_DIRECTORY "/proc"

void print_header() {
    printf("PID\tPROCESS_NAME\tPPID\tSTAT\n");
    printf("------------------------------------\n");
}

char *get_process_name(int pid) {
    char *name = malloc(512 * sizeof(char));
    sprintf(name, "/proc/%d/cmdline", pid);
    FILE *fp = fopen(name, "r");

    if (fp == NULL) {
        return "unknown";
    }

    fread(name, 1, 512, fp);
    fclose(fp);

    for (int i = 0; i < strlen(name); i++) {
        if (!isprint(name[i])) {
            name[i] = ' ';
        }
    }

    return name;
}

void get_process_stat(int pid, char *status) {
    char filename[512];
    sprintf(filename, "/proc/%d/stat", pid);

    FILE *fp = fopen(filename, "r");
    fgets(status, 512, fp);
    fclose(fp);
}

void print_process_details(int pid) {
    char status[512];
    get_process_stat(pid, status);

    int proc_pid, proc_ppid;
    char proc_name[512], proc_status;
    sscanf(status, "%d %s %c %d", &proc_pid, proc_name, &proc_status, &proc_ppid);

    printf("%d\t%s\t\t%d\t%c\n", proc_pid, get_process_name(proc_pid), proc_ppid, proc_status);
}

void list_all_processes() {
    print_header();

    DIR *dir = opendir(PROC_DIRECTORY);
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            print_process_details(atoi(entry->d_name));
        }
    }

    closedir(dir);
}

int main() {
    list_all_processes();
    return 0;
}