//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>

bool alarm_raised = false;

void handler(int signum)
{
    alarm_raised = true;
}

int main(int argc, char *argv[])
{
    char buffer[1024];
    char *logfile = "/var/log/messages";

    if (argc == 2) {
        logfile = argv[1];
    }

    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(logfile, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Cannot open syslog file %s", logfile);
        exit(EXIT_FAILURE);
    }

    signal(SIGALRM, handler);
    alarm(60); // send alarm after 60 seconds

    while ((read = getline(&line, &len, fp)) != -1) {
        if (alarm_raised) {
            printf("Intrusion detected! Exiting.\n");
            exit(EXIT_FAILURE);
        }

        if (strstr(line, "root") && strstr(line, "sshd") && strstr(line, "Accepted")) {
            // a successful login attempt
            printf("Successful login attempt by root detected.\n");
        }

        if (strstr(line, "Invalid user") || strstr(line, "Failed password")) {
            // a failed login attempt
            printf("Failed login attempt detected.\n");
        }

        if (strstr(line, "command not found") || strstr(line, "no such file or directory")) {
            // a command execution attempt
            printf("Command execution attempt detected.\n");
        }
    }

    fclose(fp);
    if (line)
        free(line);

    exit(EXIT_SUCCESS);
}