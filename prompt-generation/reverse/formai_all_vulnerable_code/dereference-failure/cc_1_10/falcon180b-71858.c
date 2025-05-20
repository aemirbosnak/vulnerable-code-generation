//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define PROC_DIR "/proc"
#define PROC_FILE "/proc/%d/stat"
#define PROC_CPU_FIELD 14
#define PROC_RSS_FIELD 23

void print_usage(char* argv[]) {
    fprintf(stderr, "Usage: %s [PID]\n", argv[0]);
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        print_usage(argv);
    }

    int pid = atoi(argv[1]);
    char proc_file[20];
    sprintf(proc_file, PROC_FILE, pid);

    FILE* fp = fopen(proc_file, "r");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open %s\n", proc_file);
        exit(1);
    }

    char line[80];
    fgets(line, 80, fp);
    fclose(fp);

    int cpu_usage = 0;
    int rss = 0;
    int fields[30];
    int i = 0;
    char* token = strtok(line, " ");
    while (token!= NULL) {
        fields[i++] = atoi(token);
        token = strtok(NULL, " ");
    }

    cpu_usage = fields[PROC_CPU_FIELD];
    rss = fields[PROC_RSS_FIELD];

    printf("PID: %d\n", pid);
    printf("CPU Usage: %.2f%%\n", (float)cpu_usage / (float)sysconf(_SC_CLK_TCK) * 100.0);
    printf("Resident Set Size: %d KB\n", rss / 1024);

    return 0;
}