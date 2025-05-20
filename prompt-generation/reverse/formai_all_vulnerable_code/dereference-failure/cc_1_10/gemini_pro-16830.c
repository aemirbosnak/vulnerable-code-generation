//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int fd;
    char *log_file = "/var/log/my_log.txt";
    char *message = "This is a test message.";
    char *timestamp;
    struct tm *tm;
    time_t t;

    // Open the log file.
    fd = open(log_file, O_WRONLY | O_APPEND | O_CREAT, 0644);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Get the current time.
    t = time(NULL);
    tm = localtime(&t);

    // Format the timestamp.
    timestamp = asctime(tm);
    if (timestamp == NULL)
    {
        perror("asctime");
        exit(EXIT_FAILURE);
    }

    // Write the message to the log file.
    if (write(fd, timestamp, strlen(timestamp)) == -1)
    {
        perror("write");
        exit(EXIT_FAILURE);
    }
    if (write(fd, message, strlen(message)) == -1)
    {
        perror("write");
        exit(EXIT_FAILURE);
    }
    if (write(fd, "\n", 1) == -1)
    {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Close the log file.
    if (close(fd) == -1)
    {
        perror("close");
        exit(EXIT_FAILURE);
    }

    return 0;
}