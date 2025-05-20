//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define PROC_DIR "/proc"
#define MAX_NAME_LENGTH 256

typedef struct {
    int pid;
    char name[MAX_NAME_LENGTH];
    char state[20];
    int ppid;
    char username[MAX_NAME_LENGTH];
    long int memory;
    long int utime;
    long int stime;
} ProcessInfo;

void get_process_info(int pid, ProcessInfo *processInfo) {
    char path[MAX_NAME_LENGTH];
    snprintf(path, sizeof(path), "%s/%d/stat", PROC_DIR, pid);
    FILE *file = fopen(path, "r");
    if (file) {
        fscanf(file, "%d %s %s %d", &processInfo->pid, processInfo->name, processInfo->state, &processInfo->ppid);
        fclose(file);
    }

    snprintf(path, sizeof(path), "%s/%d/status", PROC_DIR, pid);
    file = fopen(path, "r");
    if (file) {
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            if (strncmp(line, "VmSize:", 7) == 0) {
                sscanf(line + 7, "%ld", &processInfo->memory);
            }
            if (strncmp(line, "Uid:", 4) == 0) {
                int uid;
                sscanf(line + 4, "%d", &uid);
                struct passwd *pw = getpwuid(uid);
                if (pw) {
                    strcpy(processInfo->username, pw->pw_name);
                }
            }
        }
        fclose(file);
    }

    snprintf(path, sizeof(path), "%s/%d/stat", PROC_DIR, pid);
    file = fopen(path, "r");
    if (file) {
        int dummy;
        fscanf(file, "%*d %*s %*s %*d %*d %*d %*d %*d %*d %*d %ld %ld", &processInfo->utime, &processInfo->stime);
        fclose(file);
    }
}

void print_process_info(const ProcessInfo *processInfo) {
    printf("PID: %d | Name: %s | State: %s | PPID: %d | User: %s | Memory: %ld | UTime: %ld | STime: %ld\n",
           processInfo->pid, processInfo->name, processInfo->state, processInfo->ppid,
           processInfo->username, processInfo->memory, processInfo->utime, processInfo->stime);
}

void list_processes() {
    struct dirent *entry;
    DIR *dp = opendir(PROC_DIR);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);
            if (pid > 0) { // It's a valid PID
                ProcessInfo processInfo = {0};
                get_process_info(pid, &processInfo);
                print_process_info(&processInfo);
            }
        }
    }
    closedir(dp);
}

int main(int argc, char *argv[]) {
    printf("=== Process Viewer ===\n");
    list_processes();
    return 0;
}