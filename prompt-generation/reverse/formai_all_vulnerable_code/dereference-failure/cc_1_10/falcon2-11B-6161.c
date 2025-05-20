//Falcon2-11B DATASET v1.0 Category: System process viewer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Function to print process information
void print_process_info(int pid) {
    char* cmdline = NULL;
    ssize_t len = 0;
    int status;

    if (waitpid(pid, &status, 0)!= -1) {
        char* p = "/proc/";
        p += snprintf(p, 256, "%d/cmdline", pid);
        FILE* fp = fopen(p, "r");
        if (fp!= NULL) {
            fseek(fp, 0L, SEEK_END);
            len = ftell(fp);
            rewind(fp);

            cmdline = (char*)malloc(sizeof(char) * (len + 1));
            fread(cmdline, sizeof(char), len, fp);
            cmdline[len] = '\0';
            fclose(fp);

            printf("Process ID: %d\n", pid);
            printf("Command: %s\n", cmdline);
        }
    } else {
        printf("Failed to get process information.\n");
    }

    free(cmdline);
}

// Function to list running processes
void list_running_processes(void) {
    DIR* dir;
    struct dirent* entry;

    dir = opendir("/proc");
    if (dir == NULL) {
        printf("Failed to open /proc directory.\n");
        return;
    }

    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);
            print_process_info(pid);
        }
    }

    closedir(dir);
}

int main(int argc, char* argv[]) {
    list_running_processes();
    return 0;
}