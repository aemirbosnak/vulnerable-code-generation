//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: Cryptic
#define _CRYPTIC_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct {
    char time[17];
    char event[100];
} log_entry;

void _log(char *event) {
    log_entry entry;
    struct tm tm;
    int fd;
    char filename[20];

    time_t t = time(NULL);
    localtime_r(&t, &tm);

    strftime(entry.time, sizeof(entry.time), "%Y-%m-%d %H:%M:%S", &tm);

    strcpy(filename, "/var/log/cryptic.log");
    fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644);

    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    sprintf(entry.event, "%s: %s", entry.time, event);

    if (write(fd, &entry, sizeof(entry)) < 0) {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd);
}

#define LOG(format, args...) do {\
    char event[100];\
    snprintf(event, sizeof(event), format, ##args);\
    _log(event);\
} while (0)

int main() {
    LOG("Init: System is alive");
    sleep(1);
    LOG("Warning: Mouse not moving for 1 minute");
    sleep(60);
    LOG("Error: Disk space is below 10%");
    return 0;
}