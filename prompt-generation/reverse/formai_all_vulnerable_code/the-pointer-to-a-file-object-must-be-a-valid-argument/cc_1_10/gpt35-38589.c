//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define SAMPLE_INTERVAL_USEC (100000) // 100ms in microseconds

void printUsage(float usage) {
    printf("CPU Usage : %.2f%%\n", usage);
}

int main() {
    struct timeval t_start, t_end;
    struct timeval s_start, s_end;
    float elapsed, available;

    FILE *fp = NULL;
    char buffer[128];
    int cpu_usage = -1, prev_cpu_usage = -1;

    gettimeofday(&t_start, NULL);
    while(1) {
        gettimeofday(&s_start, NULL);
        fp = fopen("/proc/stat", "r");
        fgets(buffer, sizeof(buffer), fp);
        fclose(fp);

        sscanf(buffer, "cpu %*d %*d %*d %*d %*d %*d %*d %*d %*d %d", &cpu_usage);

        if(prev_cpu_usage == -1) {
            prev_cpu_usage = cpu_usage;
            gettimeofday(&s_end, NULL);
            elapsed = (float)(s_end.tv_sec - s_start.tv_sec) + ((float)s_end.tv_usec - (float)s_start.tv_usec)/1000000;
            available = ((float)SAMPLE_INTERVAL_USEC/1000000) - elapsed;
            if(available > 0) {
                usleep(available*1000000);
            }
            gettimeofday(&t_end, NULL);
            float usage = ((float)(cpu_usage - prev_cpu_usage)*100)/((float)(t_end.tv_sec - t_start.tv_sec)*1000000 
                + (float)(t_end.tv_usec - t_start.tv_usec));
            printUsage(usage);
        } else {
            prev_cpu_usage = cpu_usage;
            gettimeofday(&t_end, NULL);
            float usage = ((float)(cpu_usage - prev_cpu_usage)*100)/((float)(t_end.tv_sec - t_start.tv_sec)*1000000 
                + (float)(t_end.tv_usec - t_start.tv_usec));
            printUsage(usage);
        }
        gettimeofday(&t_start, NULL);
        usleep(SAMPLE_INTERVAL_USEC - 100); // Subtract 100us for the latency
    }
    return 0;
}