//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/times.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(void) {
    struct tms t;
    clock_t t_real, t_cpu;

    char buffer[BUFFER_SIZE];

    while(1) {
        t_real = times(&t);
        if(t_real == -1) {
            perror("times");
            exit(EXIT_FAILURE);
        }

        /* Read the cpu usage data from the /proc/stat file */
        FILE* stat_file = fopen("/proc/stat", "r");
        if(stat_file == NULL) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }

        /* Get the first line from the file */
        char* line = fgets(buffer, BUFFER_SIZE, stat_file);
        fclose(stat_file);

        if(line == NULL) {
            perror("fgets");
            exit(EXIT_FAILURE);
        }

        /* Extract the values we need from the first line */
        long int user_jiffies, nice_jiffies, system_jiffies, idle_jiffies;
        sscanf(line, "cpu %li %li %li %li", &user_jiffies, &nice_jiffies, &system_jiffies, &idle_jiffies);

        /* Calculate the total jiffies (sum of all cpu states) */
        long int total_jiffies = user_jiffies + nice_jiffies + system_jiffies + idle_jiffies;

        /* Calculate the cpu usage percentage */
        float cpu_usage = (user_jiffies + nice_jiffies + system_jiffies) * 100.0 / total_jiffies;

        /* Print the cpu usage percentage */
        printf("CPU Usage: %.2f%%\n", cpu_usage);

        /* Sleep for 1 second */
        usleep(1000000);

        /* Get the CPU time */
        t_cpu = times(&t);
        if(t_cpu == -1) {
            perror("times");
            exit(EXIT_FAILURE);
        }

        /* Calculate the time spent in user mode */
        long int user_time = t.tms_utime - t_real;

        /* Calculate the time spent in system mode */
        long int system_time = t.tms_stime - t_real;

        /* Calculate the elapsed real time */
        long int elapsed_time = (t_cpu - t_real) * 1000 / sysconf(_SC_CLK_TCK);

        /* Print the CPU and elapsed time */
        printf("CPU Time: %ldms, User Time: %ldms, System Time: %ldms\n", elapsed_time, user_time, system_time);
    }

    return 0;
}