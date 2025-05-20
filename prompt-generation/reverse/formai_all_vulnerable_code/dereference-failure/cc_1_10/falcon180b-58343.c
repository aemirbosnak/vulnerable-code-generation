//Falcon-180B DATASET v1.0 Category: System event logger ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define LOG_FILE_NAME "system_log.txt"

void log_event(char *event)
{
    char log_entry[256];
    time_t now;
    struct tm *tm;

    time(&now);
    tm = localtime(&now);

    sprintf(log_entry, "[%d-%02d-%02d %02d:%02d:%02d] %s\n",
            tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
            tm->tm_hour, tm->tm_min, tm->tm_sec, event);

    FILE *log_file;
    if ((log_file = fopen(LOG_FILE_NAME, "a")) == NULL)
    {
        fprintf(stderr, "Error: Failed to open log file for writing.\n");
        return;
    }

    if (fputs(log_entry, log_file) == EOF)
    {
        fprintf(stderr, "Error: Failed to write to log file.\n");
        fclose(log_file);
        return;
    }

    fclose(log_file);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s [event]\n", argv[0]);
        return 1;
    }

    log_event(argv[1]);

    return 0;
}