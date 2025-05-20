//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <dirent.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    int pid;
    char name[BUFFER_SIZE];
    char status[BUFFER_SIZE];
} Process;

void print_processes(Process *processes, int count) {
    printf("===== Remnants of the Old World - Process Viewer =====\n");
    printf("PID\tName\t\tStatus\n");
    printf("=========================================\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-15s\t%s\n", processes[i].pid, processes[i].name, processes[i].status);
    }
    printf("=========================================\n");
}

int load_processes(Process *processes) {
    DIR *proc_dir;
    struct dirent *entry;
    char path[BUFFER_SIZE];
    FILE *status_file;
    char status[BUFFER_SIZE];

    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("Failed to open /proc directory");
        return -1;
    }

    int count = 0;
    while ((entry = readdir(proc_dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);
            if (pid > 0) {
                snprintf(path, sizeof(path), "/proc/%d/stat", pid);
                status_file = fopen(path, "r");
                if (status_file) {
                    fscanf(status_file, "%*d %s %*c %s", processes[count].name, status);
                    strcpy(processes[count].status, (strcmp(status, "R") == 0) ? "Running" : "Sleeping/Stopped");
                    processes[count].pid = pid;
                    count++;
                    fclose(status_file);
                }
            }
        }
        if (count >= MAX_PROCESSES) {
            break;
        }
    }
    closedir(proc_dir);
    return count;
}

void cleanup(Process *processes, int count) {
    free(processes);
}

void signal_handler(int signum) {
    if (signum == SIGINT) {
        printf("\nSurvivor, are you sure about quitting this process observation? (Y/N) ");
        char response;
        scanf(" %c", &response);
        if (response == 'Y' || response == 'y') {
            printf("Abandoning the watch...\n");
            exit(0);
        } else {
            printf("Continuing the watch...\n");
        }
    }
}

int main() {
    signal(SIGINT, signal_handler);

    Process *processes = (Process *)malloc(MAX_PROCESSES * sizeof(Process));
    if (processes == NULL) {
        perror("Failed to allocate memory for processes");
        return EXIT_FAILURE;
    }

    while (1) {
        int count = load_processes(processes);
        if (count < 0) {
            cleanup(processes, 0);
            return EXIT_FAILURE;
        }

        print_processes(processes, count);
        printf("Tattered remnants whisper tales of survival...\n");
        sleep(5);
    }

    cleanup(processes, MAX_PROCESSES);
    return EXIT_SUCCESS;
}