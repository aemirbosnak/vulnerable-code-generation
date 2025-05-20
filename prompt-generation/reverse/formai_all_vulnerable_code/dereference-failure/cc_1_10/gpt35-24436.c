//FormAI DATASET v1.0 Category: System process viewer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define MAX_PROC 2048
#define PROC_LOC "/proc"
#define CMDLINE_LEN 256

typedef struct {
    char name[64];
    int pid;
    int ppid;
    char state;
} process;

int get_all_processes(process *procs) {
    DIR *dir;
    struct dirent *entry;

    int num_procs = 0;
    if ((dir = opendir(PROC_LOC)) == NULL) {
        perror("opendir");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(*entry->d_name)) {
            int pid = atoi(entry->d_name);
            char cmdline_file[CMDLINE_LEN];
            sprintf(cmdline_file, "%s/%d/cmdline", PROC_LOC, pid);

            FILE *fp;
            if ((fp = fopen(cmdline_file, "r")) == NULL) {
                perror("fopen");
                continue;
            }

            char name[64];
            int c, i;
            for (i = 0; i < 63 && (c = fgetc(fp)) != EOF; ++i) {
                if (c == '\0') {
                    break;
                }
                name[i] = (char)c;
            }
            name[i] = '\0';

            fclose(fp);

            char stat_file[CMDLINE_LEN];
            sprintf(stat_file, "%s/%d/stat", PROC_LOC, pid);

            if ((fp = fopen(stat_file, "r")) == NULL) {
                perror("fopen");
                continue;
            }

            int ppid;
            char state;
            fscanf(fp, "%*d %*s %c %d", &state, &ppid);

            fclose(fp);

            strcpy(procs[num_procs].name, name);
            procs[num_procs].pid = pid;
            procs[num_procs].ppid = ppid;
            procs[num_procs].state = state;

            num_procs++;
            if (num_procs >= MAX_PROC) {
                break;
            }
        }
    }

    closedir(dir);
    return num_procs;
}

void print_process_info(process p) {
    printf("Name: %-20s\tPID: %5d\tPPID: %5d\tState: %c\n",
           p.name, p.pid, p.ppid, p.state);
}

int main() {
    process procs[MAX_PROC];

    int num_procs = get_all_processes(procs);

    printf("Total %d processes found.\n", num_procs);
    printf("Name                      \tPID  \tPPID \tState\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < num_procs; ++i) {
        print_process_info(procs[i]);
    }

    return 0;
}