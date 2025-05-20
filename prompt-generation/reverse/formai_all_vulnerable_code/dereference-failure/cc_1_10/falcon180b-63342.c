//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *fp;
    char buf[BUF_SIZE];
    int cpu_percent;
    int status;

    if (argc < 2) {
        printf("Usage: %s <PID>\n", argv[0]);
        exit(1);
    }

    pid_t pid = atoi(argv[1]);

    fp = fopen("/proc/stat", "r");

    if (fp == NULL) {
        printf("Error: Could not open /proc/stat\n");
        exit(1);
    }

    while (fgets(buf, BUF_SIZE, fp)!= NULL) {
        if (strncmp(buf, "cpu", 3) == 0) {
            sscanf(buf, "cpu %*s %*s %*s %*s %d", &cpu_percent);
            break;
        }
    }

    if (cpu_percent == 0) {
        printf("Error: Could not find CPU usage for PID %d\n", pid);
        exit(1);
    }

    sprintf(buf, "/proc/%d/stat", pid);

    status = system(buf);

    if (status!= 0) {
        printf("Error: Could not get process status for PID %d\n", pid);
        exit(1);
    }

    fclose(fp);

    return 0;
}