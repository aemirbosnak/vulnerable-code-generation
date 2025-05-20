//FormAI DATASET v1.0 Category: Log analysis ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printLine(char *logLine);
void printOutput(char *firstTimestamp, char *lastTimestamp, int count);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <log file>\n", argv[0]);
        exit(1);
    }

    char *logPath = argv[1];

    FILE *logFile;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    logFile = fopen(logPath, "r");

    if (logFile == NULL)
    {
        printf("Failed to open log file\n");
        exit(1);
    }

    char *firstTimestamp = "";
    char *lastTimestamp = "";
    int count = 0;

    while ((read = getline(&line, &len, logFile)) != -1)
    {
        char *timestamp = strtok(line, " ");
        char *level = strtok(NULL, " ");
        char *message = strtok(NULL, "\n");

        if (strcmp(level, "ERROR") == 0)
        {
            printLine(line);

            count++;

            if (strcmp(firstTimestamp, "") == 0)
            {
                firstTimestamp = timestamp;
            }

            lastTimestamp = timestamp;
        }
    }

    printOutput(firstTimestamp, lastTimestamp, count);

    fclose(logFile);

    if (line)
    {
        free(line);
    }

    return 0;
}

void printLine(char *logLine)
{
    printf("%s", logLine);
}

void printOutput(char *firstTimestamp, char *lastTimestamp, int count)
{
    printf("\n\nTotal errors: %d\n", count);
    printf("First error timestamp: %s\n", firstTimestamp);
    printf("Last error timestamp: %s\n", lastTimestamp);
}