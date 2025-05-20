//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>

#define LOG_FILE "/var/log/event.log"
#define LOG_PERM 0644

void create_log_file() {
    int fd;

    fd = open(LOG_FILE, O_CREAT | O_WRONLY | O_TRUNC, LOG_PERM);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    close(fd);
}

void log_event(const char *event_type, const char *message) {
    int fd;
    time_t now;
    struct tm *now_tm;
    char log_line[256];

    fd = open(LOG_FILE, O_WRONLY | O_APPEND);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    time(&now);
    now_tm = localtime(&now);

    snprintf(log_line, sizeof(log_line), "[%s] [%s] %s\n",
             asctime(now_tm), event_type, message);

    write(fd, log_line, strlen(log_line));

    close(fd);
}

void main_logger() {
    openlog("event_logger", LOG_PID | LOG_PERROR, LOG_DAEMON);

    create_log_file();

    syslog(LOG_INFO, "Event logger started.");

    // Simulate some events
    log_event("System", "The system is now running.");
    log_event("Network", "Network connection established.");
    log_event("User", "User 'john_doe' logged in.");

    closelog();
}

int main() {
    main_logger();

    return EXIT_SUCCESS;
}