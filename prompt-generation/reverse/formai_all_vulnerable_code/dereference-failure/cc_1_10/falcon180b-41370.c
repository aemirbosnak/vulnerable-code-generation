//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_PROCESSES 100
#define MAX_LINE_LENGTH 1024

struct process {
    int pid;
    char name[MAX_LINE_LENGTH];
};

void print_processes(struct process *processes, int count) {
    printf("Process ID\t\tProcess Name\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t\t%s\n", processes[i].pid, processes[i].name);
    }
}

int get_processes(struct process *processes, int max_count) {
    char path[MAX_LINE_LENGTH];
    snprintf(path, MAX_LINE_LENGTH, "/proc");
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return 0;
    }

    struct dirent *dirent;
    int count = 0;
    while ((dirent = readdir(dir))!= NULL) {
        if (dirent->d_type == DT_DIR && isdigit(dirent->d_name[0])) {
            snprintf(path, MAX_LINE_LENGTH, "/proc/%s/cmdline", dirent->d_name);
            FILE *file = fopen(path, "r");
            if (file!= NULL) {
                char name[MAX_LINE_LENGTH];
                if (fgets(name, MAX_LINE_LENGTH, file)!= NULL) {
                    name[strcspn(name, "\n")] = '\0';
                    processes[count].pid = atoi(dirent->d_name);
                    strncpy(processes[count].name, name, MAX_LINE_LENGTH - 1);
                    count++;
                    if (count >= max_count) {
                        break;
                    }
                }
                fclose(file);
            }
        }
    }

    closedir(dir);
    return count;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [max_processes]\n", argv[0]);
        return 1;
    }

    int max_processes = atoi(argv[1]);
    struct process processes[MAX_PROCESSES];
    int count = get_processes(processes, max_processes);

    if (count == 0) {
        printf("No processes found.\n");
        return 1;
    }

    print_processes(processes, count);
    return 0;
}