//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define BUF_SIZE 64

int main() {
    char buffer[BUF_SIZE];
    FILE* fp;
    double cpu_usage;
    int num_cpus = sysconf(_SC_NPROCESSORS_ONLN);
    
    while (1) {
        fp = fopen("/proc/stat", "r");
        fgets(buffer, BUF_SIZE, fp);
        fclose(fp);

        char* token = strtok(buffer, " ");
        token = strtok(NULL, " ");
        long int user_time = atoi(token);
        token = strtok(NULL, " ");
        long int nice_time = atoi(token);
        token = strtok(NULL, " ");
        long int sys_time = atoi(token);
        token = strtok(NULL, " ");
        long int idle_time = atoi(token);

        long int total_time = user_time + nice_time + sys_time + idle_time;

        sleep(1);

        fp = fopen("/proc/stat", "r");
        fgets(buffer, BUF_SIZE, fp);
        fclose(fp);

        token = strtok(buffer, " ");
        token = strtok(NULL, " ");
        long int new_user_time = atoi(token);
        token = strtok(NULL, " ");
        long int new_nice_time = atoi(token);
        token = strtok(NULL, " ");
        long int new_sys_time = atoi(token);
        token = strtok(NULL, " ");
        long int new_idle_time = atoi(token);

        long int new_total_time = new_user_time + new_nice_time + new_sys_time + new_idle_time;

        cpu_usage = (double)(num_cpus * (new_total_time - total_time - (new_idle_time - idle_time))) / (double)(new_total_time - total_time);
        printf("CPU Usage: %0.2lf%%\n", cpu_usage);
    }

    return 0;
}