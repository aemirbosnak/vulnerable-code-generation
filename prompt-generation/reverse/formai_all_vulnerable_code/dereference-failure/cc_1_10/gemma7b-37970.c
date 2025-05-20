//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_BUFFER_SIZE 256

typedef struct CPUUsage
{
    int user;
    int system;
    int idle;
    int total;
} CPUUsage;

CPUUsage getCPUUsage()
{
    CPUUsage usage;

    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL)
    {
        return usage;
    }

    char buffer[MAX_BUFFER_SIZE];
    fgets(buffer, MAX_BUFFER_SIZE, fp);

    char *fields = buffer;
    usage.user = atoi(fields[0]);
    usage.system = atoi(fields[2]);
    usage.idle = atoi(fields[3]);
    usage.total = atoi(fields[4]);

    fclose(fp);

    return usage;
}

int main()
{
    CPUUsage usage = getCPUUsage();

    printf("CPU Usage:\n");
    printf("  - User: %d%%\n", usage.user);
    printf("  - System: %d%%\n", usage.system);
    printf("  - Idle: %d%%\n", usage.idle);
    printf("  - Total: %d%%\n", usage.total);

    return 0;
}