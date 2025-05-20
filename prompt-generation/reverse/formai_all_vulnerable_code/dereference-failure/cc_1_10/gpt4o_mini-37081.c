//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define LOG_FILE "system_event.log"
#define MAX_EVENT_SIZE 256

void initialize_log_file() {
    FILE *file = fopen(LOG_FILE, "w");
    if (file != NULL) {
        fprintf(file, "System Event Logger Initialized\n");
        fclose(file);
    }
}

void log_event(const char *event) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file != NULL) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        fprintf(file, "[%02d-%02d-%04d %02d:%02d:%02d] %s\n",
                t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
                t->tm_hour, t->tm_min, t->tm_sec, event);
        fclose(file);
    } else {
        perror("Unable to open log file");
    }
}

void log_system_info() {
    char hostname[1024];
    pid_t pid = getpid();
    gethostname(hostname, sizeof(hostname));
    
    char event[MAX_EVENT_SIZE];
    snprintf(event, sizeof(event), "Process ID: %d, Hostname: %s", pid, hostname);
    log_event(event);
}

void simulate_activity() {
    for (int i = 0; i < 5; i++) {
        sleep(1);
        char event[MAX_EVENT_SIZE];
        snprintf(event, sizeof(event), "Simulated Activity %d completed", i + 1);
        log_event(event);
    }
}

void check_log_file() {
    struct stat file_stat;
    if (stat(LOG_FILE, &file_stat) == 0) {
        char event[MAX_EVENT_SIZE];
        snprintf(event, sizeof(event), "Log file size: %ld bytes", file_stat.st_size);
        log_event(event);
    } else {
        log_event("Log file does not exist or cannot be statted");
    }
}

void cleanup() {
    log_event("Cleaning up resources before exit.");
    remove(LOG_FILE);
}

int main() {
    atexit(cleanup);
    
    initialize_log_file();
    log_event("System Event Logger Started");
    log_system_info();
    simulate_activity();
    check_log_file();
    
    log_event("System Event Logger Finished");
    return 0;
}