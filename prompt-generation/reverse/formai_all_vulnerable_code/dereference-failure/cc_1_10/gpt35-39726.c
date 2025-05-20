//FormAI DATASET v1.0 Category: System process viewer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

#define PROC_DIR "/proc"

// Structure to hold process information
typedef struct {
    int pid;
    char* name;
} process;

// Mutex for thread synchronization
pthread_mutex_t mutex;

// Function to get process PID from /proc/<pid>/stat
int get_pid_from_stat(char* path) {
    char* name = strrchr(path, '/');
    name++;

    if (isdigit(name[0])) {
        return atoi(name);
    }

    return -1;
}

// Function to get process name from /proc/<pid>/stat
char* get_name_from_stat(char* path) {
    FILE* fp = fopen(path, "r");
    if (fp == NULL) {
        return NULL;
    }

    char buffer[1024];
    if (fgets(buffer, sizeof(buffer), fp)) {
        char* start = strchr(buffer, '(') + 1;
        char* end = strchr(buffer, ')');
        if (start && end) {
            int len = end - start;
            char* name = malloc(len + 1);
            strncpy(name, start, len);
            name[len] = '\0';
            fclose(fp);
            return name;
        }
    }

    fclose(fp);
    return NULL;
}

// Thread function to get process information
void* get_processes(void* arg) {
    DIR* dir = opendir(PROC_DIR);
    if (dir == NULL) {
        perror("opendir");
        return NULL;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            int pid = get_pid_from_stat(entry->d_name);
            if (pid > 0) {
                char path[1024];
                sprintf(path, PROC_DIR "/%d/stat", pid);
                char* name = get_name_from_stat(path);

                pthread_mutex_lock(&mutex);
                process* proc = malloc(sizeof(process));
                proc->pid = pid;
                proc->name = name;
                printf("PID: %d, Name: %s\n", proc->pid, proc->name);
                pthread_mutex_unlock(&mutex);
            }
        }
    }

    closedir(dir);
    return NULL;
}

int main() {
    pthread_mutex_init(&mutex, NULL);

    pthread_t thread;
    pthread_create(&thread, NULL, get_processes, NULL);

    pthread_join(thread, NULL);

    pthread_mutex_destroy(&mutex);
    
    return 0;
}