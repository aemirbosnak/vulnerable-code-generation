//Falcon-180B DATASET v1.0 Category: System event logger ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define LOGFILE "/var/log/sys.log"
#define MAX_LINE_LEN 256

// Function to log the message to the syslog
void log_message(const char *msg)
{
    FILE *fp;
    time_t now;
    struct tm *tm;
    char timestr[80];
    char line[MAX_LINE_LEN];

    time(&now);
    tm = localtime(&now);
    strftime(timestr, 80, "%Y-%m-%d %H:%M:%S", tm);

    fp = fopen(LOGFILE, "a");
    if (fp == NULL)
    {
        fprintf(stderr, "Failed to open log file.\n");
        exit(EXIT_FAILURE);
    }

    sprintf(line, "%s %s\n", timestr, msg);
    fwrite(line, strlen(line), 1, fp);
    fclose(fp);
}

// Function to fork and execute a command
void execute_command(char *cmd)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        fprintf(stderr, "Failed to fork.\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        execl("/bin/sh", "sh", "-c", cmd, NULL);
        fprintf(stderr, "Failed to execute command.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}

// Function to parse the command line arguments
void parse_args(int argc, char *argv[])
{
    int i;

    for (i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-v") == 0)
        {
            log_message("Verbose mode enabled");
        }
        else if (strcmp(argv[i], "-q") == 0)
        {
            log_message("Quiet mode enabled");
        }
        else if (strcmp(argv[i], "-h") == 0)
        {
            log_message("Help requested");
        }
        else
        {
            execute_command(argv[i]);
        }
    }
}

int main(int argc, char *argv[])
{
    log_message("System event logger started");
    parse_args(argc, argv);
    return 0;
}