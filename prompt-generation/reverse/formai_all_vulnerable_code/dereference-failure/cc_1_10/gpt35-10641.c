//FormAI DATASET v1.0 Category: Log analysis ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256 // maximum length of each line in the log file
#define MAX_IP_LENGTH 16 // maximum length of each IP address

struct Log
{
    char ip[MAX_IP_LENGTH];
    int count;
};

int compare_logs(const void *a, const void *b)
{
    const struct Log *log1 = *(const struct Log**)a;
    const struct Log *log2 = *(const struct Log**)b;
    return log2->count - log1->count;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s [log file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *filename = argv[1];
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error: could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    struct Log *logs[MAX_IP_LENGTH] = {0};
    int num_logs = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp))
    {
        char *ip = strtok(line, " ");

        if (ip == NULL || strlen(ip) > MAX_IP_LENGTH)
        {
            printf("Warning: could not parse IP address from line: %s", line);
            continue;
        }

        int found = 0;

        for (int i = 0; i < num_logs; i++)
        {
            if (strcmp(logs[i]->ip, ip) == 0)
            {
                logs[i]->count++;
                found = 1;
                break;
            }
        }

        if (!found)
        {
            struct Log *log = malloc(sizeof(struct Log));
            strcpy(log->ip, ip);
            log->count = 1;
            logs[num_logs++] = log;
        }
    }

    qsort(logs, num_logs, sizeof(struct Log*), compare_logs);

    printf("Top 10 IP addresses:\n");

    for (int i = 0; i < num_logs && i < 10; i++)
    {
        printf("%d. %s (%d occurrences)\n", i+1, logs[i]->ip, logs[i]->count);
    }

    for (int i = 0; i < num_logs; i++)
    {
        free(logs[i]);
    }

    fclose(fp);
    return 0;
}