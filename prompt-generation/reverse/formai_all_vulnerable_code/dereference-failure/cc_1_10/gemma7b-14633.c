//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <string.h>

void parse_process_list(int pid)
{
    FILE *fp;
    char buf[4096];
    char *line = NULL;
    int offset = 0;
    int i = 0;

    fp = fopen("/proc/pid/status", "r");
    if (!fp)
    {
        return;
    }

    while (getline(&line, buf, sizeof(buf)) != -1)
    {
        char *key = strchr(line, ':');
        char *value = key + 1;

        switch (i)
        {
            case 0:
                printf("Process Name: %s\n", value);
                break;
            case 1:
                printf("User ID: %d\n", atoi(value));
                break;
            case 2:
                printf("Group ID: %d\n", atoi(value));
                break;
            case 3:
                printf("Memory Usage: %d KB\n", atoi(value));
                break;
            case 4:
                printf("CPU Usage: %.2f%%\n", atof(value));
                break;
            default:
                break;
        }

        offset++;
        i++;
    }

    fclose(fp);
    free(line);
}

int main()
{
    int pid = getpid();
    parse_process_list(pid);

    return 0;
}