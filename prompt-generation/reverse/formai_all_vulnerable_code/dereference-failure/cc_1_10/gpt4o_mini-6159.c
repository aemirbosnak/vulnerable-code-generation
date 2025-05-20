//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <pthread.h>
#include <signal.h>
#include <time.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256
#define REFRESH_INTERVAL 1

typedef struct ProcessInfo {
    int pid;
    char name[BUFFER_SIZE];
} ProcessInfo;

ProcessInfo processList[MAX_PROCESSES];
int processCount = 0;
int running = 1;

void* refreshProcesses(void* arg) {
    while (running) {
        processCount = 0;
        DIR* dir;
        struct dirent* entry;
        dir = opendir("/proc");
        if (dir == NULL) {
            perror("opendir");
            return NULL;
        }

        while ((entry = readdir(dir)) != NULL) {
            if (isdigit(entry->d_name[0])) {
                char path[BUFFER_SIZE];
                snprintf(path, sizeof(path), "/proc/%s/comm", entry->d_name);
                FILE* fp = fopen(path, "r");
                if (fp) {
                    ProcessInfo pInfo;
                    pInfo.pid = atoi(entry->d_name);
                    fgets(pInfo.name, sizeof(pInfo.name), fp);
                    pInfo.name[strcspn(pInfo.name, "\n")] = 0; // Remove newline
                    fclose(fp);
                    processList[processCount++] = pInfo;
                }
            }
        }
        closedir(dir);
        sleep(REFRESH_INTERVAL);
    }
    return NULL;
}

void displayProcesses() {
    printf("\033[H\033[J"); // Clear screen
    printf("Process Viewer:\n");
    printf("%-10s %-50s\n", "PID", "Name");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < processCount; i++) {
        printf("%-10d %-50s\n", processList[i].pid, processList[i].name);
    }
    printf("-----------------------------------------------------\n");
    printf("Press Ctrl+C to exit...\n");
}

void signalHandler(int signum) {
    running = 0;
}

int main() {
    signal(SIGINT, signalHandler);

    pthread_t threadId;

    if (pthread_create(&threadId, NULL, refreshProcesses, NULL) != 0) {
        perror("Failed to create thread");
        return 1;
    }

    while (running) {
        displayProcesses();
        usleep(500000); // Refresh display approximately every half a second
    }

    pthread_join(threadId, NULL);
    return 0;
}