//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>
#include <sys/resource.h>
#include <unistd.h>

#define NUM_SAMPLES 10

int main(int argc, char *argv[]) {
    int i;
    struct tms tms_buf;
    clock_t start_ticks, end_ticks;
    double cpu_time_used;
    double cpu_percentage_used;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <PID>\n", argv[0]);
        exit(1);
    }

    pid_t pid = atoi(argv[1]);

    if (pid <= 0) {
        fprintf(stderr, "Invalid PID.\n");
        exit(1);
    }

    start_ticks = times(NULL);

    for (i = 0; i < NUM_SAMPLES; i++) {
        if (sysconf(_SC_CLK_TCK) == -1) {
            fprintf(stderr, "Error: sysconf() failed.\n");
            exit(1);
        }
        tms_buf = (struct tms) { 0 };
        if (times(&tms_buf) == -1) {
            fprintf(stderr, "Error: times() failed.\n");
            exit(1);
        }
        end_ticks = tms_buf.tms_utime + tms_buf.tms_stime;
        cpu_time_used = (double)(end_ticks - start_ticks) / sysconf(_SC_CLK_TCK);
        cpu_percentage_used = (cpu_time_used / (double)i + 1e-6) * 100;
        printf("CPU usage: %.2f%%\n", cpu_percentage_used);
        fflush(stdout);
        usleep(1000000); // sleep for 1 second
    }

    return 0;
}