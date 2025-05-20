//FormAI DATASET v1.0 Category: System process viewer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_COMMAND_LEN 2048
#define MAX_PID_LEN 10
#define MAX_THREADS 10

void* find_process(void*);
void print_process_info(const char*);

typedef struct {
    char name[MAX_PATH];
    int pid;
} ProcessInfo;

ProcessInfo processes[MAX_THREADS];
int num_processes = 0;

int main() {
    pthread_t threads[MAX_THREADS];

    DIR* dir = opendir("/proc");
    if (!dir) {
        perror("Failed to open /proc");
        exit(1);
    }

    struct dirent* ent;
    while ((ent = readdir(dir)) != NULL) {
        // Check if directory is a process ID (i.e. a number)
        if ((ent->d_type == DT_DIR) && (isdigit(*ent->d_name))) {
            int pid = atoi(ent->d_name);

            // Create a thread to find process info
            pthread_create(&threads[num_processes], NULL, find_process, (void*)pid);
            num_processes++;
        }
    }

    for (int i = 0; i < num_processes; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < num_processes; i++) {
        print_process_info(processes[i].name);
    }

    closedir(dir);
    return 0;
}

void* find_process(void* arg) {
    int pid = (int)arg;

    // Open /proc/[pid]/cmdline to get the command used to start process
    char cmd_file_path[MAX_PATH];
    snprintf(cmd_file_path, sizeof(cmd_file_path), "/proc/%d/cmdline", pid);

    FILE* cmd_file = fopen(cmd_file_path, "r");
    if (!cmd_file) {
        perror("Failed to open cmdline file");
        return NULL;
    }

    // Get command used to start process (null-separated)
    char cmd[MAX_COMMAND_LEN];
    size_t num_read = fread(cmd, 1, sizeof(cmd), cmd_file);
    fclose(cmd_file);

    if (num_read == 0) {
        return NULL;
    }

    // Remove null-separators from command string
    int len = strlen(cmd);
    for (int i = 0; i < len; i++) {
        if (cmd[i] == '\0') {
            cmd[i] = ' ';
        }
    }

    // Add process info to global array
    ProcessInfo process_info;
    process_info.pid = pid;
    strncpy(process_info.name, cmd, sizeof(process_info.name));
    processes[num_processes] = process_info;

    pthread_exit(NULL);
}

void print_process_info(const char* name) {
    printf("Process: %s\n", name);
}