//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <sys/wait.h>
#include <limits.h>

#define TRUE  1
#define FALSE 0
#define MAX_PROCS 100
#define MAX_PROC_NAME_LEN 50
#define MAX_PROC_STAT_LEN 1024
#define MAX_PROC_COMMAND_LEN 1024
#define MAX_PROC_CGROUP_LEN 1024
#define MAX_PROC_EXE_LEN 1024
#define MAX_PROC_ARG_LEN 1024
#define MAX_PROC_ENV_LEN 1024
#define MAX_PROC_CWD_LEN 1024
#define MAX_PROC_ROOT_LEN 1024
#define MAX_PROC_STAT_ENV_LEN 1024

typedef struct {
    int total;
    int used;
    int free;
    int percent;
} ram_t;

ram_t ram;

void init_ram(void) {
    struct sysinfo info;
    if (sysinfo(&info)!= 0) {
        fprintf(stderr, "Error getting system information: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    ram.total = info.totalram;
    ram.used = info.totalram - info.freeram;
    ram.free = info.freeram;
    ram.percent = (int) round((double) ram.used / ram.total * 100);
}

void print_ram(void) {
    printf("Total RAM: %d MB\n", ram.total / (1024 * 1024));
    printf("Used RAM: %d MB\n", ram.used / (1024 * 1024));
    printf("Free RAM: %d MB\n", ram.free / (1024 * 1024));
    printf("RAM Usage: %d%%\n\n", ram.percent);
}

void monitor_ram(void) {
    while (TRUE) {
        init_ram();
        print_ram();
        sleep(5);
    }
}

int main(int argc, char *argv[]) {
    monitor_ram();
    return 0;
}