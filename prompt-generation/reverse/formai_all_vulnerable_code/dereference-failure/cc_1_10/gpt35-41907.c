//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#define BUFFER_SIZE 1024
#define MAX_CPU 4

unsigned long long get_cpu_time(unsigned long long *, unsigned long long *);
int read_cpu_info(int, unsigned long long *, unsigned long long*);
void display_cpu(int, int, unsigned long long *, unsigned long long *);

int main(int argc, char **argv)
{

    unsigned long long prev_cpu_ticks[MAX_CPU], cur_cpu_ticks[MAX_CPU];
    int fd, cpu_count, interval;

    if (argc > 1)
        interval = atoi(argv[1]);
    else
        interval = 1;

    if ((fd = open("/proc/stat", O_RDONLY)) < 0)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    cpu_count = read_cpu_info(fd, prev_cpu_ticks, NULL);

    while(1)
    {

        sleep(interval);
        lseek(fd, 0L, SEEK_SET);
        cpu_count = read_cpu_info(fd, cur_cpu_ticks, NULL);

        display_cpu(cpu_count, interval, prev_cpu_ticks, cur_cpu_ticks);

        memcpy(prev_cpu_ticks, cur_cpu_ticks, sizeof(unsigned long long) * cpu_count);

    }

    close(fd);

    return EXIT_SUCCESS;
}

/** Calculate CPU ticks **/
unsigned long long get_cpu_time(unsigned long long *usr, unsigned long long *sys)
{

    int fd;
    char buffer[BUFFER_SIZE];
    char *p;

    unsigned long long user, nice, sys_tmp, idle, iowait, irq, softirq;

    if ((fd = open("/proc/stat", O_RDONLY)) < 0)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    if (read(fd, buffer, sizeof(buffer)) < 0)
    {
        perror("read");
        exit(EXIT_FAILURE);
    }

    p = buffer;
    /* Skip cpu label */
    while (*p != 'c') p++;
    p += 4;
    /* Read user, nice, sys, idle, iowait, irq, softirq */
    sscanf(p, "%llu %llu %llu %llu %llu %llu %llu", &user, &nice, &sys_tmp, &idle, &iowait, &irq, &softirq);
    close(fd);

    *usr = user - *usr;
    *sys = sys_tmp - *sys;

    return (*usr + *sys);
}

/** Read CPU info from /proc/stat **/
int read_cpu_info(int fd, unsigned long long *usr, unsigned long long *sys)
{

    int size, count;
    char buffer[BUFFER_SIZE];
    char *p;
    unsigned long long user, nice, sys_tmp, idle, iowait, irq, softirq;
    int cpu_count = -1;

    if (read(fd, buffer, sizeof(buffer)) < 0)
    {
        perror("read");
        exit(EXIT_FAILURE);
    }

    p = strtok(buffer, "\n");

    while (p != NULL)
    {
        if (strncmp(p, "cpu", 3) == 0)
        {
            if (cpu_count < 0)
                cpu_count++;

            count = sscanf(p, "cpu%*d %llu %llu %llu %llu %llu %llu %llu", &user, &nice, &sys_tmp, &idle, &iowait, &irq, &softirq);

            if (count == 4 || count == 7)
            {
                cpu_count++;
                usr[cpu_count] = user;
                sys[cpu_count] = sys_tmp;
            }
        }
        p = strtok(NULL, "\n");
    }

    return cpu_count;
}

/** Display CPU usage **/
void display_cpu(int cpu_count, int interval, unsigned long long *prev, unsigned long long *cur)
{
    float cpu_usage;
    unsigned long long prev_cpu_ticks, cur_cpu_ticks, prev_idle_time, cur_idle_time;
    int i;

    printf("CPU usage: \n");

    for (i = 0; i <= cpu_count; i++)
    {
        prev_cpu_ticks = prev[i];
        cur_cpu_ticks = cur[i];
        prev_idle_time = prev_cpu_ticks % (prev_cpu_ticks + (prev[i+1] - prev_cpu_ticks)/cpu_count);
        cur_idle_time = cur_cpu_ticks % (cur_cpu_ticks + (cur[i+1] - cur_cpu_ticks)/cpu_count);
        cpu_usage = 100.0 * (1 - (cur_idle_time - prev_idle_time)/(float)(cur_cpu_ticks - prev_cpu_ticks));
        printf("CPU %d : %.2f %% \n", i, cpu_usage);
    }

    printf("\n");
}