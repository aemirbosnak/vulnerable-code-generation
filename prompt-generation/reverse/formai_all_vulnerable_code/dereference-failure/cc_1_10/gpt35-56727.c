//FormAI DATASET v1.0 Category: System process viewer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

struct process {
    char pid[10];
    char pname[100];
    char state;
};

int main() {
    struct process pList[100];
    DIR* proc_dir = opendir("/proc");
    struct dirent* proc_ent;
    int i = 0;

    if (!proc_dir) {
        perror("Could not open directory /proc");
        return EXIT_FAILURE;
    }

    while ((proc_ent = readdir(proc_dir))) {
        if (!isdigit(*proc_ent->d_name))
            continue;

        char stat_file[100];
        sprintf(stat_file, "/proc/%s/stat", proc_ent->d_name);

        FILE* stat_fp = fopen(stat_file, "r");
        if (!stat_fp) {
            perror("Could not open file stat");
            return EXIT_FAILURE;
        }

        fscanf(stat_fp, "%s", pList[i].pid);
        fscanf(stat_fp, "%s", pList[i].pname);
        fscanf(stat_fp, " %c", &pList[i].state);

        fclose(stat_fp);
        i++;
    }

    printf("PID\tPROCESS NAME\tSTATE\n");
    for (int j = 0; j < i; j++) {
        printf("%s\t%s\t\t%c\n", pList[j].pid, pList[j].pname, pList[j].state);
    }

    closedir(proc_dir);
    return EXIT_SUCCESS;
}