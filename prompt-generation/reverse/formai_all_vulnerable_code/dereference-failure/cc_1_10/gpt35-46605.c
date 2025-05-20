//FormAI DATASET v1.0 Category: System process viewer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PID_LENGTH 6
#define MAX_COMM_LENGTH 16
#define MAX_STATS_LENGTH 16
#define MAX_LINE_LENGTH 1024

char* get_process_status(char*);
char* get_process_name(char*);
void print_process_info(char*, char*);

int main(void) {

    DIR* proc_dir = opendir("/proc");

    if (!proc_dir) {
        perror("Could not open /proc directory");
        exit(EXIT_FAILURE);
    }

    struct dirent* dir_entry;

    while ((dir_entry = readdir(proc_dir))) {

        if (!isdigit(*dir_entry->d_name)) {
            continue;
        }

        char proc_stats_file_path[MAX_LINE_LENGTH];

        snprintf(proc_stats_file_path, MAX_LINE_LENGTH, "/proc/%s/stat", dir_entry->d_name);

        char* process_stats = get_process_status(proc_stats_file_path);
        char* process_name = get_process_name(dir_entry->d_name);

        if (process_stats && process_name) {
            print_process_info(process_name, process_stats);
        }

        free(process_stats);
        free(process_name);
    }

    closedir(proc_dir);

    return EXIT_SUCCESS;
}

char* get_process_status(char* stat_file_path) {

    FILE* stat_file = fopen(stat_file_path, "r");

    if (!stat_file) {
        return NULL;
    }

    char* process_status = malloc(MAX_STATS_LENGTH);

    if (!process_status) {
        fclose(stat_file);
        return NULL;
    }

    fscanf(stat_file, "%*d %s", process_status);

    fclose(stat_file);

    return process_status;
}

char* get_process_name(char* dir_entry_name) {

    char proc_comm_file_path[MAX_LINE_LENGTH];

    snprintf(proc_comm_file_path, MAX_LINE_LENGTH, "/proc/%s/comm", dir_entry_name);

    FILE* comm_file = fopen(proc_comm_file_path, "r");

    if (!comm_file) {
        return NULL;
    }

    char* process_name = malloc(MAX_COMM_LENGTH);

    if (!process_name) {
        fclose(comm_file);
        return NULL;
    }

    fgets(process_name, MAX_COMM_LENGTH, comm_file);

    fclose(comm_file);

    return process_name;
}

void print_process_info(char* process_name, char* process_status) {

    if (strcmp(process_status, "R") == 0) {
        printf("Paranoid Alert: Process '%s' is running and could be monitoring your actions!\n", process_name);
    } else if (strcmp(process_status, "S") == 0) {
        printf("Process '%s' is currently sleeping.\n", process_name);
    } else if (strcmp(process_status, "Z") == 0) {
        printf("Paranoid Alert: Process '%s' is a zombie! It could be hacked and under the control of an attacker.\n", process_name);
    } else {
        printf("Process '%s' is currently in a state of '%s'.\n", process_name, process_status);
    }
}