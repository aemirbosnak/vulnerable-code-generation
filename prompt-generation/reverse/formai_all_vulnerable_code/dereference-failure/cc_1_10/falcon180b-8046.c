//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <dirent.h>

#define MAX_PROCESSES 1000
#define MAX_LINE 4096

char *process_table[MAX_PROCESSES];
int process_count = 0;

void read_processes() {
    DIR *dir;
    struct dirent *ent;
    dir = opendir("/proc");
    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                int pid = atoi(ent->d_name);
                char path[32];
                sprintf(path, "/proc/%d/cmdline", pid);
                FILE *fp = fopen(path, "r");
                if (fp!= NULL) {
                    char line[MAX_LINE];
                    if (fgets(line, MAX_LINE, fp)!= NULL) {
                        process_table[process_count++] = strdup(line);
                    }
                    fclose(fp);
                }
            }
        }
        closedir(dir);
    }
}

void display_processes() {
    printf("Process ID\tCommand\n");
    for (int i = 0; i < process_count; i++) {
        printf("%d\t%s\n", i, process_table[i]);
    }
}

void signal_handler(int signum) {
    if (signum == SIGINT) {
        system("clear");
        display_processes();
    }
}

int main() {
    read_processes();
    signal(SIGINT, signal_handler);
    while (1) {
        system("clear");
        display_processes();
        sleep(1);
    }
    return 0;
}