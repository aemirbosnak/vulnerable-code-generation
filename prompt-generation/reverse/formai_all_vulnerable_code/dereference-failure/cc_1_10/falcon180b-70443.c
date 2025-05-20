//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

#define MAX_PROCESSES 1024
#define MAX_PROCESS_NAME_LENGTH 16

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
} process_t;

int get_processes(process_t *processes) {
    int count = 0;
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir("/proc")) == NULL) {
        perror("Error opening /proc directory");
        return -1;
    }

    while ((ent = readdir(dir))!= NULL) {
        if (isdigit(ent->d_name[0])) {
            int pid = atoi(ent->d_name);
            char path[32];
            snprintf(path, sizeof(path), "/proc/%d/cmdline", pid);

            FILE *file;
            char line[80];
            if ((file = fopen(path, "r"))!= NULL) {
                if (fgets(line, sizeof(line), file)!= NULL) {
                    strncpy(processes[count].name, line, MAX_PROCESS_NAME_LENGTH);
                    processes[count].name[MAX_PROCESS_NAME_LENGTH - 1] = '\0';
                    processes[count].pid = pid;
                    count++;
                }
                fclose(file);
            }
        }
    }

    closedir(dir);

    return count;
}

int main(int argc, char *argv[]) {
    process_t processes[MAX_PROCESSES];
    int count;

    if ((count = get_processes(processes)) < 0) {
        return -1;
    }

    printf("PID\tName\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].name);
    }

    return 0;
}