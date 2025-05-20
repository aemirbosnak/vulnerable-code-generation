//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <dirent.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    int pid;
    char name[BUFFER_SIZE];
    char state[BUFFER_SIZE];
} Process;

Process processes[MAX_PROCESSES];
int process_count = 0;

// Function to read the process information
void* read_processes(void* arg) {
    DIR* dir;
    struct dirent* ent;

    if ((dir = opendir("/proc")) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_DIR) {
                // Check if the directory name is a PID (numeric)
                int pid = atoi(ent->d_name);
                if (pid > 0) {
                    char path[BUFFER_SIZE];
                    snprintf(path, sizeof(path), "/proc/%d/stat", pid);
                    FILE* stat_file = fopen(path, "r");
                    if (stat_file) {
                        int pid;
                        char comm[BUFFER_SIZE];
                        char state[BUFFER_SIZE];
                        fscanf(stat_file, "%d %s %s", &pid, comm, state);
                        fclose(stat_file);
                        strcpy(processes[process_count].name, comm);
                        strcpy(processes[process_count].state, state);
                        processes[process_count].pid = pid;
                        process_count++;
                    }
                }
            }
        }
        closedir(dir);
    }
    return NULL;
}

// Function to display process information
void* display_processes(void* arg) {
    while (1) {
        printf("\033[H\033[J"); // Clear screen
        printf("PID\tNAME\t\tSTATE\n");
        printf("---------------------------------\n");
        for (int i = 0; i < process_count; i++) {
            printf("%d\t%s\t%s\n", processes[i].pid, processes[i].name, processes[i].state);
        }
        printf("---------------------------------\n");
        sleep(2); // Refresh every 2 seconds
    }
    return NULL;
}

int main() {
    pthread_t reader_thread, display_thread;

    // Create thread to read process information
    pthread_create(&reader_thread, NULL, read_processes, NULL);
    // Create thread to display process information
    pthread_create(&display_thread, NULL, display_processes, NULL);

    // Wait for reader thread to finish
    pthread_join(reader_thread, NULL);
    // Display thread runs indefinitely, so we don't join it

    return 0;
}