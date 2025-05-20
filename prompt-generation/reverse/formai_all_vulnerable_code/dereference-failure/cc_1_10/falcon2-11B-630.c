//Falcon2-11B DATASET v1.0 Category: System event logger ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/mman.h>

char *program_name = "my_program";
int event_logger_fd;
char event_logger_file_name[100];
int event_logger_pid;

void log_event(char *event_type, char *event_details) {
    time_t now = time(NULL);
    struct tm *time_info = localtime(&now);
    char *timestamp = asctime(time_info);

    snprintf(event_logger_file_name, sizeof(event_logger_file_name), "%s.%s.%s.%s", program_name, timestamp, event_type, event_details);

    event_logger_fd = open(event_logger_file_name, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (event_logger_fd < 0) {
        fprintf(stderr, "Error opening event log file: %s\n", strerror(errno));
        exit(1);
    }

    write(event_logger_fd, event_type, strlen(event_type));
    write(event_logger_fd, " ", 1);
    write(event_logger_fd, event_details, strlen(event_details));
    write(event_logger_fd, "\n", 1);

    close(event_logger_fd);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <event>\n", program_name);
        exit(1);
    }

    event_logger_pid = getpid();

    log_event(argv[1], "Logged event: ");

    exit(0);
}