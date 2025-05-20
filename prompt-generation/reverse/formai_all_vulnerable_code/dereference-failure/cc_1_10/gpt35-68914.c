//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/time.h>

float get_cpu_usage(){
    static struct timeval last_time;
    static struct timeval last_cpu;
    struct timeval cur_time, cur_cpu;
    gettimeofday(&cur_time, NULL);

    FILE* fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("Failed to open /proc/stat");
        return -1.0;
    }

    char buf[1024];
    fgets(buf, sizeof(buf), fp);
    fclose(fp);
    char* pos = strtok(buf, " ");
    pos = strtok(NULL, " ");
    int user = atoi(pos);
    pos = strtok(NULL, " ");
    int nice = atoi(pos);
    pos = strtok(NULL, " ");
    int system = atoi(pos);
    pos = strtok(NULL, " ");
    int idle = atoi(pos);
    pos = strtok(NULL, " ");
    int iowait = atoi(pos);
    pos = strtok(NULL, " ");
    int irq = atoi(pos);
    pos = strtok(NULL, " ");
    int softirq = atoi(pos);
    int cpu = user + nice + system + idle + iowait + irq + softirq;

    gettimeofday(&cur_cpu, NULL);

    float delta_time = (cur_time.tv_sec - last_time.tv_sec) + (cur_time.tv_usec - last_time.tv_usec)/1000000.0;
    float delta_cpu = cpu - last_cpu.tv_sec;
    float cpu_usage = (delta_cpu / delta_time);

    last_time = cur_time;
    last_cpu = cur_cpu;

    return cpu_usage;
}

int main(){
    while(1){
        float usage = get_cpu_usage();
        printf("CPU Usage : %2.2f%%\n", usage);
        sleep(1);
    }
    return 0;
}