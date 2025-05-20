//FormAI DATASET v1.0 Category: System process viewer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>

#define MAX_CMD_LENGTH 100
#define MAX_PROC 1024
#define MAX_NAME 128

struct proc_info {
    pid_t pid;
    char name[MAX_NAME];
    char state;
    unsigned long vsize;
    unsigned long rss;
};

void *get_proc_info(void *arg) {
    struct proc_info *p_info = (struct proc_info *) arg;

    char cmd[MAX_CMD_LENGTH];
    sprintf(cmd, "cat /proc/%d/status", p_info->pid);
    
    FILE *proc_file = popen(cmd, "r");

    char buf[MAX_NAME];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, proc_file)) != -1) {
        if (strncmp(line, "Name:", 5) == 0) {
            sscanf(line, "%s %s", buf, p_info->name);
        } else if (strncmp(line, "State:", 6) == 0) {
            sscanf(line, "%s %c", buf, &p_info->state);
        } else if (strncmp(line, "VmSize:", 7) == 0) {
            sscanf(line, "%s %lu", buf, &p_info->vsize);
        } else if (strncmp(line, "VmRSS:", 6) == 0) {
            sscanf(line, "%s %lu", buf, &p_info->rss);
        }
    }

    pclose(proc_file);
    return NULL;
}

int main() {
    DIR *dir;
    struct dirent *ent;
    struct proc_info p_info[MAX_PROC];

    pthread_t threads[MAX_PROC];
    int num_threads = 0;

    if ((dir = opendir("/proc")) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (atoi(ent->d_name) > 0) {
                p_info[num_threads].pid = atoi(ent->d_name);
                pthread_create(&threads[num_threads], NULL, get_proc_info, (void *) &p_info[num_threads]);
                num_threads++;
            }
        }
        closedir(dir);
    } else {
        perror("Error opening directory /proc");
        exit(1);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("%-10s %-20s %-10s %-20s %-20s\n", "PID", "NAME", "STATE", "VIRTUAL MEMORY", "RESIDENT SET");
    for (int i = 0; i < num_threads; i++) {
        printf("%-10d %-20s %-10c %-20lu %-20lu\n", p_info[i].pid, p_info[i].name, p_info[i].state, p_info[i].vsize, p_info[i].rss);
    }

    return 0;
}