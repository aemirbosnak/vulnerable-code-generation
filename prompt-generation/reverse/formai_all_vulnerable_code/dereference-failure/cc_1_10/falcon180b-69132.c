//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

#define SLEEP_TIME 1
#define MAX_CPU_USAGE 100
#define PROCESS_NAME "cpu_monitor"

int main(int argc, char *argv[]) {
    int cpu_usage;
    struct rusage usage;
    struct timeval start_time, end_time;
    int i;

    if (argc!= 2) {
        printf("Usage: %s <process_name>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], PROCESS_NAME)!= 0) {
        printf("Invalid process name\n");
        return 1;
    }

    getrusage(RUSAGE_SELF, &usage);
    cpu_usage = (int) (usage.ru_utime.tv_sec + usage.ru_stime.tv_sec +
                      (usage.ru_utime.tv_usec + usage.ru_stime.tv_usec) / 1000000);

    printf("CPU usage: %d%%\n", cpu_usage);

    for (i = 0; i < MAX_CPU_USAGE; i++) {
        printf("\rCPU usage: %d%%", i);
        fflush(stdout);
        usleep(SLEEP_TIME * 1000);
    }

    gettimeofday(&start_time, NULL);

    while (1) {
        gettimeofday(&end_time, NULL);

        if (end_time.tv_sec - start_time.tv_sec >= 1) {
            printf("\n");
            break;
        }

        usleep(SLEEP_TIME * 1000);
    }

    return 0;
}