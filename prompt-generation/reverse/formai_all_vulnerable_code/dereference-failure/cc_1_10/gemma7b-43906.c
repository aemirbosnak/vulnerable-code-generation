//Gemma-7B DATASET v1.0 Category: RAM usage monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    system("/bin/clear");
    system("tput cup 0 0");

    char **ram_usage = (char **)malloc(10 * sizeof(char *));
    for (int i = 0; i < 10; i++)
    {
        ram_usage[i] = (char *)malloc(20 * sizeof(char));
    }

    FILE *fp = fopen("/proc/meminfo", "r");
    char line[256];

    while (fgets(line, 256, fp) != NULL)
    {
        char *ram_usage_data = strstr(line, "Mem:");
        if (ram_usage_data)
        {
            char *free_mem = strstr(ram_usage_data, "free:");
            char *used_mem = strstr(ram_usage_data, "used:");
            char *buff_mem = strstr(ram_usage_data, "buff:");
            char *cache_mem = strstr(ram_usage_data, "cache:");

            int free_kb = atoi(free_mem) / 1024;
            int used_kb = atoi(used_mem) / 1024;
            int buff_kb = atoi(buff_mem) / 1024;
            int cache_kb = atoi(cache_mem) / 1024;

            for (int i = 0; i < 10; i++)
            {
                sprintf(ram_usage[i], "%d KB", free_kb);
            }

            printf("\n");
            for (int i = 0; i < 10; i++)
            {
                printf("%s\n", ram_usage[i]);
            }

            printf("\n");
        }
    }

    fclose(fp);

    for (int i = 0; i < 10; i++)
    {
        free(ram_usage[i]);
    }
    free(ram_usage);

    return 0;
}