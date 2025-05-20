//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <string.h>
#include <time.h>

// Custom data structure for storing process information
typedef struct ProcInfo {
    pid_t pid;
    char* name;
    int ppid;
    int state;
    int priority;
    struct timespec start_time;
} ProcInfo;

// Function to get process information
ProcInfo get_proc_info(pid_t pid) {
    ProcInfo info;
    char buf[1024];
    FILE* f;

    // Get process name
    snprintf(buf, sizeof buf, "/proc/%d/comm", pid);
    f = fopen(buf, "r");
    if (f != NULL) {
        fgets(buf, sizeof buf, f);
        fclose(f);
        info.name = strdup(buf);
    } else {
        info.name = "(unknown)";
    }

    // Get parent process ID
    snprintf(buf, sizeof buf, "/proc/%d/status", pid);
    f = fopen(buf, "r");
    if (f != NULL) {
        while (fgets(buf, sizeof buf, f) != NULL) {
            if (!strncmp(buf, "PPid:", 5)) {
                info.ppid = atoi(buf + 5);
                break;
            }
        }
        fclose(f);
    }

    // Get process state
    snprintf(buf, sizeof buf, "/proc/%d/stat", pid);
    f = fopen(buf, "r");
    if (f != NULL) {
        fgets(buf, sizeof buf, f);
        fclose(f);
        info.state = buf[2];
    }

    // Get process priority
    info.priority = getpriority(PRIO_PROCESS, pid);

    // Get process start time
    snprintf(buf, sizeof buf, "/proc/%d/stat", pid);
    f = fopen(buf, "r");
    if (f != NULL) {
        fgets(buf, sizeof buf, f);
        fclose(f);
        sscanf(buf, "%*d %*s %*c %*d %*d %*d %*d %*d %*u %*u %*u %*u %*u %llu %llu", &info.start_time.tv_sec, &info.start_time.tv_nsec);
    }

    info.pid = pid;
    return info;
}

// Function to display process information
void display_proc_info(const ProcInfo* info) {
    printf("PID:  %d\n", info->pid);
    printf("Name: %s", info->name);
    if (info->name[strlen(info->name) - 1] == '\n') {
        printf("PPID: %d\n", info->ppid);
    } else {
        printf("PPID: %d\n", info->ppid);
    }
    printf("State: %c\n", info->state);
    printf("Priority: %d\n", info->priority);
    printf("Start Time: %ld.%09ld\n", info->start_time.tv_sec, info->start_time.tv_nsec);
    printf("\n");
}

// Main function
int main(int argc, char* argv[]) {
    // Check if there are any arguments
    if (argc < 2) {
        printf("Usage: %s <pid>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get process ID
    pid_t pid = (pid_t)atoi(argv[1]);

    // Get process information
    ProcInfo info = get_proc_info(pid);

    // Display process information
    display_proc_info(&info);

    return EXIT_SUCCESS;
}