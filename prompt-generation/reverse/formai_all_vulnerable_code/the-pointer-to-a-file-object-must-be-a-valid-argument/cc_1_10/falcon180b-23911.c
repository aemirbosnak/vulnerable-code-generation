//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/statvfs.h>

#define MB 1024 * 1024

typedef struct {
    char name[50];
    int id;
    int memory;
} process;

void get_processes(process* procs, int count) {
    FILE* file;
    char line[100];
    int i = 0;
    file = fopen("/proc/self/status", "r");
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (strncmp(line, "VmSize:", 8) == 0) {
            sscanf(line, "VmSize: %d kB", &procs[i].memory);
        }
        if (strncmp(line, "Name:", 5) == 0) {
            sscanf(line, "Name: %s", procs[i].name);
        }
        i++;
    }
    fclose(file);
}

void get_ram_usage(double* used, double* total) {
    struct statvfs buf;
    if (statvfs("/", &buf) == 0) {
        *total = buf.f_blocks * buf.f_frsize / MB;
        *used = (*total - buf.f_bavail) * buf.f_frsize / MB;
    }
}

int main() {
    process procs[10];
    int count = 0;
    int i = 0;
    while (count < 10) {
        get_processes(procs, 10);
        count = 10;
        for (i = 0; i < 10; i++) {
            printf("Process %d: %s - %d MB\n", i+1, procs[i].name, procs[i].memory);
        }
        sleep(5);
    }
    return 0;
}