//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_PROCESSES 512
#define PROCESS_INFO_LINE_SIZE 256

typedef struct {
    pid_t pid;
    char name[PROCESS_INFO_LINE_SIZE];
    int ppid;
} Process;

void print_banner() {
    printf("***************************\n");
    printf("* The Last Process Viewer   *\n");
    printf("* In a World Gone Silent    *\n");
    printf("***************************\n");
}

void get_processes(Process *processes, int *count) {
    DIR *dir;
    struct dirent *entry;

    *count = 0;
    dir = opendir("/proc");

    if (!dir) {
        perror("Failed to open /proc directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            pid_t pid = atoi(entry->d_name);
            char path[PROCESS_INFO_LINE_SIZE];
            snprintf(path, sizeof(path), "/proc/%d/stat", pid);
            FILE *file = fopen(path, "r");

            if (file) {
                Process p;
                fscanf(file, "%d %s %*c %d", &p.pid, p.name, &p.ppid);
                p.name[strcspn(p.name, ")]")] = 0; // Remove trailing characters
                processes[(*count)++] = p;
                fclose(file);
            }
        }
    }
    closedir(dir);
}

void display_processes(Process *processes, int count) {
    if (count == 0) {
        printf("No processes found in this desolate realm...\n");
        return;
    }

    printf("PID\tPPID\tName\n");
    printf("------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t%s\n", processes[i].pid, processes[i].ppid, processes[i].name);
    }
}

void search_process(Process *processes, int count, const char *query) {
    printf("Searching for '%s'...\n", query);
    for (int i = 0; i < count; i++) {
        if (strstr(processes[i].name, query)) {
            printf("Found: PID %d, PPID %d, Name %s\n", processes[i].pid, processes[i].ppid, processes[i].name);
        }
    }
}

int main(int argc, char *argv[]) {
    print_banner();

    Process processes[MAX_PROCESSES];
    int count;

    get_processes(processes, &count);
    display_processes(processes, count);

    if (argc > 1) {
        search_process(processes, count, argv[1]);
    } else {
        printf("Usage: %s <search_query>\n", argv[0]);
    }

    printf("\nIn the silence that remains, we find the forgotten.\n");
    return 0;
}