//FormAI DATASET v1.0 Category: System process viewer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PROCESS_NAME_MAX_LEN 255

// Custom structure to represent a process
struct ProcessInfo
{
    char name[PROCESS_NAME_MAX_LEN]; // process name
    pid_t pid; // process ID
    int priority; // process priority
    long unsigned int vm_size; // virtual memory size
    char status; // process status
};

// Helper function to get the executable name from the process status
char* get_executable_name_from_status(char* status)
{
    char* p = strchr(status, '(');
    if (!p) return NULL;
    p++;
    char* q = strchr(p, ')');
    if (!q) return NULL;
    int len = q - p;
    char* result = malloc(len + 1);
    strncpy(result, p, len);
    result[len] = '\0';
    return result;
}

// Helper function to get the process status from /proc/[pid]/status file
void get_process_status(pid_t pid, struct ProcessInfo* process)
{
    char path[255];
    snprintf(path, 255, "/proc/%d/status", pid);
    int fd = open(path, O_RDONLY);
    if (fd == -1) return;

    char buffer[1024];
    ssize_t n = read(fd, buffer, sizeof(buffer)-1);
    if (n <= 0) return;
    buffer[n] = '\0';

    char* p = strstr(buffer, "State:");
    if (p)
    {
        char* q = strchr(p, '\n');
        if (q)
        {
            *(q++) = '\0';
            process->status = *(q++);
            process->status = tolower(process->status);
            char* exec_name = get_executable_name_from_status(q);
            if (exec_name)
            {
                strncpy(process->name, exec_name, PROCESS_NAME_MAX_LEN);
                free(exec_name);
            }
            else
            {
                strncpy(process->name, "Unknown", PROCESS_NAME_MAX_LEN);
            }
        }
    }

    close(fd);
}

// Helper function to get the process priority from /proc/[pid]/stat file
void get_process_priority(pid_t pid, struct ProcessInfo* process)
{
    char path[255];
    snprintf(path, 255, "/proc/%d/stat", pid);
    int fd = open(path, O_RDONLY);
    if (fd == -1) return;

    char buffer[1024];
    ssize_t n = read(fd, buffer, sizeof(buffer)-1);
    if (n <= 0) return;
    buffer[n] = '\0';

    char* p = buffer;
    for (int i = 0; i < 17; i++)
    {
        p = strchr(p, ' ');
        if (!p) break;
        p++;
    }

    if (p)
    {
        int priority = strtol(p, NULL, 10);
        process->priority = priority;
    }

    close(fd);
}

// Helper function to get the virtual memory size from /proc/[pid]/status file
void get_process_vm_size(pid_t pid, struct ProcessInfo* process)
{
    char path[255];
    snprintf(path, 255, "/proc/%d/status", pid);
    int fd = open(path, O_RDONLY);
    if (fd == -1) return;

    char buffer[1024];
    ssize_t n = read(fd, buffer, sizeof(buffer)-1);
    if (n <= 0) return;
    buffer[n] = '\0';

    char* p = strstr(buffer, "VmSize:");
    if (p)
    {
        char* q = strchr(p, '\n');
        if (q)
        {
            *(q++) = '\0';
            int vm_size = strtol(p+7, NULL, 10);
            process->vm_size = vm_size;
        }
    }

    close(fd);
}

// Main function that walks through /proc directory and prints process information
int main(int argc, char** argv)
{
    DIR* dir = opendir("/proc");
    if (!dir) return -1;

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type != DT_DIR) continue;
        if (!isdigit(entry->d_name[0])) continue;

        pid_t pid = strtol(entry->d_name, NULL, 10);
        struct ProcessInfo process;
        memset(&process, 0, sizeof(process));

        get_process_status(pid, &process);
        if (process.status == '\0') continue;

        get_process_priority(pid, &process);
        get_process_vm_size(pid, &process);

        printf("%5d [%c] %5dK %s\n", process.pid, process.status, process.vm_size/1024, process.name);
    }

    closedir(dir);
    return 0;
}