//FormAI DATASET v1.0 Category: System process viewer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_PATH_LEN 512
#define MAX_PROCESSES 1024

struct process_info {
    char name[MAX_PATH_LEN];
    int pid;
    int ppid;
    char state;
};

int get_processes(struct process_info *process_list) {
    DIR *dir;
    struct dirent *entry;
    char path[MAX_PATH_LEN], comm_path[MAX_PATH_LEN], state;
    int pid, ppid, count = 0;

    if ((dir = opendir("/proc")) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL && count < MAX_PROCESSES) {
        if (entry->d_type == DT_DIR && atoi(entry->d_name) != 0) {
            pid = atoi(entry->d_name);
            snprintf(comm_path, MAX_PATH_LEN, "/proc/%d/comm", pid);
            FILE *comm_file = fopen(comm_path, "r");
            fgets(process_list[count].name, MAX_PATH_LEN, comm_file);
            fclose(comm_file);

            snprintf(path, MAX_PATH_LEN, "/proc/%d/stat", pid);
            FILE *stat_file = fopen(path, "r");
            fscanf(stat_file, "%d %s %c %d", &pid, process_list[count].name, &state, &ppid);
            fclose(stat_file);

            process_list[count].pid = pid;
            process_list[count].ppid = ppid;
            process_list[count].state = state;

            count++;
        }
    }

    closedir(dir);
    return count;
}

void print_processes(struct process_info *process_list, int count) {
    printf("%-20s %-10s %-10s %s\n", "COMMAND", "PID", "PPID", "STATE");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10d %-10d %c\n", process_list[i].name, process_list[i].pid, process_list[i].ppid, process_list[i].state);
    }
}

int main() {
    struct process_info process_list[MAX_PROCESSES];
    int count = get_processes(process_list);
    print_processes(process_list, count);

    return EXIT_SUCCESS;
}